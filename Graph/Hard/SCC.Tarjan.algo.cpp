#include<stack>
#include<unordered_map>
#include<vector>
#include<climits>
#include<iostream>
using namespace std;

int StrongConnectComponent(vector< vector<int> >& G, int u, int& num, unordered_map<int, int>& visable, unordered_map<int, int>& link,
	unordered_map<int, int>&order, stack<int>& s, vector< vector<int> >& vscc)
{
	//Init context for the to be visiting vertex
	num += 1;
	order[u] = num;
	link[u] = order[u];
	visable[u] = true;
	s.push(u);
	for (auto it = G[u].begin(); it != G[u].end(); ++it)
	{
		if (-1 == order[*it]) //this adjency vertex need to visited
		{
			StrongConnectComponent(G, *it, num, visable, link, order, s, vscc);
			link[u] = link[u] > link[*it] ? link[*it] : link[u];
		}
		else if (visable[*it]) //this adjency edge is not tree edge
		{
			link[u] = link[u] > order[*it] ? order[*it] : link[u];
		}
		//else: There are no other case since one vertex just two possibility: visit or non-visit
	}

	//after finishing traversal the sub-tree rooted at vertex u. check whether it is the root of one SCC.
	if (link[u] == order[u])
	{
		vector<int> scc;
		while (1)
		{
			int v = s.top();
			s.pop();
			visable[v] = false;
			scc.push_back(v);
			if (u == v)
			{
				break;
			}
		}
		vscc.push_back(scc);
	}
	return 0;
}


int Tarjan(vector< vector<int> >& G, int V)
{
	int num = 0;
	stack<int> s;
	unordered_map<int, int> visable; //Vertex whether is in the stack
	unordered_map<int, int> link; // Vertex's order which it can path to lowest ancestor.
	unordered_map<int, int> order; //Vertex's order which it accessed by DFS.
	vector< vector<int> > vscc;

	for (int v = 0; v < V; ++v)
	{
		visable[v] = 0;
		order[v] = -1;
	}

	for (int v = 0; v < V; ++v)
	{
		if (-1 == order[v]) // vertex v is not traversed up to now.
		{
			StrongConnectComponent(G, v, num, visable, link, order, s, vscc);
		}
	}

	//Output SCC now.
	for (auto itscc = vscc.begin(); itscc != vscc.end(); ++itscc)
	{
		for (auto itv = itscc->begin(); itv != itscc->end(); ++itv)
		{
			cout << *itv;
			if (itv + 1 == itscc->end())
			{
				cout << ",";
			}
			else
			{
				cout << " ";
			}
		}
	}
	cout << endl;

	return 0;
}

int main()
{
	vector< vector<int> > G;
	int t = 0;
	int N = 0;
	int M = 0;

	cin >> t;
	while (t > 0)
	{
		--t;
		cin >> N >> M;
		int s = 0;
		int e = 0;

		for (int v = 0; v < N; ++v)
		{
			G.push_back(vector<int>());
		}

		for (int edge = 0; edge < M; ++edge)
		{
			cin >> s >> e;
			G[s].push_back(e);
		}
		Tarjan(G, N);
		G.clear();
	}

	return 0;
}