/*
https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/
Number of Longest Increasing Subsequence

Given an unsorted array of integers, find the number of longest increasing subsequence.
Example 1:
Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].

Example 2:
Input: [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.

Note: Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit signed int.
*/

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	int findNumberOfLIS(vector<int>& nums)
	{
		vector<int> lis(nums.size(), 1);
		vector<int> lc(nums.size(), 1);

		int maxlen = !nums.empty();
		for (int i = 1; i < nums.size(); ++i)
		{
			bool bUpdate = false;
			for (int j = 0; j < i; ++j)
			{
				if (nums[i] > nums[j] && lis[i] <= (lis[j] + 1)) //  "<=" is the most important
				{

					if (lis[i] < lis[j] + 1)
					{
						lc[i] = lc[j];
					}
					else
					{
						lc[i] += lc[j];
					}
					lis[i] = lis[j] + 1;
				}
			}
			if (lis[i] > maxlen)
			{
				maxlen = lis[i];
			}
		}

		int count = 0;

		for (int i = 0; i < lis.size(); ++i)
		{
			if (maxlen == lis[i])
			{
				count += lc[i];
			}
		}

		return count;
	}
};

int main()
{
	vector<int> a{ 1,3,5,4,7 };
	vector<int> b{ 2,2,2,2,2 };
	vector<int> c{ 1,2,4,3,5,4,7,2 };

	Solution sol;

	cout << sol.findNumberOfLIS(a) << endl;

	cout << sol.findNumberOfLIS(b) << endl;

	cout << sol.findNumberOfLIS(c) << endl;

	return 0;
}