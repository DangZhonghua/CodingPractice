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
#include <algorithm>
using namespace std;

class Solution
{
public:
	bool canPartitionKSubsets(vector<int>& nums, int K)
	{
		std::sort(nums.begin(), nums.end());
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
		vector< vector<int> >  vpart(K, vector<int>(S + 1, -1));
		vector< bool > vBits(N + 1, false);

		for (int k = 0; k < K; ++k)
		{
			vpart[k][0] = 0;
		}

		for (int k = 0; k<K; ++k)
		{
			vector<int> vcBits(N + 1, false);
			for (int i = 1; i <= N; ++i)
			{
				if (vBits[i] || vcBits[i])
				{
					continue;
				}
				for (int s = 1; s <= S; ++s)
				{
					if (!vcBits[i]  && s >= nums[i - 1] && -1 != vpart[k][s - nums[i - 1]])
					{
						vpart[k][s] = i;
						vcBits[i] = true;
					}
				}
			}

			if (-1 == vpart[k][S])
			{
				bPartition = false;
				break;
			}

			int s = S;
			int j = 0;
			while (s)
			{
				j = vpart[k][s];
				s -= nums[j - 1];
				vBits[j] = true;
				cout << nums[j - 1] << " ";
			}
			cout << endl;
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


	vector<int> nums3{ 4, 5, 3, 2, 5, 5, 5, 1, 5, 5, 5, 5, 3, 5, 5, 2 };

	//{ 4,  3, 2, 1, 3, 2 }
	k = 13;

	//vector<int> nums4{ 7, 2, 2, 2, 2, 2, 2, 2, 3 };
	//k = 3;

	//cout << sol.canPartitionKSubsets(nums4, k) << endl;

	return 0;
}