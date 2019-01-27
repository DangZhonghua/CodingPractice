/*
https://leetcode-cn.com/problems/unique-paths/
Unique Paths

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?

Note: m and n will be at most 100.
Example 1:
Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:
Input: m = 7, n = 3
Output: 28

*/

#include<vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vector< vector<int> > mp(m, vector<int>(n,0) );
        mp[0][0] = 1;

        for(int r = 0; r<m;++r)
        {
            for(int c = 0; c<n; ++c)
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
        return mp[m-1][n-1];
    }
};