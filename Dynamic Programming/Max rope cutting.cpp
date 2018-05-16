/*

https://practice.geeksforgeeks.org/problems/max-rope-cutting/0


Given a rope of length n meters, cut the rope in different parts of integer lengths 
in a way that maximizes product of lengths of all parts. You must make at least one cut.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is length of rope denoted by N.

Output:

Print the maximizes product of lengths of all parts.

Constraints:

1 ≤ T ≤ 50
1 ≤ N ≤ 100

Example:

Input:
2
2
5

Output:
1
6

*/

/*

This is dynamic programming problem: optimal sub-structure and overlapped sub-problem.

C[1...N] = max{ C[1...j]*C[j+1...N]; } for j:2...N;


*/