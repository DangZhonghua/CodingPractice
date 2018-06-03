/*
Optimal walk 
https://practice.geeksforgeeks.org/problems/optimal-walk/0/?ref=self
Given a point on x axis, (N,0), you are standing at origin and you can only move on x-axis. Lets say you are at (x,0), at each step you can either move one step forward ie (x+1,0) or one step backwards (x-1,0) or make a jump to double your current position (2*x,0). One step movement costs you A while a jump costs you B. If your initial position is (0,0) , find the minimum cost to reach (N,0) .

Input:
First line of input consist of a single integer T denoting the total number of test case. Then T test cases follow. Each line of test case contains 3 space separated integers N, A, B as described in the problem statement.

Output:
For each test case, print a single line containing the minimum cost to reach (N,0).


Constraints:
1<=T<=30
1<=N<=10^5
1<=A,B<=10^9


Example:
Input:
1
7 1 100

Output:
7


*/