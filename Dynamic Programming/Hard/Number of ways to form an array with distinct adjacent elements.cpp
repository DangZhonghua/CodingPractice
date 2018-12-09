/*
Number of ways to form an array with distinct adjacent elements
https://www.geeksforgeeks.org/number-of-ways-to-form-an-array-with-distinct-adjacent-elements/
Given three integers N, M and X, the task is to find the number of ways to form an array, 
such that all consecutive numbers of the array are distinct, and the value at any index of the array 
from 2 to N – 1(Considering 1 based indexing) lies between 1 and M, 
while the value at index 1 is X and the value at index N is 1.
Note: Value of X lies between 1 and M.

Examples:

    Input: N = 4, M = 3, X = 2
    Output: 3
    The following arrays are possible:
    1) 2, 1, 2, 1
    2) 2, 1, 3, 1
    3) 2, 3, 2, 1

    Input: N = 2, M = 3, X = 2
    Output: 1
    The only possible array is: 2, 1

*/

/*

DP: optimal substructure and overlapped subproblem.
or backtracing?
*/

/*

DP[i][j]: count of begin at i and end with j

*/