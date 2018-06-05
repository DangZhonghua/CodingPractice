/*
Check if any valid sequence is divisible by M
https://practice.geeksforgeeks.org/problems/check-if-any-valid-sequence-is-divisible-by-m/0/?ref=self

Given an array of N integers, using ‘+’ and ‘-‘ between the elements check if there is a way to form a sequence of numbers which evaluate to a number divisible by M.

Input:
The first line contains T, the number of test cases.For each test case, the first line contains an integer n denoting the size of the array A. Next line contains n-space separated integers and next line contains an integer m denoting the number from which divisibility needs to be checked.

Output:
For each test case, the output is 1 if divisible else 0.

Constraints:
1<=T<=100
1<=n<=50
1<=m<=10
Note: Sum of elements should be less than 1000.

Example:
Input
2
5
1 2 3 4 6
4
3
1 3 9
2
Output
1
0

Explanation:
1.There is a valid sequence i. e., (1 - 2 + 3 + 4 + 6), which evaluates to 12 that is divisible by 4.
2.There is no sequence which evaluates to a number divisible by 2

*/

#include<iostream>
#include<vector>
using namespace std;

int CheckDivisibleByM(int*a, int N, int M)
{
	int sum = 0;
	vector< vector<bool> > pas(N + 1, vector<bool>(1000, false));
	vector< vector<bool> > nas(N + 1, vector<bool>(1000, false));
	if (a[0] >= 0)
	{
		pas[0][a[0]] = true;
	}
	else
	{
		nas[0][a[0]] = true;
	}

	for (int i = 0; i<N; ++i)
	{
		sum += (a[i] >= 0 ? a[i] : (-a[i]));
	}

	for (int i = 1; i<N; ++i)
	{
		for (int p = 0; p <= sum; ++p)
		{
			if (nas[i - 1][p])
			{
				int t = (-p - a[i]);
				if (t >= 0)
				{
					pas[i][t] = true;
				}
				else
				{
					nas[i][-t] = true;
				}

				t = a[i] - p;
				if (t >= 0)
				{
					pas[i][t] = true;
				}
				else
				{
					nas[i][-t] = true;
				}
			}
			if (pas[i - 1][p])
			{
				int t = p + a[i];
				if (t >= 0)
				{
					pas[i][t] = true;
				}
				else
				{
					nas[i][-t] = true;
				}
				t = p - a[i];
				if (t >= 0)
				{
					pas[i][t] = true;
				}
				else
				{
					nas[i][-t] = true;
				}
			}
		}
	}

	bool bDiv = false;
	for (int p = 0; p <= sum; ++p)
	{
		if (p%M == 0 && (nas[N - 1][p] || pas[N - 1][p]))
		{
			bDiv = true;
			break;
		}
	}

	cout << (bDiv ? 1 : 0) << endl;

	return 0;
}




int main()
{
	int t = 0;
	int N = 0;
	int M = 0;
	int a[100];

	cin >> t;

	while (t--)
	{
		cin >> N;
		int i = 0;

		while (i<N)
		{
			cin >> a[i++];
		}
		cin >> M;
		CheckDivisibleByM(a, N, M);

	}


	return 0;
}