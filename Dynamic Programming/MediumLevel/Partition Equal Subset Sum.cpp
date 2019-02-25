/*
https://leetcode-cn.com/problems/partition-equal-subset-sum/
Partition Equal Subset Sum

Given a non-empty array containing only positive integers, 
find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:

    Each of the array element will not exceed 100.
    The array size will not exceed 200.

Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.


*/

#include<vector>
#include<iostream>
using namespace std;

class Solution
{
public:
	bool canPartition(vector<int>& nums)
	{
		int S = 0;
		for (int e : nums)
		{
			S += e;
		}
		if (S & 1)
		{
			return false;
		}
		S /= 2;
		int N = nums.size();
		vector<vector<int> > dp(N + 1, vector<int>(S + 1, -1));

		dp[0][0] = 0;

		for (int i = 1; i <= N; ++i)
		{
			for (int s = 1; s <= S; ++s)
			{
				dp[i][s] = dp[i - 1][s];
				if (s >= nums[i - 1] && -1 != dp[i - 1][s - nums[i - 1]])
				{
					dp[i][s] = 1;
				}
			}
		}

		return (-1 != dp[N][S]);
	}
};

int main()
{
	vector<int> nums{ 1, 5, 11, 5 };
	Solution sol;
	sol.canPartition(nums);

	return 0;

}