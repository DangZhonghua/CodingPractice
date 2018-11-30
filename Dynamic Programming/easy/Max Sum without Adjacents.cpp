/*
Max Sum without Adjacents 
https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents/0
https://www.geeksforgeeks.org/find-maximum-possible-stolen-value-houses/
Given an array A of positive integers. Find the maximum sum of a subsequence such that no two numbers in the sequence 
should be adjacent in the array.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N, size of array. 
The second line of each test case contains N elements.

Output:
Print the maximum sum of a subsequence.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 10^6
1 ≤ Ci ≤ 10^7

Example:
Input:
2
6
5 5 10 100 10 5
4
3 2 7 10

Output:
110
13

Explanation:
Testcase 2 : 3 and 10 forms a non-continuous subsequence with maximum sum.

*/

/*

SA[i] = max(SA[i-1], SA[i-2]+a[i])
SA[0] = a[0]
SA[1] = max{a[0],a[1]}

*/

#include<iostream>
#include<vector>
using namespace std;

int MaximumSum(vector<int>&a)
{
	int ret = 0;
	vector<int> SA(a.size(), 0);

	SA[0] = a[0];
	SA[1] = a[1] > a[0] ? a[1] : a[0];

	for (int i = 2; i < a.size(); ++i)
	{
		SA[i] = SA[i - 1];
		if (i - 2 >= 0)
		{
			if (SA[i] < (SA[i - 2] + a[i]))
			{
				SA[i] = SA[i - 2] + a[i];
			}
		}
	}

	cout << SA[a.size() - 1] << endl;

	return ret;
}


int main(int argc, char const *argv[])
{
	int t = 0;

	cin >> t;

	while (t--)
	{
		int N = 0;
		cin >> N;
		vector<int> a(N, 0);
		int i = 0;
		while (i < N)
		{
			cin >> a[i];
			++i;
		}
		MaximumSum(a);
	}

	return 0;
}

