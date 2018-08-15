/*
https://practice.geeksforgeeks.org/problems/lcs-of-three-strings/0/?ref=self
LCS of three strings

Given 3 strings X, Y and Z, the task is to find the longest common sub-sequence in all three given sequences.



Input:

The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. The first line of each test case contains integers n, m and k
denoting the length of strings X, Y and Z respectively.

The second line of each test case contains the three strings X, Y and Z.
The string consists of only lower case english alphabets.

Output:

Print the length of the longest common sub- sequence of the three strings for each test case in a new line.


Constraints:

1<= T <=100

1<= N, M, K <=100


Example:

Input:

1

5 8 13

geeks geeksfor geeksforgeeks

Output:

5

*/

/*
LCS[i-1][j-1][k-1] + 1  if x[i] == y[j] == z[k]

LCS[i][j][k] =
max{ lcs[i-1][j][k], lcs[i][j-1][k], lcs[i][j][k-1]}  if x[i] != y[j] || y[j] != z[k] || x[i] != z[k]

0 if i ==0 || j == 0 || k == 0

*/

#include<iostream>
#include<vector>
#include<string>
//#include<bits/stdc++.h>
using namespace std;


int lcsofThree(const string&x, const string& y, const string& z)
{
	int X = x.length();
	int Y = y.length();
	int Z = z.length();

	vector < vector< vector<int> > > lcs(X + 1, vector< vector<int> >(Y + 1, vector<int>(Z + 1, 0)));

	for (int i = 1; i <= X; ++i)
	{
		for (int j = 1; j <= Y; ++j)
		{
			for (int k = 1; k <= Z; ++k)
			{
				if (x[i - 1] == y[j - 1] && y[j - 1] == z[k - 1])
				{
					lcs[i][j][k] = lcs[i - 1][j - 1][k - 1] + 1;
				}
				else
				{
					lcs[i][j][k] = lcs[i - 1][j][k];
					if (lcs[i][j][k] < lcs[i][j - 1][k])
					{
						lcs[i][j][k] = lcs[i][j - 1][k];
					}
					if (lcs[i][j][k] < lcs[i][j][k - 1])
					{
						lcs[i][j][k] = lcs[i][j][k - 1];
					}
				}
			}
		}
	}

	cout << lcs[X][Y][Z] << endl;

	return  0;

}


int main()
{
	int t = 0;
	int X, Y, Z;

	cin >> t;

	while (t--)
	{
		cin >> X >> Y >> Z;
		string x, y, z;
		cin >> x >> y >> z;

		lcsofThree(x, y, z);
	}

	return 0;
}

