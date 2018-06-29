/*
Longest alternating subsequence 
https://practice.geeksforgeeks.org/problems/longest-alternating-subsequence/0/?ref=self

A sequence {x1, x2, .. xn} is alternating sequence if its elements satisfy one of the following relations :

x1 < x2 > x3 < x4 > x5..... or  x1 >x2 < x3 > x4 < x5.....

Your task is to find the longest such sequence.

 

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting the size array A.

The second line of each test case contains N space separated integers denoting elements of the array A[ ].


Output:

Print the length of the longest alternating subsequence for each testcase in a new line.


Constraints:

1<= T <=100

1<= N <=1000

1<= A[ ] <=1000


Example:

Input:

2

3

1 5 4

8

10 22 9 33 49 50 31 60

Output:

3

6

*/