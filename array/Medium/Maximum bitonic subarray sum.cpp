/*
Maximum bitonic subarray sum
https://practice.geeksforgeeks.org/problems/maximum-bitonic-subarray-sum/0/?ref=self
Given an array containing N numbers. The task is to find the maximum sum bitonic subarray. 
A bitonic subarray is a subarray in which elements are first increasing and then decreasing. 
A strictly increasing or strictly decreasing subarray is also considered as bitonic subarray.

Time Complexity : O(n)
Auxiliary Space : O(1)

Input:
The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. Each test case consists of two lines. 
First line of each test case contains 
a integer N and the second line contains N space separated array elements.

Output:
For each test case, print the maximum bitonic subarray sum in new line.

Constraints:
1<=T<=200
1<=N<=105
1<=A[i]<=105

Example:
Input:
2
7
5 3 9 2 7 6 4
7
5 4 3 2 1 10 6

Output:
19
17


*/

#include<iostream>
#include<climits>
using namespace std;

int MaximumBitonicSubarraySum(int*a, int N);

int main()
 {
    int t = 0;
    int a[100*1024] = {0};
    int N = 0;
    
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
       MaximumBitonicSubarraySum(a,N); 
        
    }


	return 0;
}

int MaximumBitonicSubarraySum(int*a, int N)
{
    unsigned long long sum = 0;
    if(N<2)
    {
        cout<<a[0]<<endl;
        return a[0];
    }
   
    int     i = 0;
    int     j = 1;
    bool    bIncrease   = true;
    bool    bFirst      = true;
    unsigned long long     maxsum      = 0;
 
    sum     = a[0];
    
    for(j = 1; j<N; ++j)
    {
        if(bFirst)
        {
            if(a[j]>a[j-1])
            {
                bIncrease = true;
                sum += a[j];
                bFirst = false;
            }
            else if(a[j]<a[j-1])
            {
                bIncrease = false;
                sum += a[j];
                bFirst = false;
            }
            else
            {
                if(sum>maxsum)
                {
                    maxsum = sum;
                }
                sum = a[j];
            }
        }
        else
        {
            if(bIncrease)
            {
                if(a[j]>a[j-1])
                {
                    sum += a[j];
                }
                else if(a[j]<a[j-1])
                {
                    sum += a[j];
                    bIncrease = false;
                }
                else
                {
                    bFirst = true;
                    if(maxsum<sum)
                    {
                        maxsum = sum;
                    }
                    sum = a[j];
                }
            }
            else
            {
                if(a[j]<a[j-1])
                {
                    sum += a[j];
                }
                else if(a[j]>a[j-1])
                {
                    if(maxsum<sum)
                    {
                        maxsum = sum;
                    }
                    sum = (a[j]+a[j-1]);
                    bIncrease = true;
                }
                else
                {
                    bFirst = true;
                    if(maxsum<sum)
                    {
                        maxsum = sum;
                    }
                    sum = a[j];
                }
            }
        }
    }
    
    if(maxsum<sum)
    {
        maxsum = sum;
    }
    cout<<maxsum<<endl;
    
    return 0;
}