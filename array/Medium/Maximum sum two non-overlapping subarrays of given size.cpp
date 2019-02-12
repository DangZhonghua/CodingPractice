/*
https://www.geeksforgeeks.org/maximum-sum-two-non-overlapping-subarrays-of-given-size/
Maximum sum two non-overlapping subarrays of given size

Given an array, we need to find two subarrays with a specific length K
such that sum of these subarrays is maximum among all possible choices of subarrays.
Examples:

Input : arr[] = [2, 5, 1, 2, 7, 3, 0]
K = 2
Output : 2 5
7 3
We can choose two arrays of maximum sum
as [2, 5] and [7, 3], the sum of these two
subarrays is maximum among all possible
choices of subarrays of length 2.

Input : arr[] = {10, 1, 3, 15, 30, 40, 4, 50, 2, 1}
K = 3
Output : 3 15 30
40 4 50


*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution
{
public:
	int MaximumSumOfTwoNonOverlappSubarrays(vector<int>&a, int K)
	{
		int N = a.size();
		vector<int> presum(N, 0);
		vector<int> vksum;
		presum[0] = a[0];
		for (int i = 1; i<N; ++i)
		{
			presum[i] = (presum[i - 1] + a[i]);
		}

		//Calculate every K size window sum.
		vksum.push_back(presum[K - 1]);
		for (int i = K; i<N; ++i)
		{
			vksum.push_back(presum[i] - presum[i - K]);
		}

		int maxsum = INT_MIN;
		int w1 = 0;
		int w2 = 0;

		for (int i = 0; i <= N - K; ++i)
		{
			for (int j = i + K; j <= N - K; ++j)
			{
				if (maxsum < vksum[i] + vksum[j])
				{
					maxsum = (vksum[i] + vksum[j]);
					w1 = i;
					w2 = j;
				}
			}
		}

		
		for (int i = w1, j = 0; j < K; ++j)
		{
			cout << a[i+j] << " ";
		}
		cout<<endl;

		for (int i = w2, j = 0; j < K; ++j)
		{
			cout << a[i+j] << " ";
		}
		cout << endl;

		return maxsum;
	}
};

int main()
{
	Solution sol;
	int K = 0;
	vector<int> num1{ 2, 5, 1, 2, 7, 3, 0 };

	K = 2;
	cout << sol.MaximumSumOfTwoNonOverlappSubarrays(num1, K) << endl;


	return 0;
}