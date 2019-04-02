#include "GDDOSILog.h"
#include "AwsS3Store.h"

extern CGDDOSILog g_GDDOSILog;




AwsS3BackupQueue::AwsS3BackupQueue()
{

}


AwsS3BackupQueue::~AwsS3BackupQueue()
{

	if (nullptr != m_pQuePush)
	{
		delete m_pQuePush;
		m_pQuePush = nullptr;
	}
	if (nullptr != m_pQuePop)
	{
		delete m_pQuePop;
		m_pQuePop = nullptr;
	}
}

int AwsS3BackupQueue::InitBackupQue(int nQueCapacity)
{
	int ret = 0;

	do
	{
		m_pQuePush = new Aws::Utils::Threading::Semaphore(nQueCapacity, nQueCapacity);
		
		if (nullptr == m_pQuePush)
		{
			ret = -1;
			break;
		}

		m_pQuePop = new Aws::Utils::Threading::Semaphore(0, nQueCapacity);
		if (nullptr == m_pQuePop)
		{
			ret = -1;
			break;
		}

		m_nQueCapacity = nQueCapacity;

	} while (false);

	return ret;
}

void AwsS3BackupQueue::pushTask(BackupQueueItem& item)
{
	m_pQuePush->WaitOne();
	
	{
		std::lock_guard<std::mutex> locker(m_queueLock);
		m_taskQ.push(item);
	}

	m_pQuePop->Release();
}



BackupQueueItem AwsS3BackupQueue::popTask()
{
	BackupQueueItem t;
	m_pQuePop->WaitOne();
	{
		std::lock_guard<std::mutex> locker(m_queueLock);
		t = m_taskQ.front();
		m_taskQ.pop();
	}
	m_pQuePush->Release();

	return t;
}

///////////////////////////////////////////////////////////////////////////////////

AwsS3BackupExecutor::AwsS3BackupExecutor()
{

}

AwsS3BackupExecutor::~AwsS3BackupExecutor()
{
	g_GDDOSILog.WriteLogA(1, "Destruct the Backup Executor!");
	for (int i = 0; i < m_vTaskThreads.size(); ++i)
	{
		BackupQueueItem item;
		item.m_nCmd = BACKUP_EXIT;
		item.m_pTask = NULL;
		m_BackupTaskQueue.pushTask(item);
	}
	for (int i = 0; i < m_vTaskThreads.size(); ++i)
	{
		m_vTaskThreads[i]->join();
	}
}

int AwsS3BackupExecutor::InitBackupExecutor(int nQueSize)
{
	int ret = 0;

	do 
	{
		ret = m_BackupTaskQueue.InitBackupQue(nQueSize);
		if (0 != ret)
		{
			break;
		}
		for (int i = 0; i < nQueSize; ++i)
		{
			std::thread* pT = new std::thread(std::bind(&AwsS3BackupExecutor::TaskExecutorFuncImpl, this));
			m_vTaskThreads.push_back(pT);
		}
	} while (false);
	
	return ret;
}

bool AwsS3BackupExecutor::SubmitToThread(std::function<void()>&& fn)
{
	std::function<void()>* pfTask = new std::function<void()>();
	*pfTask = fn;
	
	BackupQueueItem item;
	item.m_nCmd		= BACKUP_DO_TASK;
	item.m_pTask	= pfTask;
	m_BackupTaskQueue.pushTask(item);

	return true;
}


void AwsS3BackupExecutor::TaskExecutorFuncImpl()
{
	g_GDDOSILog.WriteLogA(1, "Upload thread:[%d] is started.", GetCurrentThreadId());
	while (1)
	{
		BackupQueueItem item = m_BackupTaskQueue.popTask();
		if (BACKUP_DO_TASK == item.m_nCmd)
		{
			(*item.m_pTask)();
			delete (item.m_pTask);
		}
		else
		{
			break;
		}
	}
	g_GDDOSILog.WriteLogA(1, "Upload thread:[%d] is existed.", GetCurrentThreadId());

}


///////////////////////////////////////////////////////////////////////////////////

