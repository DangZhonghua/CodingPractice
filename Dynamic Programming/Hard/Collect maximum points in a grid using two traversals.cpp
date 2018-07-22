/*
Collect maximum points in a grid using two traversals
https://www.geeksforgeeks.org/collect-maximum-points-in-a-grid-using-two-traversals/

Given a matrix where every cell represents points. How to collect maximum points using 
two traversals under following conditions?

Let the dimensions of given grid be R x C.

1) The first traversal starts from top left corner, i.e., (0, 0) and 
should reach left bottom corner, i.e., (R-1, 0). 
The second traversal starts from top right corner, i.e., (0, C-1) and 
should reach bottom right corner, i.e., (R-1, C-1)/

2) From a point (i, j), we can move to (i+1, j+1) or (i+1, j-1) or (i+1, j)

3) A traversal gets all points of a particular cell through which it passes. 
If one traversal has already collected points of a cell, then the 
other traversal gets no points if goes through that cell again.

Input :
    int arr[R][C] = {{3, 6, 8, 2},
                     {5, 2, 4, 3},
                     {1, 1, 20, 10},
                     {1, 1, 20, 10},
                     {1, 1, 20, 10},
                    };

     Output: 73

Explanation :
runninggrid
First traversal collects total points of value 3 + 2 + 20 + 1 + 1 = 27

Second traversal collects total points of value 2 + 4 + 10 + 20 + 10 = 46.
Total Points collected = 27 + 46 = 73.


*/