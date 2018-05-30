/*
Mobile numeric keypad
https://practice.geeksforgeeks.org/problems/mobile-numeric-keypad/0

Given the mobile numeric keypad. You can only press buttons that are up, left, right or down 
to the current button. 
You are not allowed to press bottom row corner buttons (i.e. * and # ).
Given a number N, find out the number of possible numbers of given length.

Input:
First line consists of T test case. Only line of the test case consists of N.

Output:
Print the possible numbers of given length.

Constraints:
1<=T<=30
1<=N<=30

Example:
Input:
2
1
2
Output:
10
36


*/

/*

C[i][N] = sum (C[j][N-1]) j is the number that be pressed following i.
Total  =  sum(c[i][N])

*/

#include<iostream>
#include<vector>
using namespace std;

static int rn[4] = {-1,1,0,0};
static int cn[4] = {0,0,-1,1};

 bool IsVisable(int r, int c, int nr, int nc)
 {
     bool bv = false;
     if(3 == r && 1 == c)
     {
         if(nr == 2 && nc == 1)
         {
             bv = true;
         }
     }
     else
     {
         if(nr>=0 && nr <=3 && nc>=0&& nc<=2)
         {
             if(nr == 3 &&(nc ==0 || nc == 2))
             {
                bv = false;
             }
             else
             {
                bv = true;    
             }
         }
     }

     return bv;
 }

int CountNumberofLen(int N)
{
    unsigned long long nTotal = 0;
    vector< vector<unsigned long long> > cur(10, vector<unsigned long long>(N+1, 0));
    int pad[4][3] = 
    {
        {1,     2,  3},
        {4,     5,  6},
        {7,     8,  9},
        {'*',   0,  '#'}
    };

    for(int d = 0; d<10; ++d)
    {
        cur[d][0] = 0;
        cur[d][1] = 1;
    }

    for(int n = 2; n<=N; ++n)
    {
        for(int r = 0; r<4; ++r)
        {
            for(int c = 0; c<3; ++c)
            {
                if((r == 3 && c == 0) || (r==3 && c == 2))
                {
                    continue;
                }
                cur[pad[r][c]][n] += cur[pad[r][c]][n-1]; //For press current key
                for(int i = 0; i<4; ++i)
                {
                    int nr = rn[i] + r;
                    int nc = cn[i] + c;
                    if(IsVisable(r,c,nr,nc))
                    {
                        cur[pad[r][c]][n] += cur[ pad[nr][nc] ][n-1];
                    }
                }
            }
        }
    }


    for(int i = 0; i<10; ++i)
    {
        nTotal += cur[i][N];
    }

    cout<<nTotal<<endl;

    return 0;
}



int main()
{
    int t = 0;
    int N = 0;

    cin>>t;
    while(t)
    {
        --t;
        cin>>N;
        CountNumberofLen(N);
    }

    return 0;
}


