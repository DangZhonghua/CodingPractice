/*
https://leetcode-cn.com/problems/integer-break/
Integer Break
Given a positive integer n, break it into the sum of at least two positive integers 
and maximize the product of those integers. Return the maximum product you can get.
Example 1:
Input: 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:
Input: 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
Note: You may assume that n is not less than 2 and not larger than 58.

*/

/*

this is similar to matrix multiply chain problem.

dp[n] = max{ dp[a]*dp[b]} for any a+b = n

1+ n-1

*/

#include <vector>
#include <iostream>
using namespace std;


class Solution 
{
public:
    int integerBreak(int n) 
    {
        if(2 == n)
        {
            return 1;
        }

        vector<int> dp(n+1,0);
        dp[1] = 1;
        dp[2] = 2;

        for(int i = 3; i<=n; ++i)
        {
            for(int j = 1; j<= i/2; ++j)
            {
                if(dp[i] < dp[j]*dp[i-j] )
                {
                     dp[i] = dp[j]*dp[i-j];
                }
            }
            if(dp[i]<i && i != n ) //this is important for that is not the final n which means it can NOT be divid
            {
                dp[i] = i;
            }
            
           // cout<<i<<":"<<dp[i]<<endl;
        }
        return dp[n];
    }
};