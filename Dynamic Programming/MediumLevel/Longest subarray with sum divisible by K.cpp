/*
Longest subarray with sum divisible by K
https://practice.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k/0
Given an array containing N integers and a positive integer K. The task is to find the length of the longest sub array with sum of the elements divisible by the given value K.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains two Integers N and K and the second line contains N space separated elements.

Output:
For each test case, print the required longest sub array length in new line.

Constraints:
1<=T<=100
1<=N,K<=106
-105<=A[i]<=105

Example:
Input:
2
6 3
2 7 6 1 4 5
7 3
-2 2 -5 12 -11 -1 7
Output:
4
5

Explanation:

Input : A[] = {2, 7, 6, 1, 4, 5}, K = 3
Output : 4
The subarray is {7, 6, 1, 4} with sum 18,
which is divisible by 3.



*/