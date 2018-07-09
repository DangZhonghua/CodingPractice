/*
Largest Sum Subarray of Size at least K 
https://practice.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k/0/?ref=self

Given an array and a number k, find the largest sum of the subarray containing at least k numbers. 
It may be assumed that the size of array is at-least k.

Input:​
The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. Each test case contains an integer n denoting the size of the array. 
Then the following line contains n space separated integers. The last line of the input contains the number k.

Output:
Print the value of the largest sum of the subarray containing at least k numbers.

Constraints:
1<=T<=10^5
1<=n<=10^5
1<=a[i]<=10^5
1<=k<=n

Example:
Input:
2
4
-4 -2 1 -3
2
6
1 1 1 1 1 1
2

Output:
-1
6

*/

/*
1
10
5 7 -9 3 -4 2 1 -8 9 10
5


*/

#include<iostream>
#include<climits>
#include<vector>
using namespace std;


int MaximumsumSubarrayOfLenAtleaseK(int*a, int N, int K)
{
    vector< vector<int> > sk(N, vector<int>(N, INT_MIN));

    int max = INT_MIN;
    int i   = 0;
    int sum = 0;
    int j = 0;

    for(int j = 0; j < N; ++j)
    {
        sum += a[j];
        if(j-i+1 == K)
        {
            if(sum>max)
            {
                max = sum;
            }
            sk[i][j] = sum;
            sum -= a[i];
            ++i;
        }
    }

    for(int l = K+1; l<=N; ++l)
    {
        for(int i = 0;  i<=N-l; ++i)
        {
            int j = i+l-1;
            sk[i][j] = sk[i][j-1] + a[j];
            if(sk[i][j]>max)
            {
                max = sk[i][j];
            }
        }
    }

    cout<<max<<endl;

    return 0;
}

int main()
{
    int t = 0;
    int N,K;
    int a[100001];
    
    cin>>t;
    
    while(t--)
    {
        cin>>N;
        int i = 0;
        while(i<N)
        {
            cin>>a[i++];
        }
        cin>>K;
        MaximumsumSubarrayOfLenAtleaseK(a,N,K);
    }


    return 0;
}