Aws::SDKOptions AwsS3Store::m_Options;

static Aws::String FormatRangeSpecifier(std::size_t rangeStart, std::size_t rangeEnd)
{
	Aws::StringStream rangeStream;
	rangeStream << "bytes=" << rangeStart << "-" << rangeEnd;
	return rangeStream.str();
}

AwsS3Store::AwsS3Store()
{
	m_s3Client = NULL;
}

AwsS3Store::~AwsS3Store()
{
	if (m_s3Client)
	{
		delete m_s3Client;
	}
}

int AwsS3Store::InitCloudStoreContext()
{
	int ret = 0;
	m_Options.loggingOptions.logLevel = Aws::Utils::Logging::LogLevel::Info;
	Aws::InitAPI(m_Options);
	return ret;
}

int AwsS3Store::DeInitCloudStoreContext()
{
	int ret = 0;
	Aws::ShutdownAPI(m_Options);
	return ret;
}


int	  AwsS3Store::SetCloudInfo(CloudStoreConfigInfo& cloudAccessInfo)
{
	int ret = 0;
	if (nullptr != cloudAccessInfo.m_szRegion)
	{
		m_strRegion = cloudAccessInfo.m_szRegion;
	}
	if (nullptr != cloudAccessInfo.m_szBucket)
	{
		m_strBucket = cloudAccessInfo.m_szBucket;
	}
	if (nullptr != cloudAccessInfo.m_szAccessKey)
	{
		m_strAccessKey = cloudAccessInfo.m_szAccessKey;
	}
	if (nullptr != cloudAccessInfo.m_szAccessID)
	{
		m_strAccessID = cloudAccessInfo.m_szAccessID;
	}
	m_nMaxReadBytesPerRead = cloudAccessInfo.m_maxBytesPerRead;

	m_UniqueDataBuf.reset(new Aws::Utils::Array<unsigned char>(m_nMaxReadBytesPerRead));

	m_cloudStoreInfo = cloudAccessInfo;
	ret = CreateCloudClient();

	return ret;
}

string AwsS3Store::GetRegion()
{
	return m_strRegion;
}

string AwsS3Store::GetBucket()
{
	return m_strBucket;
}

string AwsS3Store::GetAccessId()
{
	return m_strAccessID;
}

string AwsS3Store::GetAccessKey()
{
	return m_strAccessKey;
}

int AwsS3Store::CreateCloudClient()
{
	int ret = 0;

	Aws::Client::ClientConfiguration clientconfig;
	Aws::Auth::AWSCredentials clientcredential;
	clientcredential.SetAWSSecretKey(m_strAccessKey);
	clientcredential.SetAWSAccessKeyId(m_strAccessID);
	clientconfig.region = m_strRegion;
	clientconfig.connectTimeoutMs = 180000;
	clientconfig.requestTimeoutMs = 300000;
	if (m_cloudStoreInfo.m_nUploadThreadCount)
	{
		shared_ptr<AwsS3BackupExecutor> p = std::make_shared<AwsS3BackupExecutor>();
		p->InitBackupExecutor(m_cloudStoreInfo.m_nUploadThreadCount);
		clientconfig.executor = p;
	}
	m_s3Client = new Aws::S3::S3Client(clientcredential, clientconfig);

	return ret;
}

