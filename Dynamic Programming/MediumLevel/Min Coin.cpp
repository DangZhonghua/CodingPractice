/*
Min Coin

https://practice.geeksforgeeks.org/problems/min-coin/0/?ref=self

Given the list of coins of distinct denominations and total amount of money. 
Output the minimum number of coins required to make up that amount.
Output -1 if that money cannot be made up using given coins.

You may assume that there are infinite numbers of coins of each type.

Input:

The first line contains 'T' denoting the number of testcases. Then follows description of testcases.
Each cases begins with the two space separated integers 'n' and 'amount' denoting 
the total number of distinct coins and total amount of money respectively.
The second line contains N space-separated integers A1, A2, ..., AN denoting the values of coins.

Output:

Print the minimum number of coins required to make up that amount or return -1 
if it is impossible to make that amount using given coins.

 
Constraints:

1<=T<=30
1<=n<=100
1<=Ai<=1000
1<=amount<=100000


Example:

Input :
2
3 11
1 2 5
2 7
2 6
  
Output :

3
-1

*/

/*

This is 0-1 knapsack problem.

*/