/*
https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/
Find Minimum in Rotated Sorted Array II
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1

Example 2:

Input: [2,2,2,0,1]
Output: 0

Note:

    This is a follow up problem to Find Minimum in Rotated Sorted Array.
    Would allow duplicates affect the run-time complexity? How and why?

[1,3,3]
[3,3,1,3]
[10,1,10,10,10]


*/

#include<vector>
#include<iostream>
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
                //for handle duplicate elements:since in this case, we can't judge, which direction should be chosed, so chose "both"
                if(nums[j] == nums[m] && nums[i]==nums[j])
                {
                    i +=1;
                    j -= 1;
                }
                else
                {
                    // nums[m] is, possible, the minimum value, so use the "j = m";
                    j = m;
                }
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