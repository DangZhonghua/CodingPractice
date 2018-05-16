/*
Max sum subarray by removing at most one element
https://practice.geeksforgeeks.org/problems/max-sum-subarray-by-removing-at-most-one-element/1

Given an array, the task is to complete the function which  finds the maximum sum subarray, where you may remove atmost one element to get the maximum sum.

Examples:

Input  : A[] = {1, 2, 3, -4, 5}
Output : 11
Explanation : We can get maximum sum subarray by
removing -4.

Input  : A[] = [-2, -3, 4, -1, -2, 1, 5, -3]
Output : 9
Explanation : We can get maximum sum subarray by
removing -2 as, [4, -1, 1, 5] summing 9, which is 
the maximum achievable sum.


Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
For each test case in a new line output will be the maximum sum subarray.

Constraints:
1<=T<=100
1<=N<=100
-1000<=A[]<=1000

Example(To be used only for expected output):
Input:
2
5
1 2 3 -4 5
8
-2 -3 4 -1 -2 1 5 -3

Output:
11
9
*/