int AwsS3Store::WriteObject(CloudStoreWriteObjectContext& cloudWriteObjContext)
{
	int ret = 0;

	Aws::Client::ClientConfiguration clientconfig;
	Aws::Auth::AWSCredentials clientcredential;


	Aws::S3::Model::PutObjectRequest putObjectReq;
	putObjectReq.WithBucket(cloudWriteObjContext.m_szBucket).WithKey(cloudWriteObjContext.m_OID);
	Aws::Utils::Array<unsigned char> databuf((unsigned char*)cloudWriteObjContext.m_pBuf, cloudWriteObjContext.m_nWriteBytes);
	Aws::Utils::Stream::PreallocatedStreamBuf streamData(&databuf, databuf.GetLength());
	auto preallocatedStreamReader = Aws::MakeShared<Aws::IOStream>("preallocatedStreamReader", &streamData);
	putObjectReq.SetBody(preallocatedStreamReader);

	Aws::S3::Model::PutObjectOutcome putObjectOutcome = m_s3Client->PutObject(putObjectReq);
	if (!putObjectOutcome.IsSuccess())
	{
		ret = (int)putObjectOutcome.GetError().GetErrorType();
		g_GDDOSILog.WriteLogA(1, "region:[%s], bucket:[%s] put object:[%s] failed.", m_strRegion.c_str(), m_strBucket.c_str(), cloudWriteObjContext.m_OID);
		g_GDDOSILog.WriteLogA(1, "[%s],EC:[%d].", putObjectOutcome.GetError().GetMessage().c_str(), ret);
	}

	return ret;
}

int AwsS3Store::ReadObject(CloudStoreReadObjectContext& cloudReadObjContext)
{
	int ret = 0;
	long long nSize = 0;

	GetObjectRequest   getObjectReq;
	getObjectReq.WithBucket(cloudReadObjContext.m_szBucket).WithKey(cloudReadObjContext.m_OID).
		WithRange(FormatRangeSpecifier(cloudReadObjContext.m_nStart, cloudReadObjContext.m_nEnd));

	//Aws::Utils::Array<unsigned char> databuf(cloudReadObjContext.readLen);
	CreateDownloadStreamCallback responseStreamFunction = [&]()
	{
		auto bufferStream = Aws::New<Aws::Utils::Stream::DefaultUnderlyingStream>("",
			Aws::MakeUnique<Aws::Utils::Stream::PreallocatedStreamBuf>("", this->m_UniqueDataBuf.get(), cloudReadObjContext.readLen));
		return bufferStream;
	};
	getObjectReq.SetResponseStreamFactory(responseStreamFunction);

	GetObjectOutcome getObjectOutcome = m_s3Client->GetObject(getObjectReq);

	if (getObjectOutcome.IsSuccess())
	{
		nSize = getObjectOutcome.GetResult().GetBody().rdbuf()->in_avail();
		cloudReadObjContext.readedLen = nSize;
		getObjectOutcome.GetResult().GetBody().rdbuf()->sgetn(cloudReadObjContext.m_pBuf, nSize);
	}
	else
	{
		ret = (int)getObjectOutcome.GetError().GetErrorType();
		g_GDDOSILog.WriteLogA(1, "region:[%s], bucket:[%s] read object:[%s] failed.", m_strRegion.c_str(), m_strBucket.c_str(), cloudReadObjContext.m_OID);
		g_GDDOSILog.WriteLogA(1, "[%s:%s],EC:[%d].", getObjectOutcome.GetError().GetMessage().c_str(),getObjectOutcome.GetError().GetExceptionName().c_str(), ret);
	}

	return ret;
}

int AwsS3Store::CopyObject(CloudStoreCopyObjectContext& cloudCopyObjContext)
{
	int ret = 0;
	string sourceObj = cloudCopyObjContext.m_szSrcBucket;
	sourceObj += "/";
	sourceObj += cloudCopyObjContext.m_srcOID;

	CopyObjectRequest copyObjectReq;

	copyObjectReq.WithBucket(cloudCopyObjContext.m_szDestBucket).WithKey(cloudCopyObjContext.m_destOID).WithCopySource(sourceObj);

	auto copyObjectOutcome = m_s3Client->CopyObject(copyObjectReq);
	if (copyObjectOutcome.IsSuccess())
	{
		g_GDDOSILog.WriteLogA(1, "Copy from [%s:%s:%s] to [%s:%s:%s] success.", m_strRegion.c_str(), cloudCopyObjContext.m_szSrcBucket,
			cloudCopyObjContext.m_srcOID, cloudCopyObjContext.m_szDestBucket, cloudCopyObjContext.m_destOID);

	}
	else
	{
		ret = (int)copyObjectOutcome.GetError().GetErrorType();
		g_GDDOSILog.WriteLogA(1, "Copy from [%s:%s:%s] to [%s:%s:%s] failed.", m_strRegion.c_str(), cloudCopyObjContext.m_szSrcBucket,
			cloudCopyObjContext.m_srcOID, cloudCopyObjContext.m_szDestBucket, cloudCopyObjContext.m_destOID);
		g_GDDOSILog.WriteLogA(1, "[%s],EC:[%d]", copyObjectOutcome.GetError().GetMessage().c_str(), ret);


	}

	return ret;
}

