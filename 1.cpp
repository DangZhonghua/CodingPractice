int CDataCloudRestore::ReadData2(char* pData, int * plSize, DWORD dwBufSize, DWORD *pdwBufSizeNeeded)
{

	m_TimerReadData2.StartTimer();
	++m_ullReadDataFileTimes;

	int lRet = OK;
	unsigned __int64 ullTotalDataToRead = 0;
	unsigned __int64 ullTotalDataRead = 0;
	DWORD dwDataBlockInfoCount = 0;
	DWORD dwRead = 0;
	DWORD i = 0;

	//********************************************************************
	//Check buffer space
	ullTotalDataToRead = *(unsigned __int64 *)pData;
	if (dwBufSize < ullTotalDataToRead)
	{
		*pdwBufSizeNeeded = (DWORD)ullTotalDataToRead;
		m_TimerReadData2.EndTimer();
		return NOT_ENOUGH_MEMORY;
	}

	//********************************************************************
	//Cache data block info
	dwDataBlockInfoCount = (*plSize - 8);
	dwDataBlockInfoCount /= sizeof(DATABLOCKINFOPKT);
	if (!m_pDataBlockInfo || m_dwDataBlockInfoLen < dwDataBlockInfoCount)
	{
		if (m_pDataBlockInfo)
		{
			delete[] m_pDataBlockInfo;
			m_pDataBlockInfo = NULL;
			m_dwDataBlockInfoLen = 0;
		}
		m_pDataBlockInfo = new DATABLOCKINFOPKT[dwDataBlockInfoCount];
		if (!m_pDataBlockInfo)
		{
			CServerStatus::GetInst().SetError(ERR_NO_MEMORY);
			WriteLogID(1, L"%s alloc memory fail.", __FUNCTIONW__);
			m_TimerReadData2.EndTimer();
			return NOT_ENOUGH_MEMORY;
		}
		m_dwDataBlockInfoLen = dwDataBlockInfoCount;
	}
	memcpy(m_pDataBlockInfo, pData + 8, (*plSize - 8));

	m_ullReadDataFileBlocks += dwDataBlockInfoCount;

	READ_LIST BlockInfoList;

	ullTotalDataRead = 0;

	DATABLOCKOPTI Block;

	for (i = 0; i<dwDataBlockInfoCount; i++)
	{
		UINT64 Ind = 0, temp;
		temp = m_pDataBlockInfo[i].ulFileNo;
		Ind |= temp << 48;

		temp = m_pDataBlockInfo[i].uiSliceID;
		Ind |= temp << 32;

		temp = m_pDataBlockInfo[i].uiSliceOffset;
		Ind |= temp;

		if (BlockInfoList.find(Ind) != BlockInfoList.end())
		{
			Ind += i % 1024;
		}

		Block.pDataBlockInfo = &m_pDataBlockInfo[i];

		Block.pBuffer = pData + ullTotalDataRead;

		ullTotalDataRead += m_pDataBlockInfo[i].lDataLen;

		BlockInfoList[Ind] = Block;
	}

	if (!m_pReadBuffer)
	{
		m_pReadBuffer = new (std::nothrow) char[2 * 1024 * 1024];
		if (m_pReadBuffer == NULL)
		{
			CServerStatus::GetInst().SetError(ERR_NO_MEMORY);
			WriteLogID(1, L"%s alloc memory fail.", __FUNCTIONW__);
			m_TimerReadData2.EndTimer();
			return NOT_ENOUGH_MEMORY;
		}

		m_nReadBufferSize = 2 * 1024 * 1024;
	}

	//WriteLogID(1, L"%s:: begin,dwDataBlockInfoCount[%d],size[%d],ThreadId[%d]",__FUNCTIONW__,dwDataBlockInfoCount,BlockInfoList.size(),GetCurrentThreadId()); 

	if (dwDataBlockInfoCount == BlockInfoList.size())
	{
		ullTotalDataRead = 0;

		READ_LIST_PTR FirstPtr, Ptr;

		FirstPtr = BlockInfoList.begin();
		Ptr = BlockInfoList.begin();

		while (FirstPtr != BlockInfoList.end())
		{
			ULONG DataLen = FirstPtr->second.pDataBlockInfo->lDataLen;
			ULONG FileNo = FirstPtr->second.pDataBlockInfo->ulFileNo;
			ULONG SliceID = FirstPtr->second.pDataBlockInfo->uiSliceID;
			ULONG SliceOffset = FirstPtr->second.pDataBlockInfo->uiSliceOffset;


			Ptr++;

			while (Ptr != BlockInfoList.end())
			{
				ULONG DataLen2 = Ptr->second.pDataBlockInfo->lDataLen;
				ULONG FileNo2 = Ptr->second.pDataBlockInfo->ulFileNo;
				ULONG SliceID2 = Ptr->second.pDataBlockInfo->uiSliceID;
				ULONG SliceOffset2 = Ptr->second.pDataBlockInfo->uiSliceOffset;

				if (FileNo == FileNo2 && SliceID == SliceID2 && SliceOffset + DataLen == SliceOffset2)
				{
					DataLen += DataLen2;
					Ptr++;
				}
				else
				{
					break;
				}
			}

			if ((dwBufSize - ullTotalDataRead) < DataLen)
			{
				WriteLogID(1, L"%s:: Wrong data block info. toRead=%d, Read=%d", __FUNCTIONW__, ullTotalDataToRead, ullTotalDataRead);
				m_TimerReadData2.EndTimer();
				return READ_DATA_FAILED;
			}

			if (m_nReadBufferSize < DataLen)
			{
				if (m_pReadBuffer)
				{
					delete[] m_pReadBuffer;
					m_pReadBuffer = NULL;
					m_nReadBufferSize = 0;
				}

				m_pReadBuffer = new (std::nothrow) char[DataLen * 2];
				if (m_pReadBuffer == NULL)
				{
					CServerStatus::GetInst().SetError(ERR_NO_MEMORY);
					WriteLogID(1, L"%s alloc memory fail.", __FUNCTIONW__);
					m_TimerReadData2.EndTimer();
					return NOT_ENOUGH_MEMORY;
				}

				m_nReadBufferSize = DataLen * 2;
			}

			//********************************************************************
			dwRead = 0;
			m_TimerReadData.StartTimer();

			lRet = m_DataFile.ReadData(
				FileNo,
				SliceID,
				SliceOffset,
				DataLen,
				m_pReadBuffer,
				m_nReadBufferSize,
				&dwRead);

			m_TimerReadData.EndTimer();

			ULONG Copied = 0;

			while (FirstPtr != Ptr && FirstPtr != BlockInfoList.end())
			{
				memcpy(FirstPtr->second.pBuffer, m_pReadBuffer + Copied, FirstPtr->second.pDataBlockInfo->lDataLen);
				Copied += FirstPtr->second.pDataBlockInfo->lDataLen;

				FirstPtr++;
			}


			if (lRet != OK)
			{
				WriteLogID(1, L"%s:: m_DataFile.ReadData() ret[%d]. "
					L"fileNumber=%d, "
					L"SliceId=%d, "
					L"SliceOffset=%d, "
					L"dataToRead=%d "
					L"dataRead=%d",
					__FUNCTIONW__,
					lRet,
					FileNo,
					SliceID,
					SliceOffset,
					DataLen,
					dwRead);

				break;
			}

			ullTotalDataRead += dwRead;

		}
	}
	else
	{
		//********************************************************************

		ullTotalDataRead = 0;
		for (i = 0; i<dwDataBlockInfoCount; i++)
		{
			if ((dwBufSize - ullTotalDataRead) < m_pDataBlockInfo[i].lDataLen)
			{
				WriteLogID(1, L"%s:: Wrong data block info!"
					L" dwBufSize = %d,  Read=%d, toRead=%d, difference=%d",
					__FUNCTIONW__, dwBufSize, ullTotalDataRead, ullTotalDataToRead,
					m_pDataBlockInfo[i].lDataLen - (dwBufSize - ullTotalDataRead));
				m_TimerReadData2.EndTimer();
				return NOT_ENOUGH_MEMORY;
			}

			//********************************************************************
			dwRead = 0;
			m_TimerReadData.StartTimer();
			lRet = m_DataFile.ReadData(m_pDataBlockInfo[i].ulFileNo,
				m_pDataBlockInfo[i].uiSliceID,
				m_pDataBlockInfo[i].uiSliceOffset,
				m_pDataBlockInfo[i].lDataLen,
				pData + ullTotalDataRead,
				dwBufSize - ullTotalDataRead,
				&dwRead);
			m_TimerReadData.EndTimer();
			if (lRet != OK)
			{
				WriteLogID(1, L"%s:: m_DataFile.ReadData() return %d. "
					L"fileNumber=%d, "
					L"SliceId=%d, "
					L"SliceOffset=%d, "
					L"dataToRead=%d "
					L"dataRead=%d",
					__FUNCTIONW__,
					lRet,
					m_pDataBlockInfo[i].ulFileNo,
					//m_pDataBlockInfo[i].llOffset,
					m_pDataBlockInfo[i].uiSliceID,
					m_pDataBlockInfo[i].uiSliceOffset,
					m_pDataBlockInfo[i].lDataLen,
					dwRead);

				break;
			}

			ullTotalDataRead += dwRead;

		}//for
	}

	BlockInfoList.clear();
	m_TimerReadData2.EndTimer();
	//********************************************************************
	if (ullTotalDataRead != ullTotalDataToRead && lRet != READ_DATA_REACH_EOF)
	{
		WriteLogID(1, L"%s:: data to read mismatch with data read. toRead=%d, Read=%d",
			__FUNCTIONW__, ullTotalDataToRead, ullTotalDataRead);
		return READ_DATA_FAILED;
	}

	//********************************************************************
	*plSize = (int)ullTotalDataRead;
	return OK;
}

