/*
Search in a matrix 
https://practice.geeksforgeeks.org/problems/search-in-a-matrix/0/?ref=self

Given an n x m matrix, where every row and column is sorted in increasing order, and a number x . 
The task is to find whether element x is present in the matrix or not.

Expected Time Complexity : O(m + n)

Input:
The first line of input contains a single integer T denoting the number of test cases. 
Then T test cases follow. Each test case consists of three lines.
First line of each test case consist of two space separated integers N and M, 
denoting the number of element in a row and column respectively.
Second line of each test case consists of N*M space separated integers 
denoting the elements in the matrix in row major order.
Third line of each test case contains a single integer x, the element to be searched.
Output:

Corresponding to each test case, print in a new line, 1 if the element x is present in the matrix, otherwise simply print 0.

Constraints:
1<=T<=200
1<=N,M<=30

Example:

Input:
2
3 3
3 30 38
44 52 54 
57 60 69
62

1 6
18 21 27 38 55 67
55

Output:
0
1


*/

/*
Find the row range first. then locate the target column. then search the column
*/

#include<iostream>
#include<vector>
using namespace std;


int SearchInMatrix(vector< vector<int> >&m, int R, int C,int x)
{
    int ret = 0;
    int rs = -1;
    int re = -1;
    
    for(int i = 0; i<R; ++i)
    {
        if(m[i][0] >= x)
        {
            if(-1== re)
            {
                if( m[i][0] > x)
                {
                    re = i-1;
                }
            }
        }

        if(m[i][C-1]>=x)
        {
            if( -1 == rs)
            {
                rs = i;
            }
        }
    }

    if( -1 == re)
    {
        re = R-1;
    }
    if( -1 == rs)
    {
        cout<<0<<endl;
        return 0;
    }

    //rs and re is the row range.
    int c = 0;
    for( c = 0; c<C; ++c)
    {
        if(m[re][c]>=x)
        {
            break;    
        }
    }
    
    bool bFind = false;
    for(int r = re;r>=rs;--r)
    {
        if(m[r][c] == x)
        {
            bFind = true;
            break;
        }
    }

    cout<<(bFind?1:0)<<endl;
    
    return 0;
}

int main(int argc, char const *argv[])
{
    int t = 0;

    cin>>t;

    while(t--)
    {
        int r,c;
        cin>>r>>c;
        int i = 0;
        int j = 0;
        vector< vector<int> > m(r,vector<int>(c,0));
        while(i<r)
        {
            j = 0;
            while(j<c)
            {
                cin>>m[i][j];
                ++j;
            }
            ++i;
        }
        int X = 0;
        cin>>X;
        SearchInMatrix(m,r,c,X);
    }
    
    return 0;
}

