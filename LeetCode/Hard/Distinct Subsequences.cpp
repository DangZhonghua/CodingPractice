/*
https://leetcode-cn.com/problems/distinct-subsequences/
Distinct Subsequences
Given a string S and a string T, count the number of distinct subsequences of S which equals T.
A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
Example 1:
Input: S = "rabbbit", T = "rabbit"
Output: 3
Explanation:

As shown below, there are 3 ways you can generate "rabbit" from S.
(The caret symbol ^ means the chosen letters)

rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^
Example 2:
Input: S = "babgbag", T = "bag"
Output: 5
Explanation:

As shown below, there are 5 ways you can generate "bag" from S.
(The caret symbol ^ means the chosen letters)

babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
    ^^^

*/


/*

            dp[i-1,j-1]+ dp[i-1,j] if x[i] = y[j]

DP[i,j] =   
            dp[i-1,j]               if x[i] != y[j]

DP[i,0] = 1
*/




#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    int numDistinct(string s, string t) 
    {
        int M = s.length();
        int N = t.length();
        vector< vector<long long> > dp(M+1, vector<long long>(N+1, 0));

        for(int i = 0; i<= M; ++i)
        {
            dp[i][0] = 1;
        }
        
        for(int i = 1; i<=M; ++i)
        {
            for(int j = 1; j<=N; ++j)
            {
                if(i<j) // there is no chance for including t[1..j] in s[1...i]
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if(s[i-1] == t[j-1])
                    {
                        dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                    }
                    else
                    {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        return dp[M][N];  
    }
};