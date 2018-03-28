//https://practice.geeksforgeeks.org/problems/partition-array-to-k-subsets/1

/*

Given an integer array A[] of N elements, the task is to complete the function which returns true if the array A[] could be divided into K non-empty subsets such that the sum of elements in every subset is same.

Note: All elements of this array should be part of exactly one partition.

Examples:
Input : A[] = [2, 1, 4, 5, 6], K = 3
Output : 1, as we can divide above array into 3 parts with equal sum as (2, 4), (1, 5), (6)


Input : A[] = [2, 1, 5, 5, 6], K = 3
Output : 0, as it is not possible to divide above array into 3 parts with equal sum


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains 3 lines. The first line of each test case contains an integer denoting the size of the array. In the next line are N space separated values of the array A[ ]. In the next line is an integer K.

Output:
The output for each test case will be 1 if the array could be divided into k subsets else 0 .

Constraints:
1<=T<=100
1<=N,K<=100
1<=A[ ] <=100

Example(To be used only for expected output):
Input:
2
5
2 1 4 5 6
3
5
2 1 5 5 6
3
Output:
1
0
*/

/*

Suppose, There are multiple bags with same capacity. For Every bag, we use 0-1 knapsnack algorithm to slove it.



*/

#include <algorithm>
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

bool  ZeroOnePack(vector<int>& v, int N, int C, vector<int>& selectedIndex)
{
	// Initialize the status matrix.
	vector< vector<int> > track;
	vector< vector<int> > m;
	for (int r = 0; r <= N; ++r)
	{
		m.push_back(vector<int>());
		track.push_back(vector<int>());
		for (int c = 0; c <= C; ++c)
		{
			track[r].push_back(0);
			if (0 == c && 0 == r)
			{
				m[r].push_back(0);
			}
			else
			{
				m[r].push_back(INT_MIN);
			}
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int c = 0; c <= C; ++c)
		{
			m[i][c] = m[i - 1][c];
			if (c >= v[i] && m[i - 1][c - v[i]] != INT_MIN)
			{
				if (m[i - 1][c - v[i]] + v[i] >= m[i][c])
				{
					m[i][c] = m[i - 1][c - v[i]] + v[i];
					track[i][c] = 1;
				}
			}
		}
	}

	if (C != m[N][C])
	{
		return false;;
	}

	int c = C;
	int i = N;

	while (i>0)
	{
		if (track[i][c])
		{
			selectedIndex.push_back(i);
			c -= v[i];
			i = i - 1;
		}
		else
		{
			i = i - 1;
		}
	}

	return true;
}


bool isKPartitionPossible(int A[], int N, int K)
{
	//Your code here
	bool bPartition = false;
	int sum = 0;
	int group = 0;

	for (int i = 0; i<N; ++i)
	{
		sum += A[i];
	}
	if (sum % K)//Can't be dividable, so it is not partitioned
	{
		cout << 0<<endl;
		return false;
	}
	sum /= K;

	vector<int> v;

	v.push_back(0);
	for (int i = 0; i<N; ++i)
	{
		v.push_back(A[i]);
	}
	vector<int> leftelements;
	int Count = N;
	vector<int>* pSubArray = &v;
	vector<int>* pLeftSubArray = &leftelements;

	while (group != K)
	{
		vector<int> selectedIndex;
		if (!ZeroOnePack(*pSubArray, Count, sum, selectedIndex))
		{		
			break;
		}
		++group;
		//Decrease the element count.
		Count -= selectedIndex.size();
		pLeftSubArray->push_back(0);
		auto it = selectedIndex.rbegin();

		for (int i = 1; i<pSubArray->size(); ++i)
		{
			if (it != selectedIndex.rend())
			{
				if (i != (*it))
				{
					pLeftSubArray->push_back(pSubArray->at(i));
				}
				else
				{
					++it;
				}
			}
			else{
				pLeftSubArray->push_back(pSubArray->at(i));
			}
		}
		auto    t = pSubArray;
		pSubArray = pLeftSubArray;
		pLeftSubArray = t;
		pLeftSubArray->clear();
	}

	if (group == K && Count == 0)
	{
		bPartition = true;
	}

	if (bPartition)
	{
		cout<<1<<endl;
	}
	else
	{
		cout<<0<<endl;
	}
	return bPartition;
}


/*
int main()
{
	int K = 3;
	//int a[] = { 26, 86, 23, 100, 41, 43, 99, 14, 99, 91 };
	int a[] = { 29, 28, 51, 85, 59, 21, 25, 23, 70, 97, 82, 31, 85, 93, 73 };


	isKPartitionPossible(a, _countof(a), K);
	return 0;
}
*/