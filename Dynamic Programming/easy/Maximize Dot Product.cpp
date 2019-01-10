/*
https://practice.geeksforgeeks.org/problems/maximize-dot-product/0/?ref=self
Maximize Dot Product 

Given a array A with N elements and array B with M elements. You have to insert (N-M) zeroes in 
between array B such that the dot product of array A and array B is maximum. 

Definition of Dot Product : A.B = A[0]*B[0] + A[1]*B[1]+....A[N]*B[N].

Input :
The first line will contain T which denotes the number of test cases. 
The first line of each test case will contain integer N and M, denoting the length of array A and array B respectively. 
The second line of each test case will contain N integers denoting the elements of array A. 
The third line of each test case will contain M integers denoting the elements of array B.
 

Output:
For each test case, Output the maximized dot product in a new line .
 

Constraints :
1<=T<=10
1<= N,M<=1000
0<=A[i],B[i]<=10^7
 

Example
Input : 

1
3 1 
1 2 3
4

Output :
12 
*/