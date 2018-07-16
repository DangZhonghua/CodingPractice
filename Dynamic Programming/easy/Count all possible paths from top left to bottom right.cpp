/*
Count all possible paths from top left to bottom right 
https://practice.geeksforgeeks.org/problems/count-all-possible-paths-from-top-left-to-bottom-right/0/?ref=self

The task is to count all the possible paths from top left to bottom right of a mXn matrix with the constraints 
that from each cell you can either move only to right or down.

Input: 
First line consists of T test cases. 
First line of every test case consists of N and M, 
denoting the number of rows and number of column respectively.

Output: 
Single line output i.e count of all the possible paths from top left to bottom right of a mXn matrix. 
Since output can be very large number use %10^9+7.

Constraints:
1<=T<=100
1<=N<=100
1<=M<=100

Example:
Input:
1
3 3
Output:
6

*/

/*

CP[i][j] = CP[i-1][j] + CP[i][j-1] with i>=1 j>=1
CP[0][0] = 1 since there is one way reach the original point.

*/

#include<iostream>
#include<vector>
using namespace std;

int MatrixPossiblePath(int R, int C)
{
    vector< vector<long long > > CP(R+1, vector<long long>(C+1,0) );
    CP[0][0] = 1;

    for(int i = 0; i<R; ++i)
    {
        for(int j = 0; j<C; ++j)
        {
            if(i>=1)
            {
                CP[i][j] += CP[i-1][j];
            }
            if(j>=1)
            {
                CP[i][j] += CP[i][j-1];
            }
            CP[i][j] %= (1000000007);
        }
    }

    cout<<CP[R-1][C-1]<<endl;

    return 0;
}

int main()
{
    int t = 0;
    int R = 0;
    int C = 0;
    
    cin>>t;
    while(t--)
    {
        cin>>R>>C;
        MatrixPossiblePath(R,C);
    }

    return 0;
}