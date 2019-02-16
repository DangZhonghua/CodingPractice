/*
https://leetcode-cn.com/problems/is-subsequence/submissions/
Is Subsequence
 Given a string s and a string t, check if s is subsequence of t.

You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
s = "abc", t = "ahbgdc"

Return true.

Example 2:
s = "axc", t = "ahbgdc"

Return false.

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.

*/


/*

             lcs[i-1][j-1] + 1; if x[i] == y[j]
lcs[i][j] =  
             lcs[i][j-1]  if x[i] != y[j]

*/

#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution 
{
public:
    bool isSubsequence(string s, string t) 
    {
        int N = s.length();
        int M = t.length();
        vector< vector<bool> > lcs(2, vector<bool>(N+1,false));
        lcs[0][0] = true; // two empty string is satisfied
        lcs[1][0] = true;
        
        for(int i = 1; i<=M; ++i)
        {
            for(int j = 1; j<=N; ++j)
            {
                if(t[i-1] == s[j-1])
                {
                    lcs[i&1][j] = lcs[(i-1)&1][j-1];    
                }
                else
                {
                    lcs[i&1][j] = lcs[(i-1)&1][j];
                }
            }
        }
        return lcs[M&1][N];
    }
};