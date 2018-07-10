/*
Element with left side smaller and right side greater
https://practice.geeksforgeeks.org/problems/unsorted-array/0/?ref=self

Given an unsorted array of size N. Find the first element in array such that 
all of its left elements are smaller and all right elements to it are greater than it.

Note: Left and right side elements can be equal to required element. And extreme elements cannot be required element.

Input:
The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. Each test case consists of two lines. 
First line of each test case contains an Integer N denoting size of array 
and the second line contains N space separated array elements.

Output:
For each test case, in a new line print the required element. If no such element present in array then print -1.

Constraints:
1<=T<=100
3<=N<=10^6
1<=A[i]<=10^6

Example:
Input:
3
4
4 2 5 7
3
11 9 12
6
4 3 2 7 8 9

Output:
5
-1
7

2
4
7 14 16 18 
12
7 13 10 2 3 8 11 12 17 18 19  20

out:
14
17
*/

#include<iostream>
#include<vector>
using namespace std;

int WatchDog(int*a, int N)
{
    vector<bool> vbs(N+1, false);
    int max = a[0];
    int min = a[N-1];
    int index = -1;
    
    for(int i = 1; i<N; ++i)
    {
        if(a[i]>=max)
        {
            vbs[i] = true;
            max = a[i];
        }
    }

    for(int j = N-2; j>=0; --j)
    {
        if(a[j]<=min)
        {
            if(vbs[j])
            {
                index = j;
            }
            min = a[j];
        }
    }
    if( -1 != index)
    {
        cout<<a[index]<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }

    return 0;
}


int main()
{
    int t = 0;
    int a[1000001];
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
        WatchDog(a,N);
    }
    
    return 0;
}