/*
Pascal Triangle 
https://practice.geeksforgeeks.org/problems/pascal-triangle/0

Given an integer K,return the kth row of pascal triangle.
Pascal's triangle is a triangular array of the binomial coefficients formed by summing up the elements of previous row.

Example of pascal triangle:
1
1 1
1 2 1
1 3 3 1
 
for K=3, return 3rd row i.e 1 2 1
 

Input:

The first line contains an integer T,depicting total number of test cases. 
Then following T lines contains an integer N depicting the row of triangle to be printed.


Output:

Print the Nth row of triangle in a separate line.


Constraints:

1 ≤ T ≤ 50
1 ≤ N ≤ 25


Example:

Input
1
4
Output
1 3 3 1

*/

/*
 this is dynamic programming problem.
 
 pt[i][j] = pt[i-1][j-1] + pt[i-1][j] j-1>=0 && j< level[i-1] element count.

*/
#include<iostream>
#include<vector>

int pascalTriangle(int N)
{
    



    return 0;
}



