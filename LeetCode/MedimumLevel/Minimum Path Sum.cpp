/*
https://leetcode-cn.com/problems/minimum-path-sum/
Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
Example:
Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.

*/

#include<vector>
#include<climits>
#include<iostream>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int R = grid.size();
        int C = grid[0].size();
        vector< vector<int> > s(R,vector<int>(C,0));
        s[0][0] = grid[0][0];
        
        for(int r = 1; r<R; ++r)
        {
          s[r][0] = s[r-1][0]+grid[r][0]; 
        }
        for(int c = 1; c<C;++c)
        {
          s[0][c] = s[0][c-1] + grid[0][c];
        }

        for( int r = 1; r<R; ++r)
        {
          for(int c = 1; c<C; ++c)
          {
            s[r][c] = s[r-1][c]+grid[r][c];
            if(s[r][c]>(s[r][c-1]+grid[r][c]) )
            {
              s[r][c] = s[r][c-1] + grid[r][c];
            }
          }
        }

        return s[R-1][C-1];
    }
};

int main()
{
  vector< vector<int> > grid{  {1,3,1},
                                {1,5,1},
                                {4,2,1}
                            };

  Solution sol;

  cout<< sol.minPathSum(grid)<<endl;

  return 0;
}