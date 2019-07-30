#include "CRocksDBBench.h"
#include<Windows.h>
#include<rpc.h>

CRocksDBBench::CRocksDBBench()
{
}

CRocksDBBench::~CRocksDBBench()
{
}

int CRocksDBBench::OpenRdb(const string& strdbPath)
{
	m_dbOptions.IncreaseParallelism();
	m_dbOptions.OptimizeLevelStyleCompaction();
	m_dbOptions.create_if_missing = true;
	
	Status s = rocksdb::DB::Open(m_dbOptions, strdbPath ,&m_pDB);
	assert(s.ok()); 
	return 0;
}

int CRocksDBBench::CloseRdb()
{
	if(nullptr != m_pDB)
	{
		delete m_pDB;
		m_pDB = nullptr;
	}
	
	return 0;
}

int CRocksDBBench::StartInsert(int nThread)
{
	int ret = 0;
	vector<std::thread*>  vInsertThread;
	
	for( int i = 0; i<nThread; ++i)
	{
		vInsertThread.push_back(new std::thread(&CRocksDBBench::InsertThreadImpl,this));
	}
	for(auto a:vInsertThread)
	{
		a->join();
	}
	return ret;
}

int CRocksDBBench::InsertThreadImpl()
{
	int ret = 0;
	Status s;
	while(1)
	{
		RPC_CSTR szKey = nullptr;
		UUID uuidkey;
		UuidCreate(&uuidkey);
		UuidToStringA(&uuidkey,&szKey);
		s = m_pDB->Put(WriteOptions(), (const char*)szKey,(const char*)szKey);
		RpcStringFreeA(&szKey);
		assert(s.ok());
	}

	return ret;
}
