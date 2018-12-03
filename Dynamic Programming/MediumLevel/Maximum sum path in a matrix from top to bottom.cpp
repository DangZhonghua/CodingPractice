/*
Maximum sum path in a matrix from top to bottom
https://www.geeksforgeeks.org/maximum-sum-path-matrix-top-bottom/

Consider a n*n matrix. Suppose each cell in the matrix has a value assigned.
We can go from each cell in row i to a diagonally higher cell in row i+1 only [i.e from cell(i, j) to cell(i+1, j-1)
and cell(i+1, j+1) only]. Find the path from the top row to the bottom row following the aforementioned condition
such that the maximum sum is obtained.

Examples:

Input : mat[][] = { {5, 6, 1, 7},
{-2, 10, 8, -1},
{3, -7, -9, 11},
{12, -4, 2, 6} }
Output : 28

{5, 6, 1, 7},
{-2, 10, 8, -1},
{3, -7, -9, 11},
{12, -4, 2, 6} }

The highlighted numbers from top to bottom
gives the required maximum sum path.
(7 + 8 + 11 + 2) = 28

*/

/*

optimal sub-structure and overlapped sub-problems.
SM[i][j] = max{SM[i-1][j+1]+m[i][j], SM[i-1][j-1]+m[i][j]}
*/

#include<iostream>
#include<vector>
#include<climits>   
using namespace std;


int MaximumSumPath(vector< vector<int>>& a)
{
	int size = a.size();
	vector< vector<int> > ms(size, vector<int>(size, INT_MIN));

	for (int i = 0; i<size; ++i)
	{
		ms[0][i] = a[0][i];
	}

	for (int r = 1; r<size; ++r)
	{
		for (int c = 0; c<size; ++c)
		{
			if (c - 1 >= 0 && ms[r][c]<ms[r - 1][c - 1] + a[r][c])
			{
				ms[r][c] = ms[r - 1][c - 1] + a[r][c];
			}
			if (c + 1<size && ms[r][c]<ms[r - 1][c + 1] + a[r][c])
			{
				ms[r][c] = ms[r - 1][c + 1] + a[r][c];
			}
		}
	}
	int maxPath = INT_MIN;
	for (int c = 0; c< size; ++c)
	{
		if (ms[size - 1][c]>maxPath)
		{
			maxPath = ms[size - 1][c];
		}
	}
	cout << maxPath << endl;

	return 0;
}

int main()
{
	vector< vector<int> > mat = {
		{ 5, 6, 1, 7 },
		{ -2, 10, 8, -1 },
		{ 3, -7, -9, 11 },
		{ 12, -4, 2, 6 } };

	MaximumSumPath(mat);

	return 0;
}