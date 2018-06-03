/*

First and last occurrences of X 
https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x/0/?ref=self

Given a sorted array with possibly duplicate elements, 
the task is to find indexes of first and last occurrences of an element x in the given array.

Note: If the number x is not found in the array just print '-1'.

Input:
The first line consists of an integer T i.e number of test cases. 
The first line of each test case contains two integers n and x. 
The second line contains n spaced integers.

Output:
Print index of the first and last occurrences of the number x with a space in between.

Constraints: 
1<=T<=100
1<=n,a[i]<=1000

Example:
Input:
2
9 5
1 3 5 5 5 5 67 123 125
9 7
1 3 5 5 5 5 7 123 125

Output:
2 5
6 6
*/

#include<iostream>
using namespace std;

int binarySearch(int*a, int s, int e, int x)
{
    int index = -1;
    while(s<=e)
    {
       int m = (s+e)/2;
       if(a[m] == x)
       {
           index = m;
           break;
       }
       else if(a[m]>x)
       {
           e = m-1;
       }
       else
       {
           s = m+1;
       }
    }

    return index;
}

int findfirstlastindex(int*a, int N, int x)
{
    int f = -1;
    int l = -1;

    int s = 0;
    int e = N-1;
    

    int t = binarySearch(a,s,e,x);
    if(-1 == t)
    {
        cout<<-1<<endl;
        return 0;
    }
    else
    {
        int fs = t;
        f = t-1;
        while( -1 != f)
        {
            f = binarySearch(a,s,f,x);
            if( -1 != f )
            {
                fs = f;
                f -= 1;
            }            
        }
        f = fs;
        
        int ls = t; 
        l += 1;
        
        while(-1 != l)
        {
            l = binarySearch(a,l,e,x);
            if(-1 != l)
            {
                ls = l;
                l += 1;
            }
        }
        l = ls;
    }

   
    cout<<f<<" "<<l<<endl;

    return 0;
}



int main(int argc, char const *argv[])
{

    int t = 0;
    int N = 0;
    int x = 0;
    int a[1000];
    cin>>t;

    while(t--)
    {
        cin>>N;
        cin>>x;
        
        int i = 0;
        while(i<N)
        {
            cin>>a[i++];
        }
        findfirstlastindex(a,N,x);

    }


    return 0;
}

//https://practice.geeksforgeeks.org/problems/find-the-highest-number/0/?ref=self