/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 *
 * https://leetcode-cn.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (44.77%)
 * Total Accepted:    256.4K
 * Total Submissions: 572.8K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 * 
 * 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
 * 
 * 示例:
 * 
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 * 
 * 
 */
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,vector<int>> mapNum2Index;
        for(int i = 0; i<nums.size(); ++i)
        {
            mapNum2Index[nums[i]].push_back(i);
        }
        std::sort(nums.begin(),nums.end());
        int i = 0;
        int j = nums.size()-1;
        vector<int> vr;
        while(i<j)
        {
            int t = nums[i] + nums[j];
            if(t == target)
            {
                vr.push_back(*mapNum2Index[nums[i]].begin());
                vr.push_back(*mapNum2Index[nums[j]].rbegin());
                break;
            }
            else if(t<target)
            {
                ++i;
            }
            else
            {
                --j;
            }
        } 

        if(vr[0]>vr[1])
        {
         int t = vr[0];
         vr[0] = vr[1];
         vr[1] = t;
        }
        return vr;   
    }
};

