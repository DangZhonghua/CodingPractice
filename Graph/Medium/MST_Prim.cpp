//https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
// 

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Finds the sum of weights of the edges of the Minimum Spanning Tree.
    Graph is represented as adjacency list using array of vectors.  MAX 
    is an upper  limit on number of vertices.
   g[u] represents adjacency list of vertex u,  Every element of this list 
   is a pair<w,v>  where v is another vertex and w is weight of edge (u, v)
  Note : Vertex numbers start with 1 and don't need to be contiguous.   */
  
  #include<climits>
  #include<unordered_map>
  #include<unordered_set>
  using namespace std;
  
int spanningTree(vector <pair<int,int> > g[], int MAX)
{
	//Your code here
	unordered_map<int, int> minHeap;
	unordered_set<int>     fronter;
	int minmumMST = 0;
	int startvertex = 0;
	
	
	for(int vertex = 1; vertex<MAX; ++vertex)
	{
	    if(0 == startvertex && !g[vertex].empty())
	    {
	        minHeap.insert(std::make_pair(vertex, 0));
	        startvertex = vertex;
	    }
	    else if(!g[vertex].empty())
	    {
	        minHeap.insert(std::make_pair(vertex, INT_MAX));
	    }
	}
	
	while(!minHeap.empty())
	{
	    int minv = INT_MAX;
	    unordered_map<int, int>::iterator itmin = minHeap.end();
	    
	    for(auto it = minHeap.begin(); it != minHeap.end(); ++it)
	    {
	        
	        if(minv > it->second)
	        {
	            minv = it->second;
	            itmin = it;
	        }
	    }
	    if(itmin ==minHeap.end() )
	    {
	        break;
	    }
	    int start = itmin->first;
	    minmumMST += minv;
	    
	    fronter.insert(start);
	    minHeap.erase(itmin);
	    
	    for(auto it = g[start].begin(); it != g[start].end(); ++it)
	    {
	        auto itFronter = fronter.find(it->second);
	        if(itFronter == fronter.end())
	        {
	          auto itHeap = minHeap.find(it->second);
	          if(itHeap != minHeap.end())
	          {
	              itHeap->second = it->first;
	          }
	          
	        }
	    }
	}
	
	
    return minmumMST;
}




