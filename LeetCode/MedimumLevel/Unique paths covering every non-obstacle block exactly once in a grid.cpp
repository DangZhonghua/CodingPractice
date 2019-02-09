/*
https://www.geeksforgeeks.org/unique-paths-covering-every-non-obstacle-block-exactly-once-in-a-grid/
Unique paths covering every non-obstacle block exactly once in a grid

Unique paths covering every non-obstacle block exactly once in a grid

Given a grid grid[][] with 4 types of blocks:

	1 represents the starting block. There is exactly one starting block.
	2 represents the ending block. There is exactly one ending block.
	0 represents empty block we can walk over.
	-1 represents obstacles that we cannot walk over.

The task is to count the number of paths from the starting block to the ending block such that every non-obstacle block is covered exactly once.

Examples:

Input: grid[][] =
	{
		{1, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 2, -1}
	}
	Output: 2
	Following are the only paths covering all the non-obstacle blocks:

Input: grid[][] =
{
	{1, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 2}
}
Output: 4


Approach: We can use simple DFS here with backtracking.
We can check that a particular path has covered all the non-obstacle blocks
by counting all the blocks encountered in the way and
finally comparing it with the total number of blocks available and if they match, then we add it as a valid solution.

*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution
{
public:
	int CountUniquePathOfMatrix(vector< vector<int> >& matrix)
	{
		int ret = 0;
		int nUnique = 0;
		int R = matrix.size();
		int C = matrix[0].size();
		vector< vector<bool> > visited(R, vector<bool>(C, false));
		m_nBlock = CalcBlockCount(matrix);
		for (int r = 0; r < R; ++r)
		{
			for (int c = 0; c < C; ++c)
			{
				if (1 == matrix[r][c])
				{
					DFSPath(matrix, visited, r, c, nUnique);
				}
			}
		}

		return nUnique;
	}
private:
	void DFSPath(vector< vector<int> >& matrix, vector< vector<bool> >& visited, int r, int c, int& nUnique)
	{
		struct gVertex
		{
			int r{ 0 };
			int c{ 0 };
			int d{ 0 };
			gVertex() {}
			gVertex(int _r, int _c, int _d) { r = _r; c = _c; d = _d; }
		};
		int nVertices = 0;
		stack<gVertex>  dfsStack;
		dfsStack.push(gVertex(r, c, 0));
		visited[r][c] = true;
		++nVertices;

		while (!dfsStack.empty())
		{
			gVertex& tp = dfsStack.top();
			if (tp.d == DC)
			{
				dfsStack.pop();
				visited[tp.r][tp.c] = false;
				--nVertices;
				continue;
			}
			int nr = tp.r + rn[tp.d];
			int nc = tp.c + cn[tp.d];
			tp.d++;
			if (CanVisit(matrix, visited, nr, nc))
			{
				++nVertices;
				if (2 == matrix[nr][nc]) //this is end block
				{
					if (nVertices == m_nBlock)
					{
						++nUnique;
					}
					--nVertices;
				}
				else
				{
					dfsStack.push(gVertex(nr, nc, 0));
					visited[nr][nc] = true;
				}
			}
		}
	}

	bool CanVisit(vector< vector<int> >& matrix, vector< vector<bool> >& visited, int r, int c)
	{
		if (0 <= r && r < matrix.size() && 0 <= c && c < matrix[0].size() && matrix[r][c] != -1 && !visited[r][c])
		{
			return true;
		}
		return false;
	}

	int CalcBlockCount(vector< vector<int> >& matrix)
	{
		int nBlock = 0;

		for (auto v : matrix)
		{
			for (auto a : v)
			{
				if (-1 != a)
				{
					++nBlock;
				}
			}
		}
		return nBlock;
	}
private:
	static const int DC{ 4 };
	int  rn[DC] = { -1,0,1,0 };
	int  cn[DC] = { 0,1,0,-1 };
	int  m_nBlock{ 0 };
};



int main()
{
	int ret = 0;

	vector< vector<int> > grid1
	{
		{1, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 2, -1}
	};

	vector< vector<int> > grid2
	{
		{1, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 2}
	};

	Solution sol;

	cout << sol.CountUniquePathOfMatrix(grid1) << endl;
	cout << sol.CountUniquePathOfMatrix(grid2) << endl;

	return ret;
}


