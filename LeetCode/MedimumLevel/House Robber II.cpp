/*
https://leetcode-cn.com/problems/house-robber-ii/
House Robber II

You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. 
That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security 
system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.

Example 2:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.

Since House[1] and House[n] are adjacent, they cannot be robbed together. 
Therefore, the problem becomes to rob either House[1]-House[n-1] or House[2]-House[n], 
depending on which choice offers more money. 
Now the problem has degenerated to the House Robber, which is already been solved.

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
public:
	int rob(vector<int>& nums)
	{
		if (nums.empty())
		{
			return 0;
		}
		if (nums.size() == 1)
		{
			return nums[0];
		}
		if (nums.size() == 2)
		{
			return max(nums[0], nums[1]);
		}

		int maxs = robInternal(nums.data(), nums.size() - 1);
		int maxe = robInternal(nums.data() + 1, nums.size() - 1);

		return max(maxs, maxe);
	}
private:
	int robInternal(const int*a, int N)
	{
		vector<int> vr(N + 1, 0);
		if (1 == N)
		{
			return a[0];
		}
		if (2 == N)
		{
			return max(a[0], a[1]);
		}

		vr[0] = a[0];
		vr[1] = max(a[0], a[1]);

		for (int i = 2; i < N; ++i)
		{
			vr[i] = vr[i - 2] + a[i];
			if (vr[i] < vr[i - 1])
			{
				vr[i] = vr[i - 1];
			}
		}
		return vr[N - 1];
	}
};