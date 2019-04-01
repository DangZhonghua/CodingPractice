/*
 * @lc app=leetcode.cn id=791 lang=cpp
 *
 * [791] Custom Sort String
 *
 * https://leetcode-cn.com/problems/custom-sort-string/description/
 *
 * algorithms
 * Medium (60.33%)
 * Total Accepted:    1.3K
 * Total Submissions: 2.1K
 * Testcase Example:  '"cba"\n"abcd"'
 *
 * 字符串S和 T 只包含小写字符。在S中，所有字符只会出现一次。
 * 
 * S 已经根据某种规则进行了排序。我们要根据S中的字符顺序对T进行排序。更具体地说，如果S中x在y之前出现，那么返回的字符串中x也应出现在y之前。
 * 
 * 返回任意一种符合条件的字符串T。
 * 
 * 
 * 示例:
 * 输入:
 * S = "cba"
 * T = "abcd"
 * 输出: "cbad"
 * 解释: 
 * S中出现了字符 "a", "b", "c", 所以 "a", "b", "c" 的顺序应该是 "c", "b", "a". 
 * 由于 "d" 没有在S中出现, 它可以放在T的任意位置. "dcba", "cdba", "cbda" 都是合法的输出。
 * 
 * 
 * 注意:
 * 
 * 
 * S的最大长度为26，其中没有重复的字符。
 * T的最大长度为200。
 * S和T只包含小写字符。
 * 
 * 
 */


#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;


class Solution 
{
public:
    string customSortString(string S, string T) 
    {
        vector<int> vDict(26, 26);
        for(int i = 0; i<S.length(); ++i )
        {
            vDict[S[i]-'a'] = i;
        }
        auto fc = [&](char t1, char t2)-> bool
        {
            return vDict[t1-'a']<vDict[t2-'a'];
        };
        std::sort(T.begin(),T.end(),fc);
        return T;
    }
};