int AwsS3Store::ListObjects(CloudStoreListObjectConext& cloudListObjsContext)
{
	int ret = 0;
	ListObjectsV2Request listObjectRequest;

	listObjectRequest.WithBucket(cloudListObjsContext.m_szBucket);

	ListObjectsV2Outcome listObjectOutcome = m_s3Client->ListObjectsV2(listObjectRequest);

	if (!listObjectOutcome.IsSuccess())
	{
		ret = (int)listObjectOutcome.GetError().GetErrorType();
		g_GDDOSILog.WriteLogA(1, "list object in bucket:[%s] failed.", cloudListObjsContext.m_szBucket);
		g_GDDOSILog.WriteLogA(1, "The list error message:[%s], EC:[%d]", listObjectOutcome.GetError().GetMessage().c_str(), ret);
	}


	return ret;
}

int AwsS3Store::DeleteObject(CloudStoreDeleteObjectContext& cloudDelObjContext)
{
	int ret = 0;

	DeleteObjectRequest  deleteObjReq;
	DeleteObjectOutcome	 deleteObjOutcome;
	deleteObjReq.WithBucket(cloudDelObjContext.m_szBucket).WithKey(cloudDelObjContext.m_OID);
	deleteObjOutcome = m_s3Client->DeleteObject(deleteObjReq);
	if (!deleteObjOutcome.IsSuccess())
	{
		ret = -1;
		ret = (int)deleteObjOutcome.GetError().GetErrorType();
		g_GDDOSILog.WriteLogA(1, "Delete object:[%s] in bucket:[%s] failed.", cloudDelObjContext.m_OID, cloudDelObjContext.m_szBucket);
		g_GDDOSILog.WriteLogA(1, "The delete error message:[%s], EC:[%d]", deleteObjOutcome.GetError().GetMessage().c_str(), ret);
	}
	else
	{
		g_GDDOSILog.WriteLogA(1, "Delete object:[%s] in bucket:[%s] success.", cloudDelObjContext.m_OID, cloudDelObjContext.m_szBucket);
	}

	return ret;
}

int AwsS3Store::CreateBucket(CloudStoreCreateBucketContext& cloudCreateBucketContext)
{
	int ret = 0;
	if (nullptr == cloudCreateBucketContext.m_szBucketName)
	{
		return -1;
	}

	Aws::S3::Model::CreateBucketRequest createBucketReq;
	createBucketReq.WithBucket(cloudCreateBucketContext.m_szBucketName);
	
	auto createBucketOutcome = m_s3Client->CreateBucket(createBucketReq);
	
	if (createBucketOutcome.IsSuccess())
	{
		g_GDDOSILog.WriteLogA(1, "Create bucket:[%s] successful!", cloudCreateBucketContext.m_szBucketName);
	}
	else
	{
		ret = (int)createBucketOutcome.GetError().GetErrorType();
		g_GDDOSILog.WriteLogA(1, "Create bucket:[%s] failed! [%s], EC:[%d]", cloudCreateBucketContext.m_szBucketName,
								 createBucketOutcome.GetError().GetMessage().c_str(),ret);
	}

	return ret;
}

