/*
https://leetcode-cn.com/problems/subarray-sum-equals-k/
560. Subarray Sum Equals K
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
Example 1:
Input:nums = [1,1,1], k = 2
Output: 2

Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].


*/


#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;



class Solution 
{
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int count = 0;
        unordered_map<int,int> map_reminder_count;
        int N = nums.size();
        int sum = 0;
        for(int i = 0; i<N;++i)
        {
            sum += nums[i];
            int r =( (k == 0)?sum:sum%k);
            if(map_reminder_count[r])
            {
                count += map_reminder_count[r];
                map_reminder_count[r] += 1;
                
            }
            else
            {
                map_reminder_count[r] = 1;
            } 
        }
        return count + map_reminder_count[0];
    }
};

