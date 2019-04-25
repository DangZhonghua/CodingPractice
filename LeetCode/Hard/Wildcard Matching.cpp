/*
https://leetcode-cn.com/problems/wildcard-matching/
Wildcard Matching

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
Note:
s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:
Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:
Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:
Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:
Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:
Input:
s = "acdcb"
p = "a*c?b"
Output: false

*/


#include<string>
#include<vector>
#include<iostream>
using namespace std;


/*

prefix form subproblem. but what is the recursive formulation between them.


            WM[i-1,j-1]  if p[i] == s[j]
 WM[i,j] = 
            false

*/


class Solution 
{
public:
    bool isMatch(string s, string p) 
    {
        bool bMatch = false;
        int N = s.length();
        int M = p.length();
        vector< vector<bool> > wm(M+1, vector<bool>(N+1,false));
        wm[0][0] = true;
        
        for(int i = 1; i<=M; ++i)
        {
            for(int j = 1; j<=N; ++j)
            {
                if(p[i-1] == s[j-1])
                {
                    wm[i][j] = wm[i-1][j-1];
                }
                else
                {
                    //Now lets handle various cases.
                    if('*' == p[i])
                    {
                        //check wether its prefix matched.
                    }
                }
            }
        }
        
        return bMatch;
    }
};