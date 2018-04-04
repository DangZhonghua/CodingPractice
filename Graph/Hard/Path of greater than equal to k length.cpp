/*

Given a graph, a source vertex in the graph and a number k, find if there is a simple path (without any cycle) starting from given source and ending at any other vertex.
Source vertex should always be  0.

Input:
First Line contains an integer T denoting the number of test cases. Then T test cases follow.
Each test case contains two lines. First Line contains three integers V, E and k representing vertices, edges of the graph and the required minimum length respectively. Second line contains 3 * E integers containing the information of all edges in the graph. Information of a single edge is a triplet in the following format: (Source Destination Distance). See example for more understanding.

Output:
For each test case print 1 if the path of atleast k distance exists, else print 0 in a new line.

Constraints:
1 <= T <= 30
2 <= V <= 5
1 <= E <= 20
1 <= k <= 100

Example: The Graph below represents only the 1st test case in the example input.


2
9 14 60
0 1 4 0 7 8 1 2 8 1 7 11 2 3 7 2 5 4 2 8 2 3 4 9 3 5 14 4 5 10 5 6 2 6 7 1 6 8 6 7 8 7
4 3 8
0 1 5 1 2 1 2 3 1

Output:
1
0

Explanation:


Test Case 2: There exists no path which has a distance of 8

*/