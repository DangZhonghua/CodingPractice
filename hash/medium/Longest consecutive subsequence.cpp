/*
https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence/0/?ref=self
Longest consecutive subsequence 
Given an array of integers, find the length of the longest sub-sequence such that 
elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

Input:

The first line of input contains T, number of test cases.

First line of line each test case contains a single integer N.

Next line contains N integer array.

Output:

Print the output of each test case in a seprate line.

Constraints:

1<=T<=100
1<=N<=100
0<=a[i]<=500

Example:

Input:

2
7
2 6 1 9 4 5 3
7
1 9 3 10 4 20 2

Output:

6
4

*/

#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;


int LongestConsecutiveSubsequence(int*a, int N)
{
    unordered_map<int,int> hash;
    int maxindex = 0;
    int maxlen  = 0;

    std::sort(a,a+N);
    
    for(int i = 0; i<N; ++i)
    {
        hash[a[i]] = hash[a[i]-1]+1;
        if(hash[a[i]]> maxlen)
        {
            maxindex = a[i];
            maxlen = hash[a[i]];
        }
    }
    
    cout<<maxlen<<endl;
    

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
        LongestConsecutiveSubsequence(a,N);
    }
    return 0;
}