int CDataCloudRestore::ReadData2WithMultiThread(char* pData, int * plSize, DWORD dwBufSize, DWORD *pdwBufSizeNeeded, INT32 nThreadCount)
{
	int lRet = OK;
	lRet = InitDataRoleMultiThreadReader(nThreadCount);

	if (OK != lRet)
	{
		return lRet;
	}

	m_TimerReadData2.StartTimer();
	++m_ullReadDataFileTimes;

	unsigned __int64 ullTotalDataToRead = 0;
	unsigned __int64 ullTotalDataRead = 0;
	DWORD dwDataBlockInfoCount = 0;
	DWORD dwRead = 0;
	DWORD i = 0;

	//********************************************************************
	//Check buffer space
	ullTotalDataToRead = *(unsigned __int64 *)pData;
	if (dwBufSize < ullTotalDataToRead)
	{
		*pdwBufSizeNeeded = (DWORD)ullTotalDataToRead;
		m_TimerReadData2.EndTimer();
		return NOT_ENOUGH_MEMORY;
	}

	//********************************************************************
	//Cache data block info
	dwDataBlockInfoCount = (*plSize - 8);
	dwDataBlockInfoCount /= sizeof(DATABLOCKINFOPKT);
	if (!m_pDataBlockInfo || m_dwDataBlockInfoLen < dwDataBlockInfoCount)
	{
		if (m_pDataBlockInfo)
		{
			delete[] m_pDataBlockInfo;
			m_pDataBlockInfo = NULL;
			m_dwDataBlockInfoLen = 0;
		}
		m_pDataBlockInfo = new DATABLOCKINFOPKT[dwDataBlockInfoCount];
		if (!m_pDataBlockInfo)
		{
			CServerStatus::GetInst().SetError(ERR_NO_MEMORY);
			WriteLogID(1, L"%s alloc memory fail.", __FUNCTIONW__);
			m_TimerReadData2.EndTimer();
			return NOT_ENOUGH_MEMORY;
		}
		m_dwDataBlockInfoLen = dwDataBlockInfoCount;
	}
	memcpy(m_pDataBlockInfo, pData + 8, (*plSize - 8));

	m_ullReadDataFileBlocks += dwDataBlockInfoCount;

	READ_LIST BlockInfoList;

	ullTotalDataRead = 0;

	DATABLOCKOPTI Block;

	for (i = 0; i<dwDataBlockInfoCount; i++)
	{
		UINT64 Ind = 0, temp;
		temp = m_pDataBlockInfo[i].ulFileNo;
		Ind |= temp << 48;

		temp = m_pDataBlockInfo[i].uiSliceID;
		Ind |= temp << 32;

		temp = m_pDataBlockInfo[i].uiSliceOffset;
		Ind |= temp;

		if (BlockInfoList.find(Ind) != BlockInfoList.end())
		{
			Ind += i % 1024;
		}

		Block.pDataBlockInfo = &m_pDataBlockInfo[i];

		Block.pBuffer = pData + ullTotalDataRead;

		ullTotalDataRead += m_pDataBlockInfo[i].lDataLen;

		BlockInfoList[Ind] = Block;
	}

	if (dwBufSize < ullTotalDataRead)
	{
		*pdwBufSizeNeeded = (DWORD)ullTotalDataRead;
		m_TimerReadData2.EndTimer();
		return NOT_ENOUGH_MEMORY;
	}


	if (m_nReadBufferSize < ullTotalDataRead)
	{
		if (NULL != m_pReadBuffer)
		{
			delete[] m_pReadBuffer;
			m_pReadBuffer = NULL;
		}

		m_pReadBuffer = new (std::nothrow) char[ullTotalDataRead];
		if (m_pReadBuffer == NULL)
		{
			CServerStatus::GetInst().SetError(ERR_NO_MEMORY);
			WriteLogID(1, L"%s alloc memory fail.", __FUNCTIONW__);
			m_TimerReadData2.EndTimer();
			return NOT_ENOUGH_MEMORY;
		}

		m_nReadBufferSize = ullTotalDataRead;
	}

	//WriteLogID(1, L"%s:: begin,dwDataBlockInfoCount[%d],size[%d],ThreadId[%d]",__FUNCTIONW__,dwDataBlockInfoCount,BlockInfoList.size(),GetCurrentThreadId()); 

	if (m_pMultiThreadDataReader->ReInit(BlockInfoList.size()) != OK)
	{
		WriteLogID(1, L"%s:%d, ERROR, ReInit multi thread reader fail, use original reading method.", __FUNCTIONW__, __LINE__);
		return ReadData2(pData, plSize, dwBufSize, pdwBufSizeNeeded);
	}

	if (m_pMultiThreadDataReader->GetThreadsState() == AllDead)
	{
		WriteLogID(1, L"%s:%d, ERROR, no worker thread running, use original reading method.", __FUNCTIONW__, __LINE__);
		return ReadData2(pData, plSize, dwBufSize, pdwBufSizeNeeded);
	}

	if (dwDataBlockInfoCount == BlockInfoList.size())
	{
		ullTotalDataRead = 0;

		READ_LIST_PTR FirstPtr;

		FirstPtr = BlockInfoList.begin();

		m_TimerReadData.StartTimer();

		while (FirstPtr != BlockInfoList.end())
		{
			ULONG DataLen = FirstPtr->second.pDataBlockInfo->lDataLen;
			ULONG FileNo = FirstPtr->second.pDataBlockInfo->ulFileNo;
			ULONG SliceID = FirstPtr->second.pDataBlockInfo->uiSliceID;
			ULONG SliceOffset = FirstPtr->second.pDataBlockInfo->uiSliceOffset;


			FirstPtr++;

			while (FirstPtr != BlockInfoList.end())
			{
				ULONG DataLen2 = FirstPtr->second.pDataBlockInfo->lDataLen;
				ULONG FileNo2 = FirstPtr->second.pDataBlockInfo->ulFileNo;
				ULONG SliceID2 = FirstPtr->second.pDataBlockInfo->uiSliceID;
				ULONG SliceOffset2 = FirstPtr->second.pDataBlockInfo->uiSliceOffset;

				if (FileNo == FileNo2 && SliceID == SliceID2 && SliceOffset + DataLen == SliceOffset2)
				{
					DataLen += DataLen2;
					FirstPtr++;
				}
				else
				{
					break;
				}
			}

			//********************************************************************
			dwRead = 0;
			//Read the continuous ref entries
			{
				ReadDataIOInfo *pRequestInfo = m_pMultiThreadDataReader->GetReadDataIOInfo();
				pRequestInfo->request.DataRequest.ulFileNo = FileNo;
				pRequestInfo->request.DataRequest.ulSliceID = SliceID;
				pRequestInfo->request.DataRequest.ulSliceOffset = SliceOffset;
				pRequestInfo->request.DataRequest.ulDataToRead = DataLen;
				pRequestInfo->request.DataRequest.pDataBuf = m_pReadBuffer + ullTotalDataRead;
				pRequestInfo->request.DataRequest.ulDataRead = dwRead;

				LARGE_INTEGER llSliceNumber;
				llSliceNumber.HighPart = FileNo;
				llSliceNumber.LowPart = 0;

				m_pMultiThreadDataReader->AddRequest(pRequestInfo, llSliceNumber.QuadPart);

			}

			ullTotalDataRead += DataLen;

		}
		m_pMultiThreadDataReader->SetFinishedPuttingRequest();
		m_pMultiThreadDataReader->WaitForRequestFinished();

		m_TimerReadData.EndTimer();

		if (m_pMultiThreadDataReader->HasError())
		{
			DWORD dwErr = READ_DATA_FAILED;
			WriteLogID(1, L"%s:%d, ERROR, read data failed, EC=[%d].", __FUNCTIONW__, __LINE__, dwErr);
			return READ_DATA_FAILED;
		}

		ULONG Copied = 0;
		FirstPtr = BlockInfoList.begin();
		while (FirstPtr != BlockInfoList.end())
		{
			memcpy(FirstPtr->second.pBuffer, m_pReadBuffer + Copied, FirstPtr->second.pDataBlockInfo->lDataLen);
			Copied += FirstPtr->second.pDataBlockInfo->lDataLen;

			FirstPtr++;
		}

	}
	else
	{
		//********************************************************************

		ullTotalDataRead = 0;
		for (i = 0; i<dwDataBlockInfoCount; i++)
		{
			if ((dwBufSize - ullTotalDataRead) < m_pDataBlockInfo[i].lDataLen)
			{
				WriteLogID(1, L"%s:: Wrong data block info!"
					L" dwBufSize = %d,  Read=%d, toRead=%d, difference=%d",
					__FUNCTIONW__, dwBufSize, ullTotalDataRead, ullTotalDataToRead,
					m_pDataBlockInfo[i].lDataLen - (dwBufSize - ullTotalDataRead));
				m_TimerReadData2.EndTimer();
				return NOT_ENOUGH_MEMORY;
			}

			//********************************************************************
			dwRead = 0;
			m_TimerReadData.StartTimer();
			lRet = m_DataFile.ReadData(m_pDataBlockInfo[i].ulFileNo,
				m_pDataBlockInfo[i].uiSliceID,
				m_pDataBlockInfo[i].uiSliceOffset,
				m_pDataBlockInfo[i].lDataLen,
				pData + ullTotalDataRead,
				dwBufSize - ullTotalDataRead,
				&dwRead);
			m_TimerReadData.EndTimer();
			if (lRet != OK)
			{
				WriteLogID(1, L"%s:: m_DataFile.ReadData() return %d. "
					L"fileNumber=%d, "
					L"SliceId=%d, "
					L"SliceOffset=%d, "
					L"dataToRead=%d "
					L"dataRead=%d",
					__FUNCTIONW__,
					lRet,
					m_pDataBlockInfo[i].ulFileNo,
					//m_pDataBlockInfo[i].llOffset,
					m_pDataBlockInfo[i].uiSliceID,
					m_pDataBlockInfo[i].uiSliceOffset,
					m_pDataBlockInfo[i].lDataLen,
					dwRead);

				break;
			}

			ullTotalDataRead += dwRead;

		}//for
	}

	BlockInfoList.clear();
	m_TimerReadData2.EndTimer();
	//********************************************************************
	if (ullTotalDataRead != ullTotalDataToRead && lRet != READ_DATA_REACH_EOF)
	{
		WriteLogID(1, L"%s:: data to read mismatch with data read. toRead=%d, Read=%d",
			__FUNCTIONW__, ullTotalDataToRead, ullTotalDataRead);
		return READ_DATA_FAILED;
	}

	//********************************************************************
	*plSize = (int)ullTotalDataRead;
	return OK;
}
#if GDD_ANSYNC_READ
//********************************************************************
int CDataCloudRestore::ReadData2WithSeqNo(char* pData, int * plSize, DWORD dwBufSize, DWORD *pdwBufSizeNeeded)
{
	int lRet = OK;
	DWORD dwBlockCount = 0;
	unsigned __int64 ullTotalDataToRead = 0, ullTotalDataRead = 0;
	DWORD dwToRead = 0, dwRead = 0;
	DWORD i = 0;

	//********************************************************************
	//Check buffer space
	ullTotalDataToRead = *(unsigned __int64 *)pData;
	if (dwBufSize < ullTotalDataToRead)
	{
		*pdwBufSizeNeeded = (DWORD)ullTotalDataToRead;
		return NOT_ENOUGH_MEMORY;
	}

	m_TimerReadData2.StartTimer();

	lRet = InitReadBuffer(ullTotalDataToRead);

	if (OK != lRet)
	{
		m_TimerReadData2.EndTimer();
		return lRet;
	}

	lRet = InitBlockInfo3List(pData, plSize, dwBlockCount);
	if (OK != lRet)
	{
		m_TimerReadData2.EndTimer();
		return lRet;
	}

	m_ullReadDataFileTotalBlocks += dwBlockCount;
	//********************************************************************
	//Sort by data block info
	BLOCKINFO4_UINT32VECTOR_MAP sortMap;
	GDDBLOCKINFO_4 blockInfo;
	for (i = 0; i<dwBlockCount; i++)
	{
		blockInfo.ui32DataFileNumber = m_pBlockInfo3List[i].ui32DataFileNumber;
		blockInfo.ui32DataSliceID = m_pBlockInfo3List[i].ui32DataSliceID;
		blockInfo.ui32DataSliceOffset = m_pBlockInfo3List[i].ui32DataSliceOffset;
		blockInfo.ui32DataLen = GET_DATA_LEN(m_pBlockInfo3List[i]);
		sortMap[blockInfo].push_back(m_pBlockInfo3List[i].ui32BlockOffsetInBuffer);
	}

	//********************************************************************
	//Read data
	static int requestCount = 0;
	requestCount++;

	BLOCKINFO4_UINT32VECTOR_MAP_ITER mIterStart, mIterEnd, mIter;
	DWORD dwIters = 0;
	char * pBufPtr = NULL;
	ullTotalDataRead = 0;
	for (mIter = sortMap.begin(); mIter != sortMap.end(); mIter++)
	{
		//********************************************************************
		//Find out the continous data blocks
		if (mIter == sortMap.begin())
		{
			mIterStart = mIter; mIterEnd = mIter; dwIters = 1;
			dwToRead = mIter->first.ui32DataLen;
			continue;
		}
		if (mIterEnd->first.ui32DataFileNumber == mIter->first.ui32DataFileNumber &&
			mIterEnd->first.ui32DataSliceID == mIter->first.ui32DataSliceID &&
			(mIterEnd->first.ui32DataSliceOffset + mIterEnd->first.ui32DataLen) == mIter->first.ui32DataSliceOffset)
		{
			mIterEnd = mIter; dwIters++;
			dwToRead += mIter->first.ui32DataLen;
			continue;
		}

		//********************************************************************
		//Read the continous data blocks
		dwRead = 0;
		m_TimerReadData.StartTimer();
		lRet = m_DataFile.ReadData(mIterStart->first.ui32DataFileNumber,
			mIterStart->first.ui32DataSliceID,
			mIterStart->first.ui32DataSliceOffset,
			dwToRead, m_pReadBuffer, m_nReadBufferSize, &dwRead);
		m_TimerReadData.EndTimer();
		if (lRet != OK || dwRead != dwToRead)
		{
			WriteLogID(1, L"%s::1 m_DataFile.ReadData() return %d. "
				L"FileNumber=%d, "
				L"SliceId=%d, "
				L"SliceOffset=%d, "
				L"dataToRead=%d "
				L"dataRead=%d",
				__FUNCTIONW__, lRet,
				mIterStart->first.ui32DataFileNumber,
				mIterStart->first.ui32DataSliceID,
				mIterStart->first.ui32DataSliceOffset,
				dwToRead, dwRead);
			if (lRet == OK) lRet = READ_DATA_FAILED;
			m_TimerReadData2.EndTimer();
			return lRet;
		}
		m_ullReadDataFileTimes++; m_ullReadDataFileBlocks += dwIters;

		//********************************************************************
		//Copy the continous data blocks to Buffer
		mIter = mIterStart; pBufPtr = m_pReadBuffer;
		for (i = 0; i<dwIters; i++, mIter++)
		{
			for (UINT32_VECTOR_ITER vIter = mIter->second.begin(); vIter != mIter->second.end(); vIter++)
			{
				memcpy_s(pData + (*vIter), dwBufSize - (*vIter), pBufPtr, mIter->first.ui32DataLen);
				ullTotalDataRead += mIter->first.ui32DataLen;
			}
			pBufPtr += mIter->first.ui32DataLen;
		}

		//********************************************************************
		mIterStart = mIter; mIterEnd = mIter; dwIters = 1;
		dwToRead = mIter->first.ui32DataLen;
	}//for

	//********************************************************************
	//Read the last continous data blocks
	dwRead = 0;
	m_TimerReadData.StartTimer();
	lRet = m_DataFile.ReadData(mIterStart->first.ui32DataFileNumber,
		mIterStart->first.ui32DataSliceID,
		mIterStart->first.ui32DataSliceOffset,
		dwToRead, m_pReadBuffer, m_nReadBufferSize, &dwRead);
	m_TimerReadData.EndTimer();
	if (lRet != OK || dwRead != dwToRead)
	{
		WriteLogID(1, L"%s::2 m_DataFile.ReadData() return %d. "
			L"FileNumber=%d, "
			L"SliceId=%d, "
			L"SliceOffset=%d, "
			L"dataToRead=%d "
			L"dataRead=%d",
			__FUNCTIONW__, lRet,
			mIterStart->first.ui32DataFileNumber,
			mIterStart->first.ui32DataSliceID,
			mIterStart->first.ui32DataSliceOffset,
			dwToRead, dwRead);
		if (lRet == OK) lRet = READ_DATA_FAILED;
		m_TimerReadData2.EndTimer();
		return lRet;
	}
	m_ullReadDataFileTimes++; m_ullReadDataFileBlocks += dwIters;

	//********************************************************************
	//Copy the last continous data blocks to Buffer
	mIter = mIterStart; pBufPtr = m_pReadBuffer;
	for (i = 0; i<dwIters; i++, mIter++)
	{
		for (UINT32_VECTOR_ITER vIter = mIter->second.begin(); vIter != mIter->second.end(); vIter++)
		{
			memcpy_s(pData + (*vIter), dwBufSize - (*vIter), pBufPtr, mIter->first.ui32DataLen);
			ullTotalDataRead += mIter->first.ui32DataLen;
		}
		pBufPtr += mIter->first.ui32DataLen;
	}

	m_ullReadDataFileSize += ullTotalDataRead;

	//********************************************************************
	//Double-check the data length
	if (ullTotalDataRead != ullTotalDataToRead)
	{
		WriteLogID(1, L"%s:: data to read mismatch with data read. toRead=%d, Read=%d",
			__FUNCTIONW__, ullTotalDataToRead, ullTotalDataRead);
		return READ_DATA_FAILED;
	}

	//********************************************************************
	*plSize = (int)ullTotalDataRead;
	m_TimerReadData2.EndTimer();
	return OK;
}

