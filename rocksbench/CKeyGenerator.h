#pragma once

#include<Windows.h>
#include<rpc.h>
#include<string>
#include <fstream>
using namespace std;

class CKeyGenerator
{
public:
	CKeyGenerator();
	~CKeyGenerator();
public:
	int CreateKeyBase(const string& strKeyFile, long long nKeyCount);
	

};

