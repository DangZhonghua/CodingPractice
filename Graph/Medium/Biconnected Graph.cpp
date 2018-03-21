//https://practice.geeksforgeeks.org/problems/biconnected-graph/0/?ref=self
// Given a graph, check whether it is Biconnected or not. 

// Input:
// First line consists of T test cases. First line of every test case consists of 2 integers N, E,denoting the number of vertices and number of edges respectively. Second line of every test case consists of pair of E spaced integers, denoting the edges connecting each other.

// Output:
// Single line output, print 1 if graph is biconnected else 0.

// Constraints:
// 1<=T<=100
// 1<=N,E<=100

// Example:
// Input:
// 3
// 2 1
// 0 1
// 5 6
// 1 0 0 2 2 1 0 3 3 4 2 4
// 3 2
// 0 1 1 2
// Output:
// 1
// 1
// 0

// if there are no cut vertices in the graph, the Graph is the biconntected graph

/*
BiConnect graph at first, is connect graph. Bi-connect means there are different paths between
any vertices u,v. If graph is connected and there is no cutvertices, then graph is bi-connected graph.

Tarjan algorithm can detect BiConnect Component(BCC) based on DFS traversal. like his SCC algorithm,
during DFS, v.order and v.lowlink
*/


#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

struct dfsvertex
{
	bool m_bVisited;
	int  m_nDepth;
	int  m_nLowlink;
	bool m_bCutVertex;
	int  m_nParentVertex;
	int  m_nChildCount;
	dfsvertex()
	{
		m_bVisited = false;
		m_nDepth = 0;
		m_nLowlink = 0;
		m_bCutVertex = false;
		m_nParentVertex = -1;
		m_nChildCount = 0;
	}
};



int bccDetect(vector< vector<int > >& G, unordered_map<int, dfsvertex>& vInfomap, int u, int Seq, bool& bBiconnectedGraph)
{
	++Seq; //Record the DFS scan sequence.
	vInfomap[u].m_nDepth = Seq;
	vInfomap[u].m_nLowlink = Seq; //This may update during visit its descendents.
	vInfomap[u].m_bVisited = true;
	bool bCutVertex = false;


	for (auto vIt = G[u].begin(); vIt != G[u].end(); ++vIt)
	{
		if (!vInfomap[*vIt].m_bVisited) //This is tree edge.
		{
			vInfomap[*vIt].m_nParentVertex = u;
			vInfomap[u].m_nChildCount += 1;
			bccDetect(G, vInfomap, *vIt, Seq, bBiconnectedGraph);
			if (vInfomap[*vIt].m_nLowlink > vInfomap[u].m_nDepth)
			{
				vInfomap[u].m_bCutVertex = true;
				bBiconnectedGraph = false;
			}
			vInfomap[u].m_nLowlink = vInfomap[u].m_nLowlink < vInfomap[*vIt].m_nLowlink ? vInfomap[u].m_nLowlink : vInfomap[*vIt].m_nLowlink;
		}
		else if ((*vIt) != vInfomap[u].m_nParentVertex)
		{
			vInfomap[u].m_nLowlink = vInfomap[u].m_nLowlink < vInfomap[*vIt].m_nDepth ? vInfomap[u].m_nLowlink : vInfomap[*vIt].m_nDepth;
		}
	}
	if (-1 == vInfomap[u].m_nParentVertex && vInfomap[u].m_nChildCount > 1)
	{
		vInfomap[u].m_bCutVertex = true;
		bBiconnectedGraph = false;
	}

	return 0;
}


int DetectBCG_TarjanAlgo(vector< vector<int > >& G, int V, bool& bBiconnectedGraph)
{
	int Seq = 0;
	int nConnectedComponents = 0;
	unordered_map<int, dfsvertex> vertexinfo;
	dfsvertex dfsv;

	bBiconnectedGraph = true;
	for (int v = 0; v < V; ++v)
	{
		vertexinfo[v] = dfsv;
	}

	for (int v = 0; v < V; ++v)
	{
		if (!vertexinfo[v].m_bVisited) // Every vertex only need be scanned once.
		{
			bccDetect(G, vertexinfo, v, Seq, bBiconnectedGraph);
			++nConnectedComponents;
		}
	}
	if (bBiconnectedGraph && nConnectedComponents > 1)
	{
		bBiconnectedGraph = false;
	}

	if (1 == nConnectedComponents)
	{
		if (2 == V)
		{
			bBiconnectedGraph = true;
		}
	}

	return 0;
}



bool BiConnectedGraph(vector< vector<int > >& G, int V)
{
	bool bBiconnectedGraph = true;

	DetectBCG_TarjanAlgo(G, V, bBiconnectedGraph);
	if (bBiconnectedGraph)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << 0 << endl;
	}

	return bBiconnectedGraph;
}


//For testing on GeeksForGeeks
int main()
{

	int t = 0;
	int N = 0;
	int M = 0;

	vector< vector<int> > G;
	cin >> t;

	while (t > 0)
	{
		--t;
		cin >> N >> M;
		G.clear();
		for (int v = 0; v < N; ++v)
		{
			G.push_back(vector<int>());
		}
		for (int edge = 0; edge < M; ++edge)
		{
			int s, e;
			cin >> s >> e;
			G[s].push_back(e);
			G[e].push_back(s);
		}
		BiConnectedGraph(G, N);
	}

}