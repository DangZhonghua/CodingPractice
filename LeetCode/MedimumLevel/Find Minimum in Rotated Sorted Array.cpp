/*
https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/
Find Minimum in Rotated Sorted Array

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2]
Output: 1

Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0


*/

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	int findMin(vector<int>& nums)
	{
		int i = 0;
		int j = nums.size() - 1;

		while (i < j)
		{
			int m = (i + j) / 2;
			if (nums[m] > nums[j])
			{
                // this means, the minimum value must be in right side.
				i = m + 1;
			}
			else
			{
                // nums[m] is, possible, the minimum value, so use the "j = m";
				j = m;
			}
		}

		return nums[i];
	}
};

int main()
{
	vector<int> num1{ 3,1,2 };

	Solution sol;

	cout << sol.findMin(num1) << endl;
	return 0;
}