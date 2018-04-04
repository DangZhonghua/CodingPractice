/*

https://practice.geeksforgeeks.org/problems/possible-paths/0/?ref=self

Given a directed graph and two vertices ‘u’ and ‘v’ in it, count all the possible walks from ‘u’ to ‘v’ with exactly k edges on the walk.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of three lines.
The first line of each test case is N which is number of vertices in input graph.
The second line of each test case contains N x N binary values that represent graph[N][N].
The third line of each test case contains u, v, k where u is starting position, v is destination and k is number of edges.

Output:

Print all possible walks from 'u' to 'v'.

Constraints:

1 ≤ T ≤ 50
1 ≤ N ≤ 20
0 ≤ graph[][] ≤ 1

Example:

Input
1
4
0 1 1 1 0 0 0 1 0 0 0 1 0 0 0 0

0 3 2

Output
2
 

Explanation:

For example consider the following graph. Let source ‘u’ be vertex 0, destination ‘v’ be 3 and k be 2.
The output should be 2 as there are two walk from 0 to 3 with exactly 2 edges. The walks are {0, 2, 3} and {0, 1, 3}

*/



