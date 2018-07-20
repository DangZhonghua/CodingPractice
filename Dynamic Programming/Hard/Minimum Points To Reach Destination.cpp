/*
Minimum Points To Reach Destination 
https://practice.geeksforgeeks.org/problems/minimum-points-to-reach-destination/0/?ref=self
Given a grid with each cell consisting of positive, negative or no points i.e, zero points. 
We can move across a cell only if we have positive points ( > 0 ). 
Whenever we pass through a cell, points in that cell are added to our overall points. 
We need to find minimum initial points to reach cell (m-1, n-1) from (0, 0) 
by following these certain set of rules :
 
1.From a cell (i, j) we can move to (i+1, j) or (i, j+1).
2.We cannot move from (i, j) if your overall points at (i, j) is <= 0.
3.We have to reach at (n-1, m-1) with minimum positive points i.e., > 0.
 
Example:
 
Input: points[m][n] = { {-2, -3,   3},  
                        {-5, -10,  1},  
                        {10,  30, -5}  
                      };
Output: 7
Explanation:  
7 is the minimum value to reach destination with  
positive throughout the path. Below is the path.
 
(0,0) -> (0,1) -> (0,2) -> (1, 2) -> (2, 2)
 
We start from (0, 0) with 7, we reach(0, 1)  
with 5, (0, 2) with 2, (1, 2) with 5, (2, 2)
with and finally we have 1 point (we needed  
greater than 0 points at the end).

Input:

The first line contains an integer 'T' denoting the total number of test cases.
In each test cases, the first line contains two integer 'R' and 'C' denoting the number of rows and column of array.  
The second line contains the value of the array i.e the grid, in a single line separated by spaces in row major order.


Output:

Print the minimum initial points to reach the bottom right most cell in a separate line.


Constraints:

1 ≤ T ≤ 30
1 ≤ R,C ≤ 10
-30 ≤ A[R][C] ≤ 30


Example:

Input:
1
3 3
-2 -3 3 -5 -10 1 10 30 -5
Output:
7


*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int minimumInitCost(int m[10][10], int R, int C )
{
    vector< vector<int> > cost(10, vector<int>(10,INT_MAX));
    vector< vector<int> > sum(10, vector<int>(10,0));
    
    cost[0][0] = 0;
    if(m[0][0]<=0)
    {
        cost[0][0] = 1 -  m[0][0];
    }
    sum[0][0] = cost[0][0] + m[0][0];


    
    for(int r = 0; r<R; ++r)
    {
        for(int c = 0; c<C; ++c)
        {
            if(c>=1)
            {
                if( sum[r][c-1] + m[r][c] > 0)
                {
                    cost[r][c] = cost[r][c-1];
                    sum[r][c]  = sum[r][c-1] + m[r][c];
                }
                else
                {
                    cost[r][c] = cost[r][c-1] + (1-sum[r][c-1] - m[r][c]);
                    sum[r][c]  = 1;
                }
            }
            if(r>=1)
            {
                if(sum[r-1][c] + m[r][c] > 0)
                {
                    cost[r-1][c]; 
                    cost[r][c];
                    sum[r][c];
                    sum[r-1][c] + m[r][c];
                }
                else
                {

                }
            }
        }
    }

    cout<<cost[R-1][C-1]<<endl;

    return 0;
}


int main()
{
    int t = 0;
    int m[10][10];
    
    cin>>t;
    
    while(t--)
    {
        int R = 0;
        int C = 0;
        cin>>R>>C;
        
        int r = 0;
        while(r<R)
        {
            int c = 0;
            while(c<C)
            {
                cin>>m[r][c++];
            }
            ++r;
        }
        minimumInitCost(m,R,C);
    }


    return 0;
}