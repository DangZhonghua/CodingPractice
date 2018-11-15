/*
Bipartite Graph
https://en.wikipedia.org/wiki/Bipartite_graph
https://practice.geeksforgeeks.org/problems/bipartite-graph/1/?ref=self

Given an adjacency matrix representation of a graph g having 0 based index.
Your task is to complete the function is Bipartite which returns true if the graph is a bipartite graph else returns false.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow.
Each test case contains an integer v denoting the no of vertices of the graph then in the next line are v*v
space separated values of the adjacency matrix representation of the graph g.

Output:
For each test case in a new line output will be 1 if the graph is bipartite else 0.

Constraints:
1<=T<=100
1<=v<=15
0<=g[][]<=1

Example(To be used only for expected output):
Input:
2
4
0 1 0 1 1 0 1 0 0 1 0 1 1 0 1 0
3
0 1 0 0 0 1 1 0 0
Output:
1
0

*/

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The function takes an adjacency matrix representation of the graph (g)
and an integer(v) denoting the no of vertices as its arguments.
You are required to complete below method */

/*

use BFS to two colored vertices of graph

*/

#define MAX (4)

#include<queue>
#include<iostream>
#include<unordered_map>
using namespace std;


bool JudgeBiPartite(int G[][MAX], int V, int startVertex,unordered_map<int, int>& vertex2ColorMap )
{
	queue<int> levelQ;
	bool  bBipartite = true;
	int nextColor = 2;
	int CurColor = 1;
	int CurlevelCount = 1;
	int NextLevelCount = 0;
	//From the vertex 0 to BFS the Graph.
	vertex2ColorMap[0] = CurColor;
	levelQ.push(0);
	while (CurlevelCount && bBipartite)
	{
		while (CurlevelCount && bBipartite)
		{
			int vertex = levelQ.front();
			levelQ.pop();
			--CurlevelCount;
			for (int i = 0; i < V; ++i)
			{
				if (G[vertex][i])
				{
					if (vertex2ColorMap.find(i) == vertex2ColorMap.end())
					{
						levelQ.push(i);
						vertex2ColorMap[i] = nextColor;
						++NextLevelCount;
					}
					else if (vertex2ColorMap[i] == vertex2ColorMap[vertex])
					{
						bBipartite = false;
						break;
					}
				}
			}
		}
		if (!bBipartite)
		{
			break;
		}
		CurlevelCount = NextLevelCount;
		int color = nextColor;
		nextColor = CurColor;
		CurColor = color;
		NextLevelCount = 0;
	}

	return bBipartite;
}

bool isBipartite(int G[][MAX], int V)
{
	//Your code here
    bool bBipartite = true;
    unordered_map<int, int> vertex2ColorMap;
    for(int i = 0; i<V; ++i)
    {
        if( vertex2ColorMap.find(i) == vertex2ColorMap.end() )
        {
            bBipartite &= JudgeBiPartite(G,V,i,vertex2ColorMap);
        }
        if(!bBipartite)
        {
            break;
        }
    }
    return bBipartite;    
}


int main()
{
	int G[][4] = 
	{
		{ 0, 1, 0, 1 },
		{ 1, 0, 1, 0 },
		{ 0, 1, 0, 1 },
		{ 1, 0, 1, 0 }
	};

	isBipartite(G,4);

	return 0;
}