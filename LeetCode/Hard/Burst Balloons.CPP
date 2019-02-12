/*
https://leetcode-cn.com/problems/burst-balloons/
Burst Balloons
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. 
You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. 
Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:

    You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
    0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:

Input: [3,1,5,8]
Output: 167 
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167


*/

/*

which ballon should be bursted firstly? we don't know, so we try every possible.
coin[i,j] = max{ coin[i,k-1] + nums[k-1]*nums[k]* nums[k+1] + coin[k+1,j] }
This is dynamic programming: this is similar with matrix chain muliply problem.

*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) 
    {
        int N = nums.size();
        vector< vector<int> > maxCoins(N+2, vector<int> (N+2,0));
        
        for(int i = 1; i<=N; ++i)
        {
            maxCoins[i][i] = nums[i-1];
        }

        for(int L = 1; L<=N; ++L)
        {
            for(int i = 1; i<= N-L; ++i)
            {
                int j = i+L-1; //calculate coin[i,j]
                for(int k = i; k<=j; ++k)
                {

                }
            }   
        }
    }
};