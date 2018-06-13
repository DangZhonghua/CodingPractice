/*
Geek and its Game of Coins 
https://practice.geeksforgeeks.org/problems/geek-and-its-game-of-coins/0/?ref=self

Geek and his friend are playing a coin game. 
At the beginning there are N coins. 
Given two numbers X and Y. 
In each move a player can pick X, Y or 1 coins. 
Geek always starts the game. 
The player who picks the last coin wins the game. 
For a given value of N, find whether Geek will win the game or not if both are playing optimally.
For Example:

Input :  n = 5, x = 3, y = 4
Output : N
There are 5 coins, every player can pick 1 or 3 or 4 coins on his/her turn. Geek can win by picking 3 coins in first chance. 
Now 2 coins will be left so his frined will pick one coin and now Geek can win by picking the last coin.

Input:
First line of the input contains an integer T, denoting the number of test cases. Then T test case follows. The only line of the each test case contains three space separated integer denoting the values of N, X and Y, respectively.

Output:
For each test case output a single line containg either 'G' or 'N'. If Geek wins print 'G' else print 'N'.

Constraints:
1<=T<=100
1<=N<=105
0<=X,Y<=105

Example:
Input:
2
2 3 4
10 2 3
Output:
N
G

*/

/*

When the pick count is odd number, the Geek win this game.

Let us take few example values of n for x = 3, y = 4.
n = 0 A can not pick any coin so he losses
n = 1 A can pick 1 coin and win the game
n = 2 A can pick only 1 coin. Now B will pick 1 coin and win the game
n = 3 4 A will win the game by picking 3 or 4 coins
n = 5, 6 A will choose 3 or 4 coins. Now B will have to choose from 2 coins so A will win.

We can observe that A wins game for n coins only when it loses for coins n-1, n-x and n-y.
*/


#include<iostream>
#include<vector>
using namespace std;

int pickCoins_JudgeWin(int*a, int N)
{
	vector<bool>  dp(a[0]+1, false);
    dp[1] = true;

    for(int i = 2; i<=a[0]; ++i)
    {
        if(i>1 && !dp[i-1])
        {
            dp[i] = true;
        }
        else if(i>=a[1] && !dp[i-a[1]])
        {
            dp[i] = true;
        }
        else if(i>=a[2] && !dp[i-a[2]])
        {
            dp[i] = true;
        }
    }
    
    if(dp[a[0]])
    {
        cout<<"G"<<endl;
    }
    else
    {
        cout<<"N"<<endl;
    }

	return 0;
}

int main()
{
	int t = 0;
	int a[3];

	cin >> t;

	while (t--)
	{
		cin >> a[0];
		cin >> a[1];
		cin >> a[2];
		pickCoins_JudgeWin(a, 3);
	}

	return 0;
}