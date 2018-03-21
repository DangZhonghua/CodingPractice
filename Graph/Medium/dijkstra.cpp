//https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1/?ref=self

// DIJKSTRA(G, w, s)
// 1  INITIALIZE-SINGLE-SOURCE(G, s)
// 2  S ← Ø
// 3  Q ← V[G]
// 4  while Q ≠ Ø
// 5      do u ← EXTRACT-MIN(Q)
// 6         S ← S ∪{u}
// 7         for each vertex v ∈ Adj[u]
// 8             do RELAX(u, v, w)


/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* The function prints V space separated integers where 
    the ith integer denote the shortest distance of ith vertex
    from source vertex */
    
#include<climits>
#include<unordered_map>
#include<iostream>
using namespace std;
    
void dijkstra(int graph[MAX][MAX], int s,int V)
{
   //Your code here
   
   unordered_map<int, int> mapv2distance;
   unordered_map<int, int> shortestDistance;
   
   for(int i = 0; i<V;++ i)
   {
     if(i == s)
     {
         mapv2distance.insert(std::make_pair(i,0));
     }
     else
     {
         mapv2distance.insert(std::make_pair(i,INT_MAX));
     }
   }
   
   while(!mapv2distance.empty())
   {
       //extract minmum distance node found up to now.
       int minv     = INT_MAX;
       auto itmin   = mapv2distance.end();
       
       for(auto it = mapv2distance.begin(); it != mapv2distance.end(); ++it)
       {
           if(minv>it->second)
           {
               minv = it->second;
               itmin = it;
           }
       }
       
       shortestDistance.insert(std::make_pair(itmin->first,itmin->second));
       int u =  itmin->first;
       mapv2distance.erase(itmin);
       
       for(int i= 0;i<V;++i)
       {
          auto itv = mapv2distance.find(i);
          if(itv != mapv2distance.end() )
          {
             if( (graph[u][i] + minv) < itv->second)
             {
                 itv->second = (graph[u][i] + minv);
             }
          }
       }
   }
   
   for(int i = 0; i<V; ++i)
   {
       //if(i != s)
       {
           auto it = shortestDistance.find(i);
           if(it != shortestDistance.end())
           {
               cout<<it->second<<" ";
           }
       }
   }
  // cout<<endl;
   
}
