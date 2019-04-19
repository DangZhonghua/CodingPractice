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


1
77
9 10 3 7 7 5 10 6 1 5 9 8 2 8 3 8 3 3 7 2 1 7 2 6 10 5 10 1 10 2 8 8 2 2 6 10 8 8 7 8 4 7 6 7 4 10 5 9 2 3 10 4 10 1 9 9 6 1 10 7 4 9 6 7 2 2 6 10 9 5 9 2 1 4 1 5 5
14

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
		cost = (pw - nLine)*(pw - nLine)*(pw-nLine);
	}

	return cost;
}


//Total N words, so the max lines needed is N.
//suffix method DAG sub-problems.
int WordWrap(int*a, int N, int lineWide)
{
	vector<long long > WW(N + 1, LLONG_MAX);
	vector<int> parent(N + 1, -1);
	vector< pair<int, int> > lines;

	WW[N] = 0;

	for (int i = 0; i<N; ++i)
	{
		parent[i] = i;
	}

	for (int i = N - 1; i >= 0; --i)
	{
		// WW[i] = min{ WW[j] + cost(i,j)} // from i to j-1 this is one line
		for (int j = i + 1; j <= N; ++j) // from j, a new line is started.
		{
			int lineCost = CalcCost(a, i, j - 1, lineWide);

			if (INT_MAX != lineCost && WW[i] >= (WW[j] + lineCost) )
			{
				WW[i] = WW[j] + lineCost;
				parent[i] = j-1;
			}
		}
	}

	//cout << WW[0] << endl;

	int k = 0;
	while (k < N)
	{
		pair<int, int>  a;
		a.first = k+1;
		a.second = parent[k] + 1;
		lines.push_back(a);
		k = a.second;
	}

	for (int i = 0; i < lines.size(); ++i)
	{
		cout << lines[i].first << " " << lines[i].second << " ";
	}
	cout << endl;



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


/*

The following is the accepted solution but it should not correct


#include <limits.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#define INF INT_MAX

// A utility function to print the solution
int printSolution (int p[], int n);

// l[] represents lengths of different words in input sequence. For example,
// l[] = {3, 2, 2, 5} is for a sentence like "aaa bb cc ddddd".  n is size of
// l[] and M is line width (maximum no. of characters that can fit in a line)
void solveWordWrap (int l[], int n, int M)
{
// For simplicity, 1 extra space is used in all below arrays

// extras[i][j] will have number of extra spaces if words from i
// to j are put in a single line
int extras[n+1][n+1];

// lc[i][j] will have cost of a line which has words from
// i to j
int lc[n+1][n+1];

// c[i] will have total cost of optimal arrangement of words
// from 1 to i
int c[n+1];

// p[] is used to print the solution.
int p[n+1];

int i, j;

// calculate extra spaces in a single line.  The value extra[i][j]
// indicates extra spaces if words from word number i to j are
// placed in a single line
for (i = 1; i <= n; i++)
{
extras[i][i] = M - l[i-1];
for (j = i+1; j <= n; j++)
extras[i][j] = extras[i][j-1] - l[j-1] - 1;
}

// Calculate line cost corresponding to the above calculated extra
// spaces. The value lc[i][j] indicates cost of putting words from
// word number i to j in a single line
for (i = 1; i <= n; i++)
{
for (j = i; j <= n; j++)
{
if (extras[i][j] < 0)
lc[i][j] = INF;
else if (j == n && extras[i][j] >= 0)
lc[i][j] = 0;
else
lc[i][j] = extras[i][j]*extras[i][j];
}
}

// Calculate minimum cost and find minimum cost arrangement.
//  The value c[j] indicates optimized cost to arrange words
// from word number 1 to j.
c[0] = 0;
for (j = 1; j <= n; j++)
{
c[j] = INF;
for (i = 1; i <= j; i++)
{
if (c[i-1] != INF && lc[i][j] != INF && (c[i-1] + lc[i][j] < c[j]))
{
c[j] = c[i-1] + lc[i][j];
p[j] = i;
}
}
}

printSolution(p, n);
cout<<endl;
}

int printSolution (int p[], int n)
{
int k;
if (p[n] == 1)
k = 1;
else
k = printSolution (p, p[n]-1) + 1;
printf ("%d %d ",p[n], n);
return k;
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
solveWordWrap(a, N, LW);
}

return 0;
}

*/