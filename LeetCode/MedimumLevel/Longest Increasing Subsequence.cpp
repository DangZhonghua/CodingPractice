/*
https://leetcode-cn.com/problems/longest-increasing-subsequence/
Longest Increasing Subsequence
Given an unsorted array of integers, find the length of longest increasing subsequence.
Example:
Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note: 
There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?

*/

#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int maxlen = 1;
        vector<int> lenSmallest(nums.size()+1,0);
        lenSmallest[1] = nums[0];

        for(int i = 1; i<nums.size();++i)
        {
            
        }
    }

private:
    int findLargestWhichLessthanX(vector<int>&,int X, int Len)
    {
        
    }
};