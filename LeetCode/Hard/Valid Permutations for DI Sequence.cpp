/*
https://leetcode-cn.com/problems/valid-permutations-for-di-sequence/
Valid Permutations for DI Sequence

We are given S, a length n string of characters from the set {'D', 'I'}. (These letters stand for "decreasing" and "increasing".)
A valid permutation is a permutation P[0], P[1], ..., P[n] of integers {0, 1, ..., n}, such that for all i:
If S[i] == 'D', then P[i] > P[i+1], and;
If S[i] == 'I', then P[i] < P[i+1].
How many valid permutations are there?  Since the answer may be large, return your answer modulo 10^9 + 7.
 
Example 1:
Input: "DID"
Output: 5
Explanation: 
The 5 valid permutations of (0, 1, 2, 3) are:
(1, 0, 3, 2)
(2, 0, 3, 1)
(2, 1, 3, 0)
(3, 0, 2, 1)
(3, 1, 2, 0)
 
 (3,2,3,)
Note:
1 <= S.length <= 200
S consists only of characters from the set {'D', 'I'}.
*/

            |DP[i-1][m] if  s[i-1] = 'D'  for m<n  
DP[i][n] =  |DP[i-1][p] if  s[i-1] = 'I'  for p>n  
            |
DP[n][i]