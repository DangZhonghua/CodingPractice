/*
https://www.geeksforgeeks.org/largest-sum-contiguous-increasing-subarray/
https://practice.geeksforgeeks.org/problems/greedy-fox/0
Largest sum contiguous increasing subarray

Given an array of n positive distinct integers. The problem is to find the largest sum
of contiguous increasing subarray in O(n) time complexity.
Examples :
Input : arr[] = {2, 1, 4, 7, 3, 6}
Output : 12
Contiguous Increasing subarray {1, 4, 7} = 12

Input : arr[] = {38, 7, 8, 10, 12}
Output : 38

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int LargestSumOfIncreasingSubarray(vector<int>& nums)
	{
		int sum = nums[0];
		int maxsum = nums[0];

		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[i] > nums[i - 1])
			{
				sum += nums[i];
			}
			else
			{
				if (sum > maxsum)
				{
					maxsum = sum;
				}
				sum = nums[i];
			}
		}
		if (maxsum < sum)
		{
			maxsum = sum;
		}
		return maxsum;
	}
};

int main1()
{
	int ret = 0;

	Solution sol;
	vector<int> nums1{ 2, 1, 4, 7, 3, 6 };
	vector<int> nums2{ 38, 7, 8, 10, 12 };

	cout << sol.LargestSumOfIncreasingSubarray(nums1) << endl;
	cout << sol.LargestSumOfIncreasingSubarray(nums2) << endl;

	return 0;
}


int main()
{
	int t = 0;
	cin >> t;

	while (t--)
	{
		int N = 0;
		cin >> N;
		vector<int> nums(N, 0);
		int i = 0;

		while (i < N)
		{
			cin >> nums[i];
			++i;
		}
		Solution sol;
		cout << sol.LargestSumOfIncreasingSubarray(nums) << endl;
	}

	return 0;
}