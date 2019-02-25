/*
https://leetcode-cn.com/problems/unique-paths-iii/
Unique Paths III

On a 2-dimensional grid, there are 4 types of squares:

1 represents the starting square.  There is exactly one starting square.
2 represents the ending square.  There is exactly one ending square.
0 represents empty squares we can walk over.
-1 represents obstacles that we cannot walk over.

Return the number of 4-directional walks from the starting square to the ending square,
that walk over every non-obstacle square exactly once.



Example 1:

Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths:
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)

Example 2:

Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths:
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)

Example 3:

Input: [[0,1],[2,0]]
Output: 0
Explanation:
There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.



Note:

1 <= grid.length * grid[0].length <= 20


*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution
{
	struct gVertex
	{
		int m_r;
		int m_c;
		int m_d;
		int m_L;
		gVertex(int r, int c, int d, int L)
		{
			m_r = r;
			m_c = c;
			m_d = d;
			m_L = L;
		}
	};

public:
	int uniquePathsIII(vector<vector<int>>& grid)
	{
		if (grid.empty())
		{
			return 0;
		}

		static int  RN[4] = { -1, 1, 0, 0 };
		static int  CN[4] = { 0, 0, -1, 1 };

		int nPath = 0;
		int nVertices = 0;
		int R = grid.size();
		int C = grid[0].size();
		vector< vector<bool> > mvisited(R, vector<bool>(C, false));
		stack<gVertex> dfsStack;
		int rStart = 0;
		int cStart = 0;

		for (int r = 0; r<R; ++r)
		{
			for (int c = 0; c<C; ++c)
			{
				if (-1 != grid[r][c])
				{
					++nVertices;
				}
				if (1 == grid[r][c])
				{
					rStart = r;
					cStart = c;
				}
			}
		}

		dfsStack.push(gVertex(rStart, cStart, 0, 1));
		mvisited[rStart][cStart] = true;

		while (!dfsStack.empty())
		{
			gVertex& tp = dfsStack.top();
			if (tp.m_d == 4)
			{
				mvisited[tp.m_r][tp.m_c] = false;
				dfsStack.pop();
			}
			else
			{
				int nr = tp.m_r + RN[tp.m_d];
				int nc = tp.m_c + CN[tp.m_d];
				tp.m_d += 1;
				if (0 <= nr && nr<R && 0 <=nc && nc<C && !mvisited[nr][nc] && grid[nr][nc] != -1)
				{
					if (2 == grid[nr][nc])
					{
						if (tp.m_L + 1 == nVertices)
						{
							++nPath;
						}
					}
					else
					{
						gVertex vStart(nr, nc, 0, tp.m_L + 1);
						mvisited[nr][nc] = true;
						dfsStack.push(vStart);
					}
				}
			}
		}
		return nPath;
	}
};

int main()
{
	Solution sol;
	vector< vector<int> > grid1 { 
		{ 1, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 2, -1 }};

	cout << sol.uniquePathsIII(grid1) << endl;

	vector< vector<int> > grid2{ { 1, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 2 } };
	cout << sol.uniquePathsIII(grid2) << endl;

	vector< vector<int> > grid3{ { 0, 1 }, { 2, 0 } };
	cout << sol.uniquePathsIII(grid3) << endl;

	return 0;
}