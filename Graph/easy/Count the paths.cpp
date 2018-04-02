/*
https://practice.geeksforgeeks.org/problems/count-the-paths/0

Given a directed graph, a source vertex ‘s’ and a destination vertex ‘d’, print the count of all paths from given ‘s’ to ‘d’.

Input:
First line consists of T test cases. First line of every test case consists of V and E, denoting the vertices and edges. Second line of every test case consists of 2*E spaced integers denoting the edge between vertices. Third line of every test case consists of S and D.

Output:
Single line output, print the count of all paths from 's' to 'd'.

Constraints:
1<=T<=100
1<=V,E<=10

Example:
Input:
1
4 6
0 1 0 2 0 3 2 0 2 1 1 3
2 3
Output:
3


*/



#include<iostream>
#include<vector>
using namespace std;



int DFSVisit(int d, vector< vector<int> >& matrix, vector<int>& visited,int u, bool& bfind, int& nPath)
{
    visited[u] = 1;
    if(u == d)
    {
        bfind = true;
        nPath = 1;
    }
    
    for(auto it = matrix[u].begin(); it != matrix[u].end(); ++it)
    {
        bool b = false;
        int  nChildPath = 0;
        if(!visited[*it])
        {
            DFSVisit(d,matrix,visited,b,nChildPath);
        }
    }




    return 0;
}


int CountPathsBWSourceAndDestination(int s, int d, vector< vector<int> >& matrix, int V)
{
    vector<int> visited;

    for(int i = 0; i<V; ++i)
    {
        visited.push_back(0);
    }
    
    bool bfind  = false;
    int nPath   = 0;

    DFSVisit(d,matrix,visited,s,bfind,nPath);


    return 0;
}



int main()
{
    int t = 0;
    int s = 0;
    int d = 0;
    int v = 0;
    int e = 0;

    vector< vector<int> > matrix;

    cin>>t;
    
    while(t--)
    {
        cin>>v>>e;
        
        for(int i = 0; i<v; ++i)
        {
            matrix.push_back(vector<int>());
        }
        
        for(int i = 0; i<e; ++i)
        {
            int e1, e2;
            cin>>e1>>e2;
            matrix[e1].push_back(e2);
        }

        cin>>s>>d;

        CountPathsBWSourceAndDestination(s,d,matrix,v);

    }




}


