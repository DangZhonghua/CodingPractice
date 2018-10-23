/*
Count pairs Sum in matrices
https://practice.geeksforgeeks.org/problems/count-pairs-sum-in-matrices/0

Given two matrices mat1 and mat2 of size N x N of  elements. Given a value x. 
The problem is to count all pairs from both matrices whose sum is equal to x.

INPUT: The first line consists of an integer T i.e. the number of test cases. 
The first line of each test case contains Two Integer N , x  denoting the size of the square Matrix. 
Next 2*N lines contain N integers separated by space.


OUTPUT: For each test case Print the count.

Constraints:
1<=T<=50
1 <= N <= 50
0 <= X <= 2000
1<= A[i][j] , B[i][j] <= 1000

Example:

Input:

1

3 21

1 5 6
8 10 11
15 16 18

2 4 7
9 10 12
13 16 20

Output:

4

Explanation: The pairs are : (1 , 20 ) , (5 , 16 ) , (8 ,13 ) ,( 11 , 10 )


*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int CountPair(vector< vector<int> >& a, vector< vector<int> >& b, int N, int X)
{
    int count = 0;
    for(int i = 0; i<N; ++i)
    {
        for(int j = 0; j<N; ++j)
        {
            
        }
    }




    return count;
}


int main()
{
    int t = 0;
    cin>>t;
    
    while(t--)
    {
        int N;
        int X;
        cin>>N>>X;
        vector< vector<int> > a(N, vector<int>(N,0));
        vector< vector<int> > b(N, vector<int>(N,0));
        int i = 0;
        int j = 0;
        
        while(i<N)
        {
            j = 0;
            while(j<N)
            {
                cin>>a[i][j];
                ++j;
            }
            ++i;
        }
        i = 0;
        j = 0;
        while(i<N)
        {
            j = 0;
            while(j<N)
            {
                cin>>b[i][j];
                ++j;
            }
            ++i;
        }
        CountPair(a,b,N,X);
    }

    return 0;
}