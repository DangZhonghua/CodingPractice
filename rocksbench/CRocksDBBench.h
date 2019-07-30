#pragma once


#include<thread>
#include<string>
#include<vector>
using namespace std;

#include <rocksdb/db.h>
#include <rocksdb/slice.h>
#include <rocksdb/options.h>
using namespace rocksdb;

class CRocksDBBench
{
public:
	CRocksDBBench();
	~CRocksDBBench();
	
public:
	int OpenRdb(const string& strdbPath);
	int CloseRdb();
public:
	int StartInsert(int nThread);
private:
	int InsertThreadImpl();
	int ReadThreadImpl();

private:
	rocksdb::DB* 			m_pDB{nullptr};
	rocksdb::Options 		m_dbOptions;
};

