/*

Minimum cost to buy N kilograms of sweet for M persons
https://www.geeksforgeeks.org/minimum-cost-to-buy-n-kilograms-of-sweet-for-m-persons/

Given an array of n size contains the cost of sweets in such a way that that sweet[i] is the cost of i sweets.
The task is to find the minimum cost to spend to buy exactly ‘n’ kilograms of sweet for the ‘m’ persons.

Since sweets are available in the packets, you have to buy at most ‘m’ packet of sweets for your ‘m’ relatives.
You cannot buy more than ‘m’ packet of sweets.
Also cost[i] = 0, represents that the sweet with packet size i is unavailable.
Also, there is an infinite number of packets with i size of sweets.

Input: m = 3, n = 6, arr[] = {2, 1, 3, 0, 4, 10}
Output: 3
We can choose at most 3 packets. We choose 3 packets of size 2 having cost 1 each.Thus output is 3.

Input: m = 2, n = 7, arr[] = {1, 3, 0, 5, 0, 0, 0}
Output : 0
We can choose at most 2 packets. 7 can be formed by 1 2 and 4 index but since you require at most
2 packets to obtain the 7 sweets packets answer which is not possible.
Hence the answer is 0 as it is formed by 3 packets, not 2.

*/



/*

this is 2D complete knapsack problems. There are two resources need to consume: kilogram and the package count.
f[i][K][M]

*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int CalcMinimumSpent(vector<int>&a, int M, int N)
{
	int ret = 0;
	vector<int> vc;
	vector<int> vw;

	vc.push_back(0);
	vw.push_back(0);
	for (int i = 0; i<a.size(); ++i)
	{
		if (a[i])
		{
			vc.push_back(a[i]);
			vw.push_back(i + 1);
		}
	}

	vector< vector< vector<int> > > dp(vc.size(), vector< vector<int> >(M + 1, vector<int>(N + 1, INT_MAX)));
	//Pay attention to the initialization of matrix.
	//dp[0][0][0] = 0;

	for (int i = 0; i <vc.size(); ++i)
	{
		for (int m = 0; m <= M; ++m)
		{
			dp[i][m][0] = 0;
		}
	}

	//1.Create matrix sweet[m+1][n+1][n+1], 
	//where m is number of relatives and n is the total kg of sweets to be bought and number of packages of sweet.
	//dp[i][j][k] = dp[i - 1][j - k][k] + sweet[k]; 
	//dp[i][j][k] = dp[i][j][k - 1]; 
	for (int i = 1; i<vc.size(); ++i)
	{
		for (int m = 1; m<=M; ++m)
		{
			for (int n = 1; n<= N; ++n)
			{		
				dp[i][m][n] = dp[i - 1][m][n];
				if (n >= vw[i] && INT_MAX != dp[i][m-1][n - vw[i]] && dp[i][m][n] > dp[i][m-1][n - vw[i]] + vc[i])
				{
					dp[i][m][n] = dp[i][m - 1][n - vw[i]] + vc[i];
				}
				//if (INT_MAX == dp[i][m][n] || (INT_MAX != dp[i - 1][m][n] && dp[i][m][n] > dp[i - 1][m][n]))
				//{
				//	dp[i][m][n] = dp[i - 1][m][n];
				//}
			}
		}
	}

	if (INT_MAX != dp[vc.size() - 1][M][N])
	{
		cout << dp[vc.size() - 1][M][N] << endl;
	}
	else
	{
		cout<<-1<<endl;
	}
	

	return ret;
}


int main(int argc, char const *argv[])
{
	vector<int> a{ 2, 1, 3, 0, 4, 10 };
	int M = 3;
	int N = 6;
	CalcMinimumSpent(a, M, N);

	vector<int> b{ 1, 3, 0, 5, 0, 0, 0 };
	M = 2;
	N = 7;

	CalcMinimumSpent(b, M, N);

	return 0;
}
// C++ program to minimum cost to buy  N kilograms of sweet for M persons 
// Create matrix sweet[m+1][n+1][n+1], where m is number of relatives and 
// n is the total kg of sweets to be bought and number of packages of sweet.

//
//
//#include <bits/stdc++.h> 
//using namespace std;
//
//// Function to find the minimum cost of sweets 
//int find(int m, int n, int adj[])
//{
//	// Defining the sweet array 
//	int sweet[n + 1];
//
//	// DP array to store the values 
//	int dp[n + 1][n + 1][n + 1];
//
//	sweet[0] = 0;
//
//	// Since index starts from 1 we 
//	// reassign the array into sweet 
//	for (int i = 1; i <= m; ++i)
//		sweet[i] = adj[i - 1];
//
//	// Assigning base cases for dp array 
//	for (int i = 0; i <= m; ++i)
//	{
//		for (int k = 0; k <= n; ++k)
//		{
//			// At 0 it is free 
//			dp[i][0][k] = 0;
//		}
//
//		// Package not available for desirable amount of sweets 
//		for (int k = 1; k <= n; ++k)
//		{
//			dp[i][k][0] = -1;
//		}
//	}
//
//	for (int i = 0; i <= m; ++i) //person
//	{
//		for (int j = 1; j <= n; ++j) //to be bought
//		{
//			for (int k = 1; k <= n; ++k) // package number
//			{
//				dp[i][j][k] = -1;
//				// Buying the 'k' kg package and 
//				// assigning it to dp array 
//				if (i > 0 && j >= k && sweet[k] > 0 && dp[i - 1][j - k][k] != -1)
//				{
//					dp[i][j][k] = dp[i - 1][j - k][k] + sweet[k];
//				}
//				// If no solution, select from previous k-1 packages 
//				if (dp[i][j][k] == -1 || (dp[i][j][k - 1] != -1 && dp[i][j][k] > dp[i][j][k - 1]))
//				{
//					dp[i][j][k] = dp[i][j][k - 1];
//				}
//			}
//		}
//	}
//
//	// If solution does not exist 
//	if (dp[m][n][n] == -1)
//		return 0;
//
//	// Print the solution 
//	else
//		return dp[m][n][n];
//}
//
//// Driver Function 
//int main()
//{
//	int m = 3;
//	int adj[] = { 2, 1, 3, 0, 4, 10 };
//	int n = sizeof(adj) / sizeof(adj[0]);
//
//	// Calling the desired function 
//	cout << find(m, n, adj);
//	return 0;
//}
