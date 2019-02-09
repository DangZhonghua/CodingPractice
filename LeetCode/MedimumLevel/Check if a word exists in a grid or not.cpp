/*
https://www.geeksforgeeks.org/check-if-a-word-exists-in-a-grid-or-not/
Check if a word exists in a grid or not

Given a 2D grid of characters and a word, the task is to check if that word exists in the grid or not.
 A word can be matched in 4 directions at any point.

The 4 directions are, Horizontally Left and Right, Vertically Up and Down.
Examples:

Input:  grid[][] = {"axmy",
					"bgdf",
					"xeet",
					"raks"};
Output: Yes

a x m y
b g d f
x e e t
r a k s

Input: grid[][] = {"axmy",
				   "brdf",
				   "xeet",
				   "rass"};
Output : No


*/

#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

class Solution
{
public:
	bool WordExists(vector< vector<char>>& matrix, string& s)
	{
		bool bFind = false;
		for (int r = 0; r < matrix.size() && !bFind; ++r)
		{
			for (int c = 0; c < matrix[0].size(); ++c)
			{
				if (matrix[r][c] == s[0])
				{
					if (dfsSearch(matrix, s, r, c))
					{
						bFind = true;
						break;
					}
				}
			}
		}
		return bFind;
	}
private:
	bool dfsSearch(vector< vector<char>>& matrix, string& s, int r, int c)
	{
		vector< vector<bool> > visit(matrix.size(), vector<bool>(matrix[0].size(), false));
		struct gVertex
		{
			int m_r{ 0 };
			int m_c{ 0 };
			int m_d{ 0 };
			int m_sIndex{ 0 };
			gVertex() {}
			gVertex(int r, int c, int d, int index)
			{
				m_r = r;
				m_c = c;
				m_d = d;
				m_sIndex = index;
			}
		};
		bool bFind = false;
		int sindex = 0;
		stack<gVertex> dfsStack;
		dfsStack.push(gVertex(r, c, 0, 0));
		visit[r][c] = true;

		while (!dfsStack.empty())
		{
			gVertex& tp = dfsStack.top();
			if ((tp.m_sIndex + 1) == s.length())
			{
				bFind = true;
				break;
			}
			if (DC == tp.m_d)
			{
				dfsStack.pop();
				visit[r][c] = false;
				continue;
			}
			int nr = tp.m_r + rn[tp.m_d];
			int nc = tp.m_c + cn[tp.m_d];
			tp.m_d += 1;
			if (CanVisit(nr, nc, visit))
			{
				if (s[tp.m_sIndex + 1] == matrix[nr][nc])
				{
					dfsStack.push(gVertex(nr, nc, 0, tp.m_sIndex + 1));
					visit[nr][nc] = true;
				}
			}
		}
		return bFind;

	}

	bool CanVisit(int r, int c, vector< vector<bool>>& visit)
	{
		if (0 <= r && r < visit.size() && 0 <= c && c < visit[0].size() && !visit[r][c])
		{
			return true;
		}
		return false;
	}

private:
	static const int DC = 4;
	int rn[DC] = { -1,0,1,0 };
	int cn[DC] = { 0,1,0,-1 };

};

int main()
{
	vector< vector<char> > g
	{
		{'a','x','m','y'},
		{'b','g','d','f'},
		{'x','e','e','t'},
		{'r','a','k','s'}
	};
	string s = "geeks";
	Solution sol;
	// Function to check if word exists or not 
	if (sol.WordExists(g, s))
		cout << "Yes";
	else
		cout << "No";

	return 0;

}