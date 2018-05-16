/*
https://practice.geeksforgeeks.org/problems/subsets-with-xor-value/0/?ref=self
Given an array arr[] of N integers and a integer K, find the number of subsets of arr[] having XOR of elements as K.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. The first line of each test case contains two space separated integers N and K as described in the problem statement. Second line of each test case contains N space separated integers denoting the array arr[].

Output:
Corresponding to each test case, print a single line containing an integer denoting the total number of subsets of arr[] having XOR of thier elements as K.

Constraints:
1<=T<=10
1<=N<=20
1<=K<=100
0<=arr[i]<=100


Example:
Input:
1
4 6
6 9 4 2

Output:
2

Explanation:
The subsets are {4,2} and {6}

16 30
3 23 59 70 68 94 57 12 43 30 74 22 20 85 38 99

output: 512

*/


/*

Dynamatic programming: optimal sub-structure and overlapped sub-problems.

For this: the sub-structure is: sub-solution og  l-1 length  array is included in soultion of l length array.

count[i][j]:L = (count[i][k]:L-1)^a[j] for j=k+1 .... N

6 9 4 2

{6} {9} {4} {2}
{6,9} {6,4} {6,2}
{9,4} {9,2}
{4,2}
{6,9,4},{6,9,2}, {9,4,2}
{6,9,4,2}

*/

#include<iostream>
#include<vector>
using namespace std;

struct xorrange
{
	int v;
	int s;
	int e;
	int l;
};

int XORSubsetCount(int *a, int N, int K)
{
	int subsetCount = 0;

	vector<xorrange> c;
	vector<xorrange> n;

	vector<xorrange>* cur;
	vector<xorrange>* next;

	for (int i = 0; i<N; ++i)
	{
		xorrange onexor;
		onexor.v = a[i];
		onexor.s = i;
		onexor.e = i;
		onexor.l = 1;
		if (K == onexor.v)
		{
			++subsetCount;
		}
		c.push_back(onexor);
	}
	cur = &c;
	next = &n;
	int l = 2;
	while (l <= N)
	{
		for (auto it = cur->begin(); it != cur->end(); ++it)
		{
			xorrange onexor;
			onexor.l = l;

			for (int i = it->e + 1; i<N; ++i)
			{
				onexor.e = i;
				onexor.v = ((it->v) ^ a[i]);
				if (K == onexor.v)
				{
					++subsetCount;
				}
				next->push_back(onexor);
			}
		}
		vector<xorrange>* t = cur;
		cur = next;
		next = t;
		next->clear();
	}


	cout << subsetCount << endl;


	return 0;
}

int XORSubsetCountRawMem(int *a, int N, int K)
{
	int subsetCount = 0;
	int nCurCount = 0;
	int nNextCount = 0;

	xorrange* ax = new xorrange[184756];
	xorrange* bx = new xorrange[184756];

	xorrange* cur = ax;
	xorrange* next = bx;

	for (int i = 0; i<N; ++i)
	{
		cur[nCurCount].v = a[i];
		if (K == cur[nCurCount].v)
		{
			++subsetCount;
		}
		cur[nCurCount].s = i;
		cur[nCurCount].e = i;
		cur[nCurCount].l = 1;
		++nCurCount;
		
	}

	int l = 2;
	while (l <= N)
	{
		nNextCount = 0;
		for (int index = 0; index<nCurCount; ++index)
		{
			for (int i = cur[index].e + 1; i<N; ++i)
			{
				next[nNextCount].s = cur[index].s;
				next[nNextCount].l = l;
				next[nNextCount].e = i;
				next[nNextCount].v = (cur[index].v^a[i]);
				if (K == next[nNextCount].v)
				{
					++subsetCount;
				}
				++nNextCount;
			}
		}
		xorrange* t = cur;
		cur = next;
		next = t;
		nCurCount = nNextCount;
		nNextCount = 0;
		++l;
	}


	cout << subsetCount << endl;

	if (ax)
	{
		delete[] ax;
	}
	if (bx)
	{
		delete[] bx;
	}

	return 0;
}


int main()
{
	int t = 0;
	int a[100] = { 0 };
	int N;
	int K;

	cin >> t;

	while (t>0)
	{
		--t;
		cin >> N >> K;
		int i = 0;
		while (i<N)
		{
			cin >> a[i++];
		}
		XORSubsetCountRawMem(a, N, K);
	}


	return 0;
}
