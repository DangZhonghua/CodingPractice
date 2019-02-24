/*
https://leetcode-cn.com/problems/out-of-boundary-paths/
Out of Boundary Paths

There is an m by n grid with a ball. Given the start coordinate (i,j) of the ball,
you can move the ball to adjacent cell or cross the grid boundary in four directions (up, down, left, right).
However, you can at most move N times.
Find out the number of paths to move the ball out of grid boundary. The answer may be very large, return it after mod 10^9 + 7.

*/

#include<iostream>
#include<vector>
using namespace std;

static int rneighbour[4] = { -1,1,0,0 };
static int cneighbour[4] = { 0,0,-1,1 };
class Solution
{
public:
	int findPaths(int m, int n, int N, int i, int j)
	{
		unsigned long long nPath = 0;
		unsigned int nMode = 1e9 + 7;
		vector< vector< vector<long long> > > pm(N + 1, vector< vector<long long> >(m, vector<long long>(n, 0)));

		pm[0][i][j] = 1;

		for (int L = 1; L <= N; ++L)
		{
			for (int r = 0; r < m; ++r)
			{
				for (int c = 0; c < n; ++c)
				{
					if (pm[L - 1][r][c])
					{
						for (int d = 0; d < 4; ++d)
						{
							int nr = r + rneighbour[d];
							int nc = c + cneighbour[d];
							if (0 <= nr && nr < m && 0 <= nc && nc < n)
							{
								pm[L][nr][nc] += pm[L - 1][r][c]; //SHOULD BE previous path count, NOT 1
								pm[L][nr][nc] %= nMode;
							}
							else
							{
								nPath += pm[L - 1][r][c]; //SHOULD BE previous path count, NOT 1
								nPath %= nMode;
							}
						}
					}
				}
			}
		}

		return nPath;
	}
};

int main()
{
	int m = 2;
	int n = 3;
	int N = 8;
	int i = 1;
	int j = 0;
	Solution sol;

	cout << sol.findPaths(m, n, N, i, j) << endl;

	return 0;
}