/*
https://leetcode-cn.com/problems/longest-uncommon-subsequence-ii/
Longest Uncommon Subsequence II
Given a list of strings, you need to find the longest uncommon subsequence among them. 
The longest uncommon subsequence is defined as the longest subsequence of one of these strings 
and this subsequence should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence 
by deleting some characters without changing the order of the remaining elements. 
Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

The input will be a list of strings, and the output needs to be the 
length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.

Example 1:
Input: "aba", "cdc", "eae"
Output: 3
Note:

All the given strings' lengths will not exceed 10.
The length of the given list will be in the range of [2, 50].

*/

/*

给定字符串列表，你需要从它们中找出最长的特殊序列。最长特殊序列定义如下：该序列为某字符串独有的最长子序列（即不能是其他字符串的子序列）。
子序列可以通过删去字符串中的某些字符实现，但不能改变剩余字符的相对顺序。空序列为所有字符串的子序列，任何字符串为其自身的子序列。
输入将是一个字符串列表，输出是最长特殊序列的长度。如果最长特殊序列不存在，返回 -1 。
 
示例：
输入: "aba", "cdc", "eae"
输出: 3
 
提示：
所有给定的字符串长度不会超过 10 。
给定字符串列表的长度将在 [2, 50 ] 之间。

*/

#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution 
{
public:
    int findLUSlength(vector<string>& strs) 
    {
        int LUS = -1;
        for(int i = 0; i<strs.size(); ++i)
        {
            bool bSeq = false;
            for(int j = 0; j<strs.size(); ++j)
            {
                if(i == j) continue;
                if(IsSubSeq(strs[i], strs[j]))
                {
                    bSeq = true;
                    break;
                }
            }
            if(!bSeq)
            {
                LUS = max(LUS,(int)strs[i].size());
            }
        }
        return LUS;
    }
private:
    bool IsSubSeq(string& strSub, string& strSource) // check whether strSub is one sub-sequence of strSource
    {
       int i = 0;

       for(auto c:strSource)
       {
           if(c == strSub[i])
           {
               ++i;
           }
           if(strSub.size() == i)
           {
               break;
           }
       } 
       return i == strSub.size();
    }
};