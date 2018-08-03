/*
Largest subarray with 0 sum
https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1/?ref=self

Given an array having both positive an negative integers . 
Your task is to complete the function maxLen which returns the length of maximum subarray with 0 sum . 
The function takes two arguments an array A and n where n is the size of the array A . 

Input:
The first line of input contains an element T denoting the No of test cases. 
Then T test cases follow. Each test case consist of 2 lines. 
The first line of each test case contains a number denoting the size of the array A. 
Then in the next line are space separated values of the array A .

Output:
For each test case output will be the length of the largest subarray which has sum 0 .

Constraints:
1<=T<=100
1<=N<=100
-1000<=A[]<=1000

Example:
Input
1
8
15  -2  2  -8  1  7  10 23

Output
5


Explanation
In the above test case the  largest subarray with sum 0 will be -2  2  -8  1  7

*/

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete this function*/

#include<iostream>
#include<unordered_map>
using namespace std;

int maxLen(int A[],int n)
{
  //Your code here
  unordered_map<int, int> smap;
  int sum       = 0;
  int maxlen    = 0;
  for(int i = 0; i<n; ++i)
  {
     sum += A[i];
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



int main()
{
	int t = 0;
	int a[101];
	int N = 0;
	cin >> t;

	while (t--)
	{
		cin >> N;
		int i = 0;
		while (i < N)
		{
			cin >> a[i++];
		}
		maxLen(a, N);
	}
	
	return 0;
}