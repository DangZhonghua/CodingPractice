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

https://www.geeksforgeeks.org/find-subarray-with-given-sum/
*/

/*

use hash map to store every subarray sum.

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
        unordered_map<int,int> map_sum_count;
        int N   = nums.size();
        int sum = 0;
        for(int i = 0; i<N;++i)
        {
            sum += nums[i];
            int d = sum-k;
            
            if(map_sum_count[d])
            {
                count += map_sum_count[d];
            }
            map_sum_count[sum] += 1;
        }
        return count+map_sum_count[k];
    }
};

