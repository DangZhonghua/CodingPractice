/*
https://www.geeksforgeeks.org/implement-stack-using-priority-queue-or-heap/



*/

/*

Use Priority Queue to implement stack. the key is the enqueue sequence.


*/



#include<iostream>
#include<queue>
#include<functional>
using namespace std;

class ComparePair
{
public:
	bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
	{
		return lhs.first<rhs.first;
	}
};


class CHeapStack
{
	int m_nSeq;
	priority_queue< pair<int, int>, vector< pair<int, int> >, ComparePair > heapStack;
public:
	CHeapStack(){ m_nSeq = 0; };
	~CHeapStack(){};
public:
	void push(int a)
	{
		++m_nSeq;
		pair<int, int> ele;
		ele.first = m_nSeq;
		ele.second = a;
		heapStack.push(ele);
	};
	void pop()
	{
		heapStack.pop();
	}
	int top()
	{
		return heapStack.top().first;
	}
	bool empty()
	{
		return heapStack.empty();
	}
	int  size()
	{
		return heapStack.size();
	}
};

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	CHeapStack hs;

	for (int i = 0; i<_countof(a); ++i)
	{
		cout << a[i] << " ";
		hs.push(a[i]);
	}
	cout << endl;

	while (!hs.empty())
	{
		cout << hs.top() << " ";
		hs.pop();
	}
	cout << endl;

	return 0;

}