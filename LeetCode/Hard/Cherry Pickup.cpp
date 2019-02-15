/*
https://leetcode-cn.com/problems/cherry-pickup/
Cherry Pickup

In a N x N grid representing a field of cherries, each cell is one of three possible integers.

0 means the cell is empty, so you can pass through;
1 means the cell contains a cherry, that you can pick up and pass through;
-1 means the cell contains a thorn that blocks your way.

Your task is to collect maximum number of cherries possible by following the rules below:

Starting at the position (0, 0) and reaching (N-1, N-1) by moving right or down through valid path cells (cells with value 0 or 1);
After reaching (N-1, N-1), returning to (0, 0) by moving left or up through valid path cells;
When passing through a path cell containing a cherry, you pick it up and the cell becomes an empty cell (0);
If there is no valid path between (0, 0) and (N-1, N-1), then no cherries can be collected.


Example 1:
Input: grid =
[[0, 1, -1],
[1, 0, -1],
[1, 1,  1]]
Output: 5
Explanation:
The player started at (0, 0) and went down, down, right right to reach (2, 2).
4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
Then, the player went left, up, up, left to return home, picking up one more cherry.
The total number of cherries picked up is 5, and this is the maximum possible.

Note:
grid is an N by N 2D array, with 1 <= N <= 50.
Each grid[i][j] is an integer in the set {-1, 0, 1}.
It is guaranteed that grid[0][0] and grid[N-1][N-1] are not -1.

一个N x N的网格(grid) 代表了一块樱桃地，每个格子由以下三种数字的一种来表示：
0 表示这个格子是空的，所以你可以穿过它。
1 表示这个格子里装着一个樱桃，你可以摘到樱桃然后穿过它。
-1 表示这个格子里有荆棘，挡着你的路。
你的任务是在遵守下列规则的情况下，尽可能的摘到最多樱桃：
从位置 (0, 0) 出发，最后到达 (N-1, N-1) ，只能向下或向右走，并且只能穿越有效的格子（即只可以穿过值为0或者1的格子）；
当到达 (N-1, N-1) 后，你要继续走，直到返回到 (0, 0) ，只能向上或向左走，并且只能穿越有效的格子；
当你经过一个格子且这个格子包含一个樱桃时，你将摘到樱桃并且这个格子会变成空的（值变为0）；
如果在 (0, 0) 和 (N-1, N-1) 之间不存在一条可经过的路径，则没有任何一个樱桃能被摘到。
示例 1:
输入: grid =
[[0, 1, -1],
[1, 0, -1],
[1, 1,  1]]
输出: 5
解释：
玩家从（0,0）点出发，经过了向下走，向下走，向右走，向右走，到达了点(2, 2)。
在这趟单程中，总共摘到了4颗樱桃，矩阵变成了[[0,1,-1],[0,0,-1],[0,0,0]]。
接着，这名玩家向左走，向上走，向上走，向左走，返回了起始点，又摘到了1颗樱桃。
在旅程中，总共摘到了5颗樱桃，这是可以摘到的最大值了。
说明:
grid 是一个 N * N 的二维数组，N的取值范围是1 <= N <= 50。
每一个 grid[i][j] 都是集合 {-1, 0, 1}其中的一个数。
可以保证起点 grid[0][0] 和终点 grid[N-1][N-1] 的值都不会是 -1。
*/
/*

Get maximum cherry and must insure player can come back.
this can be sloved by what?

two dfs? and backtracking


*/

#include <vector>
#include <stack>
#include <iostream>
using namespace std;



