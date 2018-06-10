/*
Jumping Numbers 
https://practice.geeksforgeeks.org/problems/jumping-numbers/0

Given a positive number x, print all Jumping Numbers smaller than or equal to x. A number is called as a Jumping Number if all adjacent digits in it differ by 1. The difference between ‘9’ and ‘0’ is not considered as 1. All single digit numbers are considered as Jumping Numbers. For example 7, 8987 and 4343456 are Jumping numbers but 796 and 89098 are not.

Input:
The first line of the input contains T denoting the number of testcases. Each testcase contain a positive number 'x'.
Output:
All the jumping numbers less than 'x' are generated in increasing order of the most significant digit. See example for better understanding.


Constraints:
1 <=T<= 100
1 <=N<= 100000


Example:
Input:
2
10
50
Output:
0 1 10 2 3 4 5 6 7 8 9
0 1 10 12 2 21 23 3 32 34 4 43 45 5 6 7 8 9

Here, the most significant digits of each jumping number is following increasing order, i.e., 
jumping numbers starting from 0, followed by 1, then 2 and so on, themselves being in increasing order 2, 21, 23.


*/