#include<climits>
#include<unordered_map>
#include<vector>
#include<iostream>
using namespace std;

int Init_Single_Source(unordered_map<int,int>& mapD, int V, int s)
{
    for(int v = 0; v<V; ++v)
    {
        mapD.insert(std::make_pair(v, INT_MAX));
    }
    mapD[s] = 0;
    return 0;
}

int Relax(unordered_map<int,int>& mapD, int u, int v, vector<vector<int> >& G, bool& bRelax)
{
    auto itu = mapD.find(u);
    auto itv = mapD.find(v);

    if(INT_MAX != itu->second && INT_MAX != G[u][v])
    {
        if(itv->second>itu->second+G[u][v])
        {
            mapD[v] = (itu->second + G[u][v]);
            bRelax = true;
        }
    }   
    return 0;
}

int Bellman_Ford( vector<vector<int> >& G, int V, int s)
{
    unordered_map<int,int> mapD;
    Init_Single_Source(mapD,V,s);
    bool bRelax = false;
    
    for(int i = 1; i<V; ++i)
    {
        for(int u = 0; u<V; ++u)
        {
            for(int v = 0; v<V; ++v)
            {
                bRelax = false;
                Relax(mapD,u,v,G,bRelax);
            }
        }
    }

    //Detect negative weight Cycle.
    for(int u = 0; u<V; ++u)
    {
        for(int v = 0; v<V; ++v)
        {
            bRelax = false;
            Relax(mapD,u,v,G,bRelax);
            if(bRelax)
            {
                break;
            }
        }
    }

    if(!bRelax)
    {
        for(int i  = 0; i <V; ++i)
        {
            cout<<"["<<s<<":"<<i<<":"<<mapD[i]<<"].\n";
        }
    }

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
		vector< vector<int> > D;
		for (int u = 0; u < V; ++u)
		{
			D.push_back(vector<int>());
			for (int v = 0; v < V; ++v)
			{
				int e;
				cin >> e;
				D[u].push_back(e);
			}
		}
		Bellman_Ford(D, V,V-1);

	}

	return 0;
}