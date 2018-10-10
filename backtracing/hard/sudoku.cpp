/*

https://practice.geeksforgeeks.org/problems/solve-the-sudoku/0/?ref=self

Solve the Sudoku 
Given an incomplete Sudoku configuration in terms of a 9x9  2-D square matrix (mat[][]) the task to print 
a solution of the Sudoku. For simplicity you may assume that there will be only one unique solution.

Example

For the above configuration the solution is
3 1 6 5 7 8 4 9 2
5 2 9 1 3 4 7 6 8
4 8 7 6 2 9 5 3 1
2 6 3 4 1 5 9 8 7
9 7 4 8 6 3 1 2 5
8 5 1 7 9 2 6 4 3
1 3 8 9 4 7 2 5 6
6 9 2 3 5 1 8 7 4
7 4 5 2 8 6 3 1 9


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. 
Each test case contains 9*9 space separated values of the matrix mat[][] representing an incomplete Sudoku state 
where a 0 represents empty block.

Output:
For each test case in a new line print the space separated values of the solution of the the sudoku.

Constraints:
1<=T<=10
0<=mat[]<=9

Example:
Input:
1
3 0 6 5 0 8 4 0 0 5 2 0 0 0 0 0 0 0 0 8 7 0 0 0 0 3 1 0 0 3 0 1 0 0 8 0 9 0 0 8 6 3 0 0 5 0 5 0 0 9 0 6 0 0 1 3 0 0 0 0 2 5 0 0 0 0 0 0 0 0 7 4 0 0 5 2 0 6 3 0 0

Output:
3 1 6 5 7 8 4 9 2 5 2 9 1 3 4 7 6 8 4 8 7 6 2 9 5 3 1 2 6 3 4 1 5 9 8 7 9 7 4 8 6 3 1 2 5 8 5 1 7 9 2 6 4 3 1 3 8 9 4 7 2 5 6 6 9 2 3 5 1 8 7 4 7 4 5 2 8 6 3 1 9 

*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void OutputSudokuSolution(vector< vector<int> >& board, int N)
{
    for(int r = 0; r<N; ++r)
    {
        for(int c = 0; c<N; ++c)
        {
            cout<<board[r][c]<<" ";
        }
    }
    cout<<endl;
}

int CalcGridIndex(int r, int c,int n )
{
    int index = -1;
    index =  (n*(r/n) + c/n);
    return index;
}
bool findEmptyLocation(vector< vector<int> >& board, int& row, int& col, int N)
{
    for( int r = 0; r<N; ++r)
    {
        for(int c = 0; c< N; ++c)
        {
            if(0 == board[r][c])
            {
                row = r;
                col = c;
                return true;
            }
        }
    }
    return false;
}

bool isSafePlace(vector< vector<bool>  > & rv, vector<vector<bool>>& cv, vector< vector<bool> >& bv, 
                int row, int col,int num, int N)
{
    if(rv[row][num]) // have place the same num at the same row
    {
        return false;
    }
    if(cv[col][num]) // have place the same num at the same col.
    {
        return false;
    }
    if(bv[CalcGridIndex(row,col,sqrt(N))][num]) // have place the same num at the same grid
    {
        return false;
    }
    

    return true;
}


bool BtSolveSudoku( vector< vector<bool>  > & rv, vector<vector<bool>>& cv, vector<vector<bool>>& bv,vector<vector<int>> &board, int N)
{
    bool bSolve = false;
    int row = 0;
    int col = 0;
    if( !findEmptyLocation(board,row,col,N))
    {
        return true;
    }

    for(int num = 1; num<=N; ++num)
    {
        if(isSafePlace(rv,cv,bv,row,col,num,N))
        {
            //set the flag for fast backtrack.


        }
    }


    return bSolve;
}



int SolveSudoku(vector<vector<int>> &board, int N)
{
    //set the map for quick check conflict.
    vector< vector<bool> > rv(N, vector<bool>(N,0));
    vector< vector<bool> > cv(N, vector<bool>(N,0));
    vector< vector<bool> > bv(N, vector<bool>(N,0));

    int ngrid = sqrt(N);
    for(int r = 0; r<N; ++r )
    {
        for(int c = 0; c<N; ++c)
        {
            if(0 == board[r][c])
            {
                continue;
            }
            rv[r][board[r][c]] = true;
            cv[c][board[r][c]] = true;
            bv[CalcGridIndex(r,c,ngrid)][board[r][c]] = true;
        }
    }

    BtSolveSudoku(rv,cv,bv,board,N,0,0);

    return 0;
}

int main(int argc, char const *argv[])
{
    int N = 9;
    int t = 0;

    cin >> t;
    while (t--)
    {
        vector<vector<int>> board(N, vector<int>(N, 0));
        int r = 0;
        int c = 0;
        while (r < N)
        {
            c = 0;
            while (c < N)
            {
                cin >> board[r][c];
                ++c;
            }
        }
    }

    return 0;
}
