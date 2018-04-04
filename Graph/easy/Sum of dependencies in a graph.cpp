/*

https://practice.geeksforgeeks.org/problems/sum-of-dependencies-in-a-graph/0

Given a directed graph with n nodes. If there is an edge from u to v then u depends on v. 
Our task is to find out the sum of dependencies for every node.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. The first line of each test case contains two integers N and E denoting the no of vertices and edges of the graph. Then in the next line are E pairs u and v denoting an edge from u to v.

Output:
For each test case in a new line print the required output.

Constraints:
1<=T<=100
1<=N,E<=150

Example:
Input:
2
4 4 
0 2 0 3 1 3 2 3
4 3 
0 2 0 1 0 3
Output:
4
3
*/

/*
 use BFS slove this.

*/


#include<iostream>
#include<vector>
using namespace std;

int SumOfDependency(vector< vector<int> >& G, int V)
{
    int sum  = 0;

     for(int v = 0; v<V; ++v)
     {
         sum += G[v].size();
     }

     cout<<sum<<endl;

    return 0;
}



int main()
{
    int t = 0;
    int V = 0;
    int E = 0;
    vector< vector<int> > matrix;

    cin>>t;
    
    while(t--)
    {
        cin>>V>>E;
        for(int v = 0; v<V; ++v)
        {
            matrix.push_back(vector<int>());
        }
        for(int i = 0; i<E; ++i)
        {
            int v1, v2;
            cin>>v1>>v2;
            matrix[v1].push_back(v2);
        }
        SumOfDependency(matrix, V);
        matrix.clear();
    }

}
