/*
N-Queen Problem
https://practice.geeksforgeeks.org/problems/n-queen-problem/0
https://www.geeksforgeeks.org/printing-solutions-n-queen-problem/

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
Given an integer n, print all distinct solutions to the n-queens puzzle.
Each solution contains distinct board configurations of the n-queens’ placement,
where the solutions are a permutation of [1,2,3..n] in increasing order,
here the number in the ith place denotes that the ith-column queen is placed in the row with that number.
For eg below figure represents a chessboard [3 1 4 2].


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow.
Each test case contains an integer n denoting the size of the chessboard.

Output:
For each test case, output your solutions on one line where each solution is enclosed i
n square brackets '[', ']' separated by a space .
The solutions are permutations of {1, 2, 3 …, n} in increasing order
where the number in the ith place denotes the ith-column queen is placed in the row with that number,
if no solution exists print -1.

Constraints:
1<=T<=10
1<=n<=10

Example:
Input
2
1
4
Output:
[1 ]
[2 4 1 3 ] [3 1 4 2 ]

*/

#include<iostream>
#include<vector>
using namespace std;


void printSolution(vector< vector<int> >& board, int N)
{
	//for (int r = 0; r < N; ++r)
	//{
	//	for (int c = 0; c < N; ++c)
	//	{
	//		cout << board[r][c] << " ";
	//	}
	//	cout << endl;
	//}
	//cout<<endl;

	cout << "[";
	for (int c = 0; c < N; ++c)
	{
		for (int r = 0; r < N; ++r)
		{
			if (board[r][c])
			{
				cout << (r+1) << " ";
			}
		}
	}
	cout << "]";

}

bool isSafePlace(vector< vector<int> >& board, int N, int col, int row)
{
	//since the right side of the board is blink, only the left side need check.
	for (int i = 0; i < col; ++i) // check the same row.
	{
		if (board[row][i])
		{
			return false;
		}
	}

	//Check upper diagonal on left side
	for (int i = row,  j = col; i >= 0 && j >= 0; --j, --i)
	{
		if (board[i][j])
		{
			return false;
		}
	}

	//Check lower diagonal on left side
	for (int i = row,  j = col; i < N && j >= 0; ++i, --j)
	{
		if (board[i][j])
		{
			return false;
		}
	}
	return true;
}


bool SloveNQ(vector< vector<int> >& board, int N, int currentCol)
{
    bool bPlaced = false;

    if(currentCol == N) // we have reach one solution.
    {
        printSolution(board,N);
        return true;      
    }


    for(int r = 0; r<N; ++r)
    {
        if(isSafePlace(board,N,currentCol,r))
        {
            board[r][currentCol] = 1;
            if(SloveNQ(board,N,currentCol+1)) // recursive the next column
            {
                bPlaced = true;
                break;
            }
            else  // backtrck to another choice
            {
                board[r][currentCol] = 0;                
            }
        }
    }
    return bPlaced;
}

int testSolveNQ(int N)
{
    vector< vector<int> > board(N, vector<int>(N,0));
        
    SloveNQ(board, N, 0);

    return 0;
}

int main(int argc, char const *argv[])
{
    
    testSolveNQ(4);

    return 0;
}

