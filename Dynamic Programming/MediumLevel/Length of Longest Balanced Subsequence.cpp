/*
Length of Longest Balanced Subsequence
https://www.geeksforgeeks.org/length-longest-balanced-subsequence/
Given a string S, find the length of longest balanced subsequence in it. A balanced string is defined as:-

    A Null string is a balanced string.
    If X and Y are balanced strings, then (X)Y and XY are balanced strings.

Examples :

Input : S = "()())"
Output : 4

()() is the longest balanced subsequence 
of length 4.

Input : s = "()(((((()"
Output : 4


A brute force approach is to find all subsequence of the given string S and check for all possible subsequence 
if it form a balanced sequence, if yes, compare it with maximum value.

The better approach is to use Dynamic Programming.
Longest Balananced Subsequence (LBS), can be recursively defined as below.
LBS of substring str[i..j] : 
If str[i] == str[j]
    LBS(str, i, j) = LBS(str, i + 1, j - 1) + 2
Else
    LBS(str, i, j) = max(LBS(str, i, k) +
                         LBS(str, k + 1, j))
                     Where i <= k < j   

Declare a 2D matrix dp[][], where our state dp[i][j] will denote the length of longest balanced subsequence from index i to j. 
We will compute this state in order of increasing j - i. 
For a particular state dp[i][j], we will try to match the jth symbol with kth symbol, 
that can be done only if S[k] is '(' and S[j] is ')', 
we will take the max of 2 + dp[i][k - 1] + dp[k + 1][j - 1] for all such possible k and 
also max(dp[i + 1][j], dp[i][j - 1]) and put the value in dp[i][j]. 
In this way we can fill all the dp states. dp[0][length of string - 1] (considering 0 indexing) will be our answer.

*/

/*
                lbs[i+1][j-1]  if x[i] == '(' && x[j] == ')'
lbs[i][j] = 
                lbs[i][k] + lbs[k+1][j]

*/


#include<iostream>
#include<vector>
#include<string>
using namespace std;

int LongestBalancedSubsequence(const string& strx)
{
    int N = strx.size();
    vector< vector<int> > lbs(N, vector<int>(N,0) );
    
    for(int l = 2; l<=N; ++l)
    {
        for(int i = 0; i<=N-l; ++i)
        {
            int j = i+l-1;
            if(strx[i] == '(' && strx[j] == ')')
            {
                if(j-i>1)
                {
                    lbs[i][j] = 2 + lbs[i+1][j-1];
                }
                else
                {
                    lbs[i][j] = 2;
                }
                
            }
        }

    }
    
    

    

    return 0;
}

int main(int argc, char const *argv[])
{
    string str1 = "()())";
    LongestBalancedSubsequence(str1);

   string str2 = "()(((((()";
   LongestBalancedSubsequence(str2);


    return 0;
}
