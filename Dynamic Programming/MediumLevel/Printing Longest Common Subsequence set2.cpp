/*
https://www.geeksforgeeks.org/printing-longest-common-subsequence-set-2-printing/
Printing Longest Common Subsequence | Set 2 (Printing All)
Given two sequences, print all longest subsequence present in both of them.

Examples:

Input: 
string X = "AGTGATG"
string Y = "GTTAG"
Output: 
GTAG
GTTG

Input: 
string X = "AATCC"
string Y = "ACACG"
Output:  
ACC
AAC

Input: 
string X = "ABCBDAB"
string Y = "BDCABA"
Output:  
BCAB
BCBA
BDAB

We have discussed Longest Common Subsequence (LCS) problem here. The function discussed there was mainly to find the length of LCS. We have also discussed how to print the longest subsequence here. But as LCS for two strings is not unique, in this post we will print out all the possible solutions to LCS problem.

Following is detailed algorithm to print the all LCS.

We construct L[m+1][n+1] table as discussed in the previous post and traverse the 2D array starting from L[m][n]. For current cell L[i][j] in the matrix,


a) If the last characters of X and Y are same (i.e. X[i-1] == Y[j-1]), then the charcater must be present in all LCS of substring X[0…i-1] and Y[0..j-1]. We simply recurse for L[i-1][j-1] in the matrix and append current character to all LCS possible of substring X[0…i-2] and Y[0..j-2].

b) If the last characters of X and Y are not same (i.e. X[i-1] != Y[j-1]), then LCS can be constructed from either top side of the matrix (i.e. L[i-1][j]) or from left side of matrix (i.e. L[i][j-1]) depending upon which value is greater. If both the values are equal(i.e. L[i-1][j] == L[i][j-1]), then it will be constructed from both sides of matrix. So based on values at L[i-1][j] and L[i][j-1], 
we go in direction of greater value or go in both directions if the values are equal.


*/