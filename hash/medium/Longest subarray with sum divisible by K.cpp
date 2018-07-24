/*
Longest subarray with sum divisible by K
https://practice.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k/0
https://www.geeksforgeeks.org/longest-subarray-sum-divisible-k/

Given an array containing N integers and a positive integer K. 
The task is to find the length of the longest sub array with sum of the elements divisible by the given value K.

Input:
The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. Each test case consists of two lines. 
First line of each test case contains two Integers N and K and the second line contains N space separated elements.

Output:
For each test case, print the required longest sub array length in new line.

Constraints:
1<=T<=100
1<=N,K<=106
-105<=A[i]<=105

Example:
Input:
2
6 3
2 7 6 1 4 5
7 3
-2 2 -5 12 -11 -1 7
Output:
4
5

Explanation:

Input : A[] = {2, 7, 6, 1, 4, 5}, K = 3
Output : 4
The subarray is {7, 6, 1, 4} with sum 18,
which is divisible by 3.



*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;



int LSSDK(int*a, int N, int K)
{
    unordered_map<int, int> hashmodindex;
    vector<int> modarr(N,0);
    int acc = 0;
    
    for(int i = 0; i< N; ++i)
    {
        acc += a[i];
        // as the sum can be negative, taking modulo twice
        modarr[i] =( (acc%K)+K)%K;
    }

    int maxlen = 0;
    for(int i = 0; i< N; ++i )
    {
        if(modarr[i] == 0)
        {
            maxlen = i+1;
        }
        else if(hashmodindex.find(modarr[i]) == hashmodindex.end() )
        {
            hashmodindex[modarr[i]] = i;
        }
        else
        {
            if(maxlen <i-hashmodindex[modarr[i]])
            {
                maxlen = i-hashmodindex[modarr[i]];
            }
        }
    }
    
    cout<<maxlen<<endl;
    
    return 0;
}

int a[1000001];
int main()
{
    int t = 0;
    int N = 0;
    int K = 0;
    
    cin>>t;
    
    while(t--)
    {
        cin>>N>>K;
        int i = 0;
        while(i<N)
        {
            cin>>a[i++];
        }
        LSSDK(a,N,K);
    }
    
    return 0;
}