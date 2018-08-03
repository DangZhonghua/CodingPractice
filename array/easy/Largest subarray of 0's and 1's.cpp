/*
Largest subarray of 0's and 1's 
https://practice.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1/?ref=self
https://www.geeksforgeeks.org/largest-subarray-with-equal-number-of-0s-and-1s/

Given an array of 0's and 1's your task is to complete the function maxLen which returns  size of  the  largest sub array with equal number of 0's and 1's .
The function maxLen takes 2 arguments .The first argument is the array A[] and second argument is the size 'N' of the array A[] .

Input:
The first line of the input is T denoting the number of test cases .
Then T test cases follow . Each test case contains two lines . 
The first line of each test case is a number N denoting the size of the array and in the next line are N space separated values of A [ ].

Output:
For each test case output in a new line the max length of the subarray .

Constraints:
1<=T<=100
1<=N<=100
0<=A[ ] <=1

Example:
Input (To be used only for expected output) :
2
4
0 1 0 1
5
0 0 1 0 0 

Output
4
2


*/

#include<iostream>
using namespace std;

// This is O(n^2) solution.
int maxLen(int a[], int n)
{
//Your code here
    int max = -1;
    int sum = 1;
    for(int i = 0; i<n; ++i)
    {
        sum = (a[i]==0? -1:1);
        for(int j = i+1; j<n; ++j)
        {
            sum +=(a[j] ==0? -1: 1);
            if(0 == sum && max<j-i+1)
            {
                max = j-i+1;
            }
        }
    }
    
    return max;
}

#include<unordered_map>
using namespace std;

int maxLen(int arr[], int n)
{
//Your code here
unordered_map<int, int> smap;
  int sum       = 0;
  int maxlen    = 0;
  for(int i = 0; i<n; ++i)
  {
      if(0 == arr[i])
      {
          sum -= 1;
      }
      else
      {
          sum +=1;
      }
     
     if(0 == sum && maxlen< (i+1) )
     {
         maxlen = i+1;
     }
     
     unordered_map<int, int>::iterator it = smap.end();
    
     it = smap.find(sum);
     if(it !=  smap.end() )
     {
         if(maxlen< (i-it->second) )
         {
             maxlen = i- it->second;
         }
     }
     else
     {
         smap[sum] = i;
     }
  }
  
 
 return maxlen;
}