int CDataCloudRestore::ReadData2WithSeqNoMultiThread(char* pData, int * plSize, DWORD dwBufSize, DWORD *pdwBufSizeNeeded, INT32 nThreadCount)
{

	int lRet = OK;

	if (!pData || !plSize || !pdwBufSizeNeeded)
	{
		WriteLogID(1, L"%s:%d, ERROR, Invalid parameters.", __FUNCTIONW__, __LINE__);
		return INVALID_PARAMETER;
	}

	m_TimerReadData2.StartTimer();
	lRet = InitDataRoleMultiThreadReader(nThreadCount);

	if (OK != lRet)
	{
		WriteLogID(1, L"%s:%d, ERROR, Creating MultiThreadDataReader failed EC=[%d].", __FUNCTIONW__, __LINE__, lRet);
		m_TimerReadData2.EndTimer();
		return ReadData2WithSeqNo(pData, plSize, dwBufSize, pdwBufSizeNeeded);
	}

	DWORD dwBlockCount = 0;
	unsigned __int64 ullTotalDataToRead = 0, ullTotalDataRead = 0;

	//********************************************************************
	//Check buffer space
	ullTotalDataToRead = *(unsigned __int64 *)pData;
	if (dwBufSize < ullTotalDataToRead)
	{
		*pdwBufSizeNeeded = (DWORD)ullTotalDataToRead;
		m_TimerReadData2.EndTimer();
		return NOT_ENOUGH_MEMORY;
	}

	lRet = InitReadBuffer(ullTotalDataToRead);
	if (OK != lRet)
	{
		m_TimerReadData2.EndTimer();
		return lRet;
	}

	lRet = InitBlockInfo3List(pData, plSize, dwBlockCount);
	if (OK != lRet)
	{
		m_TimerReadData2.EndTimer();
		return lRet;
	}

	m_ullReadDataFileTotalBlocks += dwBlockCount;

	//********************************************************************
	//Sort by data block info
	BLOCKINFO4_UINT32VECTOR_MAP sortMap;
	GDDBLOCKINFO_4 blockInfo;
	DWORD i = 0;
	for (i = 0; i<dwBlockCount; i++)
	{
		blockInfo.ui32DataFileNumber = m_pBlockInfo3List[i].ui32DataFileNumber;
		blockInfo.ui32DataSliceID = m_pBlockInfo3List[i].ui32DataSliceID;
		blockInfo.ui32DataSliceOffset = m_pBlockInfo3List[i].ui32DataSliceOffset;
		blockInfo.ui32DataLen = GET_DATA_LEN(m_pBlockInfo3List[i]);
		sortMap[blockInfo].push_back(m_pBlockInfo3List[i].ui32BlockOffsetInBuffer);
	}

	if (m_pMultiThreadDataReader->ReInit(dwBlockCount) != OK)
	{
		WriteLogID(1, L"%s:%d, ERROR, ReInit multi thread reader fail, use original reading method.", __FUNCTIONW__, __LINE__);
		return ReadData2WithSeqNo(pData, plSize, dwBufSize, pdwBufSizeNeeded);
	}

	if (m_pMultiThreadDataReader->GetThreadsState() == AllDead)
	{
		WriteLogID(1, L"%s:%d, ERROR, no worker thread running, use original reading method.", __FUNCTIONW__, __LINE__);
		return ReadData2WithSeqNo(pData, plSize, dwBufSize, pdwBufSizeNeeded);
	}

	//********************************************************************
	//Read data
	static int requestCount = 0;
	requestCount++;

	BLOCKINFO4_UINT32VECTOR_MAP_ITER mIterStart, mIterEnd, mIter;
	DWORD dwIters = 0;
	char * pBufPtr = NULL;
	DWORD dwToRead = 0, dwRead = 0;
	unsigned __int64 ullDataOffsetInResponseBuffer = 0;
	m_TimerReadData.StartTimer();

	for (mIter = sortMap.begin(); mIter != sortMap.end(); mIter++)
	{
		//********************************************************************
		//Find out the continous data blocks
		if (mIter == sortMap.begin())
		{
			mIterStart = mIter; mIterEnd = mIter; dwIters = 1;
			dwToRead = mIter->first.ui32DataLen;
			continue;
		}
		if (mIterEnd->first.ui32DataFileNumber == mIter->first.ui32DataFileNumber &&
			mIterEnd->first.ui32DataSliceID == mIter->first.ui32DataSliceID &&
			(mIterEnd->first.ui32DataSliceOffset + mIterEnd->first.ui32DataLen) == mIter->first.ui32DataSliceOffset)
		{
			mIterEnd = mIter; dwIters++;
			dwToRead += mIter->first.ui32DataLen;
			continue;
		}

		{
			ReadDataIOInfo *pRequestInfo = m_pMultiThreadDataReader->GetReadDataIOInfo();
			pRequestInfo->request.DataRequest.ulFileNo = mIterStart->first.ui32DataFileNumber;
			pRequestInfo->request.DataRequest.ulSliceID = mIterStart->first.ui32DataSliceID;
			pRequestInfo->request.DataRequest.ulSliceOffset = mIterStart->first.ui32DataSliceOffset;
			pRequestInfo->request.DataRequest.ulDataToRead = dwToRead;
			pRequestInfo->request.DataRequest.pDataBuf = m_pReadBuffer + ullDataOffsetInResponseBuffer;
			pRequestInfo->request.DataRequest.ulDataRead = dwRead;

			LARGE_INTEGER llSliceNumber;
			llSliceNumber.HighPart = mIterStart->first.ui32DataFileNumber;
			llSliceNumber.LowPart = mIterStart->first.ui32DataSliceID;

			m_pMultiThreadDataReader->AddRequest(pRequestInfo, llSliceNumber.QuadPart);

			//WriteLogID(1, L"jerry, ===, multi sync data, %d, %d, %d, %d, %d.", requestCount, mIterStart->first.ui32DataFileNumber,
			//	mIterStart->first.ui32DataSliceID, mIterStart->first.ui32DataSliceOffset, dwToRead);
			m_ullReadDataFileTimes++;
			m_ullReadDataFileBlocks += dwIters;
		}

		ullDataOffsetInResponseBuffer += dwToRead;

		mIterStart = mIter; mIterEnd = mIter; dwIters = 1;
		dwToRead = mIter->first.ui32DataLen;
	}

	{
		ReadDataIOInfo *pRequestInfo = m_pMultiThreadDataReader->GetReadDataIOInfo();
		pRequestInfo->request.DataRequest.ulFileNo = mIterStart->first.ui32DataFileNumber;
		pRequestInfo->request.DataRequest.ulSliceID = mIterStart->first.ui32DataSliceID;
		pRequestInfo->request.DataRequest.ulSliceOffset = mIterStart->first.ui32DataSliceOffset;
		pRequestInfo->request.DataRequest.ulDataToRead = dwToRead;
		pRequestInfo->request.DataRequest.pDataBuf = m_pReadBuffer + ullDataOffsetInResponseBuffer;
		pRequestInfo->request.DataRequest.ulDataRead = dwRead;

		LARGE_INTEGER llSliceNumber;
		llSliceNumber.HighPart = mIterStart->first.ui32DataFileNumber;
		llSliceNumber.LowPart = mIterStart->first.ui32DataSliceID;

		m_pMultiThreadDataReader->AddRequest(pRequestInfo, llSliceNumber.QuadPart);

		//WriteLogID(1, L"jerry, ===, multi sync data, %d, %d, %d, %d, %d.", requestCount, mIterStart->first.ui32DataFileNumber,
		//	mIterStart->first.ui32DataSliceID, mIterStart->first.ui32DataSliceOffset, dwToRead);

		ullDataOffsetInResponseBuffer += dwToRead;
	}
	m_ullReadDataFileTimes++;
	m_ullReadDataFileBlocks += dwIters;

	m_pMultiThreadDataReader->SetFinishedPuttingRequest();
	m_pMultiThreadDataReader->WaitForRequestFinished();

	m_TimerReadData.EndTimer();

	if (m_pMultiThreadDataReader->HasError())
	{
		DWORD dwErr = READ_DATA_FAILED;
		WriteLogID(1, L"%s:%d, ERROR, read data failed, EC=[%d].", __FUNCTIONW__, __LINE__, dwErr);
		m_TimerReadData2.EndTimer();
		return READ_DATA_FAILED;
	}

	//********************************************************************
	//Copy the last continous data blocks to Buffer
	mIter = mIterStart; pBufPtr = m_pReadBuffer;
	ullDataOffsetInResponseBuffer = 0;
	ullTotalDataRead = 0;
	for (mIter = sortMap.begin(); mIter != sortMap.end(); mIter++)
	{
		for (UINT32_VECTOR_ITER vIter = mIter->second.begin(); vIter != mIter->second.end(); vIter++)
		{
			memcpy_s(pData + (*vIter), dwBufSize - (*vIter), pBufPtr, mIter->first.ui32DataLen);
			ullTotalDataRead += mIter->first.ui32DataLen;
		}
		pBufPtr += mIter->first.ui32DataLen;
	}


	m_ullReadDataFileSize += ullTotalDataRead;

	//********************************************************************
	//Double-check the data length
	if (ullTotalDataRead != ullTotalDataToRead)
	{
		WriteLogID(1, L"%s:: data to read mismatch with data read. toRead=%d, Read=%d",
			__FUNCTIONW__, ullTotalDataToRead, ullTotalDataRead);
		return READ_DATA_FAILED;
	}

	//********************************************************************
	*plSize = (int)ullTotalDataRead;
	m_TimerReadData2.EndTimer();
	return OK;
}

