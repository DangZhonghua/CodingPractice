/*
Array Pair Sum Divisibility Problem 
https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem/0/?ref=self
https://www.geeksforgeeks.org/check-if-an-array-can-be-divided-into-pairs-whose-sum-is-divisible-by-k/
Given an array of integers and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.

Input:
The first line of input contains an integer T denoting the number of test cases. 
The T test cases follow. Each test case contains an integer n denoting the size of the array. 
The next line contains the n space separated integers forming the array. 
The last line contains the value of k.

Output:
Print "True" (without quotes) if given array can be divided into pairs such that sum of 
every pair is divisible by k or else "False" (without quotes).

Constraints:
1<=T<=100
2<=n<=10^5
1<=a[i]<=10^5
1<=k<=10^5

Example:
Input:
2
4
9 7 5 3
6
4
91 74 66 48
10

Output:
True
False

*/

#include<iostream>
#include<vector>
using namespace std;

int CanPairs(int *a, int N, int K)
{
    bool bCanPair = true;
    vector<int> vreminder(K, 0);
    
    for(int i = 0; i< N; ++i)
    {
        vreminder[a[i]%K]++;
    }
    
    for(int i = 0; i<N; ++i)
    {
        int reminder = a[i]%K;
        if(2*reminder = K || 0 == reminder)
        {
            if(vreminder[reminder]&1)
            {
                bCanPair = false;
                break;
            }
        }
        else if(vreminder[reminder] != vreminder[K-reminder])
        {
            bCanPair = false;
            break;
        }
    }


    cout<<(bCanPair? "True":"False")<<endl;

    return 0;
}


int a[100001];
int main()
{
    int t = 0;
    int N = 0;
    int K = 0;
    
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
        CanPairs(a,N,K);
    }

    return 0;
}