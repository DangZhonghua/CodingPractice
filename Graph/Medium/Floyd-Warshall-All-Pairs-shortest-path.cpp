//https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall/0

/*

The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph.

Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow . The first line of each test case contains an integer V denoting the size of the adjacency matrix  and in the next line are V*V space separated values of the matrix (graph) .

Output:
For each test case output will be V*V space separated integers where the i-jth integer denote the shortest distance of ith vertex from jth vertex.

Constraints:
1<=T<=20
1<=V<=20
-1000<=graph[][]<=1000

Example:
Input
2
2
0 25 25 0
3
0 1 43 1 0 6 43 6 0

Output
0 25 25 0
0 1 7 1 0 6 7 6 0

*/

/*

The structure of a shortest path
In the Floyd-Warshall algorithm, we use a different characterization of the structure of a shortest path than we used
in the matrix-multiplication-based all-pairs algorithms.
The algorithm considers the "intermediate" vertices of a shortest path, where an intermediate vertex of a simple path p = 〈v1, v2,..., vl〉 is any vertex of p other than v1 or vl, that is, any vertex in the set {v2, v3,..., vl-1}.

The Floyd-Warshall algorithm is based on the following observation.
Under our assumption that the vertices of G are V = {1, 2,..., n}, let us consider a subset {1, 2,..., k} of vertices for some k.
For any pair of vertices i, j ∈ V, consider all paths from i to j whose intermediate vertices are all drawn from {1, 2,..., k}, and let p be a minimum-weight path from among them. (Path p is simple.)
The Floyd-Warshall algorithm exploits a relationship between path p and shortest paths from i to j with all intermediate vertices in the set {1, 2,..., k - 1}. The relationship depends on whether or not k is an intermediate vertex of path p.

If k is not an intermediate vertex of path p, then all intermediate vertices of path p are in the set {1, 2,..., k - 1}.
Thus, a shortest path from vertex i to vertex j with all intermediate vertices in the set {1, 2,..., k - 1} is also a shortest path from i to j with all intermediate vertices in the set {1, 2,..., k}.

If k is an intermediate vertex of path p, then we break p down into  as shown in Figure 25.3. By Lemma 24.1,
p1 is a shortest path from i to k with all intermediate vertices in the set {1, 2,..., k}.
Because vertex k is not an intermediate vertex of path p1, we see that p1 is a shortest path from i to k with all intermediate vertices in the set {1, 2,..., k - 1}.
Similarly, p2 is a shortest path from vertex k to vertex j with all intermediate vertices in the set {1, 2,..., k - 1}.

*/

#include<vector>
#include<iostream>
#include<climits>
using namespace std;

int Floyd_Warshall(vector< vector<long long> >& D, vector< vector<long long> >&  ND, int V)
{
	vector< vector<long long> >* curMatrix;
	vector< vector<long long> >* nextMatrix;

	curMatrix = &D;
	nextMatrix = &ND;
	bool bFirstTime = true;
	for (int k = 0; k < V; ++k)
	{
		for (int u = 0; u < V; ++u)
		{
			for (int v = 0; v < V; ++v)
			{
				(*nextMatrix)[u][v] = (*curMatrix)[u][v];
				if (INT_MAX != (*curMatrix)[u][k] && INT_MAX != (*curMatrix)[k][v])
				{
					if (((*curMatrix)[u][k] + (*curMatrix)[k][v]) < (*nextMatrix)[u][v])
					{
						(*nextMatrix)[u][v] = ((*curMatrix)[u][k] + (*curMatrix)[k][v]);
					}
				}
			}
		}
		vector< vector<long long> >* t = curMatrix;
		curMatrix = nextMatrix;
		nextMatrix = t;
	}


	D = (*curMatrix);

	return 0;
}

int AllPairsShortestPath(vector< vector<long long> >& D, int V)
{
	vector< vector<long long> >  ND;

	for (int u = 0; u < V; ++u)
	{
		ND.push_back(vector<long long>());
		for (int v = 0; v < V; ++v)
		{
			ND[u].push_back(INT_MAX);
		}
	}

	Floyd_Warshall(D, ND, V);

	for (int u = 0; u < V; ++u)
	{
		for (int v = 0; v < V; ++v)
		{
			cout << D[u][v] << " ";
		}
	}
	cout << endl;
	D.clear();
	ND.clear();
	return 0;
}

int main()
{

	int t = 0;
	int V = 0;
	cin >> t;
	while (t)
	{
		--t;

		cin >> V;
		vector< vector<long long> > D;
		for (int u = 0; u < V; ++u)
		{
			D.push_back(vector<long long>());
			for (int v = 0; v < V; ++v)
			{
				int e;
				cin >> e;
				D[u].push_back(e);
			}
		}
		AllPairsShortestPath(D, V);

	}

	return 0;
}