#endif //GDD_ANSYNC_READ

#ifdef GDD_REPLICATION_OPTIMIZATION
//********************************************************************
//Handler of the command STORAGE_USE_ASYNCREAD
int CDataCloudRestore::UseAsyncRead(DWORD dwBlockSize)
{
	int ret = 0;

	m_dwBlockSizeForDataSvr = dwBlockSize;

	if (!m_ReadRequestPool.Init(READ_DATA_QUEUE_SIZE - 1, sizeof(READ_REQUEST_ITEM)))
	{
		WriteLogID(1, L"%s:: m_ReadRequestPool.Init failed.", __FUNCTIONW__);
		return NOT_ENOUGH_MEMORY;
	}

	m_ReadRequestQueue.Init(READ_DATA_QUEUE_SIZE - 1);

	if (!m_ReadDataPool.Init(READ_DATA_QUEUE_SIZE + 1, sizeof(READ_DATA_ITEM)))
	{
		WriteLogID(1, L"%s:: m_ReadDataPool.Init failed.", __FUNCTIONW__);
		return NOT_ENOUGH_MEMORY;
	}

	m_hAsyncReadEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	if (m_hAsyncReadEvent == NULL)
	{
		WriteLogID(1, L"%s:: Failed to create asyncread event. EC=%d",
			__FUNCTIONW__, GetLastError());
		return -1;
	}

	//********************************************************************
	DWORD dwThreadId = 0;
	m_hAsyncReadThread = CreateThread(0, 0, AsyncReadThreadFunc, this, 0, &dwThreadId);
	if (m_hAsyncReadThread == NULL)
	{
		WriteLogID(1, L"%s:: Create asyncread thread failed. EC=%d",
			__FUNCTIONW__, GetLastError());
		return -1;
	}
	WriteLogID(1, L"[RESTORE]:%s restore worker threadID:[%d].", __FUNCTIONW__, dwThreadId);

	return OK;
}

