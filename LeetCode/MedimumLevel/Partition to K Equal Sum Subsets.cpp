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
#include<stack>
using namespace std;

class Solution
{
public:
	bool canPartitionKSubsets(vector<int>& nums, int K)
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
		vector< vector<int> > vs(N + 1, vector<int>(S + 1, 0));
		vector< vector<int> > vi(S + 1, vector<int>());
		vector< bool > vBits(N + 1, false);

		m_S = S;
		m_K = K;

		for (int i = 0; i <= N; ++i)
		{
			vs[i][0] = 1;
		}

		for (int i = 1; i <= N; ++i)
		{
			for (int s = 1; s <= S; ++s)
			{
				vs[i][s] = vs[i - 1][s];
				if (s >= nums[i - 1] && vs[i - 1][s - nums[i - 1]])
				{
					vs[i][s] += 1;
					vi[s].push_back(i);
				}
			}
		}
		int count = 0;
		return findKPartitionSubsets(nums, vBits, vi, S, count);
	}

	bool findKPartitionSubsets(vector<int>& nums, vector<bool>& vBits, vector< vector<int> >& vi, int S, int & count)
	{
		for (int i = 0; i < vi[S].size(); ++i)
		{
			if (!vBits[vi[S][i]])
			{
				vBits[vi[S][i]] = true;
				int NS = S-nums[vi[S][i] - 1];
				if (0 == NS)
				{
					++count;
				}
				if (m_K == count)
				{
					return true;
				}

				if (findKPartitionSubsets(nums, vBits, vi, NS ? NS : m_S, count))
				{
					return true;
				}
				if (0 == NS)
				{
					--count;
				}
				vBits[vi[S][i]] = false;
			}
		}
		return false;
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

	//cout << sol.canPartitionKSubsets(nums4, k) << endl;

	vector<int> nums5{ 4, 5, 3, 2, 5, 5, 5, 1, 5, 5, 5, 5, 3, 5, 5, 2 };
	k = 13;
	cout << sol.canPartitionKSubsets(nums4, k) << endl;
	return 0;
}