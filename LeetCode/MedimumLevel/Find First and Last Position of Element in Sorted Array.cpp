/*
https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

*/

#include<vector>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target)
	{
		int index = -1;
		int i = 0;
		int j = nums.size() - 1;
		vector<int> vr(2, -1);
		bool bFind = false;
		index = SearchTarget(nums, target, i, j, 2);

		if (-1 != index)
		{
			vr[0] = index;
			vr[1] = index;
			int leftindex = -1;
			int rightindex = -1;
			leftindex = SearchTarget(nums, target, i, index - 1, 0);
			rightindex = SearchTarget(nums, target, index + 1, j, 1);
			if (-1 != leftindex)
			{
				vr[0] = leftindex;
			}
			if (-1 != rightindex)
			{
				vr[1] = rightindex;
			}
		}


		return vr;
	}
private:
	int SearchTarget(vector<int>& nums, int target, int s, int e, int direct)
	{
		int index = -1;
		while (s <= e)
		{
			int m = (s + e) / 2;
			if (nums[m] == target)
			{
				if (0 == direct)
				{
					
					if (-1 != index && index > m)
					{
						index = m;
					}
					else if( -1 == index)
					{
						index = m;
					}
					e = m - 1;
				}
				else if (1 == direct)
				{
					if (-1 != index && index < m)
					{
						index = m;
					}
					else if( -1 ==index)
					{
						index = m;
					}
					s = m + 1;
				}
				else
				{
					index = m;
					break;
				}
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
		// if(bFind)
		// {
		//     if(0==direct)
		//     {
		//         index = e+1;
		//     }
		//     if(1 == direct)
		//     {
		//         index = s-1;
		//     }
		// }
		return index;
	}
};


int main()
{
	vector<int> a{ 5,7,7,8,8,10 };
	int target = 8;
	Solution sol;

	vector<int> b{1, 1, 1, 1, 1, 1, 2, 3, 4, 4, 5, 5, 5, 6, 7, 8, 8, 8, 8};


	sol.searchRange(b, target);

	return 0;
}