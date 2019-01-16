/*
Minimum cost to make Longest Common Subsequence of length k
https://www.geeksforgeeks.org/minimum-cost-make-longest-common-subsequence-length-k/

Given two string X, Y and an integer k. Now the task is to convert string X with minimum cost
such that the Longest Common Subsequence of X and Y after conversion is of length k.
The cost of conversion is calculated as XOR of old character value and new character value.
Character value of ‘a’ is 0, ‘b’ is 1 and so on.

Examples:

Input : X = "abble",
Y = "pie",
k = 2
Output : 25

If you changed 'a' to 'z', it will cost 0 XOR 25.

*/

/*
mc[k-1,i-1,j-1]

mc[k,i,j] =       min {
mc[k-1,i-1,j-1] + cost
mc[k,i-1,j],
mc[k,i,j-1]
}

*/


#include<string>
#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int MinimumTransform(const string& x, const string& y, int K)
{
	int ret = 0;
	int LX = x.length();
	int LY = y.length();

	vector< vector< vector<int> > > mc(K + 1, vector< vector<int> >(LX + 1, vector<int>(LY + 1, INT_MAX)));

	for (int i = 0; i <= LX; ++i)
	{
		for (int j = 0; j <= LY; ++j)
		{
			mc[0][i][j] = 0;
		}
	}

	for (int k = 1; k <= K; ++k)
	{
		for (int i = 1; i <= LX; ++i)
		{
			for (int j = 1; j <= LY; ++j)
			{
				if (x[i - 1] == y[j - 1])
				{
					mc[k][i][j] = mc[k - 1][i - 1][j - 1];
				}
				else
				{
					mc[k][i][j] = mc[k - 1][i - 1][j - 1] + (x[i - 1]-'a') ^ (y[j - 1]-'a');
					if (mc[k][i][j] > mc[k][i][j - 1])
					{
						mc[k][i][j] = mc[k][i][j - 1];
					}
					if (mc[k][i][j] > mc[k][i - 1][j])
					{
						mc[k][i][j] = mc[k][i - 1][j];
					}
				}
			}
		}
	}

	cout << mc[K][LX][LY] << endl;
	return ret;
}

int main(int argc, char const *argv[])
{
	string X = "abble";
	string Y = "pie";
	int K = 2;

	MinimumTransform(X, Y, K);

	//cout << ((int)('b' - 'a')^('p' - 'a'))<<endl;

	return 0;
}

#include <bits/stdc++.h> 
using namespace std; 
const int N = 30; 

// Return Minimum cost to make LCS of length k 
int solve(char X[], char Y[], int l, int r, 
					int k, int dp[][N][N]) 
{ 
	// If k is 0. 
	if (!k) 
		return 0; 

	// If length become less than 0, return 
	// big number. 
	if (l < 0 | r < 0) 
		return 1e9; 

	// If state already calculated. 
	if (dp[l][r][k] != -1) 
		return dp[l][r][k]; 

	// Finding the cost 
	int cost = (X[l] - 'a') ^ (Y[r] - 'a'); 

	// Finding minimum cost and saving the state value 
	return dp[l][r][k] = min({cost + 
					solve(X, Y, l - 1, r - 1, k - 1, dp), 
							solve(X, Y, l - 1, r, k, dp), 
							solve(X, Y, l, r - 1, k, dp)}); 
} 

// Driven Program 
int main() 
{ 
	char X[] = "abble"; 
	char Y[] = "pie"; 
	int n = strlen(X); 
	int m = strlen(Y); 
	int k = 2; 

	int dp[N][N][N]; 
	memset(dp, -1, sizeof dp); 
	int ans = solve(X, Y, n - 1, m - 1, k, dp); 

	cout << (ans == 1e9 ? -1 : ans) << endl; 
	return 0; 
} 
