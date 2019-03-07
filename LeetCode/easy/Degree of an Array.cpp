/*
https://leetcode-cn.com/problems/degree-of-an-array/
Degree of an Array

Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.
Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.

Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6

Note: 
nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.
*/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution 
{

    struct stRange
    {
        int count;
        int start;
        int end;
    };

public:
    int findShortestSubArray(vector<int>& nums) 
    {
       unordered_map<int,stRange> mapNum2Count;
       int degree = 1;

       for(int i = 0; i<nums.size(); ++i)
       {
           auto it = mapNum2Count.find(nums[i]);
           if(mapNum2Count.end() == it)
           {
               stRange r;
               r.start = i;
               r.end   = i;
               r.count = 1;
               mapNum2Count[nums[i]] = r;
           }
           else
           {
               it->second.end   = i;
               it->second.count += 1;
               if( it->second.count>degree)
               {
                   degree = it->second.count;
               }
           }
       }

       int minimumRange = nums.size() + 1;
       for(auto it = mapNum2Count.begin(); it != mapNum2Count.end(); ++it)
       {
           if(it->second.count == degree && (it->second.end-it->second.start+1)<minimumRange)
           {
               minimumRange = (it->second.end-it->second.start+1);
           }
       }
       return minimumRange;    
    }
};