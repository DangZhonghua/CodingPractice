/*
Maximum sum path in a matrix from top to bottom
https://www.geeksforgeeks.org/maximum-sum-path-matrix-top-bottom/

Consider a n*n matrix. Suppose each cell in the matrix has a value assigned. 
We can go from each cell in row i to a diagonally higher cell in row i+1 only [i.e from cell(i, j) to cell(i+1, j-1) 
and cell(i+1, j+1) only]. Find the path from the top row to the bottom row following the aforementioned condition 
such that the maximum sum is obtained.

Examples:

Input : mat[][] = { {5, 6, 1, 7},
                {-2, 10, 8, -1},
                {3, -7, -9, 11},
                {12, -4, 2, 6} }
Output : 28

{5, 6, 1, 7},
{-2, 10, 8, -1},
{3, -7, -9, 11},
{12, -4, 2, 6} }

The highlighted numbers from top to bottom
gives the required maximum sum path.
(7 + 8 + 11 + 2) = 28

*/