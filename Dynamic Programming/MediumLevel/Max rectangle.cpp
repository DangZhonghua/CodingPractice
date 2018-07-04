/*
https://practice.geeksforgeeks.org/problems/max-rectangle/1

https://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/

Given a binary matrix, Your task is to complete the function maxArea which the maximum size rectangle 
area in a binary-sub-matrix with all 1’s. 
The function takes 3 arguments the first argument is the Matrix M[ ] [ ] and 
the next two are two  integers n and m which denotes the size of the matrix M. 
Your function should return an integer denoting the area of the maximum rectangle .

Input:
The first line of input is an integer T denoting the no of test cases . 
Then T test cases follow. The first line of each test case are 2 integers n and m 
denoting the size of the matrix M . 
Then in the next line are n*m space separated values of the matrix M.

Output:
For each test case output will be the area of the maximum rectangle .

Constraints:
1<=T<=50
1<=n,m<=50
0<=M[][]<=1

Example:
Input
1
4 4 
0 1 1 0 1 1 1 1 1 1 1 1 1 1 0 0

Output
8

Explanation
For the above test case the matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 4 *2 = 8

Note:The Input/Ouput format and Example given are used for system's internal purpose, 
and should be used by a user for Expected Output only. 
As it is a function problem, hence a user should not read any input from stdin/console. 
The task is to complete the function specified, and not to write the full code.


*/