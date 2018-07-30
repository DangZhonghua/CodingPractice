/*
Longest Span with same Sum in two Binary arrays
https://practice.geeksforgeeks.org/problems/longest-span-with-same-sum-in-two-binary-arrays/0/?ref=self
Given two binary arrays arr1[] and arr2[] of same size n. Find length of the longest common span (i, j) where j >= i such that arr1[i] + arr1[i+1] + …. + arr1[j] = arr2[i] + arr2[i+1] + …. + arr2[j]. Elements are only 0 or 1.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'N' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array. The third line contains N space-separated integers B1, B2, ..., BN denoting the elements of the array.


Output:
In each seperated line output the maximum span with same sum.


Constraints:
1<=T<=31
1<=N<=100


Example:
Input:
1
6
0 1 0 0 0 0
1 0 1 0 0 1

Output:
4

Explaination :

Input: arr1[] = {0, 1, 0, 0, 0, 0};
       arr2[] = {1, 0, 1, 0, 0, 1};
Output: 4
The longest span with same sum is from index 1 to 4  (Zero indexing).



*/