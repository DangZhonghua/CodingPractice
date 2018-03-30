//https://practice.geeksforgeeks.org/problems/nodes-at-even-distance/0/?ref=self

/*

Given a connected acyclic graph with N nodes and N-1 edges, find out the pair of nodes that are at even distance from each other.

Input:

The first line of input contains an integer T denoting the number of test cases.

First line of each test case contains a single integer N denoting the number of nodes in graph.

Second line of each test case contains N-1 pair of nodes xi , yi denoting that there is an edges between them.


Output:

For each test case output a single integer denoting the pair of nodes which are at even distance.


Constraints:

1<=T<=10

1<=N<=10000

1<=xi,yi<=N

Example

Input

1

3

1 2 2 3

Output

1

Explanation:

Only such pair is (1,3) where distance b/w them is 2
*/


//use BFS to slove this problem: since this is a acyclic, connected graph with n-1 edgs, so
//every vertex's in-degree is at most one.

#include<iostream>
#include<queue>
#include<vector>

using namespace std;


struct BFSItem
{
  int vertex;
  int edges;

  BFSItem()
  {
    vertex = -1;
    edges = 0;
  }
};

int BFS(vector< vector<int> >& G, int V, long long& tEvenNumber)
{
    queue<BFSItem>  levelQ;
    vector<int>     visited;
    
    int nVertex = 0;
    int maxEdge = 0;

    for(int i= 0; i<V; ++i)
    {
        visited.push_back(0);
    }
    tEvenNumber             = 0;
    long long nEven =0;
    long long nOdd = 0;
    
    for(int i = 0; i<V; ++i)
    {
        if(!G[i].empty() )
        {
            if(visited[i])
            {
                continue;
            }
            
            BFSItem sItem;
            sItem.vertex = i;
            
            visited[i] = 1;
            
            levelQ.push(sItem);
            
            while(!levelQ.empty())
            {
                BFSItem h = levelQ.front();
                levelQ.pop();
                ++nVertex;
                
                if(h.edges>maxEdge)
                {
                    maxEdge = h.edges;
                }
                
                if((h.edges)%2 ==0)
                {
                    ++nEven;
                }
                else
                {
                    ++nOdd;
                }
                
                for(int i = 0; i<G[h.vertex].size(); ++i)
                {
                    if(visited[G[h.vertex][i]] )
                    {
                        continue;
                    }
                    BFSItem  lv;
                    lv.edges            = h.edges+1;
                    lv.vertex           = G[h.vertex][i];
                    visited[lv.vertex]  = 1;
                    levelQ.push(lv);
                }
            }
        }
    }
    

   
    tEvenNumber = ((nEven*(nEven-1))/2 + (nOdd*(nOdd-1))/2);
    
    if(378 == tEvenNumber)
    {
       //cout<<nVertex<<":"<<nEven<<":"<<nOdd<<endl;
    }


    return 0;
}

int QueryEvenDistanceNodeNumber(vector< vector<int> >& G,int V)
{
    long long tEvenNumber  = 0;

    BFS(G,V,tEvenNumber);
   cout<<tEvenNumber<<endl;

    return 0;
}


int main()
 {
    int t = 0;
    int N = 0;
    vector< vector<int> > G;
    cin>>t;
    
    while(t>0)
    {
        --t;
        cin>>N;
        for(int v = 0; v<N; ++v)
        {
            G.push_back(vector<int>());
        }
        int s = 0;
        int e = 0;
        for(int v = 1; v<N; ++v)
        {
            cin>>s>>e;
            G[s-1].push_back(e-1);
            G[e-1].push_back(s-1);
        }
        QueryEvenDistanceNodeNumber(G,N);
        G.clear();
    }


	return 0;
}