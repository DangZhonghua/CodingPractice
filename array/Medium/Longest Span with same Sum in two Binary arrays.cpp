/*
Longest Span with same Sum in two Binary arrays
https://practice.geeksforgeeks.org/problems/longest-span-with-same-sum-in-two-binary-arrays/0/?ref=self
Given two binary arrays arr1[] and arr2[] of same size n. Find length of the longest common span (i, j) where j >= i such that arr1[i] + arr1[i+1] + …. + arr1[j] = arr2[i] + arr2[i+1] + …. + arr2[j]. Elements are only 0 or 1.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'N' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array. The third line contains N space-separated integers B1, B2, ..., BN denoting the elements of the array.


Output:
In each seperated line output the maximum span with same sum.


Constraints:
1<=T<=31
1<=N<=100


Example:
Input:
1
6
0 1 0 0 0 0
1 0 1 0 0 1

Output:
4

Explaination :

Input: arr1[] = {0, 1, 0, 0, 0, 0};
arr2[] = {1, 0, 1, 0, 0, 1};
Output: 4
The longest span with same sum is from index 1 to 4  (Zero indexing).



*/

#include<iostream>
#include<vector>
using namespace std;

int longestSpan(int*a, int* b, int N)
{
	vector<int> av(N + 1, 0);
	vector<int> bv(N + 1, 0);
	av[1] = a[0] ? 1 : 0;
	bv[1] = b[0] ? 1 : 0;
	for (int i = 2; i <= N; ++i)
	{
		av[i] = av[i - 1];
		if (a[i - 1])
		{
			av[i] += 1;
		}
		bv[i] = bv[i - 1];
		if (b[i - 1])
		{
			bv[i] += 1;
		}
	}
	int max = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = i; j <= N; ++j)
		{
			if (av[j] - av[i - 1] == bv[j] - bv[i - 1])
			{
				if (max<(j - i + 1))
				{
					max = (j - i + 1);
				}
			}
		}
	}

	cout << max << endl;

	return 0;
}


int main()
{
	int t = 0;
	int N = 0;
	int a[200];
	int b[200];

	cin >> t;

	while (t--)
	{
		cin >> N;
		int i = 0;

		while (i<N)
		{
			cin >> a[i++];
		}
		i = 0;
		while (i < N)
		{
			cin >> b[i++];
		}
		longestSpan(a, b, N);
	}

	return 0;
}

