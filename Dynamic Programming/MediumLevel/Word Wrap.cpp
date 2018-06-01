/*
Word Wrap 
https://practice.geeksforgeeks.org/problems/word-wrap/0

Given an array of size N, which denotes the number of characters in one word. 
The task is simple, count the number of words in a single line with space character between two words.

Input:
First line contains the number of test cases T. First line of every test case consists of N, 
denoting number of elements in array. Second line consists of elements in array. 
Third line consists of characters allowed per line.

Output:
Single line output,print 2*N spaced integers, denoting from which word to word in every line.
(for more clearance of output, look the output in example).

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
4
3 2 2 5
6
3
3 2 2
4
Output:
1 1 2 3 4 4 
1 1 2 2 3 3 

For the first test case.
Line number 1: From word no. 1 to 1
Line number 2: From word no. 2 to 3
Line number 3: From word no. 4 to 4 

*/