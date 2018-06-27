/*
Dice throw
https://practice.geeksforgeeks.org/problems/dice-throw/0/?ref=self

Given n dice each with m faces, numbered from 1 to m, find the number of ways to get sum X.
X is the summation of values on each face when all the dice are thrown.

Input: The first line of the input contains T denoting the number of test cases.
First line of test case is faces 'm',
number of throws 'n' and the sum to obtain 'x'.

Output: Number of ways to get sum 'x' are displayed.
Constraints:
1 <=T<= 100
1 <=m,n,x<= 50


Example:

Input:
2
6 3 12
10 8 25

Output:
25
318648

*/


/*
this is the extension of 0-1 knapsack problem.
We first take as instance as the beginning.
two dices with 3 faces

one Dice: 1, 2, 3
two Dice: 2, 3, 4  the face is up
          3, 4, 5  the second face is up
          4, 5, 6  the third face is up.

w[i][s] += w[i-1][s-k] // k from 1 to M
*/




#include<iostream>
#include<vector>
using namespace std;

#include<iostream>
#include<vector>
using namespace std;

int CountWays(int M, int N, int S)
{
	long long  vway[100][100] = {0};

	vway[0][0] = 1; //It should be Initialize as 1 not 0 since there is only one way for 0.

	for (int i = 1; i <= N; ++i)
	{
		for (int s = i; s <= S; ++s)
		{
			for (int k = 1; k <= M; ++k)
			{
				if (s >= k && 0 != vway[i - 1][s - k])
				{
					vway[i][s] += vway[i - 1][s - k];
				}
			}
		}
	}

	cout << vway[N][S] << endl;

	return 0;
}




int main()
{
	int t = 0;
	int M = 0;
	int N = 0;
	int S = 0;

	cin >> t;

	while (t--)
	{
		cin >> M >> N >> S;
		CountWays(M, N, S);
	}

	return 0;
}

