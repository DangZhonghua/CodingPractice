/*
Snake and Ladder Problem
https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem/0/?ref=self

Given a snake and ladder board of order 5x6 , find the minimum number of dice throws required to reach the destination
or last cell (30th cell) from source (1st cell) .

For the above board output will be 3
For 1st throw get a 2
For 2nd throw get a 6
For 3rd throw get a 2

Input:
The first line of input contains an integer T denoting the no of test cases.
Then T test cases follow. Each test case contains two lines.
The first line of input contains an integer N denoting the no of ladders and snakes present.
Then in the next line are 2*N space separated values a,b which denotes a ladder or a snake
at position 'a' which takes to a position 'b'.

Output:
For each test case in a new line print the required answer denoting the min no of dice throws.

Constraints:
1<=T<=100
1<=N<=10
1<=a<30
1<=b<=30

Example:
Input:
2
6
11 26 3 22 5 8 20 29 27 1 21 9
1
2 30
Output:
3
1
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int buildGame(unordered_map<int, int> &gapMap, vector<vector<int>> &Graph)
{
	int ret = 0;

	for (int r = 1; r <= 30; ++r)
	{
		for (int c = 1; c <= 6; ++c)
		{
			int d = r + c;
			if (d > 30)
			{
				d = 30;
			}
			if (gapMap.end() != gapMap.find(d))
			{
				Graph[r][gapMap[d]] = 1;
			}
			else
			{
				Graph[r][d] = 1;
			}
		}
	}

	return ret;
}

int SnakeAndLadder(unordered_map<int, int> &gapMap)
{
	int ret = 0;
	bool bReach = false;
	int  minThrow = 0;
	queue<int> curLevelQ;
	queue<int> nextLevelQ;
	queue<int> *pCurLevelQ = &curLevelQ;
	queue<int> *pNextLevelQ = &nextLevelQ;

	vector<vector<int>> Graph(31, vector<int>(31, 0));
	buildGame(gapMap, Graph);
	curLevelQ.push(1);

	while (!pCurLevelQ->empty() && !bReach)
	{
		while (!pCurLevelQ->empty() && !bReach)
		{
			int v = pCurLevelQ->front();
			pCurLevelQ->pop();
			for (int r = 1; r <= 30; ++r)
			{
				if (Graph[v][r])
				{
					if (30 == r)
					{
						bReach = true;
					}
					pNextLevelQ->push(r);
				}
			}
		}
		++minThrow;
		if (!bReach)
		{
			queue<int>* temp = pCurLevelQ;
			pCurLevelQ = pNextLevelQ;
			pNextLevelQ = temp;
		}
	}

	cout << minThrow << endl;

	return ret;
}

int main(int argc, char const *argv[])
{
	int t = 0;
	cin >> t;

	while (t--)
	{
		int N = 0;
		int i = 0;
		cin>>N;
		unordered_map<int, int> gapMap;
		while (i < N)
		{
			int s = 0;
			int e = 0;
			cin >> s >> e;
			++i;
			gapMap[s] = e;
		}
		SnakeAndLadder(gapMap);
	}

	return 0;
}
