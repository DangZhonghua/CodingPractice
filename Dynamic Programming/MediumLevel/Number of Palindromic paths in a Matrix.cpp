/*
https://practice.geeksforgeeks.org/problems/number-of-palindromic-paths-in-a-matrix/0

Number of Palindromic paths in a Matrix 

Given a matrix containing lower alphabetical characters only, we need to count number of palindromic paths in given matrix. A path is defined as a sequence of cells starting from top-left cell and ending at bottom-right cell. We are allowed to move to right and down only from current cell.

Input:
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines.
First line of each test case consist of two space separated integers R and C, denoting the number of element in a row and column respectively.
Second line of each test case consists of R*C space separated chars denoting the elements in the matrix in row major order.

Output:
It should be single line output, Print the respective output in the respective line.

Constraints:
1<=T<=20
1<=R,C<=10

Example:
Input:
1
3 4
a a a b b a a a a b b a

Output:
3

*/