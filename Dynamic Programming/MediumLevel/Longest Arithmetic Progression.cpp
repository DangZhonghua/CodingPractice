/*
Longest Arithmetic Progression
https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression/0
https://www.geeksforgeeks.org/length-of-the-longest-arithmatic-progression-in-a-sorted-array/

Given an array of sorted numbers having no duplicates , write a program to find the length of the Longest Arithmetic Progression (LLAP) in it.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines.
The first line of each test case contains an integer N , where  N is the size of array.
The second line of each test case contains N space separated integers denoting array input A[i].

Output:
 Print the length of the Longest Arithmetic Progression ​

Constraints:
1 <=T<= 200
1 <= N <= 1000
1 <= arr[i] <= 10000

Example:

Input:
2
6
1  7 10  13  14  19
5
2 4  6 8 10

Output:
4
5

Explanation:
For test case 1:
set[] = {1, 7, 10, 13, 14, 19}
output = 4
The longest arithmetic progression is {1, 7, 13, 19}
For test case 2:
set[] = {2, 4, 6, 8, 10}
output = 5 
The whole set is in AP




*/