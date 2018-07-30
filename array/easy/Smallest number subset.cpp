/*
Smallest number subset
https://practice.geeksforgeeks.org/problems/smallest-number-subset/0/?ref=self

Given an array A[ ] of N sorted positive integers, find the smallest positive integer S such that S cannot be represented as sum of elements of any subset of the given array set.

Input
The first line of input contains an integer T denoting the number of test cases. Then T test cases
follow. 
The first line of each test case contains a positive integer N, denoting the length of the array A[ ].
The second line of each test case contains a N space separated positive integers, denoting the
elements of the array A[ ].

Note: The elements of the array should be sorted in ascending order.


Output
Print out the the smallest number S that is not equal to sum of elements of any subset.

Constraints
1 <= T <= 100
0 <   N <=30
0 <= A[ ] <= 100
 

Examples 

Input
4
3
1 2 3
4
1 10 12 20
6
3 6 9 10 20 28
5
1 1 1 2 3

Output
7
2
1
9


*/