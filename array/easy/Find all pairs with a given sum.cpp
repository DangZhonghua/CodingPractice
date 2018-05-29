/*
Find all pairs with a given sum 
https://practice.geeksforgeeks.org/problems/find-all-pairs-whose-sum-is-x/0
Given two unsorted arrays A[] of size n and B[] of size m of distinct elements, the task is to find all pairs from both arrays whose sum is equal to x.

Examples:

Input :  A[] = {-1, -2, 4, -6, 5, 7}
         B[] = {6, 3, 4, 0}  
         x = 8
Output : 4 4, 5 3

Input : A[] = {1, 2, 4, 5, 7} 
        B[] = {5, 6, 3, 4, 8}  
        x = 9
Output : 1 8, 4 5, 5 4


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains 3 lines . The first line contains 3 space separated integers n, m, x. Then in the next two lines are space separated values of the array A and B respectively.

Output:
For each test case in a new line print the sorted space separated values of all the pairs u,v where u belongs to array A and v belongs to array B, such that each pair is separated from the other by a ',' without quotes also add a space after the ',' . If no such pair exist print -1.

Constraints:
1<=T<=100
1<= n, m, x=1000
-1000<= A[], B[]<=1000

Example:
Input:
2
5 5 9
1 2 4 5 7
5 6 3 4 8
2 2 3
0 2
1 3
Output:
1 8, 4 5, 5 4
0 3, 2 1

*/