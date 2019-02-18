/*
https://leetcode-cn.com/problems/knight-probability-in-chessboard/
Knight Probability in Chessboard
On an NxN chessboard, a knight starts at the r-th row and c-th column and attempts to make exactly K moves.
The rows and columns are 0 indexed, so the top-left square is (0, 0), and the bottom-right square is (N-1, N-1).

A chess knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction,
then one square in an orthogonal direction.

Each time the knight is to move, it chooses one of eight possible
moves uniformly at random (even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly K moves or
has moved off the chessboard. Return the probability that the knight remains on the board after it has stopped moving.


Example:

Input: 3, 2, 0, 0
Output: 0.0625
Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625. 1/16


Note:

N will be between 1 and 25.
K will be between 0 and 100.
The knight always initially starts on the board.

*/

/*

use use BFS like method: this will cause many many  duplicated vertice int the queue.

*/

#include<iostream>
#include<queue>
#include<stack>
using namespace std;


static int nr[8] = { -2, -2, -1, 1, 2, 2, 1, -1 };
static int nc[8] = { -1, 1, 2, 2, 1, -1, -2, -2 };



class Solution1
{
	struct stMovestep
	{
		int m_r;
		int m_c;
		stMovestep(int r, int c)
		{
			m_r = r;
			m_c = c;
		}
	};

public:
	double knightProbability(int N, int K, int r, int c)
	{
		queue<stMovestep> levelQ;
		int ncurQ = 0;
		int nNextQ = 0;

		levelQ.push(stMovestep(r, c));
		ncurQ = 1;

		int i = 0;

		while (i<K)
		{
			while (ncurQ)
			{
				stMovestep shead = levelQ.front();
				levelQ.pop();
				--ncurQ;

				int nextr = 0;
				int nextc = 0;

				for (int d = 0; d<8; ++d)
				{
					nextr = shead.m_r + nr[d];
					nextc = shead.m_c + nc[d];
					if (0 <= nextr && N>nextr && 0 <= nextc && N > nextc)
					{
						levelQ.push(stMovestep(nextr,nextc));
						++nNextQ;
					}
				}
			}
			ncurQ  = nNextQ;
			nNextQ = 0;
			++i;
		}

		
		double probability = ((double)(levelQ.size())) / pow(8,K);
		
		return probability;
	}
};


class Solution
{
public:
	double knightProbability(int N, int K, int r, int c)
	{
		vector< vector< vector<unsigned long long> > > KP(K + 1, vector< vector< unsigned long long> >(N, vector<unsigned long long>(N, 0)));
		vector< int >	vc(K+1,0);
		vector<double>	vd(K+1,0);

		KP[0][r][c] = 1;
		for (int k = 1; k <= K; ++k)
		{
			for (int i = 0; i < N; ++i)
			{
				for (int j = 0; j < N; ++j)
				{
					int count = 0;
					for (int d = 0; d < 8; ++d)
					{
						if (KP[k - 1][i][j])
						{
							int nextr = i + nr[d];
							int nextc = j + nc[d];
							if (0 <= nextr && nextr < N && 0 <= nextc && nextc < N)
							{
								KP[k][nextr][nextc] += KP[k - 1][i][j];
								++count;
							}
						}
					}
					vc[k-1] = 1;
				}
			}
		}
		

		unsigned long long nkeep = 0;
		for (int r = 0; r < N; ++r)
		{
			for (int c = 0; c < N; ++c)
			{
				nkeep += KP[K][r][c];
			}
		}

		double probability = (double)(nkeep) / pow(8, K);

		return probability;
	}
};

int main()
{
	int N = 3;
	int K = 2;
	int r = 0;
	int c = 0;
	
	Solution sol;


	N = 8;
	K = 30;
	r = 6;
	c = 4;

	cout << sol.knightProbability(N,K,r,c)<<endl;
	
	return 0;
}