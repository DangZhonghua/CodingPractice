/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 求众数
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (57.48%)
 * Total Accepted:    22.5K
 * Total Submissions: 39.2K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 * 
 * 你可以假设数组是非空的，并且给定的数组总是存在众数。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,3]
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: [2,2,1,1,1,2,2]
 * 输出: 2
 * 
 * 
 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        unordered_map<int,int> dict;
        int N = nums.size();
        for(int i = 0; i<N; ++i )
        {
          dict[nums[i]] += 1;
        }
        int v = 0;
        for(auto it = dict.begin(); it != dict.end();++it)
        {
            if( it->second > (N/2))
            {
                v = it->first;
                cout<<v<<endl;
                break;
            }
        }
        return v;
    }
};

