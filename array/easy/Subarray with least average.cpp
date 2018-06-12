/*
Subarray with least average 
https://practice.geeksforgeeks.org/problems/subarray-with-least-average/0/?ref=self

Find the subarray with least average of size K. Given an array arr[] of size n and integer k such that k <= n.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'N' and 'K' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.


Output:
The first and last index of the subarray. (Index begins from 1).

Note: You may assume that there will only be one unique solution.


Constraints:
1<=T<=30
1<=N<=1000
1<=K<=N
1<=A[i]<=103

Example:
Input:
1
3 1
30 20 10 

Output:
3 3

*/

#include<iostream>
#include<climits>
using namespace std;

int leastAverage(int* a, int N, int K)
{
    int sum = 0;  //Use sum directly, NOT use sum/K will cause losing digital
    int i   = 0;
    int s   = 0;
    int e   = 0;
    int min = INT_MAX;


    for(int j = 0; j<N; ++j)
    {
        int l = j-i+1;
        if(l == K)
        {
            sum += a[j];
            if(sum < min)
            {
                s = i;
                e = j;
                min = sum;
            }
        }
        else if(l > K)
        {
            sum -=a[i];
            ++i;
            sum += a[j];

            if(sum < min)
            {
                s = i;
                e = j;
                min = sum;
            }
        }
        else
        {
            sum += a[j];
        }
    }

    cout<<(s+1)<<" "<<(e+1)<<endl;

    return 0;

}


int main()
{
    int t = 0;
    int a[1000];

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
        leastAverage(a,N,K);
    }


    return 0;
}