class Solution
{
	struct stVertex
	{
		int m_r{ 0 };
		int m_c{ 0 };
		int m_d{ 0 };
		int m_v{ 0 };
		int cur_sum{ 0 };
	};

public:
	int cherryPickup(vector<vector<int>> &grid)
	{
		if (grid.empty())
		{
			return 0;
		}
		if (grid.size() == 1)
		{
			return grid[0][0];
		}
		int N = grid.size();
		stack<stVertex> eDfsStack;
		vector<vector<bool>> evisit(grid.size(), vector<bool>(grid[0].size(), false));

		static int edr[DC] = { 1, 0 };
		static int edc[DC] = { 0, 1 };
		stVertex startv;
		int sumc = 0;
		int maxc = 0;
		startv.cur_sum = grid[0][0];
		startv.m_c = 0;
		startv.m_r = 0;
		startv.m_d = 0;
		startv.m_v = grid[0][0];
		grid[0][0] = 0;
		evisit[0][0] = true;

	

		eDfsStack.push(startv);
		while (!eDfsStack.empty())
		{
			stVertex &tp = eDfsStack.top();
			if (DC == tp.m_d)
			{
				evisit[tp.m_r][tp.m_c] = false;
				grid[tp.m_r][tp.m_c] = tp.m_v;
				eDfsStack.pop();
			}
			else
			{
				int nr = tp.m_r + edr[tp.m_d];
				int nc = tp.m_c + edc[tp.m_d];
				tp.m_d += 1;
				if (canVisit(grid, evisit, nr, nc))
				{
					if ((N - 1) == nr && (N - 1) == nc)
					{
						sumc = tp.cur_sum + grid[nr][nc];
						int v = grid[nr][nc];
						grid[nr][nc] = 0;
						DfsEnd2Start(grid, maxc, sumc);
						grid[nr][nc] = v;
					}
					else
					{
						stVertex nextv;
						nextv.m_r = nr;
						nextv.m_c = nc;
						nextv.m_v = grid[nr][nc];
						nextv.cur_sum = tp.cur_sum + grid[nr][nc];
						eDfsStack.push(nextv);
						evisit[nr][nc] = true;
						grid[nr][nc] = 0;
					}
				}
			}
		}
		return maxc;
	}

private:
	bool canVisit(vector<vector<int>> &grid, vector<vector<bool>> &visit, int r, int c)
	{
		if (0 <= r && r < grid.size() && 0 <= c && c < grid[0].size() && !visit[r][c] && -1 != grid[r][c])
		{
			return true;
		}
		return false;
	}

	int DfsStart2End(vector<vector<int>> &grid)
	{

		return 0;
	}

	int DfsEnd2Start(vector<vector<int>> &grid, int &maxc, int sumc)
	{
		int N = grid.size();
		vector<vector<bool>> svisit(N, vector<bool>(N, false));
		stack<stVertex> sDfsStack;
		stVertex startv;
		static int sdr[DC] = { -1, 0 };
		static int sdc[DC] = { 0, -1 };
		startv.cur_sum = sumc;
		startv.m_r = N - 1;
		startv.m_c = N - 1;
		startv.m_v = 0;
		sDfsStack.push(startv);

		while (!sDfsStack.empty())
		{
			stVertex &tp = sDfsStack.top();
			if (DC == tp.m_d)
			{
				svisit[tp.m_r][tp.m_c] = false;
				grid[tp.m_r][tp.m_c] = tp.m_v;
				sDfsStack.pop();
			}
			else
			{
				int nr = tp.m_r + sdr[tp.m_d];
				int nc = tp.m_c + sdc[tp.m_d];
				tp.m_d += 1;
				if (canVisit(grid, svisit, nr, nc))
				{
					if (0 == nr && 0 == nc)
					{
						if (maxc< tp.cur_sum)
						{
							maxc = tp.cur_sum;
						}
					}
					else
					{
						stVertex nextv;
						nextv.m_r = nr;
						nextv.m_c = nc;
						nextv.m_v = grid[nr][nc];
						nextv.cur_sum = tp.cur_sum + grid[nr][nc];
						sDfsStack.push(nextv);
						svisit[nr][nc] = true;
						grid[nr][nc] = 0;
					}
				}
			}
		}
		return 0;
	}

private:
	static const int DC = 2;
};






int main()
{
	Solution sol;
	vector< vector<int> > grid
	{
		{ 0, 1, -1 },
		{ 1, 0, -1 },
		{ 1, 1, 1 }
	};

	//cout << sol.cherryPickup(grid) << endl;

	vector< vector<int> > grid1{
		{ 1, 1, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 0, 0, 1 },
		{ 1, 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 1, 1 }
	};

	//cout << sol.cherryPickup(grid1) << endl;

	vector<vector<int>> grid2{ {1} };
	//cout << sol.cherryPickup(grid2) << endl;

	vector<vector<int>> grid3
	{
		{ 1, 1, 1, 1, -1, -1, -1, 1, 0, 0 },
		{ 1, 0, 0, 0, 1, 0, 0, 0, 1, 0 },
		{ 0, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 1, 0, 1, 1, 1, 0, -1, 1, 1 },
		{ 0, 0, 0, 0, 1, -1, 0, 0, 1, -1 },
		{ 1, 0, 1, 1, 1, 0, 0, -1, 1, 0 },
		{ 1, 1, 0, 1, 0, 0, 1, 0, 1, -1 },
		{ 1, -1, 0, 1, 0, 0, 0, 1, -1, 1 },
		{ 1, 0, -1, 0, -1, 0, 0, 1, 0, 0 },
		{ 0, 0, -1, 0, 1, 0, 1, 0, 0, 1 }
	};

	cout << sol.cherryPickup(grid3) << endl;
	return 0;
}