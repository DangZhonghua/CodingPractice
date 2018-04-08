/*

https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1/?ref=self

Given an undirected graph and an edge, the task is to find if the given edge is a bridge in graph, i.e., removing the edge disconnects the graph.
Input:

The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of two lines. 
Description of  test cases is as follows:
The First line of each test case contains two integers 'N' and 'M'  which denotes the no of vertices and no of edges respectively.
The Second line of each test case contains 'M'  space separated pairs u and v denoting that there is a bidirectional  edge from u to v 

The third line contains two space seperated integers denoting the edge to be removed.
Output:

For each test case ouput a single line 1 or 0, 1 if edge is a Bridge edge or not. 
Constraints:

1<=T<=50

1<=N,M<=100
Example:

Input:

2
4 3
0 1 1 2 2 3
1 2
5 5
1 2 2 0 1 0 3 4 3 0
2 0

Ouput:

1
0

*/