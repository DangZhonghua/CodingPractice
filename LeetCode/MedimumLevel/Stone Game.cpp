/*
https://leetcode-cn.com/problems/stone-game/
Stone Game

Alex and Lee play a game with piles of stones.  There are an even number of piles arranged in a row,
and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones.  The total number of stones is odd, so there are no ties.

Alex and Lee take turns, with Alex starting first.  Each turn, a player takes the entire pile of stones
from either the beginning or the end of the row.  This continues until there are no more piles left,
at which point the person with the most stones wins.

Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.
 

Example 1:

Input: [5,3,4,5]
Output: true
Explanation:
Alex starts first, and can only take the first 5 or the last 5.
Say he takes the first 5, so that the row becomes [3, 4, 5].
If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 points.
If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alex, so we return true.


Note:

	2 <= piles.length <= 500
	piles.length is even.
	1 <= piles[i] <= 500
	sum(piles) is odd.

*/

/*

DP[i][j] = DP[i+1][j] + a[i], DP[i][j-1] + a[j]

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution
{
public:
	bool stoneGame(vector<int>& piles)
	{
		int N = piles.size();
		vector< vector< vector<int> > > mc(2, vector< vector<int> >(N, vector<int>(N, 0)));

		int sum = piles[N - 1];
		for (int i = 0; i <= N - 2; ++i)
		{
			sum += piles[i];
			int j = i + 1;
			mc[0][i][j] = max(piles[i], piles[j]);
			mc[1][i][j] = min(piles[i], piles[j]);
		}

		for (int L = 4; L <= N; L += 2)
		{
			for (int i = 0; i <= N - L; ++i)
			{
				int j = i + L - 1;
				
				int ai = piles[i] + mc[0][i + 2][j]; // when Alex select i and Lee select i+1
				mc[1][i + 1][j] = mc[1][i + 2][j] + piles[i + 1];
				if (mc[1][i + 1][j] < mc[1][i + 1][j - 1] + piles[j]) // Lee can select j of course, so it need judge to select the most
				{
					mc[1][i + 1][j] = mc[1][i + 1][j - 1] + piles[j];
					ai = piles[i] + mc[0][i + 1][j - 1];
				}
				
				int aj = piles[j] + mc[0][i][j - 2]; // Alex select j and lee select j-1
				mc[1][i][j - 1] = mc[1][i][j - 2] + piles[j - 1];
				if (mc[1][i][j - 1] < mc[1][i + 1][j - 1] + piles[i]) // of course, lee can check i.
				{
					mc[1][i][j - 1] = mc[1][i + 1][j - 1] + piles[i];
					aj = piles[j] + mc[0][i + 1][j - 1];
				}

				if (mc[1][i + 1][j] < mc[1][i][j - 1]) //Alex select i to make Lee select less.
				{
					mc[0][i][j] = ai;
					mc[1][i][j] = mc[1][i + 1][j];
				}
				else
				{
					mc[0][i][j] = aj;
					mc[1][i][j] = mc[1][i][j - 1];
				}
			}
		}

		return mc[0][0][N - 1] > (sum - mc[0][0][N - 1]);

	}
};

int main()
{
	Solution sol;
	vector<int> piles1{ 5,3,4,5 };
	//cout << sol.stoneGame(piles1) << endl;

	vector<int> piles2{ 6, 3, 9, 9, 3, 8, 8, 7 };


	cout << sol.stoneGame(piles2) << endl;


	return 0;
}