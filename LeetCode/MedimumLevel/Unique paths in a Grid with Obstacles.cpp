/*

https://www.geeksforgeeks.org/unique-paths-in-a-grid-with-obstacles/


Unique paths in a Grid with Obstacles

Given a grid of size m * n, let us assume you are starting at (1, 1) and your goal is to reach (m, n). 
At any instance, if you are on (x, y), you can either go to (x, y + 1) or (x + 1, y).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space are marked as 1 and 0 respectively in the grid.

Examples:

Input: [[0, 0, 0],
        [0, 1, 0],
        [0, 0, 0]]
Output : 2
There is only one obstacle in the middle.

*/


/*

 mp[i][j] = mp[i-1][j] + mp[i][j-1]

*/


#include<iostream>
#include<vector>
using namespace std;



class Solution
{
public:
    int UniquePathNumber(vector< vector<int> >& matrix)
    {
        int R = matrix.size();
        int C = matrix[0].size();
        vector< vector<int> > mp(R,vector<int>(C,0));

        if(matrix.empty() || matrix[0].empty())
        {
            return 0;
        }        
        if(0 == matrix[0][0])
        {
            mp[0][0] = 1;
        }
        
        for(int r = 1; r<R; ++r)
        {
            if(matrix[r][0])
            {
                mp[r][0] = 0;
            }
            else
            {
                mp[r][0] = mp[r-1][0];
            }
        }

        for(int c = 1; c<C; ++c)
        {
            if(matrix[0][c])
            {
                mp[0][c] = 0;
            }
            else
            {
                mp[0][c] = mp[0][c-1];
            }
        }
        
        for(int r = 1; r<R; ++r)
        {
            for(int c = 1; c<C; ++c)
            {
                if(matrix[r][c])
                {
                    mp[r][c] = 0;
                }
                else
                {
                    mp[r][c] = (mp[r-1][c] + mp[r][c-1]);
                }
            }
        }
        
        return mp[R-1][C-1];
    }
};

int main()
{
    vector< vector<int> > m 
        {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
        };

    Solution Sol;
    cout<<Sol.UniquePathNumber(m)<<endl;
    return 0;
}