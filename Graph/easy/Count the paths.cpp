/*
https://practice.geeksforgeeks.org/problems/count-the-paths/0

Given a directed graph, a source vertex ‘s’ and a destination vertex ‘d’, print the count of all paths from given ‘s’ to ‘d’.

Input:
First line consists of T test cases. First line of every test case consists of V and E, denoting the vertices and edges. Second line of every test case consists of 2*E spaced integers denoting the edge between vertices. Third line of every test case consists of S and D.

Output:
Single line output, print the count of all paths from 's' to 'd'.

Constraints:
1<=T<=100
1<=V,E<=10

Example:
Input:
1
4 6
0 1 0 2 0 3 2 0 2 1 1 3
2 3
Output:
3


*/



#include<iostream>
#include<vector>
using namespace std;

#define WHITE   0
#define GRAY    1
#define BLACK   2

int DFSVisit(int d, int p, int u, vector< vector<int> >& matrix, vector<int>& visited, vector<int>& path, vector<int>& find)
{
	visited[u] = GRAY;
	if (u == d)
	{
		find[u] = true;
		path[u] = 1;
	}
	else
	{
		for (auto it = matrix[u].begin(); it != matrix[u].end(); ++it)
		{
			if ( WHITE == visited[*it] && u != *it)
			{
				DFSVisit(d, u, *it, matrix, visited, path, find);
			}

			if (BLACK == visited[*it]) //When the vertex has been completed, then add its path to current one.
			{
				path[u] += path[*it];
			}

			if (find[*it])
			{
				find[u] = true;
			}
		}
	}

	visited[u] = BLACK;


	return 0;
}


int CountPathsBWSourceAndDestination(int s, int d, vector< vector<int> >& matrix, int V)
{
	vector<int> visited;
	vector<int> path;
	vector<int> find;
	for (int i = 0; i < V; ++i)
	{
		visited.push_back(0);
		path.push_back(0);
		find.push_back(0);
	}

	bool bfind = false;

	DFSVisit(d, s, s, matrix, visited, path, find);


	if (path[s])
	{
		cout << path[s] << endl;
	}
	else
	{
		if (s == d)
		{
			cout << 1 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}

	return 0;
}



int main()
{
	int t = 0;
	int s = 0;
	int d = 0;
	int v = 0;
	int e = 0;

	vector< vector<int> > matrix;

	cin >> t;

	while (t)
	{
		--t;
		cin >> v >> e;

		for (int i = 0; i < v; ++i)
		{
			matrix.push_back(vector<int>());
		}

		for (int i = 0; i < e; ++i)
		{
			int e1, e2;
			cin >> e1 >> e2;
			matrix[e1].push_back(e2);
		}

		cin >> s >> d;

		CountPathsBWSourceAndDestination(s, d, matrix, v);
		matrix.clear();

	}




}


