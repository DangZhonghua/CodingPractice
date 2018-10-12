/*
Rat in a Maze Problem
https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1/?ref=self
https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/


Consider a rat placed at (0, 0) in a square matrix m[][] of order n and has to reach the destination
at (n-1, n-1). Your task is to complete the function which returns a
sorted array of strings denoting all the possible directions
which the rat can take to reach the destination at (n-1, n-1).
The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right).

For example
1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1

For the above matrix the rat can reach the destination at (3, 3) from (0, 0)
by two paths ie DRDDRR and DDRDRR when printed in sorted order we get DDRDRR DRDDRR.

Input:
The first line of input contains an integer T denoting the no of test cases.
Then T test cases follow. Each test case contains two lines.
The first line contains an integer n denoting the size of the square matrix.
The next line contains n*n space separated values of the matrix m
where 0's represents blocked paths and 1 represent valid paths.

Output:
For each test case output will be space separated sorted strings denoting all directions,
which the rat could take to reach the destination.

Constraints:
1<=T<=10
2<=n<=10
0<=m[][]<=1

Example(To be used only for expected output):
Input:
2
4
1 0 0 0 1 1 0 1 0 1 0 0 0 1 1 1
4
1 0 0 0 1 1 0 1 1 1 0 0 0 1 1 1

Output:
DRDDRR
DDRDRR DRDDRR

*/

#include<iostream>
#include<vector>
using namespace std;

static char tag[4] = { 'D', 'L', 'R', 'U' };

static int RD[4] = { 1, 0, 0, -1 };
static int CD[4] = { 0, -1, 1, 0 };

int SloveRatMaze(vector< vector<int> >& maze, vector<string>& vpath, int N);

int main()
{
	int t = 0;
	cin >> t;
	while (t--)
	{
		int N;
		cin >> N;
		vector< vector<int> > maze(N, vector<int>(N, 0));
		int r = 0;
		int c = 0;
		while (r < N)
		{
			c = 0;
			while (c < N)
			{
				cin >> maze[r][c];
				++c;
			}
			++r;
		}
        vector<string> vpath;
		SloveRatMaze(maze,vpath, N);
	}
}

void outputPath(vector<char>& path, vector<string>& vpath)
{
    string strPath;
	for (auto c : path)
	{
		//cout << c;
        strPath.push_back(c);
	}
    vpath.push_back(strPath);
	//cout << " ";
}


bool canPass(vector< vector<int> >& maze, int r, int c, int N)
{
	if (0 <= r && r < N && 0 <= c && c < N && maze[r][c])
	{
		return true;
	}
	return false;
}

// according to the DLRU to traverse the maze.
bool RatReachMaze(vector< vector<int> >& maze, vector<char>& path, vector<string>& vPath, int N, int r, int c, char direction)
{
	if ((N - 1) == r && (N - 1) == c)
	{
		outputPath(path,vPath);
		return true;
	}

	bool bPass = false;
	for (int i = 0; i < 4; ++i)
	{
		if (('D' == direction && tag[i] == 'U') || ('U' == direction && 'D' == tag[i]))
		{
			continue;
		}

		if (('L' == direction && tag[i] == 'R') || ('R' == direction && 'L' == tag[i]))
		{
			continue;
		}

		int row = r + RD[i];
		int col = c + CD[i];

		if (canPass(maze, row, col, N))
		{
			path.push_back(tag[i]);
            maze[row][col] = 0;
			bPass = (RatReachMaze(maze, path, vPath,N, row, col, tag[i]) | bPass);
			path.pop_back();
            maze[row][col] = 1;
            
		}
	}

	return bPass;
}



int SloveRatMaze(vector< vector<int> >& maze, vector<string>& vpath, int N)
{
	vector<char> path;
	RatReachMaze(maze, path, vpath,N, 0, 0, 'D');
	//cout << endl;

	return 0;
}


vector<string> printPath(int m[MAX][MAX], int n)
{
    //Your code here	
    vector<string> vpath;
    vector< vector<int> > maze(n, vector<int>(n,0));
    for(int r = 0; r<n;++r)
    {
        for(int c = 0; c<n; ++c)
        {
            maze[r][c] = m[r][c];
        }
    }
    SloveRatMaze(maze,vpath,n);
    return vpath;
}