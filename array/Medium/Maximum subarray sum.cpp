/*
https://www.geeksforgeeks.org/maximum-subarray-sum-using-prefix-sum/
Maximum subarray sum
Given an Array of Positive and Negative Integers, find out the Maximum Subarray Sum in that Array.

Examples:
Input1 : arr = {-2, -3, 4, -1, -2, 1, 5, -3}
Output1 : 7

Input2 : arr = {4, -8, 9, -4, 1, -8, -1, 6}
Output2 : 9

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int MaximumSumSubarray(vector<int>& nums)
	{
		int max_so_far = nums[0];
		int max_end_here = nums[0];

		for (int i = 1; i < nums.size(); ++i)
		{
			if (max_end_here > 0)
			{
				max_end_here += nums[i];
			}
			else
			{
				max_end_here = nums[i];
			}
			if (max_so_far < max_end_here)
			{
				max_so_far = max_end_here;
			}
		}
		return max_so_far;
	}
};

int main()
{
	vector<int> nums1{ -2, -3, 4, -1, -2, 1, 5, -3 };
	vector<int> nums2{ 4, -8, 9, -4, 1, -8, -1, 6 };
	Solution sol;

	cout << sol.MaximumSumSubarray(nums1) << endl;
	cout << sol.MaximumSumSubarray(nums2) << endl;

	return 0;
}