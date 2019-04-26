/*
https://leetcode-cn.com/problems/split-array-into-consecutive-subsequences/
Split Array into Consecutive Subsequences

You are given an integer array sorted in ascending order (may contain duplicates), you need to split them into several subsequences, 
where each subsequences consist of at least 3 consecutive integers. Return whether you can make such a split.
Example 1:
Input: [1,2,3,3,4,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3
3, 4, 5

Example 2:
Input: [1,2,3,3,4,4,5,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3, 4, 5
3, 4, 5

Example 3:
Input: [1,2,3,4,4,5]
Output: False

Note:
The length of the input is in range of [1, 10000]

*/
//d
#include<vector>
using namespace std;


/*

This actuall: find the longest subarray of duplicated elements

*/


class Solution 
{
public:
    bool isPossible(vector<int>& nums) 
    {
        if(nums.size()<3)
        {
            return false;
        }

        int len = 1;
        int maxlen = 0;
        int N = nums.size();
        int pre = nums[0];

        for(int i = 1; i< N; ++i)
        {
            if(pre == nums[i])
            {
                ++len;
            }
            else
            {
                if(len>maxlen)
                {
                    maxlen = len;
                }
                pre = nums[i];
                len = 1;     
            }
        }
        if(  0 == N%maxlen )
        {
            return true;
        }
        
        return false;
    }
};
