/*
https://practice.geeksforgeeks.org/problems/unique-partitions/0

Given a positive integer n, generate all possible unique ways to represent n as sum of positive integers.
The output should be printed in lexicographically decreasing order partitions.
For example, if given number is 52, then 52 itself should be printed first, then 51 1, then 50 2,  ... 
and at the end partition with all 1s.

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

22

Its Correct output is:
22 21 1 20 2 20 1 1 19 3 19 2 1 19 1 1 1 18 4 18 3 1 18 2 2 18 2 1 1 18 1 1 1 1 17 5 17 4 1 17 3 2 17 3 1 1 17 2 2 1 17 2 1 1 1 17 1 1 1 1 1 16 6 16 5 1 16 4 2 16 4 1 1 16 3 3 16 3 2 1 16 3 1 1 1 16 2 2 2 16 2 2 1 1 16 2 1 1 1 1 16 1 1 1 1 1 1 15 7 15 6 1 15 5 2 15 5 1 1 15 4 3 15 4 2 1 15 4 1 1 1 15 3 3 1 15 3 2 2 15 3 2 1 1 15 3 1 1 1 1 15 2 2 2 1 15 2 2 1 1 1 15 2 1 1 1 1 1 15 1 1 1 1 1 1 1 14 8 14 7 1 14 6 2 14 6 1 1 14 5 3 14 5 2 1 14 5 1 1 1 14 4 4 14 4 3 1 14 4 2 2 14 4 2 1 1 14 4 1 1 1 1 14 3 3 2 14 3 3 1 1 14 3 2 2 1 14 3 2 1 1 1 14 3 1 1 1 1 1 14 2 2 2 2 14 2 2 2 1 1 14 2 2 1 1 1 1 14 2 1 1 1 1 1 1 14 1 1 1 1 1 1 1 1 13 9 13 8 1 13 7 2 13 7 1 1 13 6 3 13 6 2 1 13 6 1 1 1 13 5 4 13 5 3 1 13 5 2 2 13 5 2 1 1 13 5 1 1 1 1 13 4 4 1 13 4 3 2 13 4 3 1 1 13 4 2 2 1 13 4 2 1 1 1 13 4 1 1 1 1 1 13 3 3 3 13 3 3 2 1 13 3 3 1 1 1 13 3 2 2 2 13 3 2 2 1 1 13 3 2 1 1 1 1 13 3 1 1 1 1 1 1 13 2 2 2 2 1 13 2 2 2 1 1 1 13 2 2 1 1 1 1 1 13 2 1 1 1 1 1 1 1 13 1 1 1 1 1 1 1 1 1 12 10 12 9 1 12 8 2 12 8 1 1 12 7 3 12 7 2 1 12 7 1 1 1 12 6 4 12 6 3 1 12 6 2 2 12 6 2 1 1 12 6 1 1 1 1 12 5 5 12 5 4 1 12 5 3 2 12 5 3 1 1 12 5 2 2 1 12 5 2 1 1 1 12 5 1 1 1 1 1 12 4 4 2 12 4 4 1 1 12 4 3 3 12 4 3 2 1 12 4 3 1 1 1 12 4 2 2 2 12 4 2 2 1 1 12 4 2 1 1 1 1 12 4 1 1 1 1 1 1 12 3 3 3 1 12 3 3 2 2 12 3 3 2 1 1 12 3 3 1 1 1 1 12 3 2 2 2 1 12 3 2 2 1 1 1 12 3 2 1 1 1 1 1 12 3 1 1 1 1 1 1 1 12 2 2 2 2 2 12 2 2 2 2 1 1 12 2 2 2 1 1 1 1 12 2 2 1 1 1 1 1 1 12 2 1 1 1 1 1 1 1 1 12 1 1 1 1 1 1 1 1 1 1 11 11 11 10 1 11 9 2 11 9 1 1 11 8 3 11 8 2 1 11 8 1 1 1 11 7 4 11 7 3 1 11 7 2 2 11 7 2 1 1 11 7 1 1 1 1 11 6 5 11 6 4 1 11 6 3 2 11 6 3 1 1 11 6 2 2 1 11 6 2 1 1 1 11 6 1 1 1 1 1 11 5 5 1 11 5 4 2 11 5 4 1 1 11 5 3 3 11 5 3 2 1 11 5 3 1 1 1 11 5 2 2 2 11 5 2 2 1 1 11 5 2 1 1 1 1 11 5 1 1 1 1 1 1 11 4 4 3 11 4 4 2 1 11 4 4 1 1 1 11 4 3 3 1 11 4 3 2 2 11 4 3 2 1 1 11 4 3 1 1 1 1 11 4 2 2 2 1 11 4 2 2 1 1 1 11 4 2 1 1 1 1 1 11 4 1 1 1 1 1 1 1 11 3 3 3 2 11 3 3 3 1 1 11 3 3 2 2 1 11 3 3 2 1 1 1 11 3 3 1 1 1 1 1 11 3 2 2 2 2 11 3 2 2 2 1 1 11 3 2 2 1 1 1 1 11 3 2 1 1 1 1 1 1 11 3 1 1 1 1 1 1 1 1 11 2 2 2 2 2 1 11 2 2 2 2 1 1 1 11 2 2 2 1 1 1 1 1 11 2 2 1 1 1 1 1 1 1 11 2 1 1 1 1 1 1 1 1 1 11 1 1 1 1 1 1 1 1 1 1 1 10 10 2 10 10 1 1 10 9 3 10 9 2 1 10 9 1 1 1 10 8 4 10 8 3 1 10 8 2 2 10 8 2 1 1 10 8 1 1 1 1 10 7 5 10 7 4 1 10 7 3 2 10 7 3 1 1 10 7 2 2 1 10 7 2 1 1 1 10 7 1 1 1 1 1 10 6 6 10 6 5 1 10 6 4 2 10 6 4 1 1 10 6 3 3 10 6 3 2 1 10 6 3 1 1 1 10 6 2 2 2 10 6 2 2 1 1 10 6 2 1 1 1 1 10 6 1 1 1 1 1 1 10 5 5 2 10 5 5 1 1 10 5 4 3 10 5 4 2 1 10 5 4 1 1 1 10 5 3 3 1 10 5 3 2 2 10 5 3 2 1 1 10 5 3 1 1 1 1 10 5 2 2 2 1 10 5 2 2 1 1 1 10 5 2 1 1 1 1 1 10 5 1 1 1 1 1 1 1 10 4 4 4 10 4 4 3 1 10 4 4 2 2 10 4 4 2 1 1 10 4 4 1 1 1 1 10 4 3 3 2 10 4 3 3 1 1 10 4 3 2 2 1 10 4 3 2 1 1 1 10 4 3 1 1 1 1 1 10 4 2 2 2 2 10 4 2 2 2 1 1 10 4 2 2 1 1 1 1 10 4 2 1 1 1 1 1 1 10 4 1 1 1 1 1 1 1 1 10 3 3 3 3 10 3 3 3 2 1 10 3 3 3 1 1 1 10 3 3 2 2 2 10 3 3 2 2 1 1 10 3 3 2 1 1 1 1 10 3 3 1 1 1 1 1 1 10 3 2 2 2 2 1 10 3 2 2 2 1 1 1 10 3 2 2 1 1 1 1 1 10 3 2 1 1 1 1 1 1 1 10 3 1 1 1 1 1 1 1 1 1 10 2 2 2 2 2 2 10 2 2 2 2 2 1 1 10 2 2 2 2 1 1 1 1 10 2 2 2 1 1 1 1 1 1 10 2 2 1 1 1 1 1 1 1 1 10 2 1 1 1 1 1 1 1 1 1 1 10 1 1 1 1 1 1 1 1 1 1 1 1 9 9 4 9 9 3 1 9 9 2 2 9 9 2 1 1 9 9 1 1 1 1 9 8 5 9 8 4 1 9 8 3 2 9 8 3 1 1 9 8 2 2 1 9 8 2 1 1 1 9 8 1 1 1 1 1 9 7 6 9 7 5 1 9 7 4 2 9 7 4 1 1 9 7 3 3 9 7 3 2 1 9 7 3 1 1 1 9 7 2 2 2 9 7 2 2 1 1 9 7 2 1 1 1 1 9 7 1 1 1 1 1 1 9 6 6 1 9 6 5 2 9 6 5 1 1 9 6 4 3 9 6 4 2 1 9 6 4 1 1 1 9 6 3 3 1 9 6 3 2 2 9 6 3 2 1 1 9 6 3 1 1 1 1 9 6 2 2 2 1 9 6 2 2 1 1 1 9 6 2 1 1 1 1 1 9 6 1 1 1 1 1 1 1 9 5 5 3 9 5 5 2 1 9 5 5 1 1 1 9 5 4 4 9 5 4 3 1 9 5 4 2 2 9 5 4 2 1 1 9 5 4 1 1 1 1 9 5 3 3 2 9 5 3 3 1 1 9 5 3 2 2 1 9 5 3 2 1 1 1 9 5 3 1 1 1 1 1 9 5 2 2 2 2 9 5 2 2 2 1 1 9 5 2 2 1 1 1 1 9 5 2 1 1 1 1 1 1 9 5 1 1 1 1 1 1 1 1 9 4 4 4 1 9 4 4 3 2 9 4 4 3 1 1 9 4 4 2 2 1 9 4 4 2 1 1 1 9 4 4 1 1 1 1 1 9 4 3 3 3 9 4 3 3 2 1 9 4 3 3 1 1 1 9 4 3 2 2 2 9 4 3 2 2 1 1 9 4 3 2 1 1 1 1 9 4 3 1 1 1 1 1 1 9 4 2 2 2 2 1 9 4 2 2 2 1 1 1 9 4 2 2 1 1 1 1 1 9 4 2 1 1 1 1 1 1 1 9 4 1 1 1 1 1 1 1 1 1 9 3 3 3 3 1 9 3 3 3 2 2 9 3 3 3 2 1 1 9 3 3 3 1 1 1 1 9 3 3 2 2 2 1 9 3 3 2 2 1 1 1 9 3 3 2 1 1 1 1 1 9 3 3 1 1 1 1 1 1 1 9 3 2 2 2 2 2 9 3 2 2 2 2 1 1 9 3 2 2 2 1 1 1 1 9 3 2 2 1 1 1 1 1 1 9 3 2 1 1 1 1 1 1 1 1 9 3 1 1 1 1 1 1 1 1 1 1 9 2 2 2 2 2 2 1 9 2 2 2 2 2 1 1 1 9 2 2 2 2 1 1 1 1 1 9 2 2 2 1 1 1 1 1 1 1 9 2 2 1 1 1 1 1 1 1 1 1 9 2 1 1 1 1 1 1 1 1 1 1 1 9 1 1 1 1 1 1 1 1 1 1 1 1 1 8 8 6 8 8 5 1 8 8 4 2 8 8 4 1 1 8 8 3 3 8 8 3 2 1 8 8 3 1 1 1 8 8 2 2 2 8 8 2 2 1 1 8 8 2 1 1 1 1 8 8 1 1 1 1 1 1 8 7 7 8 7 6 1 8 7 5 2 8 7 5 1 1 8 7 4 3 8 7 4 2 1 8 7 4 1 1 1 8 7 3 3 1 8 7 3 2 2 8 7 3 2 1 1 8 7 3 1 1 1 1 8 7 2 2 2 1 8 7 2 2 1 1 1 8 7 2 1 1 1 1 1 8 7 1 1 1 1 1 1 1 8 6 6 2 8 6 6 1 1 8 6 5 3 8 6 5 2 1 8 6 5 1 1 1 8 6 4 4 8 6 4 3 1 8 6 4 2 2 8 6 4 2 1 1 8 6 4 1 1 1 1 8 6 3 3 2 8 6 3 3 1 1 8 6 3 2 2 1 8 6 3 2 1 1 1 8 6 3 1 1 1 1 1 8 6 2 2 2 2 8 6 2 2 2 1 1 8 6 2 2 1 1 1 1 8 6 2 1 1 1 1 1 1 8 6 1 1 1 1 1 1 1 1 8 5 5 4 8 5 5 3 1 8 5 5 2 2 8 5 5 2 1 1 8 5 5 1 1 1 1 8 5 4 4 1 8 5 4 3 2 8 5 4 3 1 1 8 5 4 2 2 1 8 5 4 2 1 1 1 8 5 4 1 1 1 1 1 8 5 3 3 3 8 5 3 3 2 1 8 5 3 3 1 1 1 8 5 3 2 2 2 8 5 3 2 2 1 1 8 5 3 2 1 1 1 1 8 5 3 1 1 1 1 1 1 8 5 2 2 2 2 1 8 5 2 2 2 1 1 1 8 5 2 2 1 1 1 1 1 8 5 2 1 1 1 1 1 1 1 8 5 1 1 1 1 1 1 1 1 1 8 4 4 4 2 8 4 4 4 1 1 8 4 4 3 3 8 4 4 3 2 1 8 4 4 3 1 1 1 8 4 4 2 2 2 8 4 4 2 2 1 1 8 4 4 2 1 1 1 1 8 4 4 1 1 1 1 1 1 8 4 3 3 3 1 8 4 3 3 2 2 8 4 3 3 2 1 1 8 4 3 3 1 1 1 1 8 4 3 2 2 2 1 8 4 3 2 2 1 1 1 8 4 3 2 1 1 1 1 1 8 4 3 1 1 1 1 1 1 1 8 4 2 2 2 2 2 8 4 2 2 2 2 1 1 8 4 2 2 2 1 1 1 1 8 4 2 2 1 1 1 1 1 1 8 4 2 1 1 1 1 1 1 1 1 8 4 1 1 1 1 1 1 1 1 1 1 8 3 3 3 3 2 8 3 3 3 3 1 1 8 3 3 3 2 2 1 8 3 3 3 2 1 1 1 8 3 3 3 1 1 1 1 1 8 3 3 2 2 2 2 8 3 3 2 2 2 1 1 8 3 3 2 2 1 1 1 1 8 3 3 2 1 1 1 1 1 1 8 3 3 1 1 1 1 1 1 1 1 8 3 2 2 2 2 2 1 8 3 2 2 2 2 1 1 1 8 3 2 2 2 1 1 1 1 1 8 3 2 2 1 1 1 1 1 1 1 8 3 2 1 1 1 1 1 1 1 1 1 8 3 1 1 1 1 1 1 1 1 1 1 1 8 2 2 2 2 2 2 2 8 2 2 2 2 2 2 1 1 8 2 2 2 2 2 1 1 1 1 8 2 2 2 2 1 1 1 1 1 1 8 2 2 2 1 1 1 1 1 1 1 1 8 2 2 1 1 1 1 1 1 1 1 1 1 8 2 1 1 1 1 1 1 1 1 1 1 1 1 8 1 1 1 1 1 1 1 1 1 1 1 1 1 1 7 7 7 1 7 7 6 2 7 7 6 1 1 7 7 5 3 7 7 5 2 1 7 7 5 1 1 1 7 7 4 4 7 7 4 3 1 7 7 4 2 2 7 7 4 2 1 1 7 7 4 1 1 1 1 7 7 3 3 2 7 7 3 3 1 1 7 7 3 2 2 1 7 7 3 2 1 1 1 7 7 3 1 1 1 1 1 7 7 2 2 2 2 7 7 2 2 2 1 1 7 7 2 2 1 1 1 1 7 7 2 1 1 1 1 1 1 7 7 1 1 1 1 1 1 1 1 7 6 6 3 7 6 6 2 1 7 6 6 1 1 1 7 6 5 4 7 6 5 3 1 7 6 5 2 2 7 6 5 2 1 1 7 6 5 1 1 1 1 7 6 4 4 1 7 6 4 3 2 7 6 4 3 1 1 7 6 4 2 2 1 7 6 4 2 1 1 1 7 6 4 1 1 1 1 1 7 6 3 3 3 7 6 3 3 2 1 7 6 3 3 1 1 1 7 6 3 2 2 2 7 6 3 2 2 1 1 7 6 3 2 1 1 1 1 7 6 3 1 1 1 1 1 1 7 6 2 2 2 2 1 7 6 2 2 2 1 1 1 7 6 2 2 1 1 1 1 1 7 6 2 1 1 1 1 1 1 1 7 6 1 1 1 1 1 1 1 1 1 7 5 5 5 7 5 5 4 1 7 5 5 3 2 7 5 5 3 1 1 7 5 5 2 2 1 7 5 5 2 1 1 1 7 5 5 1 1 1 1 1 7 5 4 4 2 7 5 4 4 1 1 7 5 4 3 3 7 5 4 3 2 1 7 5 4 3 1 1 1 7 5 4 2 2 2 7 5 4 2 2 1 1 7 5 4 2 1 1 1 1 7 5 4 1 1 1 1 1 1 7 5 3 3 3 1 7 5 3 3 2 2 7 5 3 3 2 1 1 7 5 3 3 1 1 1 1 7 5 3 2 2 2 1 7 5 3 2 2 1 1 1 7 5 3 2 1 1 1 1 1 7 5 3 1 1 1 1 1 1 1 7 5 2 2 2 2 2 7 5 2 2 2 2 1 1 7 5 2 2 2 1 1 1 1 7 5 2 2 1 1 1 1 1 1 7 5 2 1 1 1 1 1 1 1 1 7 5 1 1 1 1 1 1 1 1 1 1 7 4 4 4 3 7 4 4 4 2 1 7 4 4 4 1 1 1 7 4 4 3 3 1 7 4 4 3 2 2 7 4 4 3 2 1 1 7 4 4 3 1 1 1 1 7 4 4 2 2 2 1 7 4 4 2 2 1 1 1 7 4 4 2 1 1 1 1 1 7 4 4 1 1 1 1 1 1 1 7 4 3 3 3 2 7 4 3 3 3 1 1 7 4 3 3 2 2 1 7 4 3 3 2 1 1 1 7 4 3 3 1 1 1 1 1 7 4 3 2 2 2 2 7 4 3 2 2 2 1 1 7 4 3 2 2 1 1 1 1 7 4 3 2 1 1 1 1 1 1 7 4 3 1 1 1 1 1 1 1 1 7 4 2 2 2 2 2 1 7 4 2 2 2 2 1 1 1 7 4 2 2 2 1 1 1 1 1 7 4 2 2 1 1 1 1 1 1 1 7 4 2 1 1 1 1 1 1 1 1 1 7 4 1 1 1 1 1 1 1 1 1 1 1 7 3 3 3 3 3 7 3 3 3 3 2 1 7 3 3 3 3 1 1 1 7 3 3 3 2 2 2 7 3 3 3 2 2 1 1 7 3 3 3 2 1 1 1 1 7 3 3 3 1 1 1 1 1 1 7 3 3 2 2 2 2 1 7 3 3 2 2 2 1 1 1 7 3 3 2 2 1 1 1 1 1 7 3 3 2 1 1 1 1 1 1 1 7 3 3 1 1 1 1 1 1 1 1 1 7 3 2 2 2 2 2 2 7 3 2 2 2 2 2 1 1 7 3 2 2 2 2 1 1 1 1 7 3 2 2 2 1 1 1 1 1 1 7 3 2 2 1 1 1 1 1 1 1 1 7 3 2 1 1 1 1 1 1 1 1 1 1 7 3 1 1 1 1 1 1 1 1 1 1 1 1 7 2 2 2 2 2 2 2 1 7 2 2 2 2 2 2 1 1 1 7 2 2 2 2 2 1 1 1 1 1 7 2 2 2 2 1 1 1 1 1 1 1 7 2 2 2 1 1 1 1 1 1 1 1 1 7 2 2 1 1 1 1 1 1 1 1 1 1 1 7 2 1 1 1 1 1 1 1 1 1 1 1 1 1 7 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 6 6 6 4 6 6 6 3 1 6 6 6 2 2 6 6 6 2 1 1 6 6 6 1 1 1 1 6 6 5 5 6 6 5 4 1 6 6 5 3 2 6 6 5 3 1 1 6 6 5 2 2 1 6 6 5 2 1 1 1 6 6 5 1 1 1 1 1 6 6 4 4 2 6 6 4 4 1 1 6 6 4 3 3 6 6 4 3 2 1 6 6 4 3 1 1 1 6 6 4 2 2 2 6 6 4 2 2 1 1 6 6 4 2 1 1 1 1 6 6 4 1 1 1 1 1 1 6 6 3 3 3 1 6 6 3 3 2 2 6 6 3 3 2 1 1 6 6 3 3 1 1 1 1 6 6 3 2 2 2 1 6 6 3 2 2 1 1 1 6 6 3 2 1 1 1 1 1 6 6 3 1 1 1 1 1 1 1 6 6 2 2 2 2 2 6 6 2 2 2 2 1 1 6 6 2 2 2 1 1 1 1 6 6 2 2 1 1 1 1 1 1 6 6 2 1 1 1 1 1 1 1 1 6 6 1 1 1 1 1 1 1 1 1 1 6 5 5 5 1 6 5 5 4 2 6 5 5 4 1 1 6 5 5 3 3 6 5 5 3 2 1 6 5 5 3 1 1 1 6 5 5 2 2 2 6 5 5 2 2 1 1 6 5 5 2 1 1 1 1 6 5 5 1 1 1 1 1 1 6 5 4 4 3 6 5 4 4 2 1 6 5 4 4 1 1 1 6 5 4 3 3 1 6 5 4 3 2 2 6 5 4 3 2 1 1 6 5 4 3 1 1 1 1 6 5 4 2 2 2 1 6 5 4 2 2 1 1 1 6 5 4 2 1 1 1 1 1 6 5 4 1 1 1 1 1 1 1 6 5 3 3 3 2 6 5 3 3 3 1 1 6 5 3 3 2 2 1 6 5 3 3 2 1 1 1 6 5 3 3 1 1 1 1 1 6 5 3 2 2 2 2 6 5 3 2 2 2 1 1 6 5 3 2 2 1 1 1 1 6 5 3 2 1 1 1 1 1 1 6 5 3 1 1 1 1 1 1 1 1 6 5 2 2 2 2 2 1 6 5 2 2 2 2 1 1 1 6 5 2 2 2 1 1 1 1 1 6 5 2 2 1 1 1 1 1 1 1 6 5 2 1 1 1 1 1 1 1 1 1 6 5 1 1 1 1 1 1 1 1 1 1 1 6 4 4 4 4 6 4 4 4 3 1 6 4 4 4 2 2 6 4 4 4 2 1 1 6 4 4 4 1 1 1 1 6 4 4 3 3 2 6 4 4 3 3 1 1 6 4 4 3 2 2 1 6 4 4 3 2 1 1 1 6 4 4 3 1 1 1 1 1 6 4 4 2 2 2 2 6 4 4 2 2 2 1 1 6 4 4 2 2 1 1 1 1 6 4 4 2 1 1 1 1 1 1 6 4 4 1 1 1 1 1 1 1 1 6 4 3 3 3 3 6 4 3 3 3 2 1 6 4 3 3 3 1 1 1 6 4 3 3 2 2 2 6 4 3 3 2 2 1 1 6 4 3 3 2 1 1 1 1 6 4 3 3 1 1 1 1 1 1 6 4 3 2 2 2 2 1 6 4 3 2 2 2 1 1 1 6 4 3 2 2 1 1 1 1 1 6 4 3 2 1 1 1 1 1 1 1 6 4 3 1 1 1 1 1 1 1 1 1 6 4 2 2 2 2 2 2 6 4 2 2 2 2 2 1 1 6 4 2 2 2 2 1 1 1 1 6 4 2 2 2 1 1 1 1 1 1 6 4 2 2 1 1 1 1 1 1 1 1 6 4 2 1 1 1 1 1 1 1 1 1 1 6 4 1 1 1 1 1 1 1 1 1 1 1 1 6 3 3 3 3 3 1 6 3 3 3 3 2 2 6 3 3 3 3 2 1 1 6 3 3 3 3 1 1 1 1 6 3 3 3 2 2 2 1 6 3 3 3 2 2 1 1 1 6 3 3 3 2 1 1 1 1 1 6 3 3 3 1 1 1 1 1 1 1 6 3 3 2 2 2 2 2 6 3 3 2 2 2 2 1 1 6 3 3 2 2 2 1 1 1 1 6 3 3 2 2 1 1 1 1 1 1 6 3 3 2 1 1 1 1 1 1 1 1 6 3 3 1 1 1 1 1 1 1 1 1 1 6 3 2 2 2 2 2 2 1 6 3 2 2 2 2 2 1 1 1 6 3 2 2 2 2 1 1 1 1 1 6 3 2 2 2 1 1 1 1 1 1 1 6 3 2 2 1 1 1 1 1 1 1 1 1 6 3 2 1 1 1 1 1 1 1 1 1 1 1 6 3 1 1 1 1 1 1 1 1 1 1 1 1 1 6 2 2 2 2 2 2 2 2 6 2 2 2 2 2 2 2 1 1 6 2 2 2 2 2 2 1 1 1 1 6 2 2 2 2 2 1 1 1 1 1 1 6 2 2 2 2 1 1 1 1 1 1 1 1 6 2 2 2 1 1 1 1 1 1 1 1 1 1 6 2 2 1 1 1 1 1 1 1 1 1 1 1 1 6 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 6 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 5 5 5 5 2 5 5 5 5 1 1 5 5 5 4 3 5 5 5 4 2 1 5 5 5 4 1 1 1 5 5 5 3 3 1 5 5 5 3 2 2 5 5 5 3 2 1 1 5 5 5 3 1 1 1 1 5 5 5 2 2 2 1 5 5 5 2 2 1 1 1 5 5 5 2 1 1 1 1 1 5 5 5 1 1 1 1 1 1 1 5 5 4 4 4 5 5 4 4 3 1 5 5 4 4 2 2 5 5 4 4 2 1 1 5 5 4 4 1 1 1 1 5 5 4 3 3 2 5 5 4 3 3 1 1 5 5 4 3 2 2 1 5 5 4 3 2 1 1 1 5 5 4 3 1 1 1 1 1 5 5 4 2 2 2 2 5 5 4 2 2 2 1 1 5 5 4 2 2 1 1 1 1 5 5 4 2 1 1 1 1 1 1 5 5 4 1 1 1 1 1 1 1 1 5 5 3 3 3 3 5 5 3 3 3 2 1 5 5 3 3 3 1 1 1 5 5 3 3 2 2 2 5 5 3 3 2 2 1 1 5 5 3 3 2 1 1 1 1 5 5 3 3 1 1 1 1 1 1 5 5 3 2 2 2 2 1 5 5 3 2 2 2 1 1 1 5 5 3 2 2 1 1 1 1 1 5 5 3 2 1 1 1 1 1 1 1 5 5 3 1 1 1 1 1 1 1 1 1 5 5 2 2 2 2 2 2 5 5 2 2 2 2 2 1 1 5 5 2 2 2 2 1 1 1 1 5 5 2 2 2 1 1 1 1 1 1 5 5 2 2 1 1 1 1 1 1 1 1 5 5 2 1 1 1 1 1 1 1 1 1 1 5 5 1 1 1 1 1 1 1 1 1 1 1 1 5 4 4 4 4 1 5 4 4 4 3 2 5 4 4 4 3 1 1 5 4 4 4 2 2 1 5 4 4 4 2 1 1 1 5 4 4 4 1 1 1 1 1 5 4 4 3 3 3 5 4 4 3 3 2 1 5 4 4 3 3 1 1 1 5 4 4 3 2 2 2 5 4 4 3 2 2 1 1 5 4 4 3 2 1 1 1 1 5 4 4 3 1 1 1 1 1 1 5 4 4 2 2 2 2 1 5 4 4 2 2 2 1 1 1 5 4 4 2 2 1 1 1 1 1 5 4 4 2 1 1 1 1 1 1 1 5 4 4 1 1 1 1 1 1 1 1 1 5 4 3 3 3 3 1 5 4 3 3 3 2 2 5 4 3 3 3 2 1 1 5 4 3 3 3 1 1 1 1 5 4 3 3 2 2 2 1 5 4 3 3 2 2 1 1 1 5 4 3 3 2 1 1 1 1 1 5 4 3 3 1 1 1 1 1 1 1 5 4 3 2 2 2 2 2 5 4 3 2 2 2 2 1 1 5 4 3 2 2 2 1 1 1 1 5 4 3 2 2 1 1 1 1 1 1 5 4 3 2 1 1 1 1 1 1 1 1 5 4 3 1 1 1 1 1 1 1 1 1 1 5 4 2 2 2 2 2 2 1 5 4 2 2 2 2 2 1 1 1 5 4 2 2 2 2 1 1 1 1 1 5 4 2 2 2 1 1 1 1 1 1 1 5 4 2 2 1 1 1 1 1 1 1 1 1 5 4 2 1 1 1 1 1 1 1 1 1 1 1 5 4 1 1 1 1 1 1 1 1 1 1 1 1 1 5 3 3 3 3 3 2 5 3 3 3 3 3 1 1 5 3 3 3 3 2 2 1 5 3 3 3 3 2 1 1 1 5 3 3 3 3 1 1 1 1 1 5 3 3 3 2 2 2 2 5 3 3 3 2 2 2 1 1 5 3 3 3 2 2 1 1 1 1 5 3 3 3 2 1 1 1 1 1 1 5 3 3 3 1 1 1 1 1 1 1 1 5 3 3 2 2 2 2 2 1 5 3 3 2 2 2 2 1 1 1 5 3 3 2 2 2 1 1 1 1 1 5 3 3 2 2 1 1 1 1 1 1 1 5 3 3 2 1 1 1 1 1 1 1 1 1 5 3 3 1 1 1 1 1 1 1 1 1 1 1 5 3 2 2 2 2 2 2 2 5 3 2 2 2 2 2 2 1 1 5 3 2 2 2 2 2 1 1 1 1 5 3 2 2 2 2 1 1 1 1 1 1 5 3 2 2 2 1 1 1 1 1 1 1 1 5 3 2 2 1 1 1 1 1 1 1 1 1 1 5 3 2 1 1 1 1 1 1 1 1 1 1 1 1 5 3 1 1 1 1 1 1 1 1 1 1 1 1 1 1 5 2 2 2 2 2 2 2 2 1 5 2 2 2 2 2 2 2 1 1 1 5 2 2 2 2 2 2 1 1 1 1 1 5 2 2 2 2 2 1 1 1 1 1 1 1 5 2 2 2 2 1 1 1 1 1 1 1 1 1 5 2 2 2 1 1 1 1 1 1 1 1 1 1 1 5 2 2 1 1 1 1 1 1 1 1 1 1 1 1 1 5 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 5 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 4 4 4 4 4 2 4 4 4 4 4 1 1 4 4 4 4 3 3 4 4 4 4 3 2 1 4 4 4 4 3 1 1 1 4 4 4 4 2 2 2 4 4 4 4 2 2 1 1 4 4 4 4 2 1 1 1 1 4 4 4 4 1 1 1 1 1 1 4 4 4 3 3 3 1 4 4 4 3 3 2 2 4 4 4 3 3 2 1 1 4 4 4 3 3 1 1 1 1 4 4 4 3 2 2 2 1 4 4 4 3 2 2 1 1 1 4 4 4 3 2 1 1 1 1 1 4 4 4 3 1 1 1 1 1 1 1 4 4 4 2 2 2 2 2 4 4 4 2 2 2 2 1 1 4 4 4 2 2 2 1 1 1 1 4 4 4 2 2 1 1 1 1 1 1 4 4 4 2 1 1 1 1 1 1 1 1 4 4 4 1 1 1 1 1 1 1 1 1 1 4 4 3 3 3 3 2 4 4 3 3 3 3 1 1 4 4 3 3 3 2 2 1 4 4 3 3 3 2 1 1 1 4 4 3 3 3 1 1 1 1 1 4 4 3 3 2 2 2 2 4 4 3 3 2 2 2 1 1 4 4 3 3 2 2 1 1 1 1 4 4 3 3 2 1 1 1 1 1 1 4 4 3 3 1 1 1 1 1 1 1 1 4 4 3 2 2 2 2 2 1 4 4 3 2 2 2 2 1 1 1 4 4 3 2 2 2 1 1 1 1 1 4 4 3 2 2 1 1 1 1 1 1 1 4 4 3 2 1 1 1 1 1 1 1 1 1 4 4 3 1 1 1 1 1 1 1 1 1 1 1 4 4 2 2 2 2 2 2 2 4 4 2 2 2 2 2 2 1 1 4 4 2 2 2 2 2 1 1 1 1 4 4 2 2 2 2 1 1 1 1 1 1 4 4 2 2 2 1 1 1 1 1 1 1 1 4 4 2 2 1 1 1 1 1 1 1 1 1 1 4 4 2 1 1 1 1 1 1 1 1 1 1 1 1 4 4 1 1 1 1 1 1 1 1 1 1 1 1 1 1 4 3 3 3 3 3 3 4 3 3 3 3 3 2 1 4 3 3 3 3 3 1 1 1 4 3 3 3 3 2 2 2 4 3 3 3 3 2 2 1 1 4 3 3 3 3 2 1 1 1 1 4 3 3 3 3 1 1 1 1 1 1 4 3 3 3 2 2 2 2 1 4 3 3 3 2 2 2 1 1 1 4 3 3 3 2 2 1 1 1 1 1 4 3 3 3 2 1 1 1 1 1 1 1 4 3 3 3 1 1 1 1 1 1 1 1 1 4 3 3 2 2 2 2 2 2 4 3 3 2 2 2 2 2 1 1 4 3 3 2 2 2 2 1 1 1 1 4 3 3 2 2 2 1 1 1 1 1 1 4 3 3 2 2 1 1 1 1 1 1 1 1 4 3 3 2 1 1 1 1 1 1 1 1 1 1 4 3 3 1 1 1 1 1 1 1 1 1 1 1 1 4 3 2 2 2 2 2 2 2 1 4 3 2 2 2 2 2 2 1 1 1 4 3 2 2 2 2 2 1 1 1 1 1 4 3 2 2 2 2 1 1 1 1 1 1 1 4 3 2 2 2 1 1 1 1 1 1 1 1 1 4 3 2 2 1 1 1 1 1 1 1 1 1 1 1 4 3 2 1 1 1 1 1 1 1 1 1 1 1 1 1 4 3 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 4 2 2 2 2 2 2 2 2 2 4 2 2 2 2 2 2 2 2 1 1 4 2 2 2 2 2 2 2 1 1 1 1 4 2 2 2 2 2 2 1 1 1 1 1 1 4 2 2 2 2 2 1 1 1 1 1 1 1 1 4 2 2 2 2 1 1 1 1 1 1 1 1 1 1 4 2 2 2 1 1 1 1 1 1 1 1 1 1 1 1 4 2 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 4 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 4 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 3 3 3 3 3 3 3 1 3 3 3 3 3 3 2 2 3 3 3 3 3 3 2 1 1 3 3 3 3 3 3 1 1 1 1 3 3 3 3 3 2 2 2 1 3 3 3 3 3 2 2 1 1 1 3 3 3 3 3 2 1 1 1 1 1 3 3 3 3 3 1 1 1 1 1 1 1 3 3 3 3 2 2 2 2 2 3 3 3 3 2 2 2 2 1 1 3 3 3 3 2 2 2 1 1 1 1 3 3 3 3 2 2 1 1 1 1 1 1 3 3 3 3 2 1 1 1 1 1 1 1 1 3 3 3 3 1 1 1 1 1 1 1 1 1 1 3 3 3 2 2 2 2 2 2 1 3 3 3 2 2 2 2 2 1 1 1 3 3 3 2 2 2 2 1 1 1 1 1 3 3 3 2 2 2 1 1 1 1 1 1 1 3 3 3 2 2 1 1 1 1 1 1 1 1 1 3 3 3 2 1 1 1 1 1 1 1 1 1 1 1 3 3 3 1 1 1 1 1 1 1 1 1 1 1 1 1 3 3 2 2 2 2 2 2 2 2 3 3 2 2 2 2 2 2 2 1 1 3 3 2 2 2 2 2 2 1 1 1 1 3 3 2 2 2 2 2 1 1 1 1 1 1 3 3 2 2 2 2 1 1 1 1 1 1 1 1 3 3 2 2 2 1 1 1 1 1 1 1 1 1 1 3 3 2 2 1 1 1 1 1 1 1 1 1 1 1 1 3 3 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 3 3 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 3 2 2 2 2 2 2 2 2 2 1 3 2 2 2 2 2 2 2 2 1 1 1 3 2 2 2 2 2 2 2 1 1 1 1 1 3 2 2 2 2 2 2 1 1 1 1 1 1 1 3 2 2 2 2 2 1 1 1 1 1 1 1 1 1 3 2 2 2 2 1 1 1 1 1 1 1 1 1 1 1 3 2 2 2 1 1 1 1 1 1 1 1 1 1 1 1 1 3 2 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 3 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 3 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 1 1 2 2 2 2 2 2 2 2 2 1 1 1 1 2 2 2 2 2 2 2 2 1 1 1 1 1 1 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1 1 1 2 2 2 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2 2 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1


*/

