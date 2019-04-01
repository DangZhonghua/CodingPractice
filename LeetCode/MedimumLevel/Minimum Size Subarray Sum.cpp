/*
https://leetcode-cn.com/problems/minimum-size-subarray-sum/

Minimum Size Subarray Sum

Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
Example:
Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).

*/

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int minSubArrayLen(int s, vector<int>& nums)
	{
		if (nums.empty())
		{
			return 0;
		}

		int N = nums.size();
		int sum = nums[0];
		int i	= 0;
		int j	= 1;
		int len = N+1;
		while (i < j && j < N)
		{
			if (s > sum)
			{
				sum += nums[j];
				++j;
			}
			else
			{
				if (len > (j - i))
				{
					len = (j - i);
				}
				sum -= nums[i];
				++i;
				//++j; keep j unchanged.
			}
		}

		while (sum >= s)
		{
			if (len > (j - i))
			{
				len = (j - i);
			}
			sum -= nums[i++];
		}


		return len=( (len==(N+1))?0:len);
	}
};

// O(n)
//class Solution {
//public:
//	int minSubArrayLen(int s, vector<int>& nums) 
//	{
//		if (nums.empty()) return 0;
//		int left = 0, right = 0, sum = 0, len = nums.size(), res = len + 1;
//		while (right < len) {
//			while (sum < s && right < len) 
//			{
//				sum += nums[right++];
//			}
//			while (sum >= s) 
//			{
//				res = min(res, right - left);
//				sum -= nums[left++];
//			}
//		}
//		return res == len + 1 ? 0 : res;
//	}
//};

int main()
{
	Solution sol;
	vector<int> nums{ 2, 3, 1, 2, 4, 3 };
	int s = 7;

	//cout << sol.minSubArrayLen(s, nums) << endl;

	vector<int> num1{ 5, 1, 3, 5, 10, 7, 4, 9, 2, 8 };
	s = 15;

	//cout << sol.minSubArrayLen(s, num1) << endl;

	s = 11;
	vector<int> num2{ 1, 2, 3, 4, 5 };
	
	cout << sol.minSubArrayLen(s, num2) << endl;

	return 0;
}