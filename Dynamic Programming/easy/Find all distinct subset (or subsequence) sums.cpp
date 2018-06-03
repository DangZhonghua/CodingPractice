/*
Find all distinct subset (or subsequence) sums

https://practice.geeksforgeeks.org/problems/find-all-distinct-subset-or-subsequence-sums/0
Given a set of integers, find distinct sum that can be generated from the subsets of the given sets
and print them in an increasing order. It is given that sum of array elements is small.

Input:

The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. The first line of each test case contains an integer N denoting the size of array A.

The second line of each test case contains N space separated integers denoting elements of the array A[ ].


Output:

Print all the distinct sum that can be generated from the subsets in increasing order for each testcase in a new line.


Constraints:

1<= T <=100

1<= N <=100

1<= A[ ] <=100


Example:

Input:

1
5
2 3 4 5 6

Output:

0 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

*/

/*
This is a extentison 0-1 knapsack problem without requiring optimal value.
            cm[i][a[i]] =true
cm[i][v] =   true    if cm[i-1][v]
            cm[i][v+a[i-1]] = true; 


*/

#include<iostream>
#include<vector>
#include<algorithm>
//#include<bits/stdc++.h>
using namespace std;

bool cm[101][10001];
int DistinctSubsetSum(int*a, int N)
{
	int sum = 0;
	for (int i = 0; i <N; ++i)
	{
		sum += a[i];
	}
	vector< vector<bool> >  cm(N + 1, vector<bool>(10001, 0));
    //memset(cm,0,sizeof(cm));


	for (int i = 0; i <= N; ++i)
	{
		cm[i][0] = true;
	}

	for (int i = 1; i <= N; ++i)
	{
		cm[i][a[i - 1]] = true;
		for (int v = 1; v <= sum; ++v)
		{
			if (cm[i-1][v])
			{
				cm[i][v] = true;
				cm[i][v+a[i-1]] = true;
			}
		}
	}

	for (int j = 0; j <= sum; ++j)
	{
		if (cm[N][j])
		{
			cout << j << " ";
		}
	}
	cout << endl;

	return 0;
}

int main()
{
	int t = 0;
	int N = 0;
	int a[101];

	cin >> t;

	while (t)
	{
	    --t;
		cin >> N;
		int i = 0;
		while (i<N)
		{
			cin >> a[i++];
		}
		DistinctSubsetSum(a, N);
	}

	return 0;
}
//Count subsets having distinct even numbers
//https://www.geeksforgeeks.org/count-subsets-distinct-even-numbers/
//https://practice.geeksforgeeks.org/problems/count-increasing-subsequences/0
//https ://www.geeksforgeeks.org/count-all-increasing-subsequences/
