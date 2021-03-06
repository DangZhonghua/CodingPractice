/*
https://leetcode-cn.com/problems/unique-paths-ii/
Unique Paths II
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to 
reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.
Note: m and n will be at most 100.
Example 1:
Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

*/

/*

mp[i][j] = mp[i-1][j] + mp[i][j-1]

*/
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
      int R = obstacleGrid.size();
      int C = obstacleGrid[0].size();
      vector< vector<int> > mp(R+1, vector<int>(C+1,0));
      if(0 == obstacleGrid[0][0]) // this for real case.
       {
         mp[0][0] = 1; 
       }
      
      for(int r = 0; r<R; ++r)
      {
        for(int c = 0; c<C; ++c)
        {
          if(0 == obstacleGrid[r][c])
          {
              if(r-1>=0)
              {
                mp[r][c] += mp[r-1][c];
              }
              if(c-1>=0)
              {
                mp[r][c] += mp[r][c-1];
              }
          }
        }
      }
      return mp[R-1][C-1];
    }
};