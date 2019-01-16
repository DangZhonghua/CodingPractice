/*
Minimum cost to make Longest Common Subsequence of length k
https://www.geeksforgeeks.org/minimum-cost-make-longest-common-subsequence-length-k/

Given two string X, Y and an integer k. Now the task is to convert string X with minimum cost 
such that the Longest Common Subsequence of X and Y after conversion is of length k. 
The cost of conversion is calculated as XOR of old character value and new character value. 
Character value of ‘a’ is 0, ‘b’ is 1 and so on.

Examples:

Input : X = "abble", 
        Y = "pie",
        k = 2
Output : 25

If you changed 'a' to 'z', it will cost 0 XOR 25.

*/

/*

mc[k,i,j] = 

*/


#include<string>
#include<iostream>
#include<vector>
using namespace std;


int MinimumTransform(const string& x, const string& y, int K)
{
    int ret = 0;


    return ret;
}