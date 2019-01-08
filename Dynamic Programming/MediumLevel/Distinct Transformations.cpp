/*
Distinct Transformations
https://practice.geeksforgeeks.org/problems/distinct-transformations/0/?ref=self
Given two sequences A, B, find out number of unique ways in sequence A, to form a subsequence
that is identical to the sequence B.

Example :
A = "abcccdf"  B = "abccdf"

Return 3. And the formations as follows:

A1= "ab.ccdf"
A2= "abc.cdf"
A3="abcc.df"

"." is where character is removed.


Input:
First line contains the test cases T.  1<=T<=500
Each test case have two lines
First is a string A of length less than 1000.
Second is a string B of length less than 100.

Exapmle:
Input:
2
abcccdf
abccdf
uwnny
uwnny

Output:
3
1

*/

/*

			mc[i,j-1]+1 if x[i] == y[j]
mc[i,j] =
			mc[i,j-1]  if x[i] != y[j]

*/

#include "pch.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;


int DistinctTransformation(string& x, string& y)
{
	vector< vector<int> > vlcs(x.length() + 1, vector<int>(y.length() + 1, 0));
	vector< vector<int> > vmc(x.length() + 1, vector<int>(y.length() + 1, 0));
	//lets initialize the matrix
	for (int c = 0; c <= y.length(); ++c)
	{
		vmc[0][c] = 1; //there is only one way to do transform: delete the whole Y string.
	}

	for (int i = 1; i <= x.length(); ++i)
	{
		for (int j = 1; j <= y.length(); ++j)
		{
			if (x[i - 1] == y[j - 1])
			{
				vlcs[i][j] = vlcs[i - 1][j - 1] + 1;
			}
			else
			{
				vlcs[i][j] = vlcs[i][j - 1]; // this make x[1,i] is a substring not the subSequence.
			}

			if (vlcs[i][j] == i)
			{
				if (vlcs[i][j - 1] == i)
				{
					vmc[i][j] = vmc[i][j - 1] + 1; // how many choices which make x[1...i] and y[1...j] lcs is i length.
				}
				else
				{
					vmc[i][j] = vmc[i - 1][j-1];
				}
			}
			else
			{
				vmc[i][j] = vmc[i][j - 1];
			}
		}
	}

	cout << vmc[x.length()][y.length()] << endl;

	return 0;
}


int main()
{
	int ret = 0;

	string x = "abccdf";
	string y = "abcccdf";

	DistinctTransformation(x, y);

	return ret;
}