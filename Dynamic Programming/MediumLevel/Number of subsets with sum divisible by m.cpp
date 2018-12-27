/*
Number of subsets with sum divisible by m
https://www.geeksforgeeks.org/number-of-subsets-with-sum-divisible-by-m/

Given an array of integers, find number of subsequence such that the sum of the subsequence is divisible by m.
It is given that sum of array elements is small.
Examples:

Input : arr[] = {1, 2, 3};
m = 3;
Output : 3
Subsequence of given set are
{1}, {2}, {3}, {1, 2}, {2, 3}, {1, 3} and {1, 2, 3}.
And their sums are 1, 2, 3, 3, 5, 4 and 6.

Input : arr[] = {1, 2, 3, 4};
m = 2;
Output : 7
{2}, {4}, {1, 3}, {2, 4}, {1, 2, 3}, {1, 3, 4}
and {1, 2, 3, 4}

*/

/*

Use 0-1 knapsack technique to slove this.

*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int CalcSubSetCount(vector<int>&a, int m)
{
	int ret = 0;
	int sum = 0;
	for (int v : a)
	{
		sum += v;
	}

	int divisibleCount = 0;

	vector< vector<int> > f(a.size() + 1, vector<int>(sum + 1, INT_MIN));

	f[0][0] = 1;

	for (int i = 1; i <= a.size(); ++i)
	{
		for (int s = 1; s <= sum; ++s)
		{
			if (s >= a[i - 1] && INT_MIN != f[i - 1][s - a[i - 1]])
			{
				if (INT_MIN == f[i][s])
				{
					f[i][s] = f[i - 1][s - a[i - 1]];
				}
				else
				{
					f[i][s] += f[i - 1][s - a[i - 1]];
				}
			}
			if (INT_MIN != f[i][s] && s%m == 0)
			{
				divisibleCount += f[i][s];
			}
		}
	}

	cout << divisibleCount << endl;


	return ret;
}

int main(int argc, char const *argv[])
{
	/* code */

	vector<int> a{ 1, 2, 3 };
	int m = 3;
	CalcSubSetCount(a, m);

	return 0;
}
