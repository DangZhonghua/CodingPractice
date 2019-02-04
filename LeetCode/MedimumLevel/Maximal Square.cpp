/*
https://leetcode-cn.com/problems/maximal-square/
Maximal Square

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4

*/

/*
            0 if matrix[i][j] = 0
dp[i][j] = 
            min{dp[i-1][j], dp[i][j-1], dp[i-1][j-1] } + 1;
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        if(matrix.empty() || matrix[0].empty())
        {
            return 0;
        }
        int R = matrix.size();
        int C = matrix[0].size();
        int LS = 0;
        vector<vector<int>> s(R,vector<int>(C,0));

        for(int r = 0; r<R; ++r)
        {
            s[r][0] = matrix[r][0];
        }
        for(int c = 0; c<C; ++c)
        {
            s[0][c] = matrix[0][c];
        }
        for(int r = 1; r<R; ++r)
        {
            for(int c = 1; c<C; ++c)
            {
                if(0 == matrix[r][c])
                {
                    s[r][c] = 0;
                }
                else
                {
                    s[r][c] = min(min(s[r-1][c],s[r][c-1]),s[r-1][c-1])+1;
                }
            }
        }

        for(int r = 0; r<R; ++r)
        {
            for(int c = 0; c<C; ++c)
            {
                if(LS<s[r][c])
                {
                    LS = s[r][c];
                }
            }
        }
        return (LS*LS);
    }
};

int main()
{
    vector<vector<char> >m
    {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}
    };
    Solution sol;
    sol.maximalSquare(m);

    return;
}