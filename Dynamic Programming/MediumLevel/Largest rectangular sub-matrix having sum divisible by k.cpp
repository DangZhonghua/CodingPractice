/*
Largest rectangular sub-matrix having sum divisible by k
https://www.geeksforgeeks.org/largest-rectangular-sub-matrix-sum-divisible-k/
Given a n x n matrix of integers. The problem is to find the largest area rectangular 
sub-matrix having sum divisible by the given value k.

Examples:

Input : mat[][] = { {1, 2, -1, -4},
                    {-8, -3, 4, 2},
                    {3, 8, 10, 1},
                    {-4, -1, 1, 7} }

        k = 5

Output : Area = 12
(Top, Left): (0, 0)
(Bottom, Right): (2, 3)
The sub-matrix is:
| 1, 2, -1, -4 |
| -8, -3, 4, 2 |
| 3, 8, 10, 1  |


*/