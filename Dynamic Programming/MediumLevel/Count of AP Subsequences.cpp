/*
https://practice.geeksforgeeks.org/problems/count-of-ap-subsequences/0
https://www.geeksforgeeks.org/count-arithmetic-progression-subsequences-array/

Count of AP Subsequences 

Given an array A[] of n positive integers. The task is to count the number of Arithmetic Progression subsequence in the array.

Note: Empty sequence or single element sequence is Arithmetic Progression. 

Examples:

Input : A[] = { 1, 2, 3 }
Output : 8
Arithmetic Progression subsequence from the 
given array are: {}, { 1 }, { 2 }, { 3 }, { 1, 2 },
{ 2, 3 }, { 1, 3 }, { 1, 2, 3 }.

Input : A[] = { 10, 20, 30, 45 }
Output : 12

Input : A[] = { 1, 2, 3, 4, 5 }
Output : 23

Input:
The first line of input contains an integer T denoting the no of test cases. 
Then T test cases follow. Each test case contains an integer n denoting size of the array. 
Then in the next line are n space separated values of the array.

Output:
For each test case in a new line print the required output.

Constraints:
1<=T<=100
1<=n<=100
1<=A[]<=100

Example:
Input:
2
3
1 2 3
4
10 20 30 45
Output:
8
12

*/