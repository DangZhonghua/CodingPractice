/*
Bitmasking and Dynamic Programming | Set-2 (TSP)
https://www.geeksforgeeks.org/bitmasking-dynamic-programming-set-2-tsp/
n this post, we will be using our knowledge of dynamic programming and Bitmasking technique to solve one of the famous NP-hard problem “Travelling Salesman Problem”.

Before solving the problem, we assume that the reader has the knowledge of

    DP and formation of DP transition relation
    Bitmasking in DP
    Travelling Salesman problem

To understand this concept lets consider the below problem :

Problem Description:
Given a 2D grid of characters representing 
a town where '*' represents the 
houses, '#' represents the blockage, 
'.' represents the vacant street 
area. Currently you are (0, 0) position.

Our task is to determine the minimum distance 
to be moved to visit all the houses and return
to our initial position at (0, 0). You can 
only move to adjacent cells that share exactly
1 edge with the current cell.

The above problem is the well-known Travelling Salesman Problem.

The first part is to calculate the minimum distance between the two cells. 
We can do it by simply using a BFS as all the distances are unit distance. 
To optimize our solution we will be pre-calculating the distances taking the 
initial location and the location of the houses as the source point for our BFS.

Each BFS traversal takes O(size of grid) time. Therefore, it is O(X * size_of_grid) for overall pre-calculation, 
where X = number of houses + 1 (initial position)


*/