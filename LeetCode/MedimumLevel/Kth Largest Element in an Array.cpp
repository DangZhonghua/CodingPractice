/*

https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
Kth Largest Element in an Array

Find the kth largest element in an unsorted array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
Example 1:
Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:
Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.

*/

/*
use order statistical to do this, let's use decreasing order
*/


#include<iostream>
#include<vector>
using namespace std;


class Solution
{
public:
	int findKthLargest(vector<int>& nums, int k)
	{
		int Start = 0;
		int End = nums.size() - 1;

		while (Start <= End)
		{
			int p = Partition(nums, Start, End);

			//count the larger element: p-Start+1
			if ((p - Start + 1) > k)
			{
				End = p - 1;
			}
			else if ((p - Start + 1) == k)
			{
				return nums[p];
			}
			else
			{
				k = k - (p - Start + 1);
				Start = p + 1;
			}
		}

		return 0;

	}

private:
	//return pivot position
	int Partition(vector<int>& nums, int start, int end)
	{
		int i = start - 1;
		int j = i + 1;
		int p = nums[end];
		while (j < end)
		{
			if (nums[j] > p)
			{
				++i;
				int t = nums[i];
				nums[i] = nums[j];
				nums[j] = t;
			}
			++j;
		}
		++i;
		nums[j] = nums[i];
		nums[i] = p;
		return  i;
	}
};

int main()
{
	Solution sol;
	int K = 2;
	vector<int> nums1{ 3, 2, 1, 5, 6, 4 };

	cout << sol.findKthLargest(nums1, K) << endl;

	return 0;

}