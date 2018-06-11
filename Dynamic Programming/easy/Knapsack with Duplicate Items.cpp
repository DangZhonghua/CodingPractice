/*
Knapsack with Duplicate Items
https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items/0

Given weights and values related to n items and the maximum capacity allowed for these items.
What is the maximum value we can achieve if we can pick any weights any number of times for a total allowed weight of W?

Input:
The first line of input contains an integer denoting the no of test cases. Then T test cases follow .
Each test case contains two integers N and W denoting the no of items and the total allowed weight.
In the next two lines are space separated values of the array denoting values of the items (val[]) and their weights (wt[])
respectively.

Output:
For each test case in a new line print the  maximum value which we can achieve
if we can pick any weights any number of times for a bag of size W.

Constraints:
1<=T<=100
1<=N, W<=1000
1<=wt[], val[]<=100

Example:
Input:
2
2 3
1 1
2 1
4 8
1 4 5 7
1 3 4 5
Output:
3
11

*/

/*
this is complete knapsack problem.

*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int completeKnapsack(int*v, int*w, int N, int W)
{
	vector< vector<int> >  f(W + 1, vector<int>(N + 1, 0));

	for (int c = 1; c <= W; ++c)
	{
		for (int i = 1; i <= N; ++i)
		{
			f[c][i] = f[c][i - 1]; //This is very important: since i total is at least i-1 pack
			if (c >= w[i])
			{
				if (f[c][i] < f[c - w[i]][i] + v[i])
				{
					f[c][i] = f[c - w[i]][i] + v[i];
				}
			}
		}
	}

	cout << f[W][N] << endl;



	return 0;
}

int main(int argc, char const *argv[])
{
	int t = 0;
	int wt[1000];
	int val[1000];
	int N = 0;
	int W = 0;

	cin >> t;

	while (t--)
	{
		cin >> N >> W;

		int i = 1;
		while (i<=N)
		{
			cin >> val[i++];
		}
		
		i = 1;
		while (i <= N)
		{
			cin >> wt[i++];
		}
		completeKnapsack(val, wt, N, W);
	}

	return 0;
}