int AwsS3Store::DeleteBucket(CloudStoreDeleteBucketContext& cloudDelBucketContext)
{
	int ret = 0;
	
	if (nullptr == cloudDelBucketContext.m_szBucketName)
	{
		return -1;
	}

	Aws::S3::Model::DeleteBucketRequest delBucketReq;
	delBucketReq.WithBucket(cloudDelBucketContext.m_szBucketName);
	
	auto delBucketOutcome = m_s3Client->DeleteBucket(delBucketReq);
	
	if (delBucketOutcome.IsSuccess())
	{
		g_GDDOSILog.WriteLogA(1, "delete bucket:[%s] successful!", cloudDelBucketContext.m_szBucketName);
	}
	else
	{
		ret = (int)delBucketOutcome.GetError().GetErrorType();
		g_GDDOSILog.WriteLogA(1, "delete bucket:[%s] failed.[%s]:[%d].", cloudDelBucketContext.m_szBucketName, delBucketOutcome.GetError().GetMessage().c_str(),ret);
	}

	return ret;
}

int AwsS3Store::ListBucket(CloudStoreListBucketContext&     cloudListBucketContext)
{
	int ret = 0;
	
	auto listBucketOutcome = m_s3Client->ListBuckets();
	
	if (listBucketOutcome.IsSuccess())
	{
		Aws::Vector<Aws::S3::Model::Bucket> bucket_list = listBucketOutcome.GetResult().GetBuckets();

		if (!bucket_list.empty())
		{
			int nBucketSize = 0;
			for (auto const &bucket : bucket_list)
			{
				nBucketSize += bucket.GetName().length();
				nBucketSize += 1;
			}
			nBucketSize += 1;
			char* szBucketArray = new char[nBucketSize];
			
			for (auto const &bucket : bucket_list)
			{
				strcat_s(szBucketArray, nBucketSize, bucket.GetName().c_str());
				szBucketArray += (bucket.GetName().length() + 1);
			}
			szBucketArray = '\0';
			cloudListBucketContext.m_szBucketNameList = szBucketArray;
		}
	}
	else
	{
		ret = (int)listBucketOutcome.GetError().GetErrorType();
		g_GDDOSILog.WriteLogA(1, "list bucket failed:[%s]. EC:[%d].", listBucketOutcome.GetError().GetMessage().c_str(), ret);
	}

	return ret;
}

int AwsS3Store::InitMultiPartUpload(CloudStoreInitMultiPartUploadContext* CloudInitUpload, CloudStoreInitMultiPartUploadOutcome* CloudInitUploadOutcome)
{
	int ret = 0;

	Aws::S3::Model::CreateMultipartUploadRequest  InitMultiPartUploadReq;
	InitMultiPartUploadReq.WithBucket(CloudInitUpload->m_szBucket).WithKey(CloudInitUpload->m_OID);

	Aws::S3::Model::CreateMultipartUploadOutcome  InitMultiPartUploadOutcome = m_s3Client->CreateMultipartUpload(InitMultiPartUploadReq);
	if (!InitMultiPartUploadOutcome.IsSuccess())
	{
		ret = (int)InitMultiPartUploadOutcome.GetError().GetErrorType();
		g_GDDOSILog.WriteLogA(1, "Init multi-part upload for:[%s:%s:%s] failed.EC:[%d].", m_strRegion.c_str(), CloudInitUpload->m_szBucket, CloudInitUpload->m_OID, ret);
		g_GDDOSILog.WriteLogA(1, "Init Error Message:[%s].", InitMultiPartUploadOutcome.GetError().GetMessage().c_str());
	}
	else
	{
		CloudInitUploadOutcome->m_strUploadID = InitMultiPartUploadOutcome.GetResult().GetUploadId();
		m_MapUploadPartId2Status[CloudInitUploadOutcome->m_strUploadID] = new UploadPartStatus();
	}
	return ret;
}

