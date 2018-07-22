/*
Find length of the longest consecutive path from a given starting character
https://www.geeksforgeeks.org/find-length-of-the-longest-consecutive-path-in-a-character-matrix/
Given a matrix of characters. Find length of the longest path from a given character,
such that all characters in the path are consecutive to each other, i.e.,
every character in path is next to previous in alphabetical order.
It is allowed to move in all 8 directions from a cell.

Example

Input: mat[][] = { {a, c, d},
{h, b, e},
{i, g, f}}
Starting Point = 'e'

Output: 5
If starting point is 'e', then longest path with consecutive
characters is "e f g h i".

Input: mat[R][C] = { {b, e, f},
{h, d, a},
{i, c, a}};
Starting Point = 'b'

Output: 1
'c' is not present in all adjacent cells of 'b'


*/

#include<iostream>
#include<vector>
using namespace std;


int rd[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int cd[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

// find the path use the graph dfs algoithm to do this.
// When adjency char is consecutive with is parent, then we 
// continue traverse.

int isValidate(int r, int c, int R, int C)
{
	if (0 <= r && r<R && 0 <= c && c<C)
	{
		return true;
	}
	return false;
}


int dfs(vector< vector<int> >& m, int sr, int sc, int R, int C)
{
	int p = 1;
	for (int i = 0; i<8; ++i)
	{
		int nr = sr + rd[i];
		int nc = sc + cd[i];
		if (!isValidate(nr, nc, R, C))
		{
			continue;
		}
		if (m[sr][sc] + 1 != m[nr][nc])
		{
			continue;
		}
		p = 1 + dfs(m, nr, nc, R, C);
	}
	return p;
}


int LCP(vector< vector<int> >& m, int sr, int sc, int R, int C)
{
	int path = 0;

	path = dfs(m, sr, sc, R, C);

	cout << path << endl;

	return 0;
}

int main()
{
	int t = 0;
	int R = 0;
	int C = 0;
	int sr = 0;
	int sc = 0;
	vector< vector<int> > m;

	cin >> t;

	while (t--)
	{
		cin >> R >> C;
		vector<int> RD(C, 0);
		int r = 0;
		while (r < R)
		{
			m.push_back(RD);
			++r;
		}
		r = 0;
		int c = 0;

		while (r < R)
		{
			c = 0;
			while (c<C)
			{
				char ch;
				cin >> ch;
				m[r][c++] = ch;
			}
			++r;
		}
		cin >> sr >> sc;
		LCP(m, sr, sc, R, C);

	}

	return 0;
}
