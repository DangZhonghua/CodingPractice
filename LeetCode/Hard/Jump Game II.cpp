/*
Jump Game II
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
Example:
Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
Note:
You can assume that you can always reach the last index.

给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用最少的跳跃次数到达数组的最后一个位置。
示例:
输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
说明:
假设你总是可以到达数组的最后一个位置。

*/

#include<vector>
#include<iostream>
#include<climits>
using namespace std;


class Solution 
{
public:
    int jump(vector<int>& nums) 
    {
        vector<int> vmj(nums.size(),INT_MAX);
        vmj[0] = 0;
        
        for(int i = 0; i<nums.size(); ++i)
        {
            if(nums[i] &&  INT_MAX != vmj[i])
            {
                for(int j = 1; j<=nums[i]; ++j)
                {
                    if( (i+j)<nums.size())
                    {
                        if(vmj[i+j]>vmj[i]+1)
                        {
                            vmj[i+j] = vmj[i]+1;
                        }
                    }
                }
            }
        }
        return vmj[nums.size()-1];
    }

};

int main()
{
    vector<int> a{2,3,1,1,4};
    Solution sol;
    sol.jump(a);

    return 0;
}