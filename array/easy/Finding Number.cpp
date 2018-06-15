/*
Finding Number 
https://practice.geeksforgeeks.org/problems/finding-number/0/?ref=self

An array is bitonic if it is comprises of an increasing sequence of integers followed 
immediately by a decreasing sequence of integers.
Given such a array, you need to find a element X in it and print its index.
In case, X does not exist in the array print "OOPS! NOT FOUND" without quotes.
Note: It is guaranteed that array consist of distinct elements. And array indexing is from 0.

Input:
First line will consist  a number T, the number of test cases.
Each test case will then consist of two numbers N and X. N being the array size and X being the element to be searched for.
Next line will consist of N space separated integers.


Output:
Print the required answer on separate lines.
 

Constraints:
1<=T<=100
1<=N<=200
-100<=A[i]<=100
 

Example:
Input:
1
5 2
1 2 7 4 3
Output:
1

*/

#include<iostream>
using namespace std;

int FindPeakInBitonicArray(int*a, int N)
{
    int peak    = -1;
    int s       = 0;
    int e       = N-1;

    while(s<=e)
    {
        if(s == e)
        {
            peak = s;
            break;
        }
        int m = (s+e)/2;
        if(e-s+1>=3) //Use the peak character
        {
            if(a[m-1]<a[m] && a[m]>a[m+1])
            {
                peak = m;
                break;
            }
            else if(a[m-1]<a[m] && a[m]<a[m+1])
            {
                s = m+1;
            }
            else if(a[m-1]>a[m] && a[m]>a[m+1])
            {
                e = m-1;
            }
        }
        else
        {
            if(a[m]<a[e])
            {
                s = m+1;
            }
            else
            {
                e = m;
            }   
        }
    }

    return peak;
}



int FindNumberInBitonicArray(int*a, int N, int T)
{
    int index   = -1;
    int s       = 0;
    int e       = N-1;

    //First: Find the peak element which seperate the array.
    int peak = FindPeakInBitonicArray(a,N);    
    //Find in the first half.
    s = 0;
    e = peak;
    
    while(s<=e)
    {
        int m = (s+e)/2;
        if(a[m] == T)
        {
            index = m;
            break;
        }
        else if(a[m]>T)
        {
            e = m-1;
        }
        else
        {
            s = m+1;
        }
    }

    if(-1 == index && -1 != peak) //Now,we try to search in second half.
    {
        s = peak+1;
        e = N-1;
        while(s<=e)
        {
            int m = (s+e)/2;
            if(a[m] == T)
            {
                index = m;
                break;
            }
            else if(a[m]>T)
            {
                s = m+1;
            }
            else
            {
                e = m-1;
            }
        }
    }

    if(-1 == index)
    {
        cout<<"OOPS! NOT FOUND"<<endl;
    }
    else
    {
        cout<<index<<endl;
    }
    return 0;
}

int main()
{
    int t = 0;
    int N = 0;
    int T = 0;
    int a[400];
    
    cin>>t;
    while(t--)
    {
        cin>>N>>T;
        int i = 0;
        while(i<N)
        {
            cin>>a[i++];
        }
        FindNumberInBitonicArray(a,N,T);
    }
}