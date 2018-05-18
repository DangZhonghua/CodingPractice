/*
Count ways to express N as the sum of 1,3 and 4

https://practice.geeksforgeeks.org/problems/count-ways-to-express-n-as-the-sum-of-13-and-4/0

Given N, count the number of ways to express N as sum of 1, 3 and 4.

Input:

The first line of the input contains a single integer T, denoting the number of test cases. Then T test case follows, a single line of the input containing a positive integer N.

Output: 
For each test case, print number of ways to express N and print under modulo 10^9+7.


Constraints:

1<=T<=100
1<=N<=10000
 

Example:
Input:
2
4
5
Output:
4
6

Explanation:
Test Case 1:  For N = 4,     we can expres 4 in { 1+1+1+1} {1+3} {3+1} {4} So, total no. of ways are 4.

*/

/*

This is dynamic programming problem:  overlapped sub-problems and optimal sub-structure.
This is a variable of complete knapsack problem.

c[N] = C[N-1]+C[N-3]+C[N-4]
c[0] = 1;

*/

#include<iostream>
using namespace std;


int comp[] = {1,3,4};

int CountCombineWays(int N)
{
    unsigned long long  c[10001] = {0};
    c[0] = 1;
    for(int i = 1; i<=N;++i)
    {
        for(int n = 0; n<3; ++n)
        {
            if(i-comp[n]>=0)
            {
                c[i] += c[i-comp[n]];
            }
        }
        c[i] %=(1000000007);
    }

    cout<<c[N]%(1000000007)<<endl;


    return 0;
}



int main()
{
    int t = 0;
    int N = 0;
    
    cin>>t;
    
    while(t>0)
    {
        --t;
        cin>>N;
        CountCombineWays(N);
    }

    return 0;
}