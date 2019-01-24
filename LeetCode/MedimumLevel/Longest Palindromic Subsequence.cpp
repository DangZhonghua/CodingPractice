/*

https://leetcode-cn.com/problems/longest-palindromic-subsequence/
Longest Palindromic Subsequence

Given a string s, find the longest palindromic subsequence's length in s. 
You may assume that the maximum length of s is 1000. 
Example 1:
Input: 
"bbbab"
Output: 
4
One possible longest palindromic subsequence is "bbbb". 

Example 2:
Input: 
"cbbd"
Output: 
2
One possible longest palindromic subsequence is "bb". 

*/

#include<vector>
#include<string>
#include<iostream>
using namespace std;


class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {        
        int Len = s.length();
        vector< vector<int> > lps(Len+1, vector<int>(Len+1,0));
        for(int i = 1; i<=Len; ++i)
        {
            lps[i][i] = 1;
        }
        int maxlps = s.empty()?0:1;

        for( int L = 2; L<=Len; ++L)
        {
            for( int i = 1; i<=Len-L+1; ++i)
            {
                int j = i+L-1;
                if(s[i-1] == s[j-1])
                {
                    lps[i][j] = lps[i+1][j-1]+2;
                }
                else
                {
                    lps[i][j] = lps[i+1][j];
                    if(lps[i][j]<lps[i][j-1])
                    {
                        lps[i][j] = lps[i][j-1];
                    }
                }
            }
        }
        return lps[1][Len];
    }
};

int main(int argc, char const *argv[])
{
    string s = "cbbd";
    Solution sol;
    cout<<sol.longestPalindromeSubseq(s)<<endl;
    return 0;
}
