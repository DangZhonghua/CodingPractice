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

This is complete knapsack problem.
1
32 22417
765 992 1 521 220 380 729 969 184 887 104 641 909 378 724 582 387 583 241 294 159 198 653 369 418 692 36 901 516 623 703 971


mc[amount] = min{mc[amount-coin[i]] + 1}  if mc[amount-coin[i]] exist for i = 0...N

*/

#include<iostream>
#include<vector>
#include<climits>
#include <algorithm>
using namespace std;

int minCoin(int* coin, int N, int amount)
{
	//vector< vector<int> > mc(amount + 1, vector<int>(N + 1, INT_MAX));
	vector< int >  mc(amount+1, INT_MAX);
	mc[0] = 0;
	
	for (int capacity = 1; capacity <= amount; ++capacity)
	{
		for (int i = 0; i < N; ++i)
		{
			if (capacity >= coin[i] && INT_MAX != mc[capacity - coin[i]])
			{
				if (mc[capacity - coin[i]] + 1 < mc[capacity])
				{
					mc[capacity] = mc[capacity-coin[i]] +1;
				}
			}
		}
	}

	if (INT_MAX == mc[amount])
	{
		cout<<-1<<endl;
	}
	else
	{
		cout << mc[amount]<<endl;
	}

	return 0;
}

int main()
{
	int t = 0;
	int a[101];
	int N = 0;
	int amount = 0;

	cin >> t;
	while (t--)
	{
		cin >> N >> amount;
		int i = 0;
		while (i < N)
		{
			cin >> a[i++];
		}
		minCoin(a, N, amount);
	}

	return 0;
}