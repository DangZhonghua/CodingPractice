/*
https://practice.geeksforgeeks.org/problems/sum-of-lengths-of-non-overlapping-subarrays/0/?ref=self
Sum of Lengths of Non-Overlapping SubArrays

Given an array of N elements, you are required to find the maximum sum of lengths of
all non-overlapping subarrays with K as the maximum element in the subarray.
.
Input:
First line of the input contains an integer T, denoting the number of the total test cases.
Then T test case follows. First line of the test case contains an integer N,
denoting the number of elements in the array.
Then next line contains N space separated integers denoting the elements of the array.
The last line of each test case contains an integer K.

Output:
For each test case ouptut a single line denoting the sum of the length of all such subarrays.

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= A[] <= 105

Example:
Input:
3
9
2 1 4 9 2 3 8 3 4
4
7
1 2 3 2 3 4 1
4
10
4 5 7 1 2 9 8 4 3 1
4
Output:
5
7
4
Explanation:
Test Case 1:
{2, 1, 4} => Length = 3
{3, 4} => Length = 2
So, 3 + 2 = 5 is the answer

Test Case 2: {1, 2, 3, 2, 3, 4, 1} => Length = 7

Test Case 3:
{4} => Length = 1
{4, 3, 1} => Length = 3
So, 1 + 3 = 4 is the answer.

*/


#include<iostream>
#include<vector>
using namespace std;


int CalcSumOfSubArray(vector<int>& a, int K)
{
	int ret = 0;
	vector<int> vl;
	int start = -1;
	int end = -1;

	for (int i = 0; i < a.size(); ++i)
	{
		if (a[i] <= K)
		{
			if (-1 == start)
			{
				start = i;
			}
			if (a[i] == K)
			{
				end = i;
			}
			else if ( -1 != end)
			{
				end = i;
			}
		}
		else
		{
			if (-1 != end && -1 != end)
			{
				vl.push_back(end - start + 1);
			}
			start = -1;
			end = -1;

		}
	}

	if (-1 != end && -1 != end)
	{
		vl.push_back(end - start + 1);
	}

	int sum = 0;

	for (int e : vl)
	{
		sum += e;
	}

	cout << sum << endl<<endl;

	return 0;
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
		int K = 0;
		cin >> K;
		CalcSumOfSubArray(a, K);
	}
	return 0;
}
