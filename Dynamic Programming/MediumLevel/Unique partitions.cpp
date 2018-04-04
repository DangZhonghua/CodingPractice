/*
https://practice.geeksforgeeks.org/problems/unique-partitions/0

Given a positive integer n, generate all possible unique ways to represent n as sum of positive integers. The output should be printed in lexicographically decreasing order partitions.  For example, if given number is 52, then 52 itself should be printed first, then 51 1, then 50 2,  ... and at the end partition with all 1s.

Note :  2+1 and 1+2 are considered as duplicates.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N.

Output:

Print all possible unique ways to represent n as sum of positive integers.

Constraints:

1 ≤ T ≤ 20
1 ≤ N ≤ 30

Example:

Input
2
3
4

Output
3 2 1 1 1 1
4 3 1 2 2 2 1 1 1 1 1 1


Explanation

For n=4 

4
3 1
2 2
2 1 1
1 1 1 1 

These 5 possible ways are there so that we can get the sum 4 .


*/