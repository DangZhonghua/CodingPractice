/*
https://leetcode-cn.com/problems/minimum-falling-path-sum/
Minimum Falling Path Sum

Given a square array of integers A, we want the minimum sum of a falling path through A.

A falling path starts at any element in the first row, and chooses one element from each row.  
The next row's choice must be in a column that is different from the previous row's column by at most one.

 

Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: 12
Explanation: 
The possible falling paths are:

    [1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
    [2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
    [3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]

The falling path with the smallest sum is [1,4,7], so the answer is 12.
*/

#include<vector>
using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) 
    {
        if(A.empty())
        {
            return 0;
        }
         int minv = 0;
        int N = A.size();
        vector<vector<int>> matrix(N,vector<int>(N,0));
        for(int c = 0; c<N; ++c)
        {
            matrix[0][c] = A[0][c];
        }
        
        for(int r = 1; r<N; ++r)
        {
            for(int c = 0; c<N; ++c)
            {
                matrix[r][c] = matrix[r-1][c]+A[r][c];
                if(c-1>=0)
                {
                    if(matrix[r][c]> (matrix[r-1][c-1]+A[r][c]) )
                    {
                        matrix[r][c]= (matrix[r-1][c-1]+A[r][c]);
                    }
                }
                if(c+1<N)
                {
                     if(matrix[r][c]> (matrix[r-1][c+1]+A[r][c]) )
                     {
                         matrix[r][c] = (matrix[r-1][c+1]+A[r][c]);
                     }
                }
            }         
        }
        minv = matrix[N-1][0];
        for(int c = 1; c<N;++c)
        {
                if(minv>matrix[N-1][c])
                {
                    minv = matrix[N-1][c];
                }
        }  
        return minv;
    }
};