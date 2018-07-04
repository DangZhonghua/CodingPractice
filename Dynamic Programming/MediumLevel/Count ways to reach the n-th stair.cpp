/*
Count ways to reach the n’th stair
https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair/0/?ref=self
There are n stairs, a person standing at the bottom wants to reach the top. 
The person can climb either 1 stair or 2 stairs at a time. 
Count the number of ways, the person can reach the top (order does matter).

Input:
The first line contains an integer 'T' denoting the total number of test cases. 
In each test cases, an integer N will be given.


Output:
Print number of possible ways to reach Nth stair. Answer your output % 10^9+7.


Constraints:
1<=T<=10^5
1<=N<=10^5

Example:
Input:
3
4
10
24
Output:
5
89
75025

*/

/*

  C[N] = C[N-1] + C[N-2]
  Like fabnacci number.

*/

#include<iostream>
#include<vector>
using namespace std;

int gMode = 1000000007;

int CountWays(int N)
{
    unsigned long long    a[2] = {0};
    unsigned long long    num = 1;
    a[0] = 1;
    a[1] = 1;
    
    int i = 2;
    while(i<=N)
    {
      num = a[0] + a[1];
      num %= gMode;
      a[0] = a[1];
      a[1] = num;
      ++i;     
    }

    cout<<num<<endl;
    return 0;
}


int main()
{
   int t = 0;
   int N = 0;

   cin>>t;

   while(t--)
   {
       cin>>N;
       CountWays(N);
   }


    return 0;
}