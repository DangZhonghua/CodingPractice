/*

Max absolute difference 
https://practice.geeksforgeeks.org/problems/max-absolute-difference/0
https://www.geeksforgeeks.org/maximum-absolute-difference-between-sum-of-two-contiguous-sub-arrays/

Given an array of integers, find two non-overlapping contiguous sub-arrays 
such that the absolute difference 
between the sum of two sub-arrays is maximum.

For example,

Input: [-2, -3, 4, -1, -2, 1, 5, -3]
Output: 12
Two subarrays are [-2, -3] and [4, -1, -2, 1, 5]

Input: [2, -1, -2, 1, -4, 2, 8]
Output: 16
Two subarrays are [-1, -2, 1, -4] and [2, 8] 


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. 
Each Test case contains an integer N denoting the size of the array. Then in the next line are N space separated values of the array.

Output:
For each test case in a new line print the required output.

Constraints:
1<=T<=100
1<=N<=100
-1000<=A[]<=1000

Example:
Input:
2
7
2 -1 -2 1 -4 2 8
8
-2 -3 4 -1 -2 1 5 -3
Output:
16
12

*/

/*

This is familiar with matrix chain multipy problem: the target two subarraies must continuous,

[i...j] [j+1...k].

For certain length subarray, we just search the partition point: j

*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int CalcMaxAbsoluteDiff(int*a, int N)
{
    vector< vector<int> > sm(N, vector<int>(N,0));
    int maxDiff = INT_MIN;

    for(int i = 0; i<N; ++i)
    {
        sm[i][i] = a[i];
    }

    //Calc the subarray sum.    
    for(int i = 0; i<N; ++i)
    {
        for(int j = i+1; j<N; ++j)
        {
            sm[i][j] = sm[i][j-1]+a[j];
        }
    }

    // ll: left subarray length.
    for(int l = 2; l<=N; ++l)
    {
        for(int i = 0; i<=N-l; ++i)
        {
            int j = i+l-1;
            for(int k = i; k<j; ++k)
            {
                int diff = sm[i][k]>sm[k+1][j]? (sm[i][k]-sm[k+1][j]):(sm[k+1][j]-sm[i][k]);
                 if(diff>maxDiff)
                 {
                     maxDiff = diff;
                 }
            }
        }
    }

    cout<<maxDiff<<endl;

    return 0;
}




int main()
{
    int t = 0;
    int a[1000];
    int N = 0;
    
    cin>>t;

    while(t--)
    {
        cin>>N;
        int i = 0;
        while(i<N)
        {
            cin>>a[i++];
        }
        CalcMaxAbsoluteDiff(a,N);
    }


    return 0;
}