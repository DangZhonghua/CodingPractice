
//https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1


/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* The function takes an adjacency list representation of the graph g
    and two integers N and M as specified in the problem statement
    You are required to complete this method. */
    


//Please note: the test data is incorrect in GeeksforGeeks site
    
#include<unordered_map>
#include<list>
using namespace std;

enum vertexColor
{
    WHILTE,
    GRAY,
    BLACK
};

int dfsvisit(vector<int>* g, list<int>& dfslist,unordered_map<int,int>& visitmap, int u)
{
    auto itvertex       = visitmap.find(u);
    itvertex->second    = GRAY;

    
    for(auto it = g[u].begin(); it != g[u].end();++it)
    {
        auto itadj = visitmap.find(*it);
       
        if(itadj != visitmap.end() && WHILTE == itadj->second)
        {
            dfsvisit(g,dfslist,visitmap,*it);
        }
    }
    
    itvertex->second = BLACK;
   dfslist.push_front(u);
    
    return 0;
}


int dfsvisitSCC(vector<int>* g,unordered_map<int,int>& visitmap, int u)
{
    auto itvertex       = visitmap.find(u);
    itvertex->second    = GRAY;
    
    for(auto it = g[u].begin(); it != g[u].end();++it)
    {
        auto itadj = visitmap.find(*it);
        if(itadj != visitmap.end() && WHILTE == itadj->second)
        {
            dfsvisitSCC(g,visitmap,*it);
        }
    }
    
    itvertex->second = BLACK;
    return 0;
}

vector<int>* TransposeGraph(vector<int>* g, int N, int M)
{
    vector<int>* gt = new vector<int>[N+1];
    
     for(int v =  0; v<=N; ++v)
     {
         gt[v].clear();
     }
    
    
    for(int v =  0; v<=N; ++v)
    {
        for(auto it = g[v].begin(); it != g[v].end();++it)
        {
            if((*it)<=N)
            {
                gt[(*it)].push_back(v);
            }
            
        }
    }
    
    
    return gt;
}


int dfs_graph(vector<int>* g, int N, int M)
{

    
    unordered_map<int,int> visitmap;
    list<int> dfslist;
    int nSCC = 0;
    
    
    //This is the first DFS.
    for(int v = 0; v<=N; ++v)
    {
        visitmap.insert(std::make_pair(v, WHILTE));
    }
    
    for(int v = 1; v<=N; ++v)
    {
        auto itvertex = visitmap.find(v);
        if(WHILTE == itvertex->second)
        {
            dfsvisit(g,dfslist,visitmap,v);
        }
    }
    
    
    
    //This is the second DFS.
    visitmap.clear();
    for(int v = 0; v<=N; ++v)
    {
        visitmap.insert(std::make_pair(v, WHILTE));
    }
    
    vector<int>* gt = TransposeGraph(g,N,M);
    
    

    for(auto it = dfslist.begin(); it != dfslist.end();  ++it)
    {
        auto itvertex = visitmap.find(*it);
        if( itvertex != visitmap.end() && WHILTE == itvertex->second)
        {
            dfsvisitSCC(gt,visitmap,*it);
            ++nSCC;
        }
    }

    return nSCC;
}




    
int kosaraju(vector<int> g[MAX], int N, int M)
{

    return dfs_graph(g,N,M);
   
}