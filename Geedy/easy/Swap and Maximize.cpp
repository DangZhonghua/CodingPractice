/*

Swap and Maximize
https://practice.geeksforgeeks.org/problems/swap-and-maximize/0/?ref=self

Given an array of n elements. Consider array as circular array i.e element after an is a1. The task is to find maximum sum of the difference between consecutive elements with rearrangement of array element allowed i.e after rearrangement of element find |a1 – a2| + |a2 – a3| + …… + |an – 1– an| + |an – a1|.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains the number of elements in the array a[] as n and next line contains space separated n elements in the array a[].

Output:
Print an integer which denotes the maximized sum.

Constraints:
1<=T<=100
1<=n<=10000
1<=a[i]<=100000​

Example:
Input:
2
4
4 2 1 8
3
10 12 15​
Output:
18​
10

*/