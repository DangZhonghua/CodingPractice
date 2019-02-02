/*
https://leetcode-cn.com/problems/word-break/
Word Break
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
determine if s can be segmented into a space-separated sequence of one or more dictionary words.
Note:
The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:
Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:
Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:
Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

*/


#include<iostream>
#include<string>
#include<vector>
using namespace std;





class Solution 
{
    struct TreeItem
    {
        int c;
        struct TreeItem* next;
    };
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        vector<bool> sb(s.length(),false);
        for(int i = 0; i<s.length();++i)
        {
            for(int j = 0;j<s.length(); ++j)
               
        }



    }
private:
    bool SearchDict(vector<string>& wordDict, const char* szWord)
    {
        for(string& str:wordDict)
        {
            if(!strcmp(str.c_str(),szWord))
            {
                return true;
            }
        }
        return false;
    } 

private:
    
};