/*
Rearrange an array with O(1) extra space 
https://practice.geeksforgeeks.org/problems/rearrange-an-array-with-o1-extra-space/0/?ref=self
Given an array arr[] of size n where every element is in range from 0 to n-1. Rearrange the given array so that arr[i] becomes arr[arr[i]]. This should be done with O(1) extra space.
 

Input:

First line contains an integer denoting the test cases 'T'. Every test case contains an integer value depicting size of array 'N' and N integer elements are to be inserted in the next line with spaces between them.


Output:

Print all elements of the array after rearranging, each separated by a space, in separate line for each test case.


Constraints:

1 <= T <= 70
1 <= N<= 100
1 <= Arr[i] <= 100
Arr[i]<=N


Example:

Input:

3
2
1 0
5
4 0 2 1 3
4
3 2 0 1

Output:

0 1
3 4 2 0 1
1 0 3 2



*/