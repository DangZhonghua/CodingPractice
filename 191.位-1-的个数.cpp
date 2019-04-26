/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */
class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        uint32_t d = 1;
        int i = 0;
        int count = 0;
        while(i<32)
        {
            if( n& d)
            {
                ++count;
            }
            d <<=1;
            ++i;
        }
        return count;   
    }
};

