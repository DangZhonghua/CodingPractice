/*
https://practice.geeksforgeeks.org/problems/jumbled-strings/0/?ref=self
Jumbled Strings

You are provided an input string S and the string “GEEKS” . Can you figure out all possible subsequence “GEEKS” in the string S ? You have to tell the number of ways in which the subsequence “GEEKS” can be formed from the string S.

Input:
The first line of input contains a single integer T, denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. The first line of each test case conatins an integer N denoting the size of the string S. Second line of each test case consists of a string S of size N.

Output:
Corresponding to each test case, print in a new line, a number denoting the number of ways in which we can form the subsequence "GEEKS". Output the answer modulo 1000000007.

Constraints :
1<=T<=10
1<=N<=500
Input String contains only uppercase English Letters

Examples:
Input
2
5
GEEKS
8
AGEEKKSB

Output :
1
2

Explanation :
In the first test case the input string is GEEKS itself so the number of ways is 1.
For the second case there are two K's. So a total of two possible strings can be formed by taking either of the two K's.


*/