
/*

https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0

https://www.geeksforgeeks.org/dynamic-programming-set-14-maximum-sum-increasing-subsequence/

Given an array of n positive integers. Write a program to find the sum of maximum sum subsequence of the given array such that the integers in the subsequence are sorted in increasing order.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N,N is the size of array.
The second line of each test case contains N input A[].

Output:

Print the sum of maximum sum sequence of the given array.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 100
1 ≤ A[] ≤ 1000

Example:

Input:
2
7
1 101 2 3 100 4 5
4
10 5 4 3

Output:
106
10

Explanation:
For input:
7
1 101 2 3 100 4 5
All the increasing subsequences : (1,101); (1,2,3,100); (1,2,3,4,5), out of this (1,2,3,100) has maximum sum,i.e., 106. 
Hence the output is stated as 106.
*/

/*
find a LIS sub-sequence which has maximum sum.
This is Dynamic programming problem. 

sum[i...i] = a[i];

for[0...i]

sum[i] = max{sum[j] + a[i]} for j:0..i-1

*/

#include<iostream>
using namespace std;

int MaximumSumIncreasingSubsequence(int*a, int*b, int N)
{
    for(int i  = 0;  i<N; ++i)
    {
        b[i] = 0;
    }
    
    int maxSum = a[0];
    b[0] = a[0];
    
    for(int i  = 1;  i<N; ++i)
    {
        int j = i-1;
        b[i] = a[i];
        
        for( j = i-1; j>= 0; --j)
        {
            if(a[i]>a[j] && b[i] < b[j] + a[i])
            {
                b[i] = b[j] + a[i];
                if(maxSum<b[i])
                {
                    maxSum = b[i];
                }
            }
        }
    }

    cout<<maxSum<<endl;
    return 0;    
}


int MaximumSumOfLIS(int*a, int* sum, int N)
{

    int maxsum = 0;
    for(int i = 0; i<N; ++i)
    {
        sum[i] = a[i];
    }
    
    maxsum = sum[0];

    for(int i = 1; i<N; ++i)
    {
        for(int j = 0; j<i; ++j)
        {
            if(a[i]>a[j] && sum[i]<sum[j]+a[i])
            {
                sum[i] = sum[j] + a[i];
            }
        }
        if(sum[i] > maxsum)
        {
           maxsum = sum[i];
        }
    }

    cout<<maxsum<<endl; 

    return 0;
}






int main()
 {
     int t = 0;
     int N = 0;
     int a[100] = {0};
     int b[100] = {0};
    
    cin>>t;
    
    while(t>0)
    {
        --t;
        cin>>N;
        int i = 0;
        while(i<N)
        {
            cin>>a[i];
            ++i;
        }
       // MaximumSumIncreasingSubsequence(a,b,N);
       MaximumSumOfLIS(a,b,N);
    }
	return 0;
}