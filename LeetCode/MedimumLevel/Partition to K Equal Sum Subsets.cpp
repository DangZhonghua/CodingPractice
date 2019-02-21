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
    bool canPartitionKSubsets(vector<int>& nums, int k) 
    {
        int N = nums.size();
        int sum = 0;
        for(int n:nums)
        {
            sum += n;
        }
        int S = sum/k;
        vector< vector< vector<int> > >  dp(k, vector< vector<int> > (N+1, vector<int>(S+1, 0)));
        vector<bool>  vbit(N+1,false);
        for(int i = 0; i<k;++i)
        {
            dp[i][0][0] = 1;
        }
        int n = 0;
        for(n = 0; n<k; ++n)
        {
            for(int i = 1;i<=N; ++i)
            {
                for(int j = 1; j<=S; ++j)
                {
                    if(vbit[i] && j>=nums[i-1] && dp[n][i-1][j-nums[i-1]])
                    {
                         dp[n][i][j] = i;              
                    }
                }
            }
            int i = N;
            int j = S;
            while(dp[n][i][j] && j)
            {
                i = dp[n][i][j];
                j = j - nums[i-1];
            }
            if(0 != j)
            {
                break;
            }
        }
        
        return (n == k);
    }
};

int main()
{
    int k = 4;
    vector<int> nums{4, 3, 2, 3, 5, 2, 1};
    Solution sol;
    
    cout<<sol.canPartitionKSubsets(nums,k)<<endl;

    return 0;
}