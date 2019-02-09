/*
https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
Search in Rotated Sorted Array

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target)
	{
		int i = 0;
		int j = nums.size() - 1;
		int index = -1;

		if (nums.empty())
		{
			return index;
		}

		if (nums[0] <= nums[nums.size() - 1])
		{
			return BinarySearch(nums, target, 0, nums.size() - 1);
		}
		
		while (i <= j)
		{
			int m = (i + j) / 2;
			
			if (nums[m] == target)
			{
				index = m;
				break;
			}
			else if (nums[m] < target)
			{
				if (nums[m] >= nums[j])
				{
					i = m + 1;
				}
				else
				{
					if (nums[j] >= target)
					{
						i = m + 1;
					}
					else
					{
						j = m - 1;
					}	
				}
			}
			else // nums[m]>target
			{
				if (nums[m] < nums[j])
				{
					j = m - 1;
				}
				else
				{
					if (target > nums[j])
					{
						j = m - 1;
					}
					else
					{
						i = m + 1;
					}
				}
			}
		}

		return index;
		
	}
private:
	int BinarySearch(vector<int>& nums, int target, int s, int e)
	{
		int index = -1;
		while (s <= e)
		{
			int m = (s + e) / 2;
			if (nums[m] == target)
			{
				index = m;
				break;
			}
			else if (nums[m] < target)
			{
				s = m + 1;
			}
			else
			{
				e = m - 1;
			}
		}
		return index;
	}
};

int main()
{
	vector<int> num1{ 4,5,6,7,0,1,2 };
	int target = 0;

	vector<int> num2{5, 1,3};

	vector<int> num3{ 3,1 };
	Solution sol;
	
	target = 0;
	//sol.search(num1, target);
	target = 5;
	//sol.search(num2, target);
	target = 1;
	sol.search(num3, target);

	vector<int> num4{ 1,3 };
	//sol.search(num4, 1);
	
	return 0;
}