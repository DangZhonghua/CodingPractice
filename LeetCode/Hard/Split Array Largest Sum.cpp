/*
https://leetcode-cn.com/problems/split-array-largest-sum/
Split Array Largest Sum
Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays. 
Note:
If n is the length of array, assume the following constraints are satisfied: 
1 ≤ n ≤ 1000
1 ≤ m ≤ min(50, n)

Examples: 
Input:
nums = [7,2,5,10,8]
m = 2

Output:
18

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.

*/

/*
use knapsnack technique to solve this.

https://segmentfault.com/a/1190000008377782

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) 
    {
        unsigned long long sum = 0;
        for(int e:nums)
        {
            sum += e;
        }
        sum /= m;
        vector<unsigned long long> vf(sum+1,0);
        for(int i = 1; i<= nums.size(); ++i)
        {
            
        }
    }
};