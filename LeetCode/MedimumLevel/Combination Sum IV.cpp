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
using namespace std;

class Solution 
{
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        int N = nums.size();
        vector< vector<int> > dp(target+1, vector<int>(N+1,0));
        dp[0][0] = 1;

        for(int t = 1; t<=target; ++t)
        {
            for(int i = 1; i<=N; ++i)
            {
                if(t>=nums[i-1] &&  dp[t-nums[i-1]][i-1])
                {
                    dp[t][i] += dp[t-nums[i-1]][i-1];
                }
                else
                {
                    dp[t][i] = dp[t][i-1];
                }
            }
        }
        return dp[target][N];        
    }
};

int main()
{
    int target = 4;
    vector<int> nums{1, 2, 3};
    Solution sol;
    cout<<sol.combinationSum4(nums,target)<<endl;

    return 0;

}