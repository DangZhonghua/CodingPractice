/*
Friends Pairing Problem 
https://practice.geeksforgeeks.org/problems/friends-pairing-problem/0/?ref=self

Given n friends, each one can remain single or can be paired up with some other friend. 
Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.

Examples:

Input  : n = 3
Output : 4
Explanation
{1}, {2}, {3} : all single
{1}, {2,3} : 2 and 3 paired but 1 is single.
{1,2}, {3} : 1 and 2 are paired but 3 is single.
{1,3}, {2} : 1 and 3 are paired but 2 is single.
Note that {1,2} and {2,1} are considered same.


Input:
The first line of input contains an integer T denoting the no of test cases. 
Then T test cases follow. Each test case contains an integer N.

Output:
For each test case in a new line print the required answer mod 10^9+7.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
3
2
Output:
4
2


*/