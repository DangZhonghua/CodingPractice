/*
Paths to reach origin 
https://practice.geeksforgeeks.org/problems/paths-to-reach-origin/0/?ref=self
You are standing on a point (n, m) and you want to go to origin (0, 0) by taking steps either left or down i.e. 
from each point you are allowed to move either in (n-1, m) or (n, m-1). Find the number of paths from point to origin.

Input:
The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. Each test case contains two integers n and m representing the point.

Output:
Print the total number of paths from point to origin.

Constraints:
1<=T<=100
1<=n,m<=100

Example:
Input:
3
3 2
3 6
3 0

Output:
10
84
1

*/

/*
    PO[i][j] = PO[i+1][j] + PO[i][j+1]

    PO[0][0] is the result.

*/
#include<iostream>
#include<vector>
using namespace std;

int Pathstoreachorigin(int N, int M)
{
    vector< vector<int> > PO(N+1, vector<int>(M+1,0));
    PO[N][M] = 1;
    
    for(int x = N; x>=0; --x)
    {
        for(int y = M; y>=0; --y)
        {
            if(x+1<=N)
            {
                PO[x][y] += PO[x+1][y];
            }
            if(y+1<=M)
            {
                PO[x][y] += PO[x][y+1];
            }
        }
    }
    cout<<PO[0][0]<<endl;
    return 0;
} 

int main()
{
    int t = 0;
    int N = 0;
    int M = 0;
    
    cin>>t;

    while(t--)
    {
        cin>>N>>M;
        
        Pathstoreachorigin(N,M);
    }
    
    return 0;
}