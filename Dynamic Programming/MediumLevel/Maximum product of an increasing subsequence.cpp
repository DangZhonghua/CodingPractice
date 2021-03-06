/*
Maximum product of an increasing subsequence
https://www.geeksforgeeks.org/maximum-product-increasing-subsequence/
Given an array of numbers, find the maximum product formed by multiplying numbers of an increasing subsequence of that array.

Note: A single number is supposed to be an increasing subsequence of size 1.

Examples:

Input : arr[] = { 3, 100, 4, 5, 150, 6 }
Output : 45000
Maximum product is 45000 formed by the 
increasing subsequence 3, 100, 150. Note
that the longest increasing subsequence 
is different {3, 4, 5, 6}

Input : arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 }
Output : 21780000
Maximum product is 21780000 formed by the 
increasing subsequence 10, 22, 33, 50, 60.
          

*/

/*

Just like LIS

*/

#include<iostream>
#include<vector>
using namespace std;


int maximumProductOfLIS(vector<int>& a)
{
    long long maxp = 0;
    vector<long long> p(a.size(),0);
    
    for(int i = 0; i<a.size(); ++i)
    {
        p[i] = a[i];
    }
    
    for(int i = 1; i<a.size(); ++i)
    {
        for(int j = 0; j<i; ++j)
        {
            if(a[i]>a[j])
            {
                if(p[i]<p[j]*a[i])
                {
                    p[i] = p[j]*a[i];
                }
            }
        }
        if(maxp<p[i])
        {
            maxp = p[i];
        }
    }

    cout<<maxp<<endl;
    return 0;
}


int main()
{
    vector<int> m{ 10, 22, 9, 33, 21, 50, 41, 60 };
    maximumProductOfLIS(m);

    return 0;
}