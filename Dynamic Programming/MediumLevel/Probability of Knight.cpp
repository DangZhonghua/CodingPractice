/*
Probability of Knight
https://practice.geeksforgeeks.org/problems/probability-of-knight/0
https://www.geeksforgeeks.org/probability-knight-remain-chessboard/

Given an NxN chessboard and a Knight at position (x,y). The Knight has to take exactly K steps, 
where at each step it chooses any of the 8 directions uniformly at random. What is the probability that the Knight remains in the chessboard after taking K steps, with the condition that it can’t enter the board again once it leaves it.

Input:
The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. The first line of each test case contains four integers N, X, Y and K. 
Where N * N is the size of the board and (X, Y) denotes the starting position of the chess piece.

Output:
Output the probability that the knight remains on the board. 
Print the answer exactly upto 6 decimal places for each testcase in a new line.

Constraints:
1<= T <=100
0<= N, K, X, Y <=100

Example:
Input:
1
8 0 0 3
Output:
0.125000


*/


/*
One thing that we can observe is that at every step the Knight has 8 choices to choose from. 
Suppose, the Knight has to take k steps and after taking the Kth step the knight reaches (x,y). 
There are 8 different positions from where the Knight can reach to (x,y) 
in one step, and they are: (x+1,y+2), (x+2,y+1), (x+2,y-1), (x+1,y-2), (x-1,y-2), (x-2,y-1), (x-2,y+1), (x-1,y+2


*/