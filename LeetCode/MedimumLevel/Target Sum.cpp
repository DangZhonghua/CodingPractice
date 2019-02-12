/*
https://leetcode-cn.com/problems/target-sum/
Target Sum
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S.
Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:

Input: nums is [1, 1, 1, 1, 1], S is 3.
Output: 5
Explanation:

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.

Note:

The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.


*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S)
	{
		int sum = 0;
		for (auto a : nums)
		{
			sum += a;
		}
		//the following are used to record the way count for every value
		vector< vector<int> > pw(nums.size() + 1, vector<int>(sum + 1, 0));
		vector< vector<int> > nw(nums.size() + 1, vector<int>(sum + 1, 0));

		//Initialize the state
		pw[0][nums[0]] = 1; // "+" case
		if (nums[0] >= 0)
		{
			nw[0][nums[0]] = 1; // "-" case
		}

		for (int i = 1; i < nums.size(); ++i)
		{
			for (int s = 0; s <= sum; ++s)
			{

				// for "+" case
				if ((s + nums[i]) <= sum)
				{
					pw[i][s + nums[i]] += pw[i - 1][s];
				}

				int t = (nums[i] - s);
				if (t >= 0)
				{
					pw[i][t] += nw[i - 1][s];
				}
				else
				{
					nw[i][-t] += nw[i - 1][s];
				}


				// for "-" case

				t = s - nums[i];
				if (t >= 0)
				{
					pw[i][t] += pw[i - 1][s];
				}
				else
				{
					nw[i][-t] += pw[i - 1][s];
				}

				t = -s - nums[i];
				if (t >= -sum)
				{
					nw[i][-t] += nw[i - 1][s];
				}
			}
		}
		int wc = 0;
		if (S > sum || S<-sum)
		{
			wc = 0;
		}
		else
		{
			wc = pw[nums.size() - 1][S];
			if (S < 0)
			{
				wc = nw[nums.size() - 1][-S];
			}
			else if (0 == S)
			{
				wc += nw[nums.size() - 1][-S];
			}
		}
		return wc;
	}
};


int main()
{
	vector<int> nums1{ 1, 1, 1, 1, 1 };
	int S = 3;
	Solution sol;

	//cout << sol.findTargetSumWays(nums1, S) << endl;

	vector<int> nums2{ 1000 };
	S = -1000;
	
	//cout << sol.findTargetSumWays(nums2, S) << endl;

	vector<int> nums3{ 0, 0, 0, 0, 0, 0, 0, 0, 1 };
	S = 1;
	cout << sol.findTargetSumWays(nums3, S) << endl;


	return 0;
}