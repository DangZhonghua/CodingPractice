/*
Count in array
https://practice.geeksforgeeks.org/problems/count-in-array/0
https://www.geeksforgeeks.org/count-arrays-adjacent-elements-one-divide-another/
Given two positive integer n and m The task is to find the number of arrays of size n that can be formed such that :
1. Each element is in range [1, m]

2. All adjacent element are such that one of them divide the another i.e element Ai divides Ai + 1 or Ai + 1 divides Ai.

Examples:

Input : n = 3, m = 3.
Output : 17
{1,1,1}, {1,1,2}, {1,1,3}, {1,2,1}, 
{1,2,2}, {1,3,1}, {1,3,3}, {2,1,1},
{2,1,2}, {2,1,3}, {2,2,1}, {2,2,2},
{3,1,1}, {3,1,2}, {3,1,3}, {3,3,1}, 
{3,3,3} are possible arrays.

Input : n = 1, m = 10.
Output : 10


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two space separated integers n and m.

Output:
For each test case print the required output in a new line. The output could be long take modulo 10^9+7.

Constraints:
1<=T<=100
1<=n,m<=100

Example:
Input:
2
3 3
1 10

Output:
17
10

*/