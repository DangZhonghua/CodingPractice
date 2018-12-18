/*

Print all possible paths from top left to bottom right of a mXn matrix
https://www.geeksforgeeks.org/print-all-possible-paths-from-top-left-to-bottom-right-of-a-mxn-matrix/

The problem is to print all the possible paths from top left to bottom right of a mXn matrix 
with the constraints that from each cell you can either move only to right or down.

Examples :

Input : 1 2 3
        4 5 6
Output : 1 4 5 6
         1 2 5 6
         1 2 3 6

Input : 1 2 
        3 4
Output : 1 2 4
         1 3 4

The algorithm is a simple recursive algorithm, 
from each cell first print all paths by going down 
and then print all paths by going right. Do this recursively for each cell encountered.

*/