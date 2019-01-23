/*

https://leetcode-cn.com/problems/longest-common-prefix/
Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
Example 1:
Input: ["flower","flow","flight"]
Output: "fl"
Example 2:
Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:
All given inputs are in lowercase letters a-z.

*/

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if(strs.size() == 0)
        {
            return "";
        }
        int minlen = strs[0].length();
        for(const string& str:strs)
        {
            if(minlen>str.length())
            {
                minlen = str.length();
            }
        }
       bool bPrefix  = true;
       int prelen = 0;
       int i = 0;
       while(bPrefix && i<minlen)
       {
          int p = strs[0][i]-'a';
          for(int j = 1; j<strs.size(); ++j)
          {
               if(p != strs[j][i]-'a')
               {
                   bPrefix = false;
                   break;
               }
           }
           if(bPrefix)
           {
              ++i;
               prelen = i;
           }
       }
       if(prelen)
       {
          return strs[0].substr(0,prelen);
       }
       else
       {
           return "";
       }
    }
};