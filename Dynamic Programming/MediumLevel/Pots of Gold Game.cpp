/*
Pots of Gold Game
https://practice.geeksforgeeks.org/problems/pots-of-gold-game/1/?ref=self

Two player X and Y are playing a game in which there are pots of gold arranged in a  line, each containing some gold coins. They get alternating turns in which the player can pick a pot from one of the ends of the line. The winner is the player who has a higher number of coins at the end. The objective is to maximize the number of coins collected by X, assuming Y also plays optimally. You are required to complete the method maxCoins which returns an integer denoting the max coins X could get while playing the game. You may assume that X starts the game.

Input:
The first line of input contains an integer T denoting the no of test cases.
Then T test cases follow. Each test case contains an integer denoting the no of gold pots.
Then in the next line are N space separated values denoting the values (A[]) of gold coins in each pot.

Output:
For each test case in a new line print the maximum amount of money X can collect.

Constraints:
1<=T<=100
1<=N<=100
1<=A[]<=1000

Example(To be used only for expected output):
Input:
2
4
8 15 3 7
4
2 2 2 2

Output:
22
4
*/

/*

this is dynamic programming, But How to define the state transform.
PG[][i][j] = max{a[i] + PG[][i+1][j], PG[][i][j] + a[j]}

*/

#include<iostream>
#include<vector>
using namespace std;



enum selector
{
	select_non,
	select_left,
	select_right
};


int maxCoins(int a[], int N)
{
	vector< vector<int> > pg(N, vector<int>(N, 0));
	vector< vector<int> > ps(N, vector<int>(N, 0));

	for (int i = 0; i<N; ++i)
	{
		pg[i][i] = a[i];
	}

	for (int l = 2; l <= N; ++l)
	{
		for (int i = 0; i <= N - l; ++i)
		{
			//The two sides both play in optimal manner.
			int j = i + l - 1;

			pg[i][j] = a[i];
			ps[i][j] = select_left;

			if (select_left == ps[i + 1][j])
			{
				pg[i][j] = a[i] + pg[i + 2][j];
			}
			else if (select_right == ps[i + 1][j])
			{
				pg[i][j] = a[i] + pg[i + 1][j - 1];
			}

			if (pg[i][j]<a[j])
			{
				pg[i][j] = a[j];
				ps[i][j] = select_right;
			}

			if (select_left == ps[i][j - 1])
			{
				if ((a[j] + pg[i + 1][j - 1])>pg[i][j])
				{
					pg[i][j] = (a[j] + pg[i + 1][j - 1]);
					ps[i][j] = select_right;
				}
			}
			else if (select_right == ps[i][j - 1])
			{
				if ((a[j] + pg[i][j - 2])>pg[i][j])
				{
					pg[i][j] = (a[j] + pg[i][j - 2]);
					ps[i][j] = select_right;
				}
			}
		}
	}

	cout << pg[0][N - 1] << endl;

	return 0;
}



int main(int argc, char const *argv[])
{

	int t = 0;
	int N = 0;
	int a[200];

	cin >> t;

	while (t--)
	{
		cin >> N;
		int i = 0;
		while (i<N)
		{
			cin >> a[i++];
		}
		maxCoins(a, N);
	}

	return 0;
}
