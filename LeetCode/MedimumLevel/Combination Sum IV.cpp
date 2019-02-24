/*
https://leetcode-cn.com/problems/combination-sum-iv/
Combination Sum IV

 Given an integer array with all positive numbers and no duplicates, find the number of possible combinations
 that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.


*/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

 class Solution 
 {
 public:
     int combinationSum4(vector<int>& nums, int target) 
     {
		 int N = nums.size();
		 vector< vector<unsigned long long> > dp(target + 1, vector<unsigned long long>(N + 1, 0));
		 for (int i = 0; i <= N; ++i)
		 {
			 dp[0][i] = 1;
		 }
		 std::sort(nums.begin(), nums.end());

		 for (int s = 1; s <= target; ++s)
		 {	
			 for (int i = 1; i <= N; ++i)
			 {	
				 dp[s][i] = dp[s][i - 1]; // for current s, keep the number which use only i-1 elements
				 if (s >= nums[i - 1])
				 {
					// dp[s - nums[i - 1]][i] = dp[s - nums[i - 1]][N]; //.
					 dp[s][i] += dp[s - nums[i - 1]][N]; // s-nums[i] use N elements
				 }
			 }
		 }

		 return dp[target][N];
     }
 };


// the following is correct,also


//class Solution {
//public:
//	int combinationSum4(vector<int>& nums, int target)
//	{
//		vector<unsigned long long> v(target + 1);
//		v[0] = 1;
//		sort(nums.begin(), nums.end());
//		for (int i = 1; i < target + 1; i++)
//		{
//			for (int j = 0; j < nums.size(); j++)
//			{
//				if (nums[j] <= i)
//				{
//					v[i] += v[i - nums[j]];
//				}
//			}
//		}
//
//		return v[target];
//	}
//
//};

int main()
{
	int target = 4;
	vector<int> nums{ 1, 2, 3 };
	Solution sol;
	cout << sol.combinationSum4(nums, target) << endl;

	return 0;

}