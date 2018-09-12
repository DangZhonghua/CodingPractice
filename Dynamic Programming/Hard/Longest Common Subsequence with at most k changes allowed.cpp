/*
https://www.geeksforgeeks.org/longest-common-subsequence-with-at-most-k-changes-allowed/
Longest Common Subsequence with at most k changes allowed

Given two sequence P and Q of numbers. The task is to find Longest Common Subsequence of two sequence 
if we are allowed to change at most k element in first sequence to any value.

Examples:

Input : P = { 8, 3 }
        Q = { 1, 3 }
        K = 1
Output : 2
If we change first element of first sequence from 8 to 1, both sequences become same.

Input : P = { 1, 2, 3, 4, 5 }
        Q = { 5, 3, 1, 4, 2 }
        K = 1
Output : 3
By changing first element of first
sequence to 5 to get the LCS ( 5, 3, 4 }.

*/



/*
The idea is to use Dynamic Programming. Define a 3D matrix dp[][][], where dp[i][j][k] 
defines the Longest Common Subsequence for the first i numbers of first array, first j number of 
second array when we are allowed to change at max k number in the first array.
Therefore, recursion will look like

If P[i] != Q[j], 
    dp[i][j][k] = max(dp[i - 1][j][k], 
                      dp[i][j - 1][k], 
                      dp[i - 1][j - 1][k - 1] + 1) 
If P[i] == Q[j], 
    dp[i][j][k] = max(dp[i - 1][j][k], 
                      dp[i][j - 1][k], 
                      dp[i - 1][j - 1][k] + 1)

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lcsatmostk(vector<int>&a, vector<int>&b, int K)
{
	int N = a.size();
	int M = b.size();
	//int klcs[N + 1][M + 1][K + 1];
	vector< vector< vector<int> > > klcs(N+1, vector< vector<int> >(M+1, vector<int>(K+1,0)));
	//memset(klcs, 0, sizeof(klcs));

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			for (int k = 1; k <= K; ++k)
			{
				int lcs = max(klcs[i - 1][j][k], klcs[i][j - 1][k]);
				if (a[i-1] != b[j-1])
				{
					if (lcs < 1 + klcs[i - 1][j - 1][k - 1])
					{
						lcs = (1 + klcs[i - 1][j - 1][k - 1]);
					}
				}
				else
				{
					if (lcs < 1 + klcs[i - 1][j - 1][k])
					{
						lcs = 1 + klcs[i - 1][j - 1][k];
					}
				}
				klcs[i][j][k] = lcs;
			}
		}
	}


	cout << klcs[N][M][K] << endl;

	return 0;
}

// Driven Program 
int main()
{
	int k = 2;
	vector<int>  a{ 1, 2, 3, 4, 5 };
	vector<int>  b{ 5, 3, 1, 4, 2 };
	lcsatmostk(a, b, k);

	return 0;
}




// // CPP program to find LCS of two arrays with 
// // k changes allowed in first array. 
// #include <bits/stdc++.h> 
// using namespace std; 
// #define MAX 10 
  
// // Return LCS with at most k changes allowed. 
// int lcs(int dp[MAX][MAX][MAX], int arr1[], int n, int arr2[], int m, int k) 
// { 
//     // If at most changes is less than 0. 
//     if (k < 0) 
//         return -1e7; 
  
//     // If any of two array is over. 
//     if (n < 0 || m < 0) 
//         return 0; 
  
//     // Making a reference variable to dp[n][m][k] 
//     int& ans = dp[n][m][k]; 
  
//     // If value is already calculated, return 
//     // that value. 
//     if (ans != -1) 
//         return ans; 
  
//     // calculating LCS with no changes made. 
//     ans = max(lcs(dp, arr1, n - 1, arr2, m, k),  
//               lcs(dp, arr1, n, arr2, m - 1, k)); 
  
//     // calculating LCS when array element are same. 
//     if (arr1[n] == arr2[m]) 
//         ans = max(ans, 1 + lcs(dp, arr1, n - 1,  
//                                 arr2, m - 1, k)); 
  
//     // calculating LCS with changes made. 
//     ans = max(ans, 1 + lcs(dp, arr1, n - 1,  
//                           arr2, m - 1, k - 1)); 
  
//     return ans; 
// } 
  
// // Driven Program 
// int main() 
// { 
//     int k = 1; 
//     int arr1[] = { 1, 2, 3, 4, 5 }; 
//     int arr2[] = { 5, 3, 1, 4, 2 }; 
//     int n = sizeof(arr1) / sizeof(arr1[0]); 
//     int m = sizeof(arr2) / sizeof(arr2[0]); 
  
//     int dp[MAX][MAX][MAX]; 
//     memset(dp, -1, sizeof(dp)); 
  
//     cout << lcs(dp, arr1, n, arr2, m, k) << endl; 
  
//     return 0; 
// } 
