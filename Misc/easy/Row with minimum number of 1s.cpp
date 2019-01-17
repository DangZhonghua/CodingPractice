/*
https://practice.geeksforgeeks.org/problems/row-with-minimum-number-of-1s/0/?ref=self
Row with minimum number of 1's 

Determine the row index with minimum number of ones. 
The given 2D matrix has only zeroes and ones and also the matrix is sorted row wise . 
If two or more rows have same number of 1's than print the row with smallest index.
Note: If there is no '1' in any of the row than print '-1'.

Input:
The first line of input contains an integer T denoting the number of test cases. 
The first line of each test case consists of two integer n and m. The next line consists of n*m spaced integers. 

Output:
Print the index of the row with minimum number of 1's.

Constraints: 
1<=T<=200
1<=n,m<=100

Example:
Input:
2
3 3
0 0 0 0 0 0 0 0 0
4 4
0 0 0 1 0 1 1 1 0 0 1 1 0 0 1 1

Output:
-1
0

*/