/*
https://leetcode-cn.com/problems/palindrome-partitioning/
Palindrome Partitioning
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]

*/

/*

ps[i][j] = ps[i+1][j-1] if s[i] = s[j]
           0 else
*/

#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) 
    {
        int N = s.length();
        vector< vector<bool> > lps(N+1, vector<bool>(N+1,false));
        vector< vector<int> >  psm(N+1, vector<int>(N+1,0));

        for(int i = 0; i<=N; ++i)
        {
            lps[i][i] = true;
        }

        for(int L = 2; L<N; ++L)
        {
            for(int i = 0; i<=N-L; ++i)
            {
                int j = i+L-1;
                if( 2 == L)
                {
                    if(s[i] == s[j])
                    {
                        lps[i][j] = true;
                        psm[j][i] = L;
                    }
                }
                else
                {
                    if(s[i] == s[j] && lps[i+1][j-1])
                    {
                        lps[i][j] = true;
                        psm[j][i] = L;
                    }
                }
            }               
        }
        
        for(int i = 0; i<N; ++i)
        {
            for(int j = 0; j )
        }

    }
};