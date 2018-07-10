/*
Count even length 
https://practice.geeksforgeeks.org/problems/count-even-length/0/?ref=self

Given a number n, find count of all binary sequences of length 2n such that sum of first n bits 
is same as sum of last n bits.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains the integer n.

Output:

Print the count of all binary sequences of length 2n such that sum of first n bits is same as sum of last n bits. Since the answer can be quite large print the answer modulo 109+7. Print the answer in a new line for each test case in a new line.


Constraints:

1<= T <=100

1<= N <=1000


Example:

Input: n = 1

Output: 2

There are 2 sequences of length 2*n, the

sequences are 00 and 11

Input:

n = 2

Output:

6

There are 6 sequences of length 2*n, the

sequences are 0101, 0110, 1010, 1001, 0000

and 1111

*/