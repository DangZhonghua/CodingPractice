/*

https://practice.geeksforgeeks.org/problems/number-of-paths/0/?ref=self

The problem is to count all the possible paths from top left to bottom right of a MxN matrix 
with the constraints that from each cell you can either move only to right or down.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is M and N, M is number of rows and N is number of columns.

Output:

Print the number of paths.

Constraints:

1 ≤ T ≤ 30
1 ≤ M,N ≤ 10

Example:

Input
2
3 3
2 8

Output
6
8


*/

#include<iostream>
using namespace std;

static const int MAX = 11;

int CalcPathNumber(int M, int N)
{
 int matrix[MAX][MAX];
 
 for(int r = 0; r<M; ++r)
 {
     for(int c = 0; c<N; ++c)
     {
         if(0 == r)
         {
            matrix[r][c] = 1;
         }
         else if(0 == c)
         {
             matrix[r][c] = 1;
         }
         else
         {
             matrix[r][c] = 0;
         }
     }
 }

    for(int r = 1; r<M;++r)
    {
        for(int c = 1; c<N;++c)
        {
            matrix[r][c] = matrix[r-1][c] + matrix[r][c-1];
        }
    }

    cout<< matrix[M-1][N-1]<<endl;

    return 0;
}

int main()
{
    int t = 0;
    int M,N;
    cin>>t;
    
    while(t--)
    {
        cin>>M>>N;
        CalcPathNumber(M,N);
    }
}