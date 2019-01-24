/*
https://leetcode-cn.com/problems/longest-palindromic-substring/
Longest Palindromic Substring

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:
Input: "cbbd"
Output: "bb"

*/

#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) 
    {
        int Len = s.length();
        vector< vector<int> > lps(Len+1, vector<int>(Len+1,0));
        for(int i = 0; i<=Len; ++i)
        {
            lps[i][i] = 1;
        }
        lps[0][0] = 0;
        
        int longest = 1;
        if(s.empty())
        {
            longest = 0;
            return "";
        }
        int start = 0;
        int end = 0;
        for(int L = 2; L<=Len; ++L)
        {
            for(int i = 1; i<=Len-L+1;++i)
            {
                int j =  i+L-1;
                if(s[i-1] == s[j-1])
                {
                    if(2 == L)
                    {
                        lps[i][j] = 2;
                    }
                    else
                    {
                        if(lps[i+1][j-1])
                        {
                            lps[i][j] = lps[i+1][j-1]+2;
                        }
                    }
                    if(lps[i][j] > longest)
                    {
                        longest = lps[i][j];
                        start = i-1;
                        end = j-1;
                    }
                }
                else
                {
                    lps[i][j] = 0;
                }
            }
        }

        if(longest)
        {
            return s.substr(start, end-start+1);
        }
        return "";
    }

};