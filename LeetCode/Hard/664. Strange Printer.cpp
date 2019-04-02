/*
https://leetcode-cn.com/problems/strange-printer/
https://leetcode.com/problems/remove-boxes/discuss/101310/java-top-down-and-bottom-up-dp-solutions
664. Strange Printer

There is a strange printer with the following two special requirements: 
The printer can only print a sequence of the same character each time.
At each turn, the printer can print new characters starting from and ending at any places, 
and will cover the original existing characters.

Given a string consists of lower English letters only, 
your job is to count the minimum number of turns the printer needed in order to print it. 
Example 1:
Input: "aaabbb"
Output: 2
Explanation: Print "aaa" first and then print "bbb".

Example 2:
Input: "aba"
Output: 2
Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.

Hint: Length of the given string will not exceed 100.

*/

//"ababc"  4

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*

DP[i,j,k] = min
                {
                    1+DP[i+1,j,0],
                    DP[i+1,m-1,0] + DP[m, j,k+1]
                }

*/


class Solution {
public:
    int strangePrinter(string s) 
    {
        int N = s.length();
        
        if(0 == N)
        {
            return 0;
        }

        vector< vector< vector<int> > > dp(N, vector< vector<int> >(N, vector<int>(N,0)));
        
        for(int i = 0; i<N; ++i)
        {
            for(int k = 0; k<=i; ++k)
            {
                dp[i][i][k] = 1; // 1 for s[i];
            }
        }

        for(int L = 2; L<=N; ++L)
        {
            for(int i = 0; i+L<=N; ++i)
            {
                int j = i+L-1; // range window, in this loop, we'll calculate the minimum count for [i,j]
                //Now, we try every possible k
                for(int k = 0; k<=i; ++k)
                {
                    int minCount = 1 + dp[i+1][j][0];

                    for(int m = i+1; m<=j; ++m)
                    {
                        if(s[i] == s[m])
                        {
                            minCount = min(minCount, dp[i+1][m-1][0] + dp[m][j][k+1] );
                        }
                    }
                    dp[i][j][k] = minCount;
                }
            }
        }
        
        return dp[0][N-1][0];
    }
};
