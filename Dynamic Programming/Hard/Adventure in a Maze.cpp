/*
Adventure in a Maze
https://practice.geeksforgeeks.org/problems/adventure-in-a-maze/0

You have got a maze, which is a N*N Grid. Every cell of the maze contains these numbers 1, 2 or 3. 
If it contains 1 : means we can go Right from that cell only.
If it contains 2 : means we can go Down from that cell only.
If it contains 3 : means we can go Right and Down to both paths from that cell.
We cant go out of the maze at any time.

Initially, You are on the Top Left Corner of The maze(Entry). And, You need to go to the Bottom Right Corner of the Maze(Exit).
You need to find the total number of paths from Entry to Exit Point.

There may be many paths but you need to select that path which contains the maximum number of Adventure.
The Adventure on a path is calculated by taking the sum of all the cell values thatlies in the path.
If no valid path exists, Adventure is zero.Since the total paths may be very large, Output it Modulo (1e9+7).

Input:
The first Line contains T- denoting the number of test cases.
The first line of each test case contains an Integer- N denoting the size of the Matrix.
The Next N lines contains N integers each denoting the cell of the Maze.

Output:
For each testcase-Output Two integers denoting the Total Number of Paths and maximum Adventure in a valid Path from Entry to Exit.

Constraints:
1<=T<=10
1<=N<=1000

Explanation:
Sample Input:
1
5
1 1 3 2 1
3 2 2 1 2
1 3 3 1 3
1 2 3 1 2
1 1 1 3 1 


Sample Output:
4 18


Explanation:
There are total 4 Paths Available out of which The Max Adventure is 18
Total possible Adventures are 18,17,17,16.
Of these 18 is the maximum.

*/