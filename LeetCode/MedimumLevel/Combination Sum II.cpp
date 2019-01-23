/*
https://leetcode-cn.com/problems/combination-sum-ii/
Combination Sum II

Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.
Each number in candidates may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:
Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]

*/


/*

This is 0-1 knapsnack problem

*/


#include<string>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        int R = candidates.size();
        vector< vector<bool> > dp(R+1, vector<bool>(target+1, false));
        dp[0][0] = true;
        
        for( int i = 0; i<=target; ++i)
        {
            dp[0][i] = true;
        }
        
    }
};