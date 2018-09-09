/*

Number of ways to represent a number as sum of k fibonacci numbers
https://www.geeksforgeeks.org/number-of-ways-to-represent-a-number-as-sum-of-k-fibonacci-numbers/
Given two numbers N and K. Find the number of ways to represent N as the sum of K Fibonacci numbers.

Examples:

Input : n = 12, k = 1 
Output : 0

Input : n = 13, k = 3
Output : 2
Explanation : 2 + 3 + 8, 3 + 5 + 5.  

Approach: The Fibonacci series is f(0)=1, f(1)=2 and f(i)=f(i-1)+f(i-2) for i>1. 
Let’s suppose F(x, k, n) be the number of ways to form the sum x using exactly k numbers from f(0), f(1), …f(n-1). 
To find a recurrence for F(x, k, n), notice that there are two cases: whether f(n-1) in the sum or not.

    f f(n-1) is not in the sum, then x is formed as a sum using exactly k numbers from f(0), f(1), …, f(n-2).
    If f(n-1) is in the sum, then the remaining x-f(n-1) is formed using exactly k-1 numbers from f(0), f(1), …, f(n-1). (Notice that f(n-1) is still included because duplicate numbers are allowed.).

So the recurrence relation will be:

    F(x, k, n)= F(x, k, n-1)+F(x-f(n-1), k-1, n)

Base cases:

    If k=0, then there are zero numbers from the series, so the sum can only be 0. Hence, F(0, 0, n)=1.
    F(x, 0, n)=0, if x is not equals to 0.

*/

/*

This is 2D knapsack problems.
Select ith element or not select ith element

f[i][N][k] += f[i-1][N-fibo[i-1]][k-1];

*/



#include<iostream>
#include<vector>
using namespace std;

int FibonacciWay(int N,int K, vector<int>& vf)
{
    vector<int>  w(N+1, 0);
    
    for(int i = 0; i<K; ++i)



}