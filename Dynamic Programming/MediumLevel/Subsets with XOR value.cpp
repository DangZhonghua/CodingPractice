/*
https://practice.geeksforgeeks.org/problems/subsets-with-xor-value/0/?ref=self
Given an array arr[] of N integers and a integer K, find the number of subsets of arr[] having XOR of elements as K.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. The first line of each test case contains two space separated integers N and K as described in the problem statement. Second line of each test case contains N space separated integers denoting the array arr[].

Output:
Corresponding to each test case, print a single line containing an integer denoting the total number of subsets of arr[] having XOR of thier elements as K.

Constraints:
1<=T<=10
1<=N<=20
1<=K<=100
0<=arr[i]<=100


Example:
Input:
1
4 6
6 9 4 2

Output:
2

Explanation:
The subsets are {4,2} and {6}

16 30
3 23 59 70 68 94 57 12 43 30 74 22 20 85 38 99

output: 512

*/


/*

Dynamatic programming: optimal sub-structure and overlapped sub-problems.

For this: the sub-structure is: sub-solution og  l-1 length  array is included in soultion of l length array.

count[i][j]:L = (count[i][i+L-2]:L-1)^a[j] for j=i+L-1 .... N

*/

#include<iostream>
#include<vector>
using namespace std;

int XORSubsetCount(int *a, int N, int K)
{
    int subsetCount = 0 ;
    vector< vector<int> > c;
    vector< vector<int> > n;
    
    vector< vector<int> >* cur;
    vector< vector<int> >* next;
    
    for(int i = 0; i<N; ++i)
    {
        c.push_back(vector<int>());
        for(int j = 0; j<N; ++j)
        {
            c[i].push_back(0);
        }
    }
    n = c;

    for(int i = 0; i<N; ++i)
    {
        c[i][i] = a[i];
        if(a[i] == K)
        {
            ++subsetCount;
        }
    }

    cur  = &c;
    next = &n;

    for(int l = 2; l<=N; ++l)
    {
        for(int i = 0; i<=N-l;++i)
        {
            for(int j = i+l-1; j<N; ++j)
            {
                (*next)[i][j] = ((*cur)[i][i+l-2]^a[j]);
                if(K == (*next)[i][j] )
                {
                    ++subsetCount;
                }
            }
        }
        vector< vector<int> >* t = cur;
        cur = next;
        next = t; 
    }

    cout<<subsetCount<<endl;


    return 0;
}


int main()
{
    int t = 0;
    int a[100] = {0};
    int N;
    int K;

    cin>>t;
    
    while(t>0)
    {
        --t;
        cin>>N>>K;
        int i = 0;
        while(i<N)
        {
            cin>>a[i++];
        }
        XORSubsetCount(a,N,K);
    }


    return 0;
}
