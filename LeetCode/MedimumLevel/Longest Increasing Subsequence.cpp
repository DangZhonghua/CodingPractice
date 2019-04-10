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

/*
 for some certain length, use the smallest elements
 
 for arrLen[], the index is the length, its elements are increasing order

*/

#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        if(nums.empty())
        {
            return 0;
        }
        int maxlen = 1;
        vector<int> lenSmallest(nums.size()+1,0);
        lenSmallest[1] = nums[0];

        for(int i = 1; i<nums.size();++i)
        {
            bool bFind = false;
            int index = findLargestWhichLessthanX(lenSmallest,nums[i],maxlen,bFind);
            if(!bFind)
            {
                lenSmallest[index] = nums[i]; // use the smaller update the same length 
                if(index>maxlen)
                {
                    maxlen = index;
                }
            }
        }
        
        return maxlen;
    }

private:
    int findLargestWhichLessthanX(vector<int>&lis,int X, int Len,bool& bFind)
    {
        int i = 1;
        int j = Len;
        int index = -1;
        bFind = false;
        while(i<=j)
        {
            int m = (i+j)/2;
            if(lis[m] == X)
            {
                bFind = true;
                break;
            }
            else if(lis[m]>X)
            {
                j = m-1;
            }
            else
            {
                i = m+1;
            }
        }
        if(-1 == index )
        {
            index = i;
        }
        return index;
    }
};