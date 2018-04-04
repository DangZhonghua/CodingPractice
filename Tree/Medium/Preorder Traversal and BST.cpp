/*
https://practice.geeksforgeeks.org/problems/preorder-traversal-and-bst/0


Given an array, write a program that prints 1 if given array can represent preorder traversal of a BST, else prints 0.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N,N is the size of array.
The second line of each test case contains N input A[i].

Output:
Should print 1 if given array can represent preorder traversal of BST. Otherwise 0.

Constraints:
1 <=T<= 55
1 <= N <= 1000
1 <= arr[i] <= 1000

Example:

Input:
3
5
40 30 35 80 100
8
40 30 32 35 80 90 100 120
8
7  9 6 1 4 2 3 40

Output:
1
1
0

*/

/*

This problem main purpose: construct BST from tree pre-order seq. if the BST can be constructed
so its true.

*/