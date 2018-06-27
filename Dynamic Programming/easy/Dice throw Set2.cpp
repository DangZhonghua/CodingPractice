/*
You do not care about the accuracy of the result, we will help you to output results.

Given N dices whose have M face and one face stand for one value(1...M). thow these N dices, all upper faces sum is S.
So the problem is: What are the possible value of S and their possibilities.

*/

/*

This is the dynamic programming:the extenstion of O-1 KNAPSACK problem.

*/

#include<iostream>
#include<vector>
using namespace std;


int CountSumPossibility(int N, int M)
{
	int S = N*M;
	vector< vector<unsigned long long> > w(N + 1, vector<unsigned long long>(S + 1, 0));
	w[0][0] = 1; //0 dice, there are only one possible: sum = 0;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = i; j <= S; ++j)
		{
			for (int k = 1; k <= M; ++k)
			{
				if (j >= k && 0 != w[i - 1][j - k])
				{
					w[i][j] += w[i - 1][j - k];
				}
			}
		}
	}


	unsigned long long  total = 0;
	for (int i = 1; i <= S; ++i)
	{
		if (w[N][i])
		{
			cout << i << " ";
			total += w[N][i];
		}
	}
	cout << endl;

	for (int i = 1; i <= S; ++i)
	{
		if (w[N][i])
		{
			cout << (double)w[N][i] / total << " ";
		}
	}
	cout << endl;
	

	return 0;
}


int main(int argc, char const *argv[])
{
	/* code */

	int t = 0;
	int N = 0;
	int M = 0;

	cin >> t;

	while (t--)
	{
		cin >> N >> M;
		CountSumPossibility(N, M);
	}


	return 0;
}
