/*
Longest Common Increasing Subsequence
https://practice.geeksforgeeks.org/problems/longest-common-increasing-subsequence/0

Given two arrays, find length of the longest common increasing subsequence (LCIS).  For example length of LCIS for A[] = {3, 4, 9, 1} and B[] = {5, 3, 8, 9, 10, 2, 1}  is 2 ( The subsequence {3, 9} is the longest subsequence that is both common and increasing.   As another example LCIS for A[] = {1, 1, 4, 3} and B[] = {1, 1, 3, 4} is 2 (There are two subsequences {1, 4} and {1, 3}).



Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
The first line of each test case contains an integer 'a', where 'a' is the size of the array A[ ].
The second line of each test case contains 'a' space separted integers denoting  the array elements A[0] ... A[a-1]  
The third line of each test case contains an integer 'b', where 'b' is the size of the array B[].
The next line below it contains the value of the array elements B[0]..B[b-1] separated by space.

Output:

For each test case output a single line containing the length of the longest common increasing subsequnce of the two array A[] and B[]
Remember to output the answer of each test case in a new line.

Constraints:

1<=T<=100
1<=a<=50
1<=b<=50
1<=A[i]<=100
1<=B[i]<=100

Example:

Input:
1
4 
3 4 9 1
7
5 3  8  9  10  2  1

Output:
2

Explanation
Here we have 2 arrays
A[] = {3, 4, 9, 1} and
B[] = {5, 3, 8, 9, 10, 2, 1}
of these the longest common increasing subsequence is {3,9} and its length is 2.

*/