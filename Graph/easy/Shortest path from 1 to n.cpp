//https://practice.geeksforgeeks.org/problems/shortest-path-from-1-to-n/0

/*


Consider a directed graph whose vertices are numbered from 1 to n. There is an edge from a vertex i to a vertex j iff either j = i + 1 or j = 3i. The task is to find the minimum number of edges in a path in G from vertex 1 to vertex n.

Input:  
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.

Each test case contains a value of n. 

Output:  
Print the number of edges in the shortest path from 1 to n.

Constraints:
1<=T<=30
1<=n <=1000

Example:
Input:
2
9
4

Output:
2
2

*/

//Use BFS to slove this.

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int CalcShortestPath(int N)
{
    int d = 0;
    struct BFSItem
    {
        int v;
        int d;
    };

    vector<int> visited;
    queue<BFSItem> bfsQ;

    for(int i = 0; i<=N; ++i)
    {
        visited.push_back(0);
    }
    
    BFSItem item;
    item.v = 1;
    item.d = 0;
    visited[1] = 1;

    bfsQ.push(item);

    while(!bfsQ.empty())
    {
        BFSItem head = bfsQ.front();
        bfsQ.pop();
        if(!visited[head.v + 1])
        {
            visited[head.v + 1] = 1;
            BFSItem item;
            item.d = head.d+1;
            item.v = head.v+1;
            if(item.v == N)
            {
                d = item.d;
                break;
            }
            bfsQ.push(item);
        }
        if(!visited[head.v*3])
        {
            visited[head.v*3] = 1;
            BFSItem item;
            item.d = head.d+1;
            item.v = head.v*3;
            if(item.v == N)
            {
                d = item.d;
                break;
            }
            bfsQ.push(item);
        }
    }
    bfsQ.clear();
    cout<<d<<endl;


    return 0;

}

int main()
{
    int t = 0;
    int N = 0;

    cin>>t;

    while(t--)
    {
        cin>>N;
        CalcShortestPath(N);
    }

}
