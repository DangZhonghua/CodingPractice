/*

https://www.geeksforgeeks.org/maximum-points-top-left-matrix-bottom-right-return-back/
Maximum points from top left of matrix to bottom right and return back


Maximum points from top left of matrix to bottom right and return back

Given a matrix of size N X M consisting of ‘#’, ‘.’ and ‘*’. ‘#’ means blocked path, ‘.’ means walkable path and ‘*’ means point you have to collect. Now consider you are at top left of the matrix. You have to reach bottom right of the matrix and come back to top left. When you are moving top left to bottom right, you are allowed to walk right or down. And when you are moving bottom right to top left, you are allowed to walk left or up. The task is find the maximum points you can grab during your whole journey. Points once taken will be converted into ‘.’ i.e walkable path.

Examples:

Input : N = 3, M = 4
****
.##.
.##.
****
Output : 8

Input : N = 9, M = 7
*........
.....**#.
..**...#*
..####*#.
.*.#*.*#.
...#**...
*........
Output : 7



*/