/*
Length of largest region of 1's 
https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s/0

Consider a matrix with rows and columns (n,m), where each cell contains either a ‘0’ or a ‘1’ and 
any cell containing a 1 is called a filled cell. 
Two cells are said to be connected if they are adjacent to 
each other horizontally, vertically, or diagonally .
If one or more filled cells are connected, they form a region. 
Your task is to  find the length of the largest region.

Examples:

Input : M[][5] = { 0 0 1 1 0
                   1 0 1 1 0
                   0 1 0 0 0
                   0 0 0 0 1 }
Output : 6 
Ex: in the following example, there are 
2 regions one with length 1 and the other as 6.
so largest region : 6


Input:
The first line of input will be the no of test cases T then T test cases follow. The first line of each test case contains Two space separated integers n and m. Then in the next line are the nxm inputs of the matrix A separated by space .

Output:
The output in the expected output will be the length of the largest region formed.

Constraints:
1<=T<=100
1<=n,m<=50
0<=A[][]<=1

Example:
Input:
2
3 3
1 1 0 0 0 1 1 0 1
1 3
1 1 1
Output:
4
3


*/