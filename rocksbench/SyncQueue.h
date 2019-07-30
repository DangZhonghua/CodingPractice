#pragma once

#include <windows.h>
#include <deque>
using namespace std;


template< typename T>
class CSyncQueue
{
public:
	CSyncQueue();
	~CSyncQueue();

public:
	int InitSyncQueue(int nCapacity);
	int DeInitSyncQueue();
public:
	void push(const T& item);
	T	 pop();
private:
	deque<T> m_Q;
	HANDLE		m_hPushSem{ nullptr };
	HANDLE		m_hPopSem{ nullptr };
	HANDLE		m_hMutex{ nullptr };
};

template< typename T> CSyncQueue<T>::CSyncQueue()
{
	
}

template< typename T> CSyncQueue<T>::~CSyncQueue()
{
	if (nullptr != m_hMutex)
	{
		CloseHandle(m_hMutex);
		m_hMutex = nullptr;
	}

	if (nullptr != m_hPopSem)
	{
		CloseHandle(m_hPopSem);
		m_hPopSem = nullptr;
	}

	if (nullptr != m_hPushSem)
	{
		CloseHandle(m_hPushSem);
		m_hPushSem = nullptr;
	}
}

template< typename T> int CSyncQueue<T>::InitSyncQueue(int nCapacity)
{
	int ret = 0;
	
	do 
	{
		m_hMutex = CreateMutex(NULL, false, NULL);
		if (nullptr == m_hMutex)
		{
			ret = GetLastError();
			break;
		}
		m_hPushSem = CreateSemaphore(NULL, nCapacity, nCapacity, NULL);
		
		if (nullptr == m_hPushSem)
		{
			ret = GetLastError();
			break;
		}
		
		m_hPopSem = CreateSemaphore(NULL, 0, nCapacity, NULL);
		if (nullptr == m_hPopSem)
		{
			ret = GetLastError();
			break;
		}

	} while (false);


	return ret;
}

template< typename T> int CSyncQueue<T>::DeInitSyncQueue()
{
	int ret = 0;

	if (nullptr != m_hMutex)
	{
		CloseHandle(m_hMutex);
		m_hMutex = nullptr;
	}

	if (nullptr != m_hPopSem)
	{
		CloseHandle(m_hPopSem);
		m_hPopSem = nullptr;
	}

	if (nullptr != m_hPushSem)
	{
		CloseHandle(m_hPushSem);
		m_hPushSem = nullptr;
	}

	m_Q.clear();

	return ret;
}

template< typename T> void CSyncQueue<T>::push(const T& item)
{
	WaitForSingleObject(m_hPushSem, INFINITE);
	WaitForSingleObject(m_hMutex, INFINITE); //Make sure only one thread modify this queue
	m_Q.push_back(item);
	ReleaseMutex(m_hMutex);
	ReleaseSemaphore(m_hPopSem, 1, NULL);
}


template< typename T> T CSyncQueue<T>::pop()
{
	WaitForSingleObject(m_hPopSem, INFINITE);
	WaitForSingleObject(m_hMutex, INFINITE);
	T head = m_Q.front();
	m_Q.pop_front();
	ReleaseMutex(m_hMutex);
	ReleaseSemaphore(m_hPushSem, 1, NULL);
	return head;
}
