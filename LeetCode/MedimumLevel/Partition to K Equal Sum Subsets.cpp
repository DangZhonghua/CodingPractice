/*
https://leetcode-cn.com/problems/partition-to-k-equal-sum-subsets/
Partition to K Equal Sum Subsets

Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into
k non-empty subsets whose sums are all equal.



Example 1:

Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.



Note:

	1 <= k <= len(nums) <= 16.
	0 < nums[i] < 10000.

*/


#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	bool canPartitionKSubsets(vector<int>& nums, int K)
	{
		bool bPartition = true;
		int S = 0;
		for (int e : nums)
		{
			S += e;
		}
		if (S%K)
		{
			return false;
		}
		S /= K;

		int N = nums.size();

		vector<int> a = nums;
		for (int k = 0; k < K; ++k)
		{
			N = a.size();
			vector< vector<int>> dp(N + 1, vector<int>(S + 1, -1));
			for (int i = 0; i <= N; ++i)
			{
				dp[i][0] = 0;
			}
			

			for (int i = 1; i <= N; ++i)
			{
				for (int s = 1; s <= S; ++s)
				{
					dp[i][s] = dp[i - 1][s];
					if (s >= a[i - 1] && -1 != dp[i - 1][s - a[i - 1]])
					{
						dp[i][s] = i;
					}
				}
			}

			if (-1 == dp[N][S])
			{
				bPartition = false;
				break;
			}

			vector<bool> vbits(N + 1, false);
			int m = S;
			int j = dp[N][m];
			while (m)
			{
				vbits[j] = true;
				m = m - a[j - 1];
				j = dp[j-1][m];
			}
			vector<int> b;
			for (int j = 1; j <= N; ++j)
			{
				if (!vbits[j])
				{
					b.push_back(a[j - 1]);
				}
			}
			a = b;
		}

		return bPartition;

	}
};

int main()
{
	int k = 4;
	vector<int> nums{ 4, 3, 2, 3, 5, 2, 1 };
	Solution sol;

	//cout << sol.canPartitionKSubsets(nums, k) << endl;

	k = 3;
	vector<int> nums1{ 2, 2, 10, 5, 2, 7, 2, 2, 13 };

	vector<int> nums2{ 4, 3, 2, 3, 5, 2, 1 };
	k = 4;



	cout << sol.canPartitionKSubsets(nums2, k) << endl;

	return 0;
}