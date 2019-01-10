/*
Search in a matrix 
https://practice.geeksforgeeks.org/problems/search-in-a-matrix/0/?ref=self

Given an n x m matrix, where every row and column is sorted in increasing order, and a number x . 
The task is to find whether element x is present in the matrix or not.

Expected Time Complexity : O(m + n)

Input:
The first line of input contains a single integer T denoting the number of test cases. 
Then T test cases follow. Each test case consists of three lines.
First line of each test case consist of two space separated integers N and M, 
denoting the number of element in a row and column respectively.
Second line of each test case consists of N*M space separated integers 
denoting the elements in the matrix in row major order.
Third line of each test case contains a single integer x, the element to be searched.
Output:

Corresponding to each test case, print in a new line, 1 if the element x is present in the matrix, otherwise simply print 0.

Constraints:
1<=T<=200
1<=N,M<=30

Example:

Input:
2
3 3
3 30 38 44 52 54 57 60 69
62
1 6
18 21 27 38 55 67
55

Output:
0

1


*/