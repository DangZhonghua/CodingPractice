#include "CKeyGenerator.h"



CKeyGenerator::CKeyGenerator()
{
}

CKeyGenerator::~CKeyGenerator()
{
}

int CKeyGenerator::CreateKeyBase(const string& strKeyFile, long long nKeyCount)
{
	RPC_CSTR szKey = nullptr;
	UUID uuidkey;
	std::ofstream  keyStream;
	
	keyStream.open(strKeyFile, std::ofstream::binary);

	for (long long index = 0; index < nKeyCount; ++index)
	{
		UuidCreate(&uuidkey);
		UuidToStringA(&uuidkey, &szKey);
		
		keyStream << szKey;
		keyStream << endl;
		RpcStringFreeA(&szKey);
	}
	
	keyStream.close();

	return 0;
}
