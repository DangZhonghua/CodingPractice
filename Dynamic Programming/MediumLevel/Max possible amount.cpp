/*

https://practice.geeksforgeeks.org/problems/max-possible-amount/0

Given a row of n coins of values v1 , v2 ... vn, where n is even. We play a game against an opponent by alternating turns. 
In each turn, a player selects either the first or last coin from the row, 
removes it from the row permanently, and receives the value of the coin. 
Determine the maximum possible amount of money we can definitely win if we move first.

Note : The opponent is as clever as the user.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
Each test case consists of two lines.
The first line of each test case contains an integer N, where N is the number of coins.
The second line of each test case contains N  space separated integers denoting input for v[ ].

Output:

Corresponding to each test case, print in a new line, the maximum possible amount of money.

Constraints:
1 ≤ T ≤ 100
2 ≤ N ≤ 100
1 ≤ v[i] ≤ 500

Example:
Input
2
4
5 3 7 10
4
8 15 3 7

Output
15
22

*/

/*

What is the optimal sub-structure and overlapped subproblems.
count[0...N] = max{a[N] + count[0...N-1], a[0] + count[1...N]}

Dynamic problem need check every sub-problems and chose the best choice.
*/