/*
https://leetcode-cn.com/problems/rotate-array/
Rotate Array
Given an array, rotate the array to the right by k steps, where k is non-negative.
Example 1:
Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:
Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?

*/
#include<iostream>
#include<vector>
using namespace std;

/*
Find the exchgange range, the step the range.
use the short part exchange with the same length of longer part.

*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int len = nums.size();
        
        k %= len;
        if(0 == k)
        {
            return;
        }

        int ke = nums.size()-1;
        int ks = ke-k + 1;
        
        int se = ks+1;
        int ss = ks-k;
        while(ss>=0) //handle these middle parts rotate
        {
            for(int i = ss; i<= se; ++i)
            {
                int t = nums[i];
                nums[i] = nums[k+i];
                nums[k+i] = t;
            }
            ke = 
        }
        //handle the last part rotate
        {

        }

        



    }
};