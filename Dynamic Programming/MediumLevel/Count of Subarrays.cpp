/*
Count of Subarrays 
https://practice.geeksforgeeks.org/problems/minimum-steps-to-delete-a-string/0

Given an array of N positive integers  a1, a2 ............ an.
The value of each contiguous subarray in given array is the maximum element present in that subarray. Return the number of subarrays having value strictly greater than K.

Input:

The first line of the input contains 'T' denoting the total number of testcases.Then follows the description of testcases.
The first line of each testcase contains two space separated positive integers N and K denoting the size of array and the value of K. The second line contains N space separated positive integers denoting the elements of array.

Output:

Output the number of subarrays having value strictly greater than K.

Constraints:

1<=T<=50
1<=N<=100
1<=a[i]<=10^5

Example:

Input:
2
3 2
3 2 1
4 1
1 2 3 4

Output:
3
9



*/