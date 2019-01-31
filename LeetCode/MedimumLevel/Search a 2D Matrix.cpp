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
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int row = SearchColumn(matrix, target);
        SearchInRow(matrix,row,target);
    }
    
private:
    int SearchColumn(vector<vector<int>>& matrix, int target)
    {
        int i = 0;
        int j = matrix.size()-1;

        while(i<=j)
        {
            
        }
    }
    int SearchInRow( vector<vector<int>>& matrix, int row, int target)
    {

    }
};