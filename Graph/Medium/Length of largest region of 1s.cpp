/*
Length of largest region of 1's
https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s/0
https://www.geeksforgeeks.org/find-length-largest-region-boolean-matrix/


Consider a matrix with rows and columns (n,m), where each cell contains either a ‘0’ or a ‘1’ and
any cell containing a 1 is called a filled cell.
Two cells are said to be connected if they are adjacent to
each other horizontally, vertically, or diagonally .
If one or more filled cells are connected, they form a region.
Your task is to  find the length of the largest region.

Examples:

Input : M[][5] = { 0 0 1 1 0
				   1 0 1 1 0
				   0 1 0 0 0
				   0 0 0 0 1 }
Output : 6
Ex: in the following example, there are
2 regions one with length 1 and the other as 6.
so largest region : 6


Input:
The first line of input will be the no of test cases T then T test cases follow.
The first line of each test case contains Two space separated integers n and m.
Then in the next line are the nxm inputs of the matrix A separated by space .

Output:
The output in the expected output will be the length of the largest region formed.

Constraints:
1<=T<=100
1<=n,m<=50
0<=A[][]<=1

Example:
Input:
2
3 3
1 1 0 0 0 1 1 0 1
1 3
1 1 1
Output:
4
3


*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution
{
public:

	//Use DFS to solve this task.
	int LargestRegion(vector< vector<int> >& Graph)
	{
		int R = Graph.size();
		int C = Graph[0].size();
		vector< vector<bool> > visited(R, vector<bool>(C, 0));
		int maxRegion = 0;
		for (int r = 0; r < R; ++r)
		{
			for (int c = 0; c < C; ++c)
			{
				int nVertices = 0;
				DFS(Graph, visited, r, c, nVertices);
				if (nVertices > maxRegion)
				{
					maxRegion = nVertices;
				}
			}
		}
		return maxRegion;
	}

private:
	int DFS(vector< vector<int> >& Graph, vector< vector<bool> >& visited, int r, int c, int& nVertices)
	{
		struct gVertex
		{
			int r;
			int c;
			int d;
			gVertex() { d = 0; }
			gVertex(int _r, int _c, int _d) { r = _r; c = _c; d = _d; }
		};
		if (!Graph[r][c] || visited[r][c]) // this vertex has already visited or NOT "connected"
		{
			return 0;
		}
		stack<gVertex> dfsStack;
		dfsStack.push(gVertex(r, c, 0));
		visited[r][c] = true;
		++nVertices;

		while (!dfsStack.empty())
		{
			gVertex& tp = dfsStack.top();
			if (tp.d == DC)
			{
				dfsStack.pop();
				continue;
			}
			int nr = tp.r + rn[tp.d];
			int nc = tp.c + cn[tp.d];
			++tp.d;
			if (CanVisit(Graph, visited, nr, nc))
			{
				++nVertices; // count it if it can be push into stack.
				dfsStack.push(gVertex(nr, nc, 0));
				visited[nr][nc] = true;
			}
		}
	}

	bool CanVisit(vector< vector<int> >& Graph, vector< vector<bool> >& visited, int r, int c)
	{
		if (0 <= r && r < Graph.size() && 0 <= c && c < Graph[0].size() && !visited[r][c] && Graph[r][c])
		{
			return true;
		}
		return false;
	}

private:
	static const int DC = 8;
	int rn[DC] = { -1,-1,-1,0,1,1,1,0 }; // "n" means neighbour
	int cn[DC] = { -1,0,1,1,1,0,-1,-1 };
};


int main()
{
	int t = 0;

	cin >> t;

	while (t--)
	{
		int r = 0;
		int c = 0;
		cin >> r >> c;
		vector< vector<int> > Graph(r, vector<int>(c, 0));
		int i = 0;
		int j = 0;

		while (i < r)
		{
			j = 0;
			while (j < c)
			{
				cin >> Graph[i][j];
				++j;
			}
			++i;
		}
		Solution sol;
		cout << sol.LargestRegion(Graph) << endl;
	}


	return 0;
}