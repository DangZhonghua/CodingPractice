/*
Game of XOR 
https://practice.geeksforgeeks.org/problems/game-of-xor/0

You are given an array A[] of size N. Now, we call the value of an array the bit-wise XOR 
of all elements it contains. For example, the value of the array [1,2,3] = 1^2^3. 
Now, Your task is to find the bit-wise XOR of the values of all sub arrays of array A. 

Example:

Input: A[] = {1,2,3} 
Output: 2
xor[1] = 1, 
xor[1, 2] = 3
xor[2, 3] = 1
xor[1, 2, 3] = 0
xor[2] = 2
xor[3] = 3
Result : 1 ^ 3 ^ 1 ^ 0 ^ 2 ^ 3 = 2

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow . 
Each test case contains an integer N denoting the size of the array. 
Then in the next line are N space separated values of the array A[].

Output:
For each test case in a new line print the bit-wise XOR of the values of all sub arrays of array A

Constraints:
1<=T<=100
1<=N<=1000
1<=A[]<=10000

Example:
Input:
2
3
1 2 3 
4
1 2 3 4
Output:
2
0


*/