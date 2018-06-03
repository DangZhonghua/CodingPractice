/*
Peak element 
https://practice.geeksforgeeks.org/problems/peak-element/1

Given an array of integers. The task is to find a peak element in it. 
An array element is peak if it is not smaller than its neighbors. 
For corner elements, we need to consider only one neighbor. 
For example, for input array {5, 10, 20, 15}, 20 is the only peak element. 
For input array {10, 20, 15, 2, 23, 90, 67}, there are two peak elements: 20 and 90. 

Note: There may be multiple peak element possible, in that case you may return any valid index.

Input:
The first line of input contains an integer T denoting the no of test cases. 
Then T test cases follow. Each test case contains an integer N. 
Then in the next line are N space separated values of the array.

Output:
For each test case output will be 1 if the index returned by the function is an peak index.

Constraints:
1<=T<=100
1<=N<=100
1<=A[]<=1000

Example:
Input:
2
3
1 2 3
2
3 4
Output:
1
1


*/

#include<vector>
#include<iostream>
using namespace std;

int peak(int a[], int n)
{
    if(n == 1)
    {
        return 0;
    }
    if(a[0]>=a[1])
    {
        return 0;
    }
    if(a[n-1]>= a[n-2])
    {
        return n-1;
    }


   for(int i = 1; i<n-1; ++i)
   {
      if(a[i]>=a[i-1] && a[i]>= a[i+1])
      {
          return i;
      }
   }

    return 0;
}


int main()
{
    int t = 0;
    int N = 0;
    int a[101];

    cin>>t;
    
    while(t--)
    {
        cin>>N;
        int i = 0;
        
        while(i<N)
        {
            cin>>a[i++];
        }
        peak(a,N);
    }


    return 0;
}