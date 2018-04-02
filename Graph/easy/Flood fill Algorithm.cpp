//https://practice.geeksforgeeks.org/problems/flood-fill-algorithm/0

/*
Given a 2D screen, location of a pixel in the screen ie(x,y) and a color(K), your task is to replace color of the given pixel and all adjacent(excluding diagonally adjacent) same colored pixels with the given color K.

Example:

                     {{1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 0, 0},
                      {1, 0, 0, 1, 1, 0, 1, 1},
                      {1, 2, 2, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 2, 2, 0},
                      {1, 1, 1, 1, 1, 2, 1, 1},
                      {1, 1, 1, 1, 1, 2, 2, 1},
                      };

                        x=4, y=4, color=3 

                     {
                     {1, 1, 1, 1, 1, 1, 1, 1},
                     {1, 1, 1, 1, 1, 1, 0, 0},
                     {1, 0, 0, 1, 1, 0, 1, 1}, 
                     {1, 3, 3, 3, 3, 0, 1, 0},
                     {1, 1, 1, 3, 3, 0, 1, 0},
                     {1, 1, 1, 3, 3, 3, 3, 0},
                     {1, 1, 1, 1, 1, 3, 1, 1},
                     {1, 1, 1, 1, 1, 3, 3, 1},
                    };


Note: Use zero based indexing.


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. The first line of each test case contains Two integers N and M denoting the size of the matrix. Then in the next line are N*M space separated values of the matrix. Then in the next line are three values x, y and K.

Output:
For each test case print the space separated values of the new matrix.

Constraints:
1<=T<=100
1<=M[][]<=100

Example:
Input:
3
3 4
0 1 1 0 1 1 1 1 0 1 2 3
0 1 5
2 2
1 1 1 1
0 1 8
4 4 
1 2 3 4 1 2 3 4 1 2 3 4 1 3 2 4
0 2 9

Output:
0 5 5 0 5 5 5 5 0 5 2 3
8 8 8 8
1 2 9 4 1 2 9 4 1 2 9 4 1 3 2 4


*/

#include <iostream>
#include <vector>
using namespace std;



//Use DFS to slove this, well, this is the argument of DFS: the key points are chose the adjacency principle and
// only from the start point do the DFS.


int DFSVisit(vector< vector<int> >& matrix, vector< vector<bool> >& visited, int N,int M,int x, int y, int b,int K)
{
    visited[x][y] = true;

    static int rNbr[4] = {0,-1,0,1};
    static int cNbr[4] = {-1,0,1,0};

    for(int i = 0; i<4; ++i)
    {
        int x1 = x + rNbr[i];
        int y1 = y + cNbr[i];
        if(x1>=0 && x1<N && y1>=0 && y1<M && !visited[x1][y1] && matrix[x1][y1] == b)
        {
            matrix[x1][y1] = K;
            DFSVisit(matrix,visited,N,M,x1,y1,b,K);
        }
    }


    return 0;
}

int FlooFill(vector< vector<int> >& matrix, int N,int M, int x,int y, int K)
{
    vector< vector<bool> > visited;

    for(int r = 0; r<N; ++r)
    {
        visited.push_back(vector<bool>());
        for(int c = 0; c<M; ++c)
        {
            visited[r].push_back(false);
        }
    }
    int b = matrix[x][y];
    
    matrix[x][y] = K;

    DFSVisit(matrix,visited,N,M,x,y,b,K);

    for(int r = 0; r<N; ++r)
    {
        for(int c = 0; c<M; ++c)
        {
            cout<<matrix[r][c]<<" ";
        }
    }
    cout<<endl;


    return 0;
}



int main()
{
    int t = 0;
    int N = 0;
    int M = 0;

    vector< vector<int> > matrix;
    cin>>t;

    while(t--)
    {
        cin>>N>>M;
        for(int r = 0; r<N; ++r)
        {
            matrix.push_back(vector<int>());
            for(int c = 0; c<M; ++c)
            {
                int e = 0;
                cin>>e;
                matrix[r].push_back(e);
            }
        }
        int x, y,k;
        cin>>x>>y>>k;
        FlooFill(matrix, N,M, x,y,k);
        matrix.clear();
    }


    return 0;
}