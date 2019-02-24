/*
Coin Change
https://leetcode-cn.com/problems/coin-change/

You are given coins of different denominations and a total amount of money amount.
Write a function to compute the fewest number of coins that you need to make up that amount.
If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:

Input: coins = [2], amount = 3
Output: -1

Note:
You may assume that you have an infinite number of each kind of coin.

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
public:
	int coinChange(vector<int>& coins, int amount)
	{
		int N = coins.size();
		vector< vector<int> > mc(N + 1, vector<int>(amount + 1, INT_MAX));

		for (int i = 0; i <= N; ++i)
		{
			mc[i][0] = 0;
		}

		for (int i = 1; i <= N; ++i)
		{
			for (int v = 1; v <= amount; ++v)
			{
				mc[i][v] = mc[i - 1][v];
				if (v >= coins[i - 1] && mc[i][v - coins[i-1]] != INT_MAX)
				{
					if (mc[i][v] > mc[i][v - coins[i-1]] + 1)
					{
						mc[i][v] = mc[i][v - coins[i-1]] + 1;
					}
				}
			}
		}

		return mc[N][amount] == INT_MAX ? -1 : mc[N][amount];
	}
};


int main()
{
	Solution sol;
	vector<int> c1{ 1, 2, 5 };
	int amount = 11;

	cout<<sol.coinChange(c1, amount) << endl;
	
	return 0;
}