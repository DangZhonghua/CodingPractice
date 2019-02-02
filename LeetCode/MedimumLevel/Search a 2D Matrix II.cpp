/*
https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
Search a 2D Matrix II

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:
Consider the following matrix:
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.
Given target = 20, return false.

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		bool bFind = false;
		do
		{
			if (matrix.empty() || matrix[0].empty())
			{
				break;
			}
			int row = SearchRowBoundary(matrix, target);

			if (row != matrix.size())
			{
				if (matrix[row][0] == target)
				{
					bFind = true;
					break;
				}
			}

			if (0 == row)
			{
				break;
			}

			int col = SearchColumnBoundary(matrix, row - 1, target);

			if (col != matrix[0].size())
			{
				if (matrix[row-1][col] == target)
				{
					bFind = true;
					break;
				}
			}
			if (0 == col)
			{
				break;
			}

			int index = -1;
			
			while( -1 == index && col<matrix[0].size())
			{
				index = searchTarget(matrix, row - 1, col, target);
				++col;
			}
			

			if (-1 != index)
			{
				bFind = true;
			}
		} while (false);

		return bFind;
	}

private:
	// search a row from column 0
	int SearchRowBoundary(vector<vector<int>>& matrix, int target)
	{
		int i = 0;
		int j = matrix.size() - 1;
		int index = -1;
		while (i <= j)
		{
			int m = (i + j) / 2;
			if (matrix[m][0] == target)
			{
				index = m;
				break;
			}
			else if (matrix[m][0] < target)
			{
				i = (m + 1);
			}
			else
			{
				j = (m - 1);
			}
		}
		if (-1 == index)
		{
			index = i;
		}
		return index;
	}

	int SearchColumnBoundary(vector<vector<int>>& matrix, int row, int target)
	{
		int i = 0;
		int j = matrix[row].size() - 1;
		int index = -1;
		while (i <= j)
		{
			int m = (i + j) / 2;
			if (matrix[row][m] == target)
			{
				index = m;
				break;
			}
			else if (matrix[row][m] < target)
			{
				i = (m + 1);
			}
			else
			{
				j = (m - 1);
			}
		}
		if (-1 == index)
		{
			index = i;
		}

		return index;
	}

	int searchTarget(vector<vector<int>>& matrix, int row, int col, int target)
	{
		int i = 0;
		int j = row;
		int index = -1;
		while (i <= j)
		{
			int m = (i + j) / 2;

			if (matrix[m][col] == target)
			{
				index = m;
				break;
			}
			else if (matrix[m][col] > target)
			{
				j = (m - 1);
			}
			else
			{
				i = (m + 1);
			}
		}
		return index;
	}
};

int main()
{
	Solution sol;
	int target = 20;
	
	vector<vector<int> > m
	{
		  {1,   4,  7, 11, 15},
		  {2,   5,  8, 12, 19},
		  {3,   6,  9, 16, 22},
		  {10, 13, 14, 17, 24},
		  {18, 21, 23, 26, 30}
	};
	
	cout << sol.searchMatrix(m, target) << endl;
	vector< vector<int> > m1
	{
		{5,  6, 10,  14},
		{6, 10, 13,  18},
		{10,13, 18,  19}
	};
	cout << sol.searchMatrix(m1, 14) << endl;

	return 0;
}