/*
https://leetcode-cn.com/problems/search-a-2d-matrix/
 Search a 2D Matrix

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:
Input:
matrix =
[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:
Input:
matrix =
[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false

*/

#include<iostream>
#include<vector>>
using namespace std;

class Solution {
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
			int row = SearchColumn(matrix, target);
			if (-1 == row)
			{
				break;
			}
			if (row != matrix.size() && matrix[row][0] == target)
			{
				bFind = true;
				break;
			}
			if (0 == row)
			{
				break;
			}

			int col = SearchInRow(matrix, row - 1, target);
			if (-1 != col)
			{
				bFind = true;
			}
		} while (false);

		return bFind;
	}

private:

    //return row whose first element is no less than target
	int SearchColumn(vector<vector<int>>& matrix, int target)
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
			else if (matrix[m][0] > target)
			{
				j = m - 1;
			}
			else
			{
				i = m + 1;
			}
		}
		if (-1 == index)
		{
			index = i;
		}
		return index;
	}
	int SearchInRow(vector<vector<int>>& matrix, int row, int target)
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
			else if (matrix[row][m] > target)
			{
				j = m - 1;
			}
			else
			{
				i = m + 1;
			}
		}
		return index;
	}
};


int main()
{
	vector<vector<int> > a{ 0, vector<int>(0,0) };
	int target = 1;
	Solution sol;
	sol.searchMatrix(a, 1);

	return 0;
}