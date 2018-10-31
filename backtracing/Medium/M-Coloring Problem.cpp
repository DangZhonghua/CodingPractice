/*
M-Coloring Problem 
https://practice.geeksforgeeks.org/problems/m-coloring-problem/0
https://www.geeksforgeeks.org/m-coloring-problem-backtracking-5/

Given an undirected graph and an integer M, determine if the graph can be colored 
with at most M colors such that no two adjacent vertices of the graph are colored with the same color. 
Here coloring of a graph means assignment of colors to all vertices. 
Print 1 if it is possible to colour vertices and 0 otherwise.

Vertex are 1-based (vertext number starts with 1, not 0).

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow.
Each test case consists of four lines.
The first line of each test case contains an integer N denoting the number of vertices.
The second line of each test case contains an integer M denoting the number of colors available
The third line of each test case contains an integer E denoting the number of edges available.
The fourth line of each test case contains E pairs of space separated integers denoting the edges between vertices.

Output:
Print the desired output.

Constraints:
1<=T<= 30
1<=N<= 50
1<= E <= N*(N-1)
1<= M <= N

Example:

Input :
1
4
3
5
1 2 2 3 3 4 4 1 1 3

Output:
1

*/

/*
The basic idea is the backtracking: try to assign a color to vertex, if the color is safe. then process the next vertext
if the color is not safe, then try another color.
*/


#include<iostream>
#include<vector>
using namespace std;

int ColorGraph(vector< vector<int> >&,int M )
{


    return 0;
}


int main(int argc, char const *argv[])
{
    int t = 0;
    cin>>t;

    while(t--)
    {
        int N;
        int M;
        int E;
        cin>>N>>M>>E;
        vector< vector<int> > graph(N+1, vector<int>(N+1,0));
        for(int i = 0; i<E; ++i)
        {
            int s,e;
            cin>>s>>e;
            graph[s][e] = 1;
            graph[e][s] = 1;
        }
    }


    return 0;
}








