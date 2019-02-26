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
#include<algorithm>
using namespace std;

class Solution
{
public:
	bool canPartitionKSubsetsDP(vector<int>& nums, int K)
	{
		std::sort(nums.begin(), nums.end());
		bool bPartition = true;
		int S = 0;
		bPartition = CalAverage(nums, S, K);
		if (!bPartition)
		{
			return bPartition;
		}

		int N = nums.size();
		vector< vector< vector<int> > > dp(K, vector< vector<int > >(N + 1, vector<int>(S + 1, -1)));
		vector<bool> vBits(N + 1, false);

		for (int k = 0; k < K; ++k)
		{
			for (int i = 0; i <= N; ++i)
			{
				dp[k][i][0] = 0;
			}
		}

		for (int k = 0; k < K; ++k)
		{
			dp[k][0][0] = 0;

			for (int i = 1; i <= N; ++i)
			{
				for (int s = 1; s <= S; ++s)
				{

					if (!vBits[i] && s >= nums[i - 1] && -1 != dp[k][i - 1][s - nums[i - 1]])
					{
						dp[k][i][s] = i;
					}
					else
					{
						dp[k][i][s] = dp[k][i - 1][s];
					}
				}
			}
			if (-1 == dp[k][N][S])
			{
				bPartition = false;
				break;
			}
			
			int m = S;
			int j = dp[k][N][S];
			while (m && j)
			{
				cout << nums[j - 1] << " ";
				vBits[j] = true;
				m -= nums[j - 1];
				j = dp[k][j-1][m];
			}
			cout << endl;
		}

		return bPartition;
	}
	bool canPartitionKSubsets(vector<int>& nums, int K)
	{
		
	}

	bool PartitionKSubsets(vector<int>& nums, vector<bool>& vBits, vector< vector<int> > vsets, int k, vector<int>& vsum)
	{
		if (k = m_K)
		{
			return true;
		}
		for (int i = 0; i < nums.size(); ++i)
		{
			if (!vBits[i])
			{
				vsum[k] += nums[i];
				if (vsum[k] == m_S)
				{
					vBits[i] = true;	
				}
			}
		}
	}

private:
	bool CalAverage(vector<int>& nums, int& S, int K)
	{
		int sum = 0;
		for (int e : nums)
		{
			sum += e;
		}
		if (sum % K)
		{
			return false;
		}
		S = sum / K;
		return true;
	}
private:
	int m_S{ 0 };
	int m_K{ 0 };
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
	//cout << sol.canPartitionKSubsets(nums2, k) << endl;


	vector<int> nums3{ 2, 2, 2, 2, 3, 4, 5 };
	k = 4;


	//cout << sol.canPartitionKSubsets(nums3, k) << endl;


	vector<int> nums4{ 10, 10, 10, 7, 7, 7, 7, 7, 7, 6, 6, 6 };
	k = 3;

	cout << sol.canPartitionKSubsets(nums4, k) << endl;

	return 0;
}