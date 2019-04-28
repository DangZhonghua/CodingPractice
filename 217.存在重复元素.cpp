/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_map<int,int> dict;
        int N       = nums.size();
        bool bDe    = false;

        for(int i = 0; i<nums.size(); ++i)
        {
            dict[nums[i]] += 1;
            if(dict[nums[i]]>=2)
            {
                bDe = true;
            }
        }
        return bDe;
    }
};

