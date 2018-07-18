/*
Word Wrap
https://practice.geeksforgeeks.org/problems/word-wrap/0
https://www.geeksforgeeks.org/word-wrap-problem-space-optimized-solution/
https://www.geeksforgeeks.org/dynamic-programming-set-18-word-wrap/

https://en.wikipedia.org/wiki/Line_wrap_and_word_wrap

Given an array of size N, which denotes the number of characters in one word.
The task is simple, count the number of words in a single line with space character between two words.

Input:
First line contains the number of test cases T.
First line of every test case consists of N, denoting number of elements in array.
Second line consists of elements in array.
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

1
4
3 2 2 5
6

*/

/*

Dynamic programming: optimal sub-structure and overlapped sub-problems
W[i][j]: value of i words puts in j lines: But this thinking need to handle too many variables(various case)
the subproblem is NOT a DAG.


Another thinking about subproblems:which words start a new line for suffix string [i:n], i from 0
after first line is formed, how to form the left lines? this is optimal sub-structure.

WW[i] = min{ WW[j] + cost[i,j]: for j = i+1,.... N} this is the iteration.


*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;


// int CalcSquare(int a)
// {
// 	return a*a;
// }
// struct  PW
// {
// 	int pos;
// 	int weight;
// 	PW()
// 	{
// 		pos = 0;
// 		weight = INT_MAX;
// 	}
// };

// int WordWrap(int*a, int N, int lineWide)
// {
// 	vector<  vector<PW> > WL(N + 1, vector<PW>(N + 1, PW()));

// 	WL[1][1].weight = (N == 1 ? 0 : CalcSquare(lineWide - a[1]));
// 	WL[1][1].pos = 1;

// 	for (int w = 2; w <= N; ++w)
// 	{
// 		for (int l = 1; l < w; ++l)
// 		{
// 			// In the same line with w-1 case.
// 			if (WL[w - 1][l].pos && WL[w - 1][l].pos + a[w - 1] + a[w] <= lineWide)
// 			{
// 				WL[w][l].pos = WL[w - 1][l].pos + a[w - 1] + 1/*for space*/;
// 				WL[w][l].weight = WL[w-1][l] + CalcSquare(lineWide - (WL[w][l].pos + a[w]) + 1)-
//                                   CalcSquare(lineWide +1 -(WL[w-1][l].pos + a[w]-1));
// 			}
// 		}
// 		WL[w][w].pos = 1;
// 		WL[w][w].weight = WL[w - 1][w - 1].weight + CalcSquare(lineWide - a[w]);
// 		//New line case.
// 	}

// 	return 0;
// }


//line start from ith word and end with jth word
int CalcCost(int*a, int i, int j, int pw)
{
	int cost = INT_MAX;
	int nLine = 0;
	for (int k = i; k < j; ++k)
	{
		nLine += a[k];
		nLine += 1; //for space between words.
	}
	nLine += a[j];

	if (nLine <= pw)
	{
		cost = (pw - nLine)*(pw - nLine);
	}

	return cost;
}


//Total N words, so the max lines needed is N.
//suffix method DAG sub-problems.
int WordWrap(int*a, int N, int lineWide)
{
	vector<int> WW(N + 1, INT_MAX);
	WW[N] = 0;

	for (int i = N - 1; i >= 0; --i)
	{
		// WW[i] = min{ WW[j] + cost(i,j)} // from i to j-1 this is one line
		for (int j = i + 1; j <= N; ++j) // from j, a new line is started.
		{
			int lineCost = CalcCost(a, i, j - 1, lineWide);

			if (INT_MAX != lineCost && WW[i] > WW[j] + lineCost)
			{
				WW[i] = WW[j] + lineCost;
			}
		}
	}
	cout << WW[0] << endl;

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
		int i = 0;
		while (i < N)
		{
			cin >> a[i++];
		}
		cin >> LW;
		WordWrap(a, N, LW);
	}

	return 0;
}