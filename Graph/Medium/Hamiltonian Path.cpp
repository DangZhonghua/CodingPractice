//https://practice.geeksforgeeks.org/problems/hamiltonian-path/0

/*

A Hamiltonian path, is a path in an undirected or directed graph that visits each vertex exactly once.
Given an undirected graph, the task is to check if a Hamiltonian path is present in it or not.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line consists of two space separated integers N and M denoting the number of vertices and number of edges.Then in the next line are M space separated pairs u,v denoting an edge from u to v.

Output:
For each test case in a new line print 1 if a Hamiltonean path exists else print 0.

Constraints:
1<=T<=100
1<=N<=10
1<=M<=15

Example:
Input:
2
4 4
1 2 2 3 3 4 2 4
4 3
1 2 2 3 2 4
Output:
1
0


*/

// Use DFS to slove Hamiltonian path: during the DFS count the unique vertex number in one path.

#include<iostream>
#include<vector>
using namespace std;

enum VERTEXCOLOR
{
    WHITE,
    GRAY,
    BLACK
};

/* path length is the vertex count, not the edge count */
int DFSVisit(vector< vector<int> >& G, vector<int>& visited, vector<int>& path, int u,  int V)
{
    visited[u] = GRAY;
    path.push_back(u);
    if(path.size() == V)
    {
        visited[u] = WHITE;
        return 0;
    }
    
    for(auto it = G[u].begin(); it != G[u].end();++it)
    {
        if(WHITE == visited[*it])
        {
            DFSVisit(G,visited,path,*it, V);
            if(path.size() == V)
            {
                break;               
            }
            else
            {
                path.pop_back();
            }
        }
    }
    visited[u] = WHITE;
    return 0;
}


int HamiltonianPathDetect(vector< vector<int> >& G, int V)
{
    bool bFind = false;
    vector<int> visited;
    vector<int> path;

    for(int i = 0; i<V; ++i)
    {
        visited.push_back(WHITE);
    }
    
    for(int i = 0; i<V; ++i)
    {
        DFSVisit(G,visited,path,i,V);
        if(path.size() == V)
        {
            bFind = true;
            break;
        }
        path.clear();
        for(int v = 0; v<V; ++v)
        {
            visited[v] = WHITE;
        }
    }

    cout<<(bFind?1:0)<<endl;
    
    if(bFind)
    {
        for(auto it = path.begin(); it != path.end(); ++it)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }

    return 0;
}


int main()
{

    int t = 0;
    int V,E;
    vector< vector<int> > G;
    cin>>t;
    
    while(t--)
    {
        cin>>V>>E;

        G.clear();
        for(int i = 0; i<V; ++i)
        {
            G.push_back(vector<int>());
        }
        for(int i = 0; i<E; ++i)
        {
            int v1, v2;
            cin>>v1>>v2;
            G[v1-1].push_back(v2-1);
            G[v2-1].push_back(v1-1);
        }
        HamiltonianPathDetect(G,V);
    }


    return 0;
}