int AwsS3Store::DoMultiPartUpload(CloudStoreMultiPartUploadContext * CloudMultiPartUpload)
{
	int ret = 0;

	Aws::S3::Model::UploadPartRequest uploadPartReq;
	uploadPartReq.WithBucket(CloudMultiPartUpload->m_szBucket).WithKey(CloudMultiPartUpload->m_OID).WithUploadId(CloudMultiPartUpload->m_szUploadID).WithPartNumber(CloudMultiPartUpload->m_nPartID);

	Aws::Utils::Array<unsigned char> databuf((unsigned char*)CloudMultiPartUpload->m_pBuf, CloudMultiPartUpload->m_nPartSize);
	Aws::Utils::Stream::PreallocatedStreamBuf streamData(&databuf, databuf.GetLength());
	auto preallocatedStreamReader = Aws::MakeShared<Aws::IOStream>("preallocatedStreamReader", &streamData);
	uploadPartReq.SetBody(preallocatedStreamReader);

	Aws::S3::Model::UploadPartOutcome UploadPartOutcome = m_s3Client->UploadPart(uploadPartReq);
	if (!UploadPartOutcome.IsSuccess())
	{
		ret = (int)UploadPartOutcome.GetError().GetErrorType();
		g_GDDOSILog.WriteLogA(1, "Part Upload:[%s:%s:%s:%d:%d] failed.", m_strRegion.c_str(), CloudMultiPartUpload->m_szBucket, CloudMultiPartUpload->m_OID,
			CloudMultiPartUpload->m_nPartID, CloudMultiPartUpload->m_nPartSize);
		g_GDDOSILog.WriteLogA(1, "Part Upload:[%s].", UploadPartOutcome.GetError().GetMessage().c_str());
	}
	else
	{
		m_MapUploadPartId2Status[CloudMultiPartUpload->m_szUploadID]->m_mapPartID2ETag.insert(std::make_pair(CloudMultiPartUpload->m_nPartID, UploadPartOutcome.GetResult().GetETag()));
	}

	return ret;
}

void AwsS3Store::HandleAsyncUploadPartFunc(const Aws::S3::S3Client*, const Aws::S3::Model::UploadPartRequest& request,
	const Aws::S3::Model::UploadPartOutcome& outcome, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context)
{
	//delete allocated buffer at this function
	UploadPartStatus* pCurStatus = NULL;
	{
		std::lock_guard<std::mutex> lock(m_mapSync);
		pCurStatus = (m_MapUploadPartId2Status.at(request.GetUploadId()));
	}


	std::unique_lock<std::mutex> lockstatus(pCurStatus->m_Sync);
	if (outcome.IsSuccess())
	{
		pCurStatus->m_mapPartID2ETag[request.GetPartNumber()] = outcome.GetResult().GetETag();
	}
	else
	{	
		int ret = (int)outcome.GetError().GetErrorType();
		pCurStatus->nError = ret;
		g_GDDOSILog.WriteLogA(1, "Part Upload:[%s:%s:%s:%d] failed.", m_strRegion.c_str(), request.GetBucket(), request.GetKey(),
			request.GetPartNumber());
		g_GDDOSILog.WriteLogA(1, "Part Upload:[%s].", outcome.GetError().GetMessage().c_str());
	}
	++pCurStatus->nActualUploadPart;
	if (pCurStatus->m_bAllPart && pCurStatus->nActualUploadPart == pCurStatus->nTotalUploadPart)
	{
		pCurStatus->m_cv.notify_one();
	}
	lockstatus.unlock();

}


int AwsS3Store::DoMultiPartUploadAsync(CloudStoreMultiPartUploadContext * CloudMultiPartUpload)
{
	int ret = 0;

	Aws::S3::Model::UploadPartRequest uploadPartReq;
	uploadPartReq.WithBucket(CloudMultiPartUpload->m_szBucket).WithKey(CloudMultiPartUpload->m_OID).WithUploadId(CloudMultiPartUpload->m_szUploadID).WithPartNumber(CloudMultiPartUpload->m_nPartID);

	UploadPartStatus* pCurStatus = NULL;
	{
		std::lock_guard<std::mutex> lock(m_mapSync);
		pCurStatus = (m_MapUploadPartId2Status.at(CloudMultiPartUpload->m_szUploadID));
		pCurStatus->nTotalUploadPart += 1;
		if (CloudMultiPartUpload->m_bLastPart)
		{
			pCurStatus->m_bAllPart = true;
		}
	}

	Aws::Utils::Array<unsigned char>* databuf = new Aws::Utils::Array<unsigned char>((unsigned char*)CloudMultiPartUpload->m_pBuf, CloudMultiPartUpload->m_nPartSize);
	Aws::Utils::Stream::PreallocatedStreamBuf *streamData = new Aws::Utils::Stream::PreallocatedStreamBuf(databuf, databuf->GetLength());
	pCurStatus->m_mapPartID2DataBuf[CloudMultiPartUpload->m_nPartID]	= databuf;
	pCurStatus->m_mapPartID2DataStream[CloudMultiPartUpload->m_nPartID] = streamData;

	auto preallocatedStreamReader = Aws::MakeShared<Aws::IOStream>("preallocatedStreamReader", streamData);
	uploadPartReq.SetBody(preallocatedStreamReader);

	auto uploadPartCallback = [this](const Aws::S3::S3Client* client, const Aws::S3::Model::UploadPartRequest& request,
		const Aws::S3::Model::UploadPartOutcome& outcome, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context)
	{
		this->HandleAsyncUploadPartFunc(client, request, outcome, context);
	};

	m_s3Client->UploadPartAsync(uploadPartReq, uploadPartCallback);

	return ret;
}

