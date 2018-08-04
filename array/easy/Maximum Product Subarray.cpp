/*
Maximum Product Subarray 
https://practice.geeksforgeeks.org/problems/maximum-product-subarray/0

https://www.geeksforgeeks.org/maximum-product-subarray/

Given an array that contains both positive and negative integers, find the product of the maximum product subarray.
Assumption: There is always a positive product possible, i.e., no array of this form: {0,-20,0,0} or {-20}.

Input:
First line of input contain number of test cases T. 
First line of test case contain the size of array and second line of test case contain the array elements.

Output:
Maximum product of subarray is displayed to the user.

Constraints:
1 <=T<= 100
1 <=N<= 9
-10 <=arr[i]<= 10

Example:

Input:

3
5
6 -3 -10 0 2
6
2 3 4 5 -1 0 
10
8 -2 -2 0 8 0 -6 -8 -6 -1

Output:
180
120
288

*/

/*

Use slide window handle this: how to define the window size, [index of non-zero, index of zero]

if product of window is negative, then from left side/right side, select maximum negative product side.

divide the selected side


*/

#include<iostream>
using namespace std;

// In the window, there is no zero element
int FindMaxProductOfWindow(int*a, int sw, int ew, long long& maxp)
{
    long long leftp  = 1;
    long long rightp = 1;
    int s = sw;
    int e = ew;
    int  leftneg     = -1;
    int  rightneg    = e+1;
    while(s<=e)
    {
        leftp *= a[s];
        if(a[s]< 0)
        {
            leftneg = s;
            break;
        }
        ++s;
    }
    if(-1 != leftneg)
    {
        while(s<=e)
        {
            rightp *= a[e];
            if(a[e] < 0)
            {
                rightneg = e;
                break;
            }
            --e;
        }
    }


    long long wp = 1;
    if(-1 == leftneg) //there is no negative element
    {
        maxp = leftp;
    }
    else
    {
        if(leftneg == rightneg) // there is only one negative element
        {
            if(leftp<rightp)
            {
                maxp = leftp/a[leftneg];
            }
            else
            {
                maxp = rightp/a[rightneg];
            }
        }
        else
        {
            for(int i = leftneg+1; i<=rightneg-1; ++i)
            {
                wp *= a[i];
            }
            wp *= (leftp*rightp);
            if(wp>0)
            {
                maxp = wp;
            }
            else
            {
                if( wp / leftp > wp/rightp)
                {
                    maxp = wp/leftp;
                }
                else
                {
                    maxp = wp/rightp;
                }
            }
        }
    }

    return 0;
}

int MaximumProductSubarray(int *a, int N)
{
    long long maxp = 0;
    long long maxwp = 0;
    int s = 0;
    int e = 0;
    int i = 0;
    while(i<N)
    {
        if(0 == a[i])
        {
          e = i-1;
          maxwp = 0;
          FindMaxProductOfWindow(a,s,e,maxwp);
          if(maxwp>maxp)
          {
            maxp = maxwp;
          }
          s = i+1;
          e = i;
        }
        ++i;
        ++e;
    }
    // handle the last window
    
    if(s<e)
    {
        maxwp = 0;
        FindMaxProductOfWindow(a,s,e-1,maxwp);
        if(maxwp>maxp)
        {
            maxp = maxwp;
        }
    }

    cout<<maxp<<endl;

    return 0;
}


int main()
{
    int t = 0;
    int N = 0;
    int a[10000];

     cin>>t;
     while(t--)
     {
         cin>>N;
         int i = 0;
         while(i<N)
         {
            cin>>a[i++];
         }
         MaximumProductSubarray(a,N);         
     }
    
    return 0;
    
}