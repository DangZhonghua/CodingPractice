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

		int sum = nums[0];
		int i = 0;
		int j = 1;
		int len = 0;
		while (i <j && j <= nums.size())
		{
			if (sum == s )
			{
				if ( 0== len || len > (j - i))
				{
					len = (j - i);
				}
				sum -= nums[i];
				sum += nums[j];
				++j;
				++i;
			}
			else if (sum < s)
			{
				if (j < nums.size())
				{
					sum += nums[j];
					++j;
				}
				else
				{
					sum -= nums[i];
					++i;
				}

			}
			else
			{
				sum -= nums[i];
				++i;
				if (sum == s && (0== len ||len > (j - i)))
				{
					len = (j - i);
				}
				if (sum < s|| i == j)
				{
					if (j < nums.size())
					{
						sum += nums[j];
						++j;
					}
				}

			}
		}
		return len;
	}
};

int main()
{
	Solution sol;
	vector<int> nums{ 2,3,1,2,4,3 };
	int s = 7;

	vector<int> num1{ 5,1,3,5,10,7,4,9,2,8 };
	s = 15;

	cout << sol.minSubArrayLen(s, num1) << endl;

	return 0;
}