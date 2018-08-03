/*
Tic-Tac-Toe
https://practice.geeksforgeeks.org/problems/tic-tac-toe/0/?ref=self

A Tic-Tac-Toe board is given after some moves are played. Find out if the given board is valid, 
i.e., is it possible to reach this board position after some moves or not.

Note that every arbitrary filled grid of 9 spaces isn’t valid e.g. a grid filled with 3 X and 6 O 
isn’t valid situation because each player needs to take alternate turns.

Note :  The game starts with X

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is given as a 1D array of size 9.

Output:

Print Valid if board is valid, else Invalid.

Constraints:

1 ≤ T ≤ 100

Example:

Input:
2
X X O O X O O O O 
X X O O O X X O X

Output:
Invalid
Valid
*/

/*

The criterion of valid should be defined:

if X win: X count should larger than O's. X Count - O Count = 1
if O win: O count should equal with X's.
if no win: X count - O count = 1;

so X and O count should be calcuate and win side should be calculate

*/

#include<iostream>
#include<vector>
using namespace std;

int TicTacToe(char game[3][3])
{
    int xcount = 0;
    int ocount = 0;
    int xwin = 0;
    int owin = 0;

    vector<int> vflag(8,0);

    //row
    for(int r = 0; r<3; ++r)
    {
        int rx = 0;
        int ro = 0;
        for(int c = 0; c<3; ++c)
        {
            if('O' == game[r][c])
            {
                ++ocount;
                ++ro;
            }
            else
            {
                ++xcount;
                ++rx;
            }
        }
        if(3 == rx)
        {
         vflag[r] = 'X';
         ++xwin;
        }
        else if(3 == ro)
        {
            vflag[r] = 'O';
            ++owin;
        }
    }

    ///////////////////////////////////////////
    //col
    for(int c = 0; c<3; ++c)
    {
        int cx = 0;
        int co = 0;
        for(int r = 0; r<3; ++r)
        {
            if('O' == game[r][c]){
                ++co;
            }
            else{
                ++cx;
            }
        }
        if(3 == cx){
            vflag[3+c] = 'X';
            ++xwin;
        }
        else if(3 == co){
            vflag[3+c] = 'O';
            ++owin;
        }
    }

    //digonal

    if(game[0][0] == game[1][1] && game[1][1] == game[2][2])
    {
        vflag[6] = game[0][0];
        if('X' == game[0][0])
        {
            ++xwin;
        }
        else
        {
            ++owin;
        }
    }
    
    if(game[0][2] == game[1][1] && game[1][1] == game[2][0])
    {
        vflag[7] = game[0][2];
        if('X' == game[0][2])
        {
            ++xwin;
        }
        else
        {
            ++owin;
        }
    }
    
    bool bValid = false;
    if( 0 == xwin && 0 == owin)
    {
        if( xcount == ocount+1 )
        {
            bValid = true;
        }
    }
    else if(xwin && 0 == owin)
    {
        if( xcount == ocount+1 )
        {
            bValid = true;
        }
    }
    else if(0 == xwin && owin)
    {
        if(xcount == ocount)
        {
            bValid = true;
        }
    }

    if(bValid)
    {
        cout<<"Valid"<<endl;
    }
    else
    {
        cout<<"Invalid"<<endl;
    }


    return 0;
}


int main()
{
    int t = 0;
    char game[3][3];
    
    cin>>t;

    while(t--)
    {
        int i = 0;
        int j = 0;
        while(i<3)
        {
            j = 0;
            while(j<3)
            {
                cin>>game[i][j++];
            }
            ++i;
        }
        TicTacToe(game);
    }

    return 0;
}



