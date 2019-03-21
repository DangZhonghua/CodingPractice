/*
https://leetcode-cn.com/problems/scramble-string/
87. Scramble String

Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
Below is one possible representation of s1 = "great":
    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.
For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".
Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".
Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
Example 1:
Input: s1 = "great", s2 = "rgeat"
Output: true
Example 2:
Input: s1 = "abcde", s2 = "caebd"
Output: false

*/

/*



Analysis

If string s1 and s2 are scramble strings, there must be a point that breaks s1 to two parts s11, s12, 
and a point that breaks s2 to two parts, s21, s22, and isScramble(s11, s21) && isScramble(s12, s22) is true, 
or isScramble(s11, s22) && isScramble(s12, s21) is true.

So we can make it recursively. We just break s1 at different position to check if 
there exists one position satisfies the requirement.

Some checks are needed otherwise it will time out. For example, 
if the lengths of two strings are different, they can’t be scramble. 
And if the characters in two strings are different, they can’t be scramble either.

Another way is to use DP. I use a three dimension array scramble[][][] to save the states. 
What scramble[k][i][j] means is that two substrings of length k, one starts from i of string s1, 
another one starts from j of string s2, are scramble. We are trying to find scramble[L][0][0]. For every length k, 
we try to divide the string to two parts differently, checking if there is a way that can make it true.
Code

*/


#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) 
    {
        // special case
        if(s1.size() != s2.size()) return false;
        if(s1 == s2) return true;
        //end special case
        int N = s1.length();
        //dp[L][i][j]: [i,i+L-1] [j,j+L-1] is the Scramble?
        vector< vector< vector< bool> > > dp(N+1, vector< vector<bool> >(N+1, vector<bool>(N+1,false)));
        // Initialize the length == 1 case
        for(int i = 0; i<N;++i)
        {
            for(int j = 0; j<N; ++j)
            {
                dp[1][i][j] = (s1[i] == s2[j]);
            }
        }
        for(int L = 2; L<=N; ++L) // optimal-substructure based on length.
        {
            for(int i = 0; i+L<=N; ++i)
            {
                for(int j = 0; j+L<=N; ++j)
                {
                    for(int k = 1;k<L; ++k) // try every possible segment point
                    {
                        if(
                            (dp[k][i][j] && dp[L-k][i+k][j+k] ) 
                            ||
                            (dp[k][i][j+L-k] && dp[L-k][i+k][j])
                          )
                          {
                              dp[L][i][j] = true;
                              break;
                          }
                    }
                }
            }
        }
        return dp[N][0][0];
    }
};