int AwsS3Store::CompleteMultiPartUpload(CloudStoreFinishMultiPartUploadContext* CloudCompleteMultiPartUpload)
{
	int ret = 0;

	Aws::S3::Model::CompleteMultipartUploadRequest compMultiPartUploadReq;
	Aws::S3::Model::CompletedMultipartUpload compMultipartUpload;
	Aws::Vector<Aws::S3::Model::CompletedPart>  vcparts(CloudCompleteMultiPartUpload->m_nPartNum, Aws::S3::Model::CompletedPart());

	UploadPartStatus* status = m_MapUploadPartId2Status[CloudCompleteMultiPartUpload->m_szUploadID];

	for (int i = 1; i <= CloudCompleteMultiPartUpload->m_nPartNum; ++i)
	{
		vcparts[i - 1].SetETag(status->m_mapPartID2ETag[i]);
		vcparts[i - 1].SetPartNumber(i);
	}
	compMultipartUpload.SetParts(vcparts);
	compMultiPartUploadReq.WithBucket(CloudCompleteMultiPartUpload->m_szBucket).WithKey(CloudCompleteMultiPartUpload->m_OID).WithUploadId(CloudCompleteMultiPartUpload->m_szUploadID).WithMultipartUpload(compMultipartUpload);
	Aws::S3::Model::CompleteMultipartUploadOutcome compMultiPartUploadOutcome = m_s3Client->CompleteMultipartUpload(compMultiPartUploadReq);

	if (!compMultiPartUploadOutcome.IsSuccess())
	{
		ret = (int)compMultiPartUploadOutcome.GetError().GetErrorType();
		g_GDDOSILog.WriteLogA(1, "Complete Multi-Part [%s:%s:%s:%s:%d] failed.", m_strRegion, CloudCompleteMultiPartUpload->m_szBucket,
			CloudCompleteMultiPartUpload->m_OID, CloudCompleteMultiPartUpload->m_szUploadID, CloudCompleteMultiPartUpload->m_nPartNum);
		g_GDDOSILog.WriteLogA(1, "Reason:[%s],EC:[%d].", compMultiPartUploadOutcome.GetError().GetMessage().c_str(), ret);
	}

	delete status;
	m_MapUploadPartId2Status.erase(CloudCompleteMultiPartUpload->m_szUploadID);
	return ret;
}

