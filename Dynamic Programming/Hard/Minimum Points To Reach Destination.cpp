/*
Minimum Points To Reach Destination 
https://practice.geeksforgeeks.org/problems/minimum-points-to-reach-destination/0/?ref=self
https://www.geeksforgeeks.org/minimum-positive-points-to-reach-destination/

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
 ooooooooo; k,okl;  lop
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

/*

At the first look, this problem looks similar Max/Min Cost Path, but maximum overall points 
gained will not guarantee the minimum initial points. 
Also, it is compulsory in the current problem that the points never drops to zero or below. 
For instance, Suppose following two paths exists from source to destination cell.

We can solve this problem through bottom-up table filling dynamic programing technique.

To begin with, we should maintain a 2D array dp of the same size as the grid, where dp[i][j] represents the minimum points that guarantees the continuation of the journey to destination before entering the cell (i, j). It’s but obvious that dp[0][0] is our final solution. Hence, for this problem, we need to fill the table from the bottom right corner to left top.
Now, let us decide minimum points needed to leave cell (i, j) (remember we are moving from bottom to up). There are only two paths to choose: (i+1, j) and (i, j+1). Of course we will choose the cell that the player can finish the rest of his journey with a smaller initial points. Therefore we have: min_Points_on_exit = min(dp[i+1][j], dp[i][j+1])

Now we know how to compute min_Points_on_exit, but we need to fill the table dp[][] to get the solution in dp[0][0].

How to compute dp[i][j]?
     The value of dp[i][j] can be written as below.

dp[i][j] = max(min_Points_on_exit – points[i][j], 1)

Let us see how above expression covers all cases.

If points[i][j] == 0, then nothing is gained in this cell; the player can leave the cell with the same points as he enters the room with, i.e. dp[i][j] = min_Points_on_exit.
If dp[i][j] < 0, then the player must have points greater than min_Points_on_exit before entering (i, j) in order to compensate for the points lost in this cell. The minimum amount of compensation is " – points[i][j] ", so we have dp[i][j] = min_Points_on_exit – points[i][j].
If dp[i][j] > 0, then the player could enter (i, j) with points as little as min_Points_on_exit – points[i][j]. since he could gain “points[i][j]” points in this cell. However, the value of min_Points_on_exit – points[i][j] might drop to 0 or below in this situation. When this happens, we must clip the value to 1 in order to make sure dp[i][j] stays positive:
dp[i][j] = max(min_Points_on_exit – points[i][j], 1).

Finally return dp[0][0] which is our answer.

*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int minimumInitCost(int m[10][10], int R, int C )
{
    vector< vector<int> > cost(10, vector<int>(10,0));
    
    //This is the initilalize
    cost[R-1][C-1] = m[R-1][C-1]>=0? 1: 1-m[R-1][C-1];
    
    for(int r = R-1; r>=0; --r)
    {
        for(int c = C-1; c>=0; --c)
        {
            if(r == R-1 && c == C-1)
            {
                continue;
            }
            int mincost = INT_MAX;
            if(r+1<R)
            {
                 mincost = cost[r+1][c];
            }
            if(c+1<C && mincost>cost[r][c+1])
            {
                mincost = cost[r][c+1];   
            }
            cost[r][c] = 1;
            if(cost[r][c]<mincost-m[r][c])
            {
                cost[r][c] = mincost-m[r][c];
            } 
        }
    }


    cout<<cost[0][0]<<endl;

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