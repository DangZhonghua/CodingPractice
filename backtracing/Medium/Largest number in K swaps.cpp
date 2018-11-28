/*
Largest number in K swaps 
https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps/0
https://www.geeksforgeeks.org/find-maximum-number-possible-by-doing-at-most-k-swaps/


Given a number K and string S of digits denoting a positive integer, 
build the largest number possible by performing swap operations on the digits of S atmost K times.

Input
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
The first line of each test case contains a positive integer K.
The second line of each test case contains a string of digits denoting a positive integer.


Output
Print out the largest number possible.


Constraints
1 <= T <= 100
0 <   S <= 30
0 <   K  <= 10

Examples 

Input
3
4
1234567
3
3435335
2
1034

Output
7654321
5543333
4301

*/
#include<string>
#include<iostream>
using namespace std;


void btSwap(string& x, int K, string& strMax)
{
    
}

int MaximumValueBySwap(string& x, int K)
{
    int ret = 0;
    string strMax = 0;
    
    btSwap(x,K, strMax);


    return ret;
}