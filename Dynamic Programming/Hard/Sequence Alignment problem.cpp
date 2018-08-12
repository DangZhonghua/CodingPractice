/*
https://www.geeksforgeeks.org/sequence-alignment-problem/
Sequence Alignment problem


Sequence Alignment problem
Given as an input two strings, X = x_{1} x_{2}... x_{m}, and Y = y_{1} y_{2}... y_{m},
output the alignment of the strings, character by character,
so that the net penalty is minimised. The penalty is calculated as:
1. A penalty of p_{gap} occurs if a gap is inserted between the string.
2. A penalty of p_{xy} occurs for mis-matching the characters of X and Y.

Examples:

Input : X = CG, Y = CA, p_gap = 3, p_xy = 7
Output : X = CG_, Y = C_A, Total penalty = 6

Input : X = AGGGCT, Y = AGGCA, p_gap = 3, p_xy = 2
Output : X = AGGGCT, Y = A_GGCA, Total penalty = 5

Input : X = CG, Y = CA, p_gap = 3, p_xy = 5
Output : X = CG, Y = CA, Total penalty = 5

*/

/*
This problem like edit distance problem.

		   SA[i-1][j-1]  x[i] == y[j]

SA[i][j] =  min{
                SA[i-1][j-1]+p_xy, 
                SA[i][j-1] + p_gap, // gap in y
                SA[i-1][j] + p_gap //gap in x
                }

*/

#include<iostream>
#include<string>
#include<vector>
#include<climits>
using namespace std;

int SequenceAlignment(const string& x, const string& y, int gap, int mismatch)
{
	int R = x.length();
	int C = y.length();
	vector< vector<int> > sa(R + 1, vector<int>(C + 1, INT_MAX));

	// if x is empty
	for (int i = 0; i <= C; ++i)
	{
		if (gap>mismatch)
		{
			sa[0][i] = i*mismatch;
		}
		else
		{
			sa[0][i] = i*gap;
		}
	}
	// if y is empty
	for (int i = 0; i <= R; ++i)
	{
		if (gap>mismatch)
		{
			sa[i][0] = i*mismatch;
		}
		else
		{
			sa[i][0] = i*gap;
		}
	}

	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			if (x[i - 1] == y[j - 1])
			{
				sa[i][j] = sa[i - 1][j - 1];
			}
			else
			{
				sa[i][j] = sa[i - 1][j - 1] + mismatch;

				if (sa[i][j]> sa[i][j-1] + gap)
				{
					sa[i][j] = sa[i][j - 1] + gap;
				}
				if (sa[i][j] > sa[i - 1][j] + gap)
				{
					sa[i][j] = sa[i - 1][j] + gap;
				}
			}
		}
	}

	cout << sa[R][C] << endl;

	return 0;
}

int main(int argc, char const *argv[])
{
	string x = "AGGGCT";
	string y = "AGGCA";
	int gap = 3;
	int mismatch = 2;
	SequenceAlignment(x, y, gap, mismatch);

	return 0;
}
