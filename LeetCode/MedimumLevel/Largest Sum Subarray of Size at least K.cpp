/*
https://practice.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k/0
https://www.geeksforgeeks.org/largest-sum-subarray-least-k-numbers/
Largest Sum Subarray of Size at least K
Given an array and a number k, find the largest sum of the subarray containing at least k numbers.
It may be assumed that the size of array is at-least k.

Input:
The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. Each test case contains an integer n denoting the size of the array.
Then the following line contains n space separated integers. The last line of the input contains the number k.

Output:
Print the value of the largest sum of the subarray containing at least k numbers.

Constraints:
1<=T<=10^5
1<=n<=10^5
1<=a[i]<=10^5
1<=k<=n

Example:
Input:
2
4
-4 -2 1 -3
2
6
1 1 1 1 1 1
2

Output:
-1
6

*/

/*
use the sliding window technique, the window size is K. [i,i+k-1]
the largest sum subarray end at (i-1) is pre-computed, then check sum of pre-calculated and window sum.


This problem is an extension of Largest Sum Subarray Problem.

1) We first compute maximum sum till every index and store it in an array maxSum[].
2) After filling the array, we use the sliding window concept of size k. 
Keep track of sum of current k elements. To compute sum of current window, 
remove first element of previous window and add current element. After getting the sum of current window, 
we add the maxSum of the previous window, 
if it is greater than current max, then update it else not. 
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	long long LargestSumOfSubarrayAtLeastK(vector<long long>& a, int K)
	{
		int N = a.size();
		vector<long long>  largestsumAtIndex(N, 0);
		largestsumAtIndex[0] = a[0];
		long long curSum = a[0];

		for (int i = 1; i < N; ++i)
		{
			if (a[i] < (curSum + a[i]))
			{
				curSum += a[i];
			}
			else
			{
				curSum = a[i];
			}
			largestsumAtIndex[i] = curSum;
		}
		long long kSum = 0;
		int i = 0;
		long long maxsum = 0;
		for (i = 0; i < K && i < N; ++i)
		{
			kSum += a[i];
		}
		maxsum = kSum;

		for (int i = K; i < N; ++i)
		{
			kSum = kSum + a[i] - a[i - K]; // the next K size window sum.

			if (kSum > maxsum)
			{
				maxsum = kSum;
			}
		
			if (maxsum < (kSum + largestsumAtIndex[i - K]))
			{
				maxsum = (kSum + largestsumAtIndex[i - K]);
			}
		}
		return maxsum;
	}

};


int main()
{
	int K = 2;
	vector<long long> a1{ -4, -2, 1, -3 };
	Solution sol;

	//cout << sol.LargestSumOfSubarrayAtLeastK(a1, K) << endl;

	vector<long long> a2{ 5, 7, -9, 3 ,-4, 2, 1, -8, 9, 10 };
	K = 5;
	
	cout<<sol.LargestSumOfSubarrayAtLeastK(a2,K)<<endl;

	return 0;
}



int main()
{
	int t = 0;
	cin>>t;
	
	while (t--)
	{
		int N = 0;
		cin>>N;
		vector<long long> a(N,0);
		int i = 0;
		while (i < N)
		{
			cin >> a[i];
			++i;
		}
		int K = 0;
		cin>>K;
		Solution sol;
		sol.LargestSumOfSubarrayAtLeastK(a,K);
	}
}