//********************************************************************
int CDataCloudRestore::AsyncReadData(char* pData, int * plSize, DWORD dwBufSize, DWORD *pdwBufSizeNeeded)
{
	int lRet = OK;
	DWORD dwResponseBufSz = sizeof(DataReadResponseBuf);
	DWORD dwBlockInfoSz = sizeof(DATABLOCKINFOPKT);
	IOControlInfo *pControlInfo = (IOControlInfo *)pData;
	DWORD dwControlInfoSz = sizeof(IOControlInfo);
	P_READ_REQUEST_ITEM pRequest = NULL;

	//********************************************************************
	//Check buffer space
	if (dwBufSize < dwResponseBufSz)
	{
		*pdwBufSizeNeeded = dwResponseBufSz;
		return NOT_ENOUGH_MEMORY;
	}

	//********************************************************************
	//Get read result before pushing read request into request queue
	DataReadResponseBuf ResponseBuf;
	memset(&ResponseBuf, 0, dwResponseBufSz);
	ResponseBuf.lRequestId = pControlInfo->RepInfo.lRequestId;
	lRet = GetReadResult(ResponseBuf.rdResult);
	if (lRet != OK)
	{
		ResponseBuf.dwResult = lRet;
		return lRet;
	}

	//********************************************************************
	pRequest = (P_READ_REQUEST_ITEM)m_ReadRequestPool.Allocate();
	pRequest->dwType = READQUEUE_TYPE_READDATA;
	pRequest->lRequestId = pControlInfo->RepInfo.lRequestId;
	pRequest->lDataLen = pControlInfo->RepInfo.ulTotalDataLen;
	memcpy_s((void *)(pRequest->arrBlockInfo), dwBlockInfoSz*MAX_ENTRIES,
		(void *)(pData + dwControlInfoSz), (*plSize - dwControlInfoSz));
	pRequest->lBlockCount = ((*plSize - dwControlInfoSz) / dwBlockInfoSz);
	m_ReadRequestQueue << pRequest;

	//********************************************************************
	*plSize = 12 + ResponseBuf.rdResult.dwCount * sizeof(SingleDataResult);
	memcpy_s(pData, *plSize, &ResponseBuf, *plSize);
	return OK;
}

//********************************************************************
int CDataCloudRestore::GetReadResult(ReadDataResult &Result)
{
	int ret = OK;

	//********************************************************************
	//Clear read data queue2
	int n = m_ReadDataQueue2.size();
	for (int i = 0; i<n; i++)
	{
		P_READ_DATA_ITEM pReadDataItem = m_ReadDataQueue2.front();
		m_ReadDataQueue2.pop();
		m_ReadDataPool.Free(pReadDataItem);
	}

	//********************************************************************
	//Handle read result
	readresult_lock();
	DWORD dwCount = m_readResult.dwCount;
	for (DWORD i = 0; i<dwCount; i++)
	{
		if (m_readResult.arResult[i].dwResult != OK)
		{
			ret = m_readResult.arResult[i].dwResult;
			break;
		}
	}
	memcpy(&Result, &m_readResult, sizeof(ReadDataResult));
	memset(&m_readResult, 0, sizeof(ReadDataResult));
	//Handle read data
	n = m_ReadDataQueue1.size();
	for (int i = 0; i<n; i++)
	{
		P_READ_DATA_ITEM pReadDataItem = m_ReadDataQueue1.front();
		m_ReadDataQueue1.pop();
		m_ReadDataQueue2.push(pReadDataItem);
	}
	readresult_unlock();

	return ret;
}

//********************************************************************
//Don't need lock to protect read data queue2 because only one thread will access it.
int CDataCloudRestore::AsyncReadResult(char* pData, int * plSize, DWORD dwBufSize, DWORD *pdwBufSizeNeeded)
{
	int lRet = OK;
	int lRequestId = 0;

	memcpy(&lRequestId, pData, sizeof(int));

	//********************************************************************
	//Check buf space
	if (dwBufSize < QBUF_DATA_LEN)
	{
		*pdwBufSizeNeeded = QBUF_DATA_LEN;
		return NOT_ENOUGH_MEMORY;
	}

	//********************************************************************
	//Check read data queue2
	if (m_ReadDataQueue2.size() == 0)
	{
		WriteLogID(1, L"%s:: Read data queue2 is empty. RequestId=%d",
			__FUNCTIONW__, lRequestId);
		return OPERATION_NOT_ALLOWED;
	}

	//********************************************************************
	//Check requestid
	P_READ_DATA_ITEM pReadDataItem = m_ReadDataQueue2.front();
	m_ReadDataQueue2.pop();
	if (pReadDataItem->lRequestId != lRequestId)
	{
		WriteLogID(1, L"%s:: Mismatched requestid[%d:%d]",
			__FUNCTIONW__, lRequestId, pReadDataItem->lRequestId);
		m_ReadDataPool.Free(pReadDataItem);
		return OPERATION_NOT_ALLOWED;
	}

	//********************************************************************
	*plSize = pReadDataItem->lBlockCount*m_dwBlockSizeForDataSvr;
	memcpy_s(pData, dwBufSize, pReadDataItem->DataBuf, *plSize);
	m_ReadDataPool.Free(pReadDataItem);
	return OK;
}

