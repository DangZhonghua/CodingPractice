/*
Longest Zig-Zag Sub Sequence 
https://practice.geeksforgeeks.org/problems/longest-zig-zag-sub-sequence/0/?ref=self
The longest Zig-Zag subsequence problem is to find the length of the longest subsequence of 
given sequence such that all elements of this are alternating.
If a sequence {x1, x2, .. xn} is alternating sequence then its element satisfy one of the following relation:

  x1 < x2 > x3 < x4 > x5 < …. xn or 
  x1 > x2 < x3 > x4 < x5 > …. xn 

Input:
The first line of input contains an integer T denoting the number of test cases. 
Each test case contains an integer n which denotes the number of elements in the array a[]. 
Next line contains space separated n elements in the array a[].​

Output:
Print the length of the longest such subsequence.

Constraints:
1<=T<=200
1<=n<=1000
1<=a[i]<=10000​​

Example:
Input:
2
6
5 5 10 100 10 5
3
1 2 3

Output:
3
2

*/

/*

Dynamic Programming:overlapped subproblem and optimal structure.

*/