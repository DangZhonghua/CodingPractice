//https://practice.geeksforgeeks.org/problems/knight-walk/0

/*
Given a chess board of order NxM and source points (s1,s2) and destination points (d1,d2), Your task to find min number of moves required by the Knight to go to the destination cell.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line of each test case contains two space separated integers N and M. Then in the next line are four space separated values s1, s2 and d1, d2.

Output:
For each test case in a new line print the min no of moves required by the knight to go to the destination from the source. If no such move is possible print -1.

Constraints:
1<=T<=100
1<=N,M<=25

Example:
Input:
2
4 7
2 6 2 4
7 13
2 8 3 4
Output:
2
3
*/

/*

Just use BFS or DFS to solve this.

*/

#include<iostream>
#include<queue>
#include<climits>
using namespace std;


#define MAX 30

int KnightWalk(int N, int M, int s1, int s2, int d1, int d2)
{
	bool board[MAX][MAX];
	int  SPM[MAX][MAX];
	bool bfind = false;
	int  nCurLevel = 0;
	int  nNextLevel = 0;
	int  nLevel = 0;


	//int rNbr[8] = { -1, -1, -1, 0, 1, 1,  1, 0 };
	//int cNbr[8] = { -1, 0,   1, 1, 1, 0, -1,-1 };

    int rNbr[8] = {-1,-2,-2,-1,1,2,2,1};
    int cNbr[8] = {2,1,-1,-2,2,1,-1,-2};

	for (int r = 0; r <= N; ++r)
	{
		for (int c = 0; c <= M; ++c)
		{
			board[r][c] = false;
			SPM[r][c] = INT_MAX;
		}
	}

	struct BFSItem
	{
		int r;
		int c;
		BFSItem(int a = 0, int b = 0)
		{
			r = a;
			c = b;
		}
	};

	queue< BFSItem >  levelQ;
	levelQ.push(BFSItem(s1, s2));
	board[s1][s2] = true;
	nCurLevel = 1;

	while (!levelQ.empty() && !bfind)
	{
		while (nCurLevel > 0 && !bfind)
		{
			--nCurLevel;
			BFSItem head = levelQ.front();
			levelQ.pop();
            if(head.r == d1 && head.c == d2)
            {
				bfind = true;
				break;
                
			}

			for (int i = 0; i < 8; ++i)
			{
				int t1 = head.r + rNbr[i];
				int t2 = head.c + cNbr[i];
				if (t1 > 0 && t1 <= N && t2 > 0 && t2 <= M)
				{
					if (!board[t1][t2]) // Firs time found, this distance should be the shortest.
					{
						board[t1][t2] = true;
						levelQ.push(BFSItem(t1, t2));
						++nNextLevel;
					}
				}
			}

		}

        if(bfind)
        {
            break;
        }
        ++nLevel;
		nCurLevel = nNextLevel;
		nNextLevel = 0;

	}


	cout << nLevel << endl;

	return 0;
}

int main()
{
	int t = 0;
	int N, M;
	int s1, s2, d1, d2;

	cin >> t;
	while (t > 0)
	{
		--t;
		cin >> N >> M;
		cin >> s1 >> s2 >> d1 >> d2;

		KnightWalk(N, M, s1, s2, d1, d2);
	}
}