//********************************************************************
int CDataCloudRestore::AsyncReadFlush(char* pData, int * plSize, DWORD dwBufSize, DWORD *pdwBufSizeNeeded)
{
	int lRet = OK;
	DWORD dwResponseBufSz = sizeof(DataReadResponseBuf);

	//********************************************************************
	//Check buffer space
	if (dwBufSize < dwResponseBufSz)
	{
		*pdwBufSizeNeeded = dwResponseBufSz;
		return NOT_ENOUGH_MEMORY;
	}

	//********************************************************************
	//Notify read thread to read data
	P_READ_REQUEST_ITEM pRequest = (P_READ_REQUEST_ITEM)m_ReadRequestPool.Allocate();
	pRequest->dwType = READQUEUE_TYPE_FLUSH;
	m_ReadRequestQueue << pRequest;

	//********************************************************************
	//Wait read thread to read data
	DWORD dwWaitResult = WaitForSingleObject(m_hAsyncReadEvent, INFINITE);
	if (dwWaitResult != WAIT_OBJECT_0)
	{
		WriteLogID(1, L"%s:: WaitForSingleObject failed [%d]. EC=%d",
			__FUNCTIONW__, dwWaitResult, GetLastError());
		return SYS_INVOKE_ERROR;
	}

	//********************************************************************
	//Get read result
	DataReadResponseBuf ResponseBuf;
	memset(&ResponseBuf, 0, dwResponseBufSz);
	lRet = GetReadResult(ResponseBuf.rdResult);
	if (lRet != OK)
	{
		ResponseBuf.dwResult = lRet;
		return lRet;
	}

	//********************************************************************
	*plSize = 12 + ResponseBuf.rdResult.dwCount * sizeof(SingleDataResult);
	memcpy_s(pData, *plSize, &ResponseBuf, *plSize);
	return OK;
}

//********************************************************************
DWORD CDataCloudRestore::AsyncReadThreadImpl(void)
{
	int lRet = OK;

	BOOL bMultiThread = FALSE;
	if (g_serverConfigInfo.m_dwThreadNumberForDataRequest > 1)
	{
		lRet = InitDataRoleMultiThreadReader(g_serverConfigInfo.m_dwThreadNumberForDataRequest);
		if (OK != lRet)
		{
			WriteLogID(1, L"%s:%d, ERROR, Creating MultiThreadDataReader failed EC=[%d].", __FUNCTIONW__, __LINE__, lRet);
		}
		else
		{
			bMultiThread = TRUE;
		}
	}

	while (true)
	{
		//********************************************************************
		void* p = NULL;
		m_ReadRequestQueue >> p;
		P_READ_REQUEST_ITEM pRequest = (P_READ_REQUEST_ITEM)p;

		//********************************************************************
		if (pRequest->dwType == READQUEUE_TYPE_READDATA)
		{
			P_READ_DATA_ITEM pData = (P_READ_DATA_ITEM)m_ReadDataPool.Allocate();

			bool bAcquiredLock = false;

			if (AcquireDiskLock())
			{
				bAcquiredLock = true;
			}
			if (FALSE == bMultiThread)
			{
				lRet = _ReadData(pRequest, pData);
			}
			else
			{
				lRet = _ReadDataWithMultiThread(pRequest, pData);
			}
			//lRet = _ReadData(pRequest, pData);
			if (bAcquiredLock)
			{
				ReleaseDiskLock();
			}
			if (lRet != OK)
			{
				WriteLogID(1, L"%s:: _ReadData() failed. RequestId=%d, EC=%d",
					__FUNCTIONW__, pRequest->lRequestId, lRet);
			}

			AddOneReadResult(pRequest, lRet, pData);
			m_ReadRequestPool.Free(pRequest);
		}

		//********************************************************************
		else if (pRequest->dwType == READQUEUE_TYPE_FLUSH)
		{
			m_ReadRequestPool.Free(pRequest);
			SetEvent(m_hAsyncReadEvent);
		}

		//********************************************************************
		else if (pRequest->dwType == READQUEUE_TYPE_QUIT)
		{
			m_ReadRequestPool.Free(pRequest);
			break;
		}

	} //while
	return lRet;
}

//********************************************************************
int CDataCloudRestore::_ReadData(P_READ_REQUEST_ITEM pRequest, P_READ_DATA_ITEM pData)
{
	int lRet = OK;
	PDATABLOCKINFOPKT pBlockInfo = NULL;
	int lBlockCount = 0;
	int lDataLenToRead = 0;
	int lDataLenRead = 0;
	char *pDataBuf = NULL;
	DWORD dwRead = 0;
	int i = 0;

	//********************************************************************
	//Check parameters
	if (!pRequest || !pData)
	{
		WriteLogID(1, L"%s:: Invalid parameters.", __FUNCTIONW__);
		return INVALID_PARAMETER;
	}

	//********************************************************************
	lDataLenToRead = pRequest->lDataLen;
	lBlockCount = pRequest->lBlockCount;
	pBlockInfo = pRequest->arrBlockInfo;
	pDataBuf = pData->DataBuf;
	if (lDataLenToRead == 0) //no data to read
	{
		return OK;
	}
	if (lBlockCount > QBUF_DATA_LEN / m_dwBlockSizeForDataSvr)
	{
		WriteLogID(1, L"%s:: Data buf is not big enough. lBlockCount[%d], BufSize[%d], BlockSize[%d]",
			__FUNCTIONW__, lBlockCount, QBUF_DATA_LEN, m_dwBlockSizeForDataSvr);
		return INVALID_PARAMETER;
	}

	//********************************************************************
	if (m_nReadBufferSize < QBUF_DATA_LEN)
	{
		if (m_pReadBuffer)
		{
			delete[] m_pReadBuffer;
			m_pReadBuffer = NULL;
			m_nReadBufferSize = 0;
		}
		m_pReadBuffer = new char[QBUF_DATA_LEN];
		if (m_pReadBuffer == NULL)
		{
			CServerStatus::GetInst().SetError(ERR_NO_MEMORY);
			WriteLogID(1, L"%s alloc memory fail.", __FUNCTIONW__);
			return NOT_ENOUGH_MEMORY;
		}
		m_nReadBufferSize = QBUF_DATA_LEN;
	}

	//********************************************************************
	READ_LIST BlockInfoList;
	DATABLOCKOPTI Block;
	lDataLenRead = 0;
	for (i = 0; i<lBlockCount; i++)
	{
		UINT64 Ind = 0, temp;
		temp = pBlockInfo[i].ulFileNo;
		Ind |= temp << 48;
		temp = pBlockInfo[i].uiSliceID;
		Ind |= temp << 32;
		temp = pBlockInfo[i].uiSliceOffset;
		Ind |= temp;
		if (BlockInfoList.find(Ind) != BlockInfoList.end())
		{
			Ind += i % 1024;
		}
		Block.pDataBlockInfo = pBlockInfo + i;
		Block.pBuffer = pDataBuf + lDataLenRead;
		//lDataLenRead += pBlockInfo[i].lDataLen;
		lDataLenRead += m_dwBlockSizeForDataSvr;
		BlockInfoList[Ind] = Block;
	}

	//********************************************************************
	++m_ullReadDataFileTimes;
	if (lBlockCount == BlockInfoList.size())
	{
		lDataLenRead = 0;
		pDataBuf = pData->DataBuf;
		READ_LIST_PTR FirstPtr, Ptr;
		FirstPtr = BlockInfoList.begin();
		Ptr = BlockInfoList.begin();

		while (FirstPtr != BlockInfoList.end())
		{
			ULONG DataLen = FirstPtr->second.pDataBlockInfo->lDataLen;
			ULONG FileNo = FirstPtr->second.pDataBlockInfo->ulFileNo;
			ULONG SliceID = FirstPtr->second.pDataBlockInfo->uiSliceID;
			ULONG SliceOffset = FirstPtr->second.pDataBlockInfo->uiSliceOffset;

			Ptr++;
			while (Ptr != BlockInfoList.end())
			{
				ULONG DataLen2 = Ptr->second.pDataBlockInfo->lDataLen;
				ULONG FileNo2 = Ptr->second.pDataBlockInfo->ulFileNo;
				ULONG SliceID2 = Ptr->second.pDataBlockInfo->uiSliceID;
				ULONG SliceOffset2 = Ptr->second.pDataBlockInfo->uiSliceOffset;

				if (FileNo == FileNo2 && SliceID == SliceID2 && SliceOffset + DataLen == SliceOffset2)
				{
					DataLen += DataLen2;
					Ptr++;
				}
				else break;
			}

			//********************************************************************
			dwRead = 0;
			m_TimerReadData.StartTimer();
			lRet = m_DataFile.ReadData(
				FileNo,
				SliceID,
				SliceOffset,
				DataLen,
				m_pReadBuffer,
				m_nReadBufferSize,
				&dwRead);
			m_TimerReadData.EndTimer();

			if (lRet != OK)
			{
				WriteLogID(1, L"%s:: m_DataFile.ReadData() ret[%d]. "
					L"fileNumber=%d, "
					L"SliceId=%d, "
					L"SliceOffset=%d, "
					L"dataToRead=%d "
					L"dataRead=%d",
					__FUNCTIONW__, lRet, FileNo, SliceID,
					SliceOffset, DataLen, dwRead);
				break;
			}

			//********************************************************************
			ULONG Copied = 0;
			while (FirstPtr != Ptr && FirstPtr != BlockInfoList.end())
			{
				memcpy(FirstPtr->second.pBuffer, m_pReadBuffer + Copied, FirstPtr->second.pDataBlockInfo->lDataLen);
				Copied += FirstPtr->second.pDataBlockInfo->lDataLen;
				FirstPtr++;
			}
			lDataLenRead += dwRead;
		}//while
	}
	else
	{
		//********************************************************************
		lDataLenRead = 0;
		pDataBuf = pData->DataBuf;
		for (i = 0; i<lBlockCount; i++)
		{
			//********************************************************************
			dwRead = 0;
			m_TimerReadData.StartTimer();
			lRet = m_DataFile.ReadData(pBlockInfo[i].ulFileNo,
				pBlockInfo[i].uiSliceID,
				pBlockInfo[i].uiSliceOffset,
				pBlockInfo[i].lDataLen,
				pDataBuf + i*m_dwBlockSizeForDataSvr,
				QBUF_DATA_LEN - i*m_dwBlockSizeForDataSvr,
				&dwRead);
			m_TimerReadData.EndTimer();
			if (lRet != OK)
			{
				WriteLogID(1, L"%s:: m_DataFile.ReadData() return %d. "
					L"fileNumber=%d, "
					L"SliceId=%d, "
					L"SliceOffset=%d, "
					L"dataToRead=%d "
					L"dataRead=%d",
					__FUNCTIONW__, lRet,
					pBlockInfo[i].ulFileNo,
					pBlockInfo[i].uiSliceID,
					pBlockInfo[i].uiSliceOffset,
					pBlockInfo[i].lDataLen,
					dwRead);
				break;
			}
			lDataLenRead += dwRead;
		}//for
	}
	BlockInfoList.clear();

	//********************************************************************
	if (lDataLenRead != lDataLenToRead && lRet != READ_DATA_REACH_EOF)
	{
		WriteLogID(1, L"%s:: data to read mismatch with data read. toRead=%d, Read=%d",
			__FUNCTIONW__, lDataLenToRead, lDataLenRead);
		return READ_DATA_FAILED;
	}
	pData->lRequestId = pRequest->lRequestId;
	pData->lDataLen = lDataLenRead;
	pData->lBlockCount = lBlockCount;
	return OK;
}

