/*

Path in Matrix 
https://practice.geeksforgeeks.org/problems/path-in-matrix/0

Given a N X N  matrix Matrix[N][N] of positive integers.  
There are only three possible moves from a cell Matrix[r][c].

1. Matrix[r+1][c]

2. Matrix[r+1][c-1]

3. Matrix[r+1][c+1]

Starting from any column in row 0, return the largest sum of any of the paths up to row N-1.

Input:
The first line of the input contains an integer T denoting the number of test cases. 
The description of T test cases follows.
The first line of each test case contains a single integer N denoting the order of matrix. 
Next line contains N*N integers denoting the elements of the matrix in row-major form.

Output:
Output the largest sum of any of the paths starting from any cell 
of row 0 to any cell of row N-1. Print the output of each test case in a new line.

Constraints:
1<=T<=20
2<=N<=20
1<=Matrix[i][j]<=1000 (for all 1<=i<=N && 1<=j<=N)

Example:

Input:
1
2
348 391 618 193

Output:
1009

Explanation: In the sample test case, the path leading to maximum possible sum is 391->618.  (391 + 618 = 1009)

*/

/*

sum[r][i] = max{sum[r-1][i]+m[r][i], sum[r-1][i-1]+m[r][i], sum[r-1][i-1]} for i in one column
max  = max{sum[r][i]}

*/

#include<iostream>
#include<vector>
using namespace std;


int maximumSumPath(vector< vector<int> >& m)
{
    vector< vector<int> > sm(m.size(),vector<int>(m[0].size(),0));
    int max = 0;


    for(int i = 0; i<m[0].size(); ++i)
    {
        sm[0][i] = m[0][i];
        if(sm[0][i]>max)
        {
            max = sm[0][i];
        }
    }
    
    for(int i = 1; i<m.size(); ++i)
    {
        for(int j = 0; j<m[0].size(); ++j)
        {
            if(j-1>=0)
            {
                if( sm[i][j] < sm[i-1][j-1] + m[i][j] )
                {
                    sm[i][j] = sm[i-1][j-1] + m[i][j];
                }
            }

            if( sm[i][j] < sm[i-1][j] + m[i][j] )
            {
                sm[i][j] = sm[i-1][j] + m[i][j];
            }
            if(j+1<m[0].size() && sm[i][j]<sm[i-1][j+1] + m[i][j])
            {
                sm[i][j] = sm[i-1][j+1] + m[i][j];
            }  
            if(max<sm[i][j])
            {
                max = sm[i][j];
            } 
        }
    }
    
    cout<<max<<endl;

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
        
        vector<vector<int> > m(N,vector<int>(N,0));
        int i = 0;
        int j = 0;
        while(i<N)
        {
            j = 0;
            while(j<N)
            {
                int d = 0;
                cin>>d;
                m[i][j++] = d;
            }
            ++i;
        }
        maximumSumPath(m);
    }

    return 0;
}


