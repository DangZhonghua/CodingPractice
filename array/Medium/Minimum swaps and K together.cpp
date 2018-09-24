/*
https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together/0
Minimum swaps and K together

Given an array of n positive integers and a number k. 
Find the minimum number of swaps required to bring all the numbers less than or equal to k together.

Input:
The first line of input contains integer T denoting the number of test cases. 
For each test case,  the first line of input contains an integer n denoting the size of the array. 
Next line contains n space separated integers denoting the elements of the array. 
Next line contains an integer k denoting the number such that elements less than and equal to k are group together. 

Output:
For each test case, the output is an integer displaying the minimum swaps required.

Constraints:
1<=T<=100
1<=n<=50

Example:
Input
2
5
2 1 5 6 3
3
7
2 7 9 5 8 7 4
6
Output
1
2

Explanation:
1. To bring elements 2, 1, 3 together, swap element '5' with '3' 
such that final array will be- arr[] = {2, 1, 3, 6, 5}


2. To bring elements 2, 5, 4 together, swap element 7 with 5 & 9 with 4 
such that the final array will be {2,5,4,7,8,7,9} 

*/

/*
find maximum length of consecutive element which less the K; suppose the length is L;
total number which less than K is T

the number will be

*/