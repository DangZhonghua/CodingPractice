/*
Find nth element of spiral matrix 
https://practice.geeksforgeeks.org/problems/find-nth-element-of-spiral-matrix/1

Given a matrix your task is to find the kth element which is obtained while traversing the matrix spirally. 
You need to complete the method findK which takes four arguments the first argument is the matrix A 
and the next two arguments will be n and m denoting the size of the matrix A 
and then the forth argument is an integer  k denoting the kth element . 
The function will return the kth element obtained while traversing the matrix spirally.


Input:
The first line of input is the no of test cases then T test cases follow . The first line of each test case has three integers n,m and k . Then in the next line are n*m space separated values of the matrix A [ ] [ ] .

Output:
The output for each test case will be the kth obtained element .

Constraints:
1<=T<=100
1<=n,m<=20
1<=k<=n*m

Example:
Input
1
3 3 4
1 2 3 4 5 6 7 8 9 

Output
6

Explanation
The matrix above will look like 
1 2 3
4 5 6
7 8 9
and the 4th element in spiral fashion will be 6 .


*/