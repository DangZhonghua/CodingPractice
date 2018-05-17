/*
Largest Independent Set Problem
https://practice.geeksforgeeks.org/problems/largest-independent-set-problem/1

Given a Binary Tree of size N, find size of the Largest Independent Set(LIS) in it. A subset of all tree nodes is an independent set if there is no edge between any two nodes of the subset. Your task is to complete the function LISS(), which finds the size of the Largest Independent Set.

For example:
Consider the following binary tree.The LIS is
LIS: [10, 40, 60, 70, 80]
Size: 5.

Input:
The function takes a single argument as input, the root of the binary tree. There will be T test cases and for each test case the function will be called separately.

Output:
For each test case function should return the size of the Largest Independent Set (LIS).

Constraints:
1<=T<=100
1<=N<=500

Example:
Input:
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R
Output:
2
3



*/