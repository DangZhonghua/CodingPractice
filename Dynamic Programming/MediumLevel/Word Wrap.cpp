/*
Word Wrap
https://practice.geeksforgeeks.org/problems/word-wrap/0
https://www.geeksforgeeks.org/word-wrap-problem-space-optimized-solution/

Given an array of size N, which denotes the number of characters in one word.
The task is simple, count the number of words in a single line with space character between two words.

Input:
First line contains the number of test cases T. First line of every test case consists of N,
denoting number of elements in array. Second line consists of elements in array.
Third line consists of characters allowed per line.

Output:
Single line output,print 2*N spaced integers, denoting from which word to word in every line.
(for more clearance of output, look the output in example).

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
4
3 2 2 5
6
3
3 2 2
4
Output:
1 1 2 3 4 4
1 1 2 2 3 3

For the first test case.
Line number 1: From word no. 1 to 1
Line number 2: From word no. 2 to 3
Line number 3: From word no. 4 to 4

*/

/*

Dynamic programming: optimal sub-structure and overlapped sub-problems

Line[N] =  Line[N-1] + 1;


*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int CalcSquare(int a)
{
	return a*a;
}
struct  PW
{
	int pos;
	int weight;
	PW()
	{
		pos		= 0;
		weight	= 0;
	}
};

int WordWrap(int*a, int N, int lineWide)
{
	vector<  vector<PW> > WL(N + 1, vector<PW>(N + 1, PW()));

	WL[1][1].weight = (N == 1 ? 0 : CalcSquare(lineWide - a[1]));
	WL[1][1].pos = 1;

	for (int w = 2; w <= N; ++w)
	{
		for (int l = 1; l <= w; ++l)
		{
            // In the same line with w-1 case.
			if (WL[w - 1][l].pos && WL[w - 1][l].pos + a[w - 1] + a[w] <= lineWide)
			{
				WL[w][l].pos	= WL[w - 1][l].pos + a[w - 1] + 1/*for space*/;
				int pweight		= CalcSquare(lineWide - (WL[w - 1][l].pos + a[w - 1]) + 1);
				int curWeight	= CalcSquare(lineWide - (WL[w][l].pos + a[w]) + 1);
				WL[w][l].weight = WL[w - 1][l].weight - pweight + curWeight;
			}
		}
        //New line case.
	}

	return 0;
}


int main()
{
	int t = 0;
	int N = 0;
	int a[101];
	int LW = 0;

	cin >> t;

	while (t--)
	{
		cin >> N;
		int i = 1;
		while (i <= N)
		{
			cin >> a[i++];
		}
		cin >> LW;
		WordWrap(a, N, LW);
	}



	return 0;
}