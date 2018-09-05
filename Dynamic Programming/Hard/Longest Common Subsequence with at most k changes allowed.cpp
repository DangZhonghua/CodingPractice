/*
https://www.geeksforgeeks.org/longest-common-subsequence-with-at-most-k-changes-allowed/
Longest Common Subsequence with at most k changes allowed

Given two sequence P and Q of numbers. The task is to find Longest Common Subsequence of two sequence 
if we are allowed to change at most k element in first sequence to any value.

Examples:

Input : P = { 8, 3 }
        Q = { 1, 3 }
        K = 1
Output : 2
If we change first element of first
sequence from 8 to 1, both sequences 
become same.

Input : P = { 1, 2, 3, 4, 5 }
        Q = { 5, 3, 1, 4, 2 }
        K = 1
Output : 3
By changing first element of first
sequence to 5 to get the LCS ( 5, 3, 4 }.

*/

/*

The idea is to use Dynamic Programming. Define a 3D matrix dp[][][], where dp[i][j][k] 
defines the Longest Common Subsequence for the first i numbers of first array, first j number of 
second array when we are allowed to change at max k number in the first array.
Therefore, recursion will look like

If P[i] != Q[j], 
    dp[i][j][k] = max(dp[i - 1][j][k], 
                      dp[i][j - 1][k], 
                      dp[i - 1][j - 1][k - 1] + 1) 
If P[i] == Q[j], 
    dp[i][j][k] = max(dp[i - 1][j][k], 
                      dp[i][j - 1][k], 
                      dp[i - 1][j - 1][k] + 1)


*/