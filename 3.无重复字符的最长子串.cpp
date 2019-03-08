/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.29%)
 * Total Accepted:    85.1K
 * Total Submissions: 300.3K
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 */

/*
Sliding window technique

*/


#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;


class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char, int> mapChar2Count;
        int i = -1; //i+1 is the first char of the slide windows
        int j = 0;
        int L = s.length();
        int maxSliceLen = 0;

        while( j< L)
        {
            mapChar2Count[s[j]] += 1;
            if(mapChar2Count[s[j]] > 1 ) // we need narrow the window
            {
                while(mapChar2Count[s[j]] > 1)
                {
                    ++i;
                    mapChar2Count[s[i]] -= 1;
                }
            }
            else
            {
                if(maxSliceLen< j-i)
                {
                    maxSliceLen = j-i;
                }
            }
             ++j;
        }
        return maxSliceLen;
    }
};

