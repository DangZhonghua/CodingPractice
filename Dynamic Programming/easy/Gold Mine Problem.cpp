/*
Gold Mine Problem
https://practice.geeksforgeeks.org/problems/gold-mine-problem/0
Given a gold mine (M) of n*m dimensions. Each field in this mine contains a positive integer
which is the amount of gold in tons.
Initially the miner is at first column but can be at any row.
He can move only (right->,right up /,right down\) that is from a given cell,
the miner can move to the cell diagonally up towards the right or right or diagonally down towards the right.
Your task is to find out maximum amount of gold which he can collect.

Examples:

Input : M[][] = {{1, 3, 3},
{2, 1, 4},
{0, 6, 4}};
Output : 12
{(1,0)->(2,1)->(2,2)}

Input: M[][] = {{1, 3, 1, 5},
{2, 2, 4, 1},
{5, 0, 2, 3},
{0, 6, 1, 2}};
Output : 16
(2,0) -> (1,1) -> (1,2) -> (0,3) OR
(2,0) -> (3,1) -> (2,2) -> (2,3)


Input:
The first line of input contains an integer T denoting the no of test cases. 
Then T test cases follow. Each test case contains an integer n and m denoting the size of the matrix. 
Then in the next line are n*m space separated values of the matrix.

Output:
For each test case in a new line print an integer denoting the max gold the miner could collect.

Constraints:
1<=T<=100
1<=n,m<=20
1<=M[][]<=100

Example:
Input:
2
3 3
1 3 3 2 1 4 0 6 4
2 2
1 2 3 4
Output:
12
7

*/

/*
1
4 7
77 15 93 35 86 92 49 21 62 27 90 59 63 26 40 26 72 36 11 68 67 29 82 30 62 23 67 35


*/

/*

gmc[r][c] = max{ gmc[r-1][c-1], gmc[r][c-1], gmc[r+1][c-1]} +v, FOR ONE certain c and any r


*/


#include<iostream>
#include<vector>
using namespace std;


int GoldMine(vector< vector<int> >& gm, int R, int C)
{
	vector< vector< int> > gmc(R, vector<int>(C, 0));
	int max = 0;

	for (int r = 0; r < R; ++r)
	{
		gmc[r][0] = gm[r][0];
		if (gmc[r][0]>max)
		{
			max = gmc[r][0];
		}
	}

	for (int c = 0; c< C; ++c)
	{
		for (int r = 0; r< R; ++r)
		{
			if (r - 1 >= 0 && c - 1 >= 0)
			{
				if (gmc[r][c]<gmc[r - 1][c - 1] + gm[r][c])
				{
					gmc[r][c] = gmc[r - 1][c - 1] + gm[r][c];
				}
			}
			if (c - 1 >= 0)
			{
				if (gmc[r][c] < gmc[r][c - 1] + gm[r][c])
				{
					gmc[r][c] = gmc[r][c - 1] + gm[r][c];
				}
			}
			if (r + 1<R && c - 1 >= 0)
			{
				if (gmc[r][c] < gmc[r + 1][c - 1] + gm[r][c])
				{
					gmc[r][c] = gmc[r + 1][c - 1] + gm[r][c];
				}
			}

			if (gmc[r][c]>max)
			{
				max = gmc[r][c];
			}
		}
	}

	cout << max << endl;


	return 0;
}


int main()
{
	int t = 0;
	int R = 0;
	int C = 0;


	cin >> t;
	while (t--)
	{
		cin >> R >> C;
		vector< vector<int> > gm(R, vector<int>(C, 0));

		for (int r = 0; r<R; ++r)
		{
			for (int c = 0; c<C; ++c)
			{
				int a = 0;
				cin >> a;
				gm[r][c] = a;
			}
		}
		GoldMine(gm, R, C);
	}

	return 0;
}