int AwsS3Store::CompleteMultiPartUploadAsync(CloudStoreFinishMultiPartUploadContext* CloudCompleteMultiPartUpload)
{
	int ret = 0;

	UploadPartStatus* pCurStatus = NULL;
	{
		std::lock_guard<std::mutex> lock(m_mapSync);
		pCurStatus = (m_MapUploadPartId2Status.at(CloudCompleteMultiPartUpload->m_szUploadID));
	}

	std::unique_lock<std::mutex> lockstatus(pCurStatus->m_Sync);
	pCurStatus->m_cv.wait(lockstatus);
	lockstatus.unlock();

	for (auto it : pCurStatus->m_mapPartID2DataStream)
	{
		Aws::Utils::Array<unsigned char>* p = (Aws::Utils::Array<unsigned char>*) it.second;
		it.second = nullptr;
		delete p;
	}
	for (auto it:pCurStatus->m_mapPartID2DataBuf)
	{
		Aws::Utils::Stream::PreallocatedStreamBuf* p = (Aws::Utils::Stream::PreallocatedStreamBuf*)it.second;
		it.second = nullptr;
		delete p;
	}

	if (0 == pCurStatus->nError)
	{
		Aws::S3::Model::CompleteMultipartUploadRequest	compMultiPartUploadReq;
		Aws::S3::Model::CompletedMultipartUpload		compMultipartUpload;
		Aws::Vector<Aws::S3::Model::CompletedPart>		vcparts(CloudCompleteMultiPartUpload->m_nPartNum, Aws::S3::Model::CompletedPart());


		for (int i = 1; i <= CloudCompleteMultiPartUpload->m_nPartNum; ++i)
		{
			vcparts[i - 1].SetETag(pCurStatus->m_mapPartID2ETag[i]);
			vcparts[i - 1].SetPartNumber(i);
		}
		compMultipartUpload.SetParts(vcparts);
		compMultiPartUploadReq.WithBucket(CloudCompleteMultiPartUpload->m_szBucket).WithKey(CloudCompleteMultiPartUpload->m_OID).WithUploadId(CloudCompleteMultiPartUpload->m_szUploadID).WithMultipartUpload(compMultipartUpload);
		Aws::S3::Model::CompleteMultipartUploadOutcome compMultiPartUploadOutcome = m_s3Client->CompleteMultipartUpload(compMultiPartUploadReq);

		if (!compMultiPartUploadOutcome.IsSuccess())
		{
			ret = (int)compMultiPartUploadOutcome.GetError().GetErrorType();
			g_GDDOSILog.WriteLogA(1, "Complete Multi-Part [%s:%s:%s:%s:%d] failed.", m_strRegion, CloudCompleteMultiPartUpload->m_szBucket,
				CloudCompleteMultiPartUpload->m_OID, CloudCompleteMultiPartUpload->m_szUploadID, CloudCompleteMultiPartUpload->m_nPartNum);
			g_GDDOSILog.WriteLogA(1, "Reason:[%s],EC:[%d].", compMultiPartUploadOutcome.GetError().GetMessage().c_str(), ret);
		}
	}
	else
	{
		ret = pCurStatus->nError;
	}

	{
		std::lock_guard<std::mutex> lock(m_mapSync);
		
		pCurStatus = (m_MapUploadPartId2Status.at(CloudCompleteMultiPartUpload->m_szUploadID));
		delete pCurStatus;
		m_MapUploadPartId2Status.erase(CloudCompleteMultiPartUpload->m_szUploadID);
	}

	return ret;
}

int AwsS3Store::AbortMultiPartUpload(CloudStoreAbortMultiPartUploadContext* abortMultiPart)
{
	int ret = 0;

	Aws::S3::Model::AbortMultipartUploadRequest abortMultiPartUploadReq;

	abortMultiPartUploadReq.WithBucket(abortMultiPart->m_szBucket).WithKey(abortMultiPart->m_OID).WithUploadId(abortMultiPart->m_szUploadID);

	Aws::S3::Model::AbortMultipartUploadOutcome   abortMultiPartUploadOut = m_s3Client->AbortMultipartUpload(abortMultiPartUploadReq);

	if (!abortMultiPartUploadOut.IsSuccess())
	{
		ret = (int)abortMultiPartUploadOut.GetError().GetErrorType();
		g_GDDOSILog.WriteLogA(1, "Abort Multi-Upload:[%s:%s:%s:%s] failed.", m_strRegion.c_str(), abortMultiPart->m_szBucket, abortMultiPart->m_OID,abortMultiPart->m_szUploadID);
		g_GDDOSILog.WriteLogA(1, "Abort message:[%s],", abortMultiPartUploadOut.GetError().GetMessage());
	}

	return ret;
}
