/*
Recaman’s sequence
https://practice.geeksforgeeks.org/problems/recamans-sequence/0/?ref=self
Given an integer n. Print first n elements of Recaman’s sequence.
It is basically a function with domain and co-domain as natural numbers and 0. It is recursively defined as below:
Specifically, let a(n) denote the (n+1)-th term. (0 being already there).
The rule says:

a(0) = 0,
if n > 0 and the number is not already included in the sequence,
     a(n) = a(n - 1) - n 
else 
     a(n) = a(n-1) + n. 

      a(n-1)-n if a(n-1)-n > 0 and new
a(n) = a(n-1) + n 

Examples:

Input : n = 6
Output : 0, 1, 3, 6, 2, 7

Input  : n = 17
Output : 0, 1, 3, 6, 2, 7, 13, 20, 12, 21, 
         11, 22, 10, 23, 9, 24, 8


Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer N.

Output:
For each test case in a new line print the space separated values of the first n elements of the Recaman's series.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
3
6
Output:
0 1 3
0 1 3 6 2 7

*/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int RecamanSequence(int N)
{
  unordered_set< long long> hrs;
  vector< long long> a(N+1, 0);
  a[0] = 0;
  hrs.insert(0);

  for(int i = 1; i<=N; ++i)
  {
    if(a[i-1]-i >0 && hrs.end() != hrs.find(a[i-1] -i))
     {
       a[i] = a[i-1] - i;
     } 
     else
     {
       a[i] = a[i-1] + i;
     }
     hrs.insert(a[i]);
  }
  for(int i = 0; i<N; ++i)
  {
    cout<<a[i]<<" ";
  }
  cout<<endl;
  
  return 0;
}

int main(int argc, char const *argv[])
{
  int t = 0;
  cin>>t;
  while(t--)
  {
    int N = 0;
    cin>>N;
    RecamanSequence(N);
  }

  return 0;
}
