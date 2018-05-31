/*
Longest Bitonic subsequence
https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence/0

https://www.geeksforgeeks.org/dynamic-programming-set-15-longest-bitonic-subsequence/

Given an array of positive integers. The task is to print the maximum length of Bitonic subsequence. 
a subsequenceof array is called Bitonic if it is first increasing, then decreasing.

Input:
First line contains T test cases. First line of every test case consists of N , denoting number of elements in an array. Second line of every test consists of elements in array.

Output:
Single line output, print the longest bitonic sequence.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
5
1 2 5 3 2
8
1 11 2 10 4 5 2 1
Output:
5
6

*/

#include<iostream>
#include<vector>
using namespace std;

int CalcLongestBitonicSeq(int* a, int N)
{
    vector<int> vis(N,1);
    vector<int> vds(N,1);
    int max = 1;
    
    for(int i = 1; i<N; ++i)
    {
        for(int j = 0; j<i; ++j )
        {
            if(a[j]<a[i]) //Calc the increasing sequence.
            {
                if(vis[i] < vis[j]+1)
                {
                    vis[i] = vis[j] + 1;
                }
            }
        }
    }

    for(int i =  N-2; i>=0; --i)
    {
        for(int j = N-1; j>i; --j)
        {
            if(a[i]>a[j] && vds[i]<(vds[j]+1))
            {
                vds[i] = (vds[j]+1);
            }
        }
    }
    
    for(int i = 0; i<N; ++i)
    {
        if(max<(vis[i]+vds[i]-1))
        {
            max = (vis[i] + vds[i]-1);
        }
    }

    cout<<max<<endl;

    return 0;
}


int main()
{
    int t = 0;
    int N = 0;
    int a[200];
    
    cin>>t;
    
    while(t--)
    {
        cin>>N;
        int i = 0;
        while(i<N)
        {
            cin>>a[i++];
        }
        CalcLongestBitonicSeq(a, N);
    }




    return 0;
}