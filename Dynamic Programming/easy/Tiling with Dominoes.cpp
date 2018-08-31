/*
Tiling with Dominoes
https://www.geeksforgeeks.org/tiling-with-dominoes/

Given a 3 x n board, find the number of ways to fill it with 2 x 1 dominoes.

Defining Subproblems:
At any point while filling the board, there are three possible states that the last column can be in:

An =  No. of ways to completely fill a 3 x n board. (We need to find this)
Bn =  No. of ways to fill a 3 x n board with top corner in last column not filled.
Cn =  No. of ways to fill a 3 x n board with bottom corner in last column not filled.

Finding Reccurences
Note: Even though Bn and Cn are different states, they will be equal for same ‘n’. i.e Bn = Cn
Hence, we only need to calculate one of them.



B[n] = Finding Reccurences
Note: Even though Bn and Cn are different states, they will be equal for same ‘n’. i.e Bn = Cn
Hence, we only need to calculate one of them.

A[n] = A[n-2] + B[n-1] + C[n-1]
since B[n] == C[n] : 


A[n] = A[n-2] + 2*B[n-1]
B[n] = A[n-1] + B[n-2]

base case:
A[0] = 1; A[1] = 0  n == 1 can't be complete filled
B[0] = 0; b[1] = 1;
*/
#include<iostream>
#include<vector>
using namespace std;

int TilingDominoes(int N)
{
    vector<int> a(N+1,0);
    vector<int> b(N+1,0);
    
    a[0] = 1;
    a[1] = 0;
    b[0] = 0;
    b[1] = 1;

    for(int i = 2; i<=N; ++i)
    {
        a[i] = a[i-2] + 2*b[i-1];
        b[i] = a[i-1] + b[i-2];
    }
    //cout<<a[N] <<endl;

    return  a[N];
}

int main(int argc, char const *argv[])
{
    cout<< 3<<" "<<TilingDominoes(3)<<endl;
    cout<< 8<<" "<<TilingDominoes(8)<<endl;
    cout<< 12<<" "<<TilingDominoes(12)<<endl;

    return 0;
}

