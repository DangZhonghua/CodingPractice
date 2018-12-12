/*

Find minimum adjustment cost of an array 
https://practice.geeksforgeeks.org/problems/find-minimum-adjustment-cost-of-an-array/0
https://www.geeksforgeeks.org/find-minimum-adjustment-cost-of-an-array/


Given an array of positive integers, replace each element in the array such that the difference 
between adjacent elements in the array is less than or equal to a given target. We need to minimize the adjustment cost, 
that is the sum of differences between new and old values. 
We basically need to minimize ∑|A[i] – Anew[i]| where 0 <= i <= n-1, n is size of A[] and Anew[] 
is the array with adjacent difference less that or equal to target.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
The first line of each test case contains two integers N and K where N denotes the size of array A and K is the target.

The second line of each test case contains N space separated integers denoting elements of the array A[ ].

Output:

Print the minimum adjustment cost for each test case in a new line.

Constraints:
1<= T <=100
1<= N, K <=1000
1<= A[ ] <=100


Example:

Input:
4 1
1 3 0 3
Output:
3

*/

/*
optimal substructure and overlapped problem
1. optimal substructure:  subarray solution is contained in the origin solution.
2. overlapped subproblem: the min-cost end at every possible value.
*/

/*

mdc[i][j] = min { mdc[i-1][k] + abs(j-a[i])} for abs(j-k)<X(target) 

*/

#include<iostream>
#include<vector>
using namespace std;


int MinimumAdjustCost(vector<int>& a, int target)
{
    int ret = 0;

    

    return ret;
}





int main(int argc, char const *argv[])
{
    
    return 0;
}
