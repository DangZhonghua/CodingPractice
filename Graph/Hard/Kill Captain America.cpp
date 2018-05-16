/*

https://practice.geeksforgeeks.org/problems/kill-captain-america/0

Captain America is hiding from Thanos in a maze full of rooms.
The maze is designed in such a way that the room, within it, leads to another room via gate. 
Captain America is hiding only in those rooms which are accessible directly/indirectly through every other room in the maze.
Further provided that, the movement from one room (R1) to another room (R2) is one way(unidirectional) only .
Now, you being on Thanos side, want to kill Captain America.  

Input:
First line of the input contains T, the number of test cases.
First line of each test case contains n(no of rooms) and m(no of gates).
Each m line of test case contains p and q denoting room p is connected to room q .

Output:
Each new line of the output contains Total no of rooms .

Constraints:
1 ≤ T ≤ 100
1 ≤ n ≤ 30000
1 ≤ m ≤ 200000
1 ≤ p,q ≤ n

Example:
Input:
1
5 5
1 2
2 3
3 4
4 3
5 4
Output:
2

*/


/*

Solution: any other room can reach the target room (hiding room) in the origin graph. So in tranposing graph,
the target room can reach any other room. So:
1: Tranpose the origin Graph.
2: DFS the Gt (Transpose Graph) from every vertex, during traversl, recording the reachable vertex count. If the count is equal to |V| -1
then find one target.

*/



#include<iostream>
#include<vector>
using namespace std;

enum
{
    UN_VISITED,
    VISITED,
    CONNECT_ALL
};


//The index is started from 1 NOT zero.

int dfsconnectAllVertex(vector< vector<int> >& g, vector<int>& visited, int v,int n, int& nConnectedCount)
{
    ++nConnectedCount;
    visited[v] = VISITED;
    for(int adj = 0; adj < g[v].size(); ++adj)
    {
        if(UN_VISITED == visited[ g[v][adj] ])
        {
            dfsconnectAllVertex(g, visited,g[v][adj],n,nConnectedCount);
        }
        //if the v's connected vertex has been marked as CONNECT_ALL status by this DFS, or other DFS.
        //Mark v is CONNECT_ALL status.
        if(CONNECT_ALL == visited[ g[v][adj] ] )
        {
            visited[v] = CONNECT_ALL;
            break;
        }
    }

    return 0;
}

int DetectCentralRoom(vector< vector<int> >& g, int n, int m, int& centercount)
{
    centercount = 0;
    vector<int> visited;
    for(int i = 0;i<=n; ++i)
    {
        visited.push_back(UN_VISITED);
    }

    for(int v = 1; v<=n; ++v)
    {
        int nConnected = 0; 
        if(0 == visited[v])
        {
            dfsconnectAllVertex(g,visited,v,n, nConnected);
            if(nConnected == n || CONNECT_ALL == visited[v])
            {
                visited[v] = CONNECT_ALL;
                ++centercount;
            }

            for(int i = 1; i<=n; ++i)
            {
                if(CONNECT_ALL != visited[i])
                {
                    visited[i] = 0;
                }
            }
        }   
    }    
    
    return 0;
}

int TransposeGraph(vector<vector<int> >& G, int n, int m, vector<vector<int> >& Gt)
{
    for(int v = 0; v<=n; ++v)
    {
        Gt.push_back(vector<int>());
    }
    for(int v = 1; v<=n; ++v)
    {
        for(int e = 0; e<G[v].size(); ++e)
        {
            Gt[G[v][e]].push_back(v);
        }
    }

    return 0;
}

int killCaptainAmerica(vector<vector<int> >& G, int n, int m)
{
    vector<vector<int> > Gt;
    int ncenterroom = 0;

    TransposeGraph(G,n,m,Gt);
    DetectCentralRoom(Gt,n,m,ncenterroom);
    cout<<ncenterroom<<endl;

    return 0;
}

int main()
{
    int t = 0;
    int n = 0;
    int m = 0;
    int s = 0;
    int e = 0;
    vector< vector<int> > g;

    cin>>t;
    
    while(t>0)
    {
        --t;
        cin>>n>>m;
        g.clear();
        for(int v = 0; v<=n; ++v)
        {
            g.push_back(vector<int>());
        }
        for(int gate = 0; gate<m; ++gate)
        {
            cin>>s>>e;
            g[s].push_back(e);
        }

        killCaptainAmerica(g, n,m);

    }


    return 0;
}



