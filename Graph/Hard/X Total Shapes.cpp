//https://practice.geeksforgeeks.org/problems/x-total-shapes/0

#include <vector>
#include <iostream>
using namespace std;

#define MAX 60

int DFSVisit(char m[MAX][MAX], char visited[MAX][MAX], int R, int C, int u, int v)
{
    visited[u][v] = true;

    static int RNbr[4] = {-1,0,1,0};
    static int CNbr[4] = {0, 1,0,-1};

    for(int n = 0; n<4; ++n)
    {
        int r = RNbr[n] + u;
        int c = CNbr[n] + v;
        if(r>=0 && r<R && c>=0 && c<C && !visited[r][c] && m[r][c] == 'X' )
        {
            DFSVisit(m,visited,R,C,r,c);
        }
    } 
    
    return 0;
}


int XShapeCount(char m[MAX][MAX],int R, int C)
{
    int xSC = 0;
    char visited[MAX][MAX];
    
    for(int r = 0; r<R; ++r)
    {
        for(int c = 0; c<C; ++c)
        {
            visited[r][c] = false;
        }
    }

    for(int r = 0; r<R; ++r)
    {
        for(int c = 0; c<C; ++c)
        {
            if(!visited[r][c] && 'X' == m[r][c])
            {
                ++xSC;
                DFSVisit(m,visited,R,C,r,c);
            }
        }
    }

    cout<<xSC<<endl;


    return 0;
}


int main()
{
    int t = 0;
    int R = 0;
    int C = 0;
    char m[MAX][MAX];

    cin>>t;

    while(t>0)
    {
        --t;
        cin>>R>>C;
        int r = 0;
        while(r<R)
        {
            cin>>m[r++];
        }
        XShapeCount(m,R,C);
    }


    return 0;
}