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
count[1,N] = max{a[1] + count[2,N], a[N] + count[1,N-1]}
count[i,j] = max{a[i] + count[i+1,j], a[j] + count[i, j-1]}
L = 0; means select left endpoint of array.
R = 1; means select right endpoint of array.

max_amount = max{count[L][1][N],count[R][1][N]};

                 Since the enemy is smart enough.
                 if(count[L][s+1][e]): a[i] + ((count[R][s + 2][e]>count[L][s + 2][e] ? count[R][s + 2][e] : count[L][s + 2][e]));
count[L][i][j] = 
                 else: a[i] +((count[L][s + 1][e - 1]>count[R][s + 1][e - 1] ? count[L][s + 1][e - 1] : count[R][s + 1][e - 1]));


                  if (count[L][s][e - 1] > count[R][s][e - 1]): a[j] + (count[R][s+1][e - 1]>count[L][s+1][e - 1] ? count[R][s+1][e - 1] : count[L][s+1][e - 1])
count[R][i][j] = 
                  else: a[j] + (count[L][s][e - 2]>count[R][s][e - 2] ? count[L][s][e - 2] : count[R][s][e - 2])

Dynamic problem need check every sub-problems and chose the best choice.

*/

#include <iostream>
using namespace std;

enum
{
	L = 0,
	R = 1,
	NUM
};

int maxCount(int a[], int N, int& max)
{
	int count[NUM][101][101];
//	memset(count, 0, sizeof(count));
	for (int k = 0; k<NUM; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (i == j)
				{
					count[k][i][i] = a[i];
				}
				else
				{
					count[k][i][j] = 0;
				}
			}
			
		}
	}

	for (int l = 2; l <= N; ++l)
	{
		for (int s = 1; s <= N - l + 1; ++s)
		{
			int e = s + l - 1;
			count[L][s][e] = a[s];

			if (count[L][s + 1][e] > count[R][s + 1][e])
			{
				if (s + 2 <= e)
				{
					count[L][s][e] += (count[R][s + 2][e]>count[L][s + 2][e] ? count[R][s + 2][e] : count[L][s + 2][e]);
				}
			}
			else
			{
				if (s + 1 <= e - 1)
				{
					count[L][s][e] += (count[L][s + 1][e - 1]>count[R][s + 1][e - 1] ? count[L][s + 1][e - 1] : count[R][s + 1][e - 1]);
				}
			}
			

			count[R][s][e] = a[e];
			if (count[L][s][e - 1] > count[R][s][e - 1])
			{
				if (s + 1 <= e - 1)
				{
					count[R][s][e] += (count[R][s+1][e - 1]>count[L][s+1][e - 1] ? count[R][s+1][e - 1] : count[L][s+1][e - 1]);
				}
			}
			else
			{
				if (s <= e - 2)
				{
					count[R][s][e] += (count[L][s][e - 2]>count[R][s][e - 2] ? count[L][s][e - 2] : count[R][s][e - 2]);
				}
			}
		}
	}

	max = count[L][1][N]>count[R][1][N] ? count[L][1][N] : count[R][1][N];
	cout << max << endl;

	return 0;
}


int main()
{
	int t = 0;
	int N = 0;
	int a[101] = { 0 };
	int max = 0;

	cin >> t;

	while (t>0)
	{
		--t;
		cin >> N;
		int i = 0;
		while (i<N)
		{
			cin >> a[++i];
		}
		maxCount(a, N, max);
	}

	return 0;
}