/*

    Dynamic Programming: (1)Optimal sub-structure (2) overlapped sub-problems. 
    But it is general description. For practical problem: analyze the charactic of problem target with
    reduce the problem scale, and but whole from small scale.

*/


#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;


static const int max_count = 40;

struct parition
{
    vector<int> seg;
    parition(int v)
    {
        seg.push_back(v);
    }
    parition()
    {

    }
};

int UniquePartition(int N)
{
    vector< parition > segarr[max_count];

    segarr[1].push_back(parition(1));
    for(int n = 2; n<=N; ++n)
    {
        segarr[n].push_back(parition(n));
        int base       = n-1;
        int preindex   = 1;

        while(base >= (n/2 + n%2) || preindex<segarr[n-1].size())
        {
            if(base >=segarr[n-1][preindex].seg[0])
            {
                parition p;
                p.seg.push_back(base);
                p.seg.push_back(n-base);
                segarr[n].push_back(p);
                --base;
            }
            else
            {
                parition p;
                for(int i  = 0; i< segarr[n-1][preindex].seg.size(); ++i)
                {
                    p.seg.push_back(segarr[n-1][preindex].seg[i]);
                }
                p.seg.push_back(1);
                segarr[n].push_back(p);
                ++preindex;
            }
        }
    }
    
    for(int k = 0; k < segarr[N].size(); ++k)
    {
        for(int i = 0; i< segarr[N][k].seg.size();++i)
        {
            cout<<segarr[N][k].seg[i]<<" ";
        }
    }
    cout<<endl;
    

    return 0;
}


int main()
{
    int t = 0;
    int N = 0;

    cin>>t;
    
    while(t--)
    {
        cin>>N;
        UniquePartition(N);
    }


    return 0;
}