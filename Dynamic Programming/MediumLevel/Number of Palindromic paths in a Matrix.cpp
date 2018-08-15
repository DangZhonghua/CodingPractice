/*


https://practice.geeksforgeeks.org/problems/number-of-palindromic-paths-in-a-matrix/0

Number of Palindromic paths in a Matrix

Given a matrix containing lower alphabetical characters only, we need to count number of palindromic paths in given matrix. A path is defined as a sequence of cells starting from top-left cell and ending at bottom-right cell. We are allowed to move to right and down only from current cell.

Input:
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines.
First line of each test case consist of two space separated integers R and C, denoting the number of element in a row and column respectively.
Second line of each test case consists of R*C space separated chars denoting the elements in the matrix in row major order.

Output:
It should be single line output, Print the respective output in the respective line.

Constraints:
1<=T<=20
1<=R,C<=10

Example:
Input:
1
3 4
a a a b b a a a a b b a

Output:
3
*/


#include<iostream>
#include<vector>
using namespace std;

bool judgePalindromic(const vector<char>& vpath)
{
	int i = 0;
	int j = vpath.size() - 1;
	bool bPalindromic = true;
	while (i<j)
	{
		if (vpath[i] != vpath[j])
		{
			bPalindromic = false;
			break;
		}
		++i;
		--j;
	}
	return bPalindromic;
}


int FindPath(vector< vector<char> >& m, int R, int C, int r, int c, vector<char>& path, int& pathcount)
{
	if (R - 1 == r && C - 1 == c)
	{
		path.push_back(m[r][c]);
		if (judgePalindromic(path))
		{
			++pathcount;
		}
		path.pop_back();
	}
	else
	{
		path.push_back(m[r][c]);
		if (r + 1<R)
		{
			FindPath(m, R, C, r + 1, c, path, pathcount);
		}
		if (c + 1<C)
		{
			FindPath(m, R, C, r, c + 1, path, pathcount);
		}
		path.pop_back();
	}

	return 0;
}

int main()
{
	int t = 0;

	cin >> t;

	while (t--)
	{
		int R, C;
		cin >> R >> C;
		vector< vector<char> > m(R, vector<char>(C, 0));
		int i = 0;
		int j = 0;
		while (i<R)
		{
			j = 0;
			while (j<C)
			{
				char a;
				cin >> a;
				m[i][j] = a;
				++j;
			}
			++i;
		}
		vector<char> path;
		int ncount = 0;
		FindPath(m, R, C, 0, 0, path, ncount);
		cout << ncount << endl;
	}


	return 0;
}