int CDataCloudRestore::_ReadDataWithMultiThread(P_READ_REQUEST_ITEM pRequest, P_READ_DATA_ITEM pData)
{
	int lRet = OK;
	PDATABLOCKINFOPKT pBlockInfo = NULL;
	int lBlockCount = 0;
	int lDataLenToRead = 0;
	int lDataLenRead = 0;
	char *pDataBuf = NULL;
	DWORD dwRead = 0;
	int i = 0;

	//********************************************************************
	//Check parameters
	if (!pRequest || !pData)
	{
		WriteLogID(1, L"%s:: Invalid parameters.", __FUNCTIONW__);
		return INVALID_PARAMETER;
	}

	//********************************************************************
	lDataLenToRead = pRequest->lDataLen;
	lBlockCount = pRequest->lBlockCount;
	pBlockInfo = pRequest->arrBlockInfo;
	pDataBuf = pData->DataBuf;
	if (lDataLenToRead == 0) //no data to read
	{
		return OK;
	}
	if (lBlockCount > QBUF_DATA_LEN / m_dwBlockSizeForDataSvr)
	{
		WriteLogID(1, L"%s:: Data buf is not big enough. lBlockCount[%d], BufSize[%d], BlockSize[%d]",
			__FUNCTIONW__, lBlockCount, QBUF_DATA_LEN, m_dwBlockSizeForDataSvr);
		return INVALID_PARAMETER;
	}

	//********************************************************************
	if (m_nReadBufferSize < QBUF_DATA_LEN)
	{
		if (m_pReadBuffer)
		{
			delete[] m_pReadBuffer;
			m_pReadBuffer = NULL;
			m_nReadBufferSize = 0;
		}
		m_pReadBuffer = new char[QBUF_DATA_LEN];
		if (m_pReadBuffer == NULL)
		{
			CServerStatus::GetInst().SetError(ERR_NO_MEMORY);
			WriteLogID(1, L"%s alloc memory fail.", __FUNCTIONW__);
			return NOT_ENOUGH_MEMORY;
		}
		m_nReadBufferSize = QBUF_DATA_LEN;
	}

	//********************************************************************
	READ_LIST BlockInfoList;
	DATABLOCKOPTI Block;
	lDataLenRead = 0;
	for (i = 0; i<lBlockCount; i++)
	{
		UINT64 Ind = 0, temp;
		temp = pBlockInfo[i].ulFileNo;
		Ind |= temp << 48;
		temp = pBlockInfo[i].uiSliceID;
		Ind |= temp << 32;
		temp = pBlockInfo[i].uiSliceOffset;
		Ind |= temp;
		if (BlockInfoList.find(Ind) != BlockInfoList.end())
		{
			Ind += i % 1024;
		}
		Block.pDataBlockInfo = pBlockInfo + i;
		Block.pBuffer = pDataBuf + lDataLenRead;
		//lDataLenRead += pBlockInfo[i].lDataLen;
		lDataLenRead += m_dwBlockSizeForDataSvr;
		BlockInfoList[Ind] = Block;
	}

	if (m_pMultiThreadDataReader->ReInit(lBlockCount) != OK)
	{
		WriteLogID(1, L"%s:%d, ERROR, ReInit multi thread reader fail, use original reading method.", __FUNCTIONW__, __LINE__);
		return _ReadData(pRequest, pData);
	}
	if (m_pMultiThreadDataReader->GetThreadsState() == AllDead)
	{
		WriteLogID(1, L"%s:%d, ERROR, no worker thread running, use original reading method.", __FUNCTIONW__, __LINE__);
		return _ReadData(pRequest, pData);
	}

	//********************************************************************
	++m_ullReadDataFileTimes;
	unsigned __int64 ullDataOffsetInResponseBuffer = 0;
	if (lBlockCount == BlockInfoList.size())
	{
		lDataLenRead = 0;
		pDataBuf = pData->DataBuf;
		READ_LIST_PTR FirstPtr, Ptr;
		FirstPtr = BlockInfoList.begin();
		//Ptr = BlockInfoList.begin();

		m_TimerReadData.StartTimer();
		while (FirstPtr != BlockInfoList.end())
		{
			ULONG DataLen = FirstPtr->second.pDataBlockInfo->lDataLen;
			ULONG FileNo = FirstPtr->second.pDataBlockInfo->ulFileNo;
			ULONG SliceID = FirstPtr->second.pDataBlockInfo->uiSliceID;
			ULONG SliceOffset = FirstPtr->second.pDataBlockInfo->uiSliceOffset;

			FirstPtr++;
			while (FirstPtr != BlockInfoList.end())
			{
				ULONG DataLen2 = FirstPtr->second.pDataBlockInfo->lDataLen;
				ULONG FileNo2 = FirstPtr->second.pDataBlockInfo->ulFileNo;
				ULONG SliceID2 = FirstPtr->second.pDataBlockInfo->uiSliceID;
				ULONG SliceOffset2 = FirstPtr->second.pDataBlockInfo->uiSliceOffset;

				if (FileNo == FileNo2 && SliceID == SliceID2 && SliceOffset + DataLen == SliceOffset2)
				{
					DataLen += DataLen2;
					FirstPtr++;
				}
				else break;
			}

			//********************************************************************
			dwRead = 0;
			{
				ReadDataIOInfo *pRequestInfo = m_pMultiThreadDataReader->GetReadDataIOInfo();
				pRequestInfo->request.DataRequest.ulFileNo = FileNo;
				pRequestInfo->request.DataRequest.ulSliceID = SliceID;
				pRequestInfo->request.DataRequest.ulSliceOffset = SliceOffset;
				pRequestInfo->request.DataRequest.ulDataToRead = DataLen;
				pRequestInfo->request.DataRequest.pDataBuf = m_pReadBuffer + ullDataOffsetInResponseBuffer;
				pRequestInfo->request.DataRequest.ulDataRead = DataLen;

				LARGE_INTEGER llSliceNumber;
				llSliceNumber.HighPart = FileNo;
				llSliceNumber.LowPart = SliceID;

				m_pMultiThreadDataReader->AddRequest(pRequestInfo, llSliceNumber.QuadPart);
				ullDataOffsetInResponseBuffer += DataLen;

				//WriteLogID(1, L"jerry, ===, multi sync data, %d, %d, %d, %d, %d.", requestCount, mIterStart->first.ui32DataFileNumber,
				//	mIterStart->first.ui32DataSliceID, mIterStart->first.ui32DataSliceOffset, dwToRead);
			}

		}//while

		m_pMultiThreadDataReader->SetFinishedPuttingRequest();
		m_pMultiThreadDataReader->WaitForRequestFinished();
		m_TimerReadData.EndTimer();
		if (m_pMultiThreadDataReader->HasError())
		{
			DWORD dwErr = READ_DATA_FAILED;
			WriteLogID(1, L"%s:%d, ERROR, read data failed, EC=[%d].", __FUNCTIONW__, __LINE__, dwErr);
			return READ_DATA_FAILED;
		}

		//********************************************************************
		FirstPtr = BlockInfoList.begin();
		ULONG Copied = 0;

		while (FirstPtr != BlockInfoList.end())
		{
			memcpy(FirstPtr->second.pBuffer, m_pReadBuffer + Copied, FirstPtr->second.pDataBlockInfo->lDataLen);
			Copied += FirstPtr->second.pDataBlockInfo->lDataLen;
			FirstPtr++;
		}
		lDataLenRead = Copied;
	}
	else
	{
		//********************************************************************
		lDataLenRead = 0;
		pDataBuf = pData->DataBuf;
		for (i = 0; i<lBlockCount; i++)
		{
			//********************************************************************
			dwRead = 0;
			m_TimerReadData.StartTimer();
			lRet = m_DataFile.ReadData(pBlockInfo[i].ulFileNo,
				pBlockInfo[i].uiSliceID,
				pBlockInfo[i].uiSliceOffset,
				pBlockInfo[i].lDataLen,
				pDataBuf + i*m_dwBlockSizeForDataSvr,
				QBUF_DATA_LEN - i*m_dwBlockSizeForDataSvr,
				&dwRead);
			m_TimerReadData.EndTimer();
			if (lRet != OK)
			{
				WriteLogID(1, L"%s:: m_DataFile.ReadData() return %d. "
					L"fileNumber=%d, "
					L"SliceId=%d, "
					L"SliceOffset=%d, "
					L"dataToRead=%d "
					L"dataRead=%d",
					__FUNCTIONW__, lRet,
					pBlockInfo[i].ulFileNo,
					pBlockInfo[i].uiSliceID,
					pBlockInfo[i].uiSliceOffset,
					pBlockInfo[i].lDataLen,
					dwRead);
				break;
			}
			lDataLenRead += dwRead;
		}//for
	}
	BlockInfoList.clear();

	//********************************************************************
	if (lDataLenRead != lDataLenToRead && lRet != READ_DATA_REACH_EOF)
	{
		WriteLogID(1, L"%s:: data to read mismatch with data read. toRead=%d, Read=%d",
			__FUNCTIONW__, lDataLenToRead, lDataLenRead);
		return READ_DATA_FAILED;
	}
	pData->lRequestId = pRequest->lRequestId;
	pData->lDataLen = lDataLenRead;
	pData->lBlockCount = lBlockCount;
	return OK;
}

