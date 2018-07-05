/*
Find number of times a string occurs as a subsequence
https://practice.geeksforgeeks.org/problems/find-number-of-times-a-string-occurs-as-a-subsequence/0
https://www.geeksforgeeks.org/find-number-times-string-occurs-given-string/

Given two strings S1 and S2, find the number of times the second string occurs in the first string,
whether continuous or discontinuous.

Input:

The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. The first line of each test case contains
integers N and M denoting the length of the strings S1 and S2 respectively.

The second line of each test case contains the strings S1 and S2.

Output:

Print the number of times S2 appears in S1, whether continuous or discontinuous.
Print the answer for each test case in a new line.


Constraints:
1<= T <=100
1<= N, M <=1000
Example:


Input:
1
13 3
geeksforgeeks gks

Output:
4

*/




/*

m: Length of str1 (first string)
n: Length of str2 (second string)

If last characters of two strings are same,
1. We consider last characters and get count for remaining
strings. So we recur for lengths m-1 and n-1.
2. We can ignore last character of first string and
recurse for lengths m-1 and n.
else
If last characters are not same,
We ignore last character of first string and
recurse for lengths m-1 and n.


            C[i-1][j-1] + C[i-1][j] if x[i] == y[j]  use x[i] or not.
C[i][j] =
            C[i-1][j]  if  x[i] != y[j]

C[0][j] = 0
C[0][0] = 1
C[i][0] = 1


*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int CountStringAsSubsequence(const string& strtext, const string& strsrc)
{
	int R = strtext.length();
	int C = strsrc.length();
	vector< vector<int> > lcs(R + 1, vector<int>(C + 1, 0));

	//The First string is empty
	for (int i = 0; i <= C; ++i)
	{
		lcs[0][i] = 0;
	}


	//The second string is empty    
	for (int i = 0; i <= R; ++i)
	{
		lcs[i][0] = 1;
	}

	for (int r = 1; r <= R; ++r)
	{
		for (int c = 1; c <= C; ++c)
		{
			if (strtext[r - 1] == strsrc[c - 1])
			{
				lcs[r][c] = lcs[r - 1][c - 1] + lcs[r - 1][c];
			}
			else
			{
				lcs[r][c] = lcs[r - 1][c];
			}
		}
	}
	cout << lcs[R][C] << endl;



	return 0;
}


int main()
{
	int t = 0;
	int N = 0;
	int M = 0;
	string strtext;
	string strsrc;

	cin >> t;

	while (t--)
	{
		cin >> N >> M;
		cin >> strtext;
		cin >> strsrc;
		CountStringAsSubsequence(strtext, strsrc);
	}
	return 0;
}