//********************************************************************
int CDataCloudRestore::AddOneReadResult(P_READ_REQUEST_ITEM pRequest, int lResult, P_READ_DATA_ITEM pData)
{
	int ret = OK;

	//********************************************************************
	readresult_lock();
	DWORD dwCount = m_readResult.dwCount;
	m_readResult.arResult[dwCount].lRequestId = pRequest->lRequestId;
	m_readResult.arResult[dwCount].dwResult = lResult;
	m_readResult.dwCount++;
	if (lResult == OK && pRequest->lDataLen)
	{
		m_ReadDataQueue1.push(pData);
	}
	readresult_unlock();

	//********************************************************************
	if (lResult != OK || pRequest->lDataLen == 0)
	{
		m_ReadDataPool.Free(pData);
	}
	return OK;
}

int CDataCloudRestore::InitDataRoleMultiThreadReader(INT32 nThreadCount)
{
	int iRet = OK;
	if (m_pMultiThreadDataReader == NULL)
	{
		m_pMultiThreadDataReader = new MultiThreadFileReader<CDataFile>();
		if (!m_pMultiThreadDataReader)
		{
			DWORD dwErr = GetLastError();
			WriteLogID(1, L"%s:%d, ERROR, Creating multi thread reader fail. EC=[%d]", __FUNCTIONW__, __LINE__, dwErr);
			iRet = dwErr;
		}
		else
		{

			m_pMultiThreadDataReader->SetRealReader(&m_DataFile);
			m_pMultiThreadDataReader->SetWorkerThreadCount(nThreadCount);
			iRet = m_pMultiThreadDataReader->Init(READ_DATA_MAX_ENTRIES);
			if (OK != iRet)
			{
				WriteLogID(1, L"%s:%d, ERROR, Init multi thread reader fail. EC=[%d]", __FUNCTIONW__, __LINE__, iRet);
			}
		}
	}

	return iRet;
}

int CDataCloudRestore::InitIndexRoleMultiThreadReader(INT32 nThreadCountForIndex, INT32 nThreadCountForRef)
{
	int iRet = OK;
	do
	{
		if (NULL == m_pIndexFileEx)
		{
			m_pIndexFileEx = new CIndexFileEx();
			if (!m_pIndexFileEx)
			{
				DWORD dwErr = GetLastError();
				WriteLogID(1, L"%s:%d, ERROR, Create CIndexFileEx failed for path %s, EC=[%d].", __FUNCTIONW__, __LINE__, m_szIndexPath, dwErr);
				iRet = dwErr;
				break;
			}
			m_pIndexFileEx->SetPath(m_szIndexPath);
		}

		if (NULL == m_pMultiThreadIndexReader)
		{
			m_pMultiThreadIndexReader = new MultiThreadFileReader<CIndexFileEx>();
			if (!m_pMultiThreadIndexReader)
			{
				DWORD dwErr = GetLastError();
				WriteLogID(1, L"%s:%d, ERROR, Creating multi thread index reader fail. EC=[%d].", __FUNCTIONW__, __LINE__, dwErr);
				iRet = dwErr;
				break;
			}
			else
			{
				m_pMultiThreadIndexReader->SetRealReader(m_pIndexFileEx);
				m_pMultiThreadIndexReader->SetWorkerThreadCount(nThreadCountForIndex);
				iRet = m_pMultiThreadIndexReader->Init(READ_DATA_MAX_ENTRIES);
				if (0 != iRet)
				{
					WriteLogID(1, L"%s:%d, ERROR, Init multi thread index reader fail. EC=[%d]", __FUNCTIONW__, __LINE__, iRet);
					break;
				}
				else
				{
					WriteLogID(1, L"%s:%d, INFO, Init multi thread index reader succeed.", __FUNCTIONW__, __LINE__);
				}
			}
		}

		if (NULL == m_pMultiThreadRefReader)
		{
			m_pMultiThreadRefReader = new MultiThreadFileReader<CRefFile>();
			if (!m_pMultiThreadRefReader)
			{
				DWORD dwErr = GetLastError();
				WriteLogID(1, L"%s:%d, ERROR, Creating multi thread ref reader fail. EC=[%d]", __FUNCTIONW__, __LINE__, dwErr);
				iRet = dwErr;
				break;
			}
			else
			{
				m_pMultiThreadRefReader->SetRealReader(&m_RefFile);
				m_pMultiThreadRefReader->SetWorkerThreadCount(nThreadCountForRef);
				iRet = m_pMultiThreadRefReader->Init(READ_DATA_MAX_ENTRIES);
				if (0 != iRet)
				{
					WriteLogID(1, L"%s:%d, ERROR, Init multi thread ref reader fail. EC=[%d]", __FUNCTIONW__, __LINE__, iRet);
					break;
				}
				else
				{
					WriteLogID(1, L"%s:%d, INFO, Init multi thread ref reader succeed.", __FUNCTIONW__, __LINE__);
				}
			}
		}
	} while (FALSE);

	return iRet;
}

int CDataCloudRestore::InitReadBuffer(UINT64 ullTotalDataToRead)
{
	int iRet = OK;
	//********************************************************************
	//Check m_pReadBuffer
	if (m_nReadBufferSize < ullTotalDataToRead)
	{
		if (m_pReadBuffer)
		{
			delete[] m_pReadBuffer; m_pReadBuffer = NULL;
		}
		m_nReadBufferSize = 0;
		m_pReadBuffer = new char[ullTotalDataToRead];
		if (m_pReadBuffer == NULL)
		{
			CServerStatus::GetInst().SetError(ERR_NO_MEMORY);
			WriteLogID(1, L"%s alloc memory fail. Len[%d]. EC[%d]",
				__FUNCTIONW__, ullTotalDataToRead, GetLastError());
			return NOT_ENOUGH_MEMORY;
		}
		m_nReadBufferSize = ullTotalDataToRead;
	}

	return iRet;
}

int CDataCloudRestore::InitBlockInfo3List(char* pData, int * plSize, DWORD &dwBlockCount)
{
	int iRet = OK;
	if (!pData || !plSize)
	{
		WriteLogID(1, L"%s:%d, ERROR, Invalid parameters.", __FUNCTIONW__, __LINE__);
		return INVALID_PARAMETER;
	}

	//********************************************************************
	//Cache blockinfo3 list
	dwBlockCount = (*plSize - 8);
	dwBlockCount /= sizeof(GDDBLOCKINFO_3);
	if (!m_pBlockInfo3List || m_dwBlockInfo3Len < dwBlockCount)
	{
		if (m_pBlockInfo3List) delete[] m_pBlockInfo3List;
		m_pBlockInfo3List = new GDDBLOCKINFO_3[dwBlockCount];
		if (!m_pBlockInfo3List)
		{
			WriteLogID(1, L"%s:%d, ERROR, Failed to allocate BlockInfo3 list. Len=%d, EC=[%d]",
				__FUNCTIONW__, __LINE__, dwBlockCount, GetLastError());
			return NOT_ENOUGH_MEMORY;
		}
		m_dwBlockInfo3Len = dwBlockCount;
	}
	memcpy(m_pBlockInfo3List, pData + 8, (*plSize - 8));
	return iRet;
}

#endif //GDD_REPLICATION_OPTIMIZATION