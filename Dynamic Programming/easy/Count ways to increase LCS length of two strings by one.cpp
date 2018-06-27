/*
Count ways to increase LCS length of two strings by one 
https://practice.geeksforgeeks.org/problems/count-ways-to-increase-lcs-length-of-two-strings-by-one/0

Given two strings of lower alphabet characters, we need to find the number of ways to insert a character 
in the first string such that length of LCS of both strings increases by one.

 

Input:

The first line of the contains T denoting the number of testcases. Then T testcases follow. 
The first line of each test case contains integers N and M denoting the length of strings str1 and str2.
The second line of each test case contains the strings str1 and str2 consisiting of only lower case alphabets.


Output:

Print the answer for each test case in a new line.


Constraints:

1<= T <=100

1<= N, M <=100


Example:

Input:

1
5 3
abab abc

Output:

3

*/

/*

            LCS[i-1,j-1]  if x[i] == y[j]
LCS[i,j] =  max(LCS[i-1,j],LCS[i,j-1]) if x[i] != y[j]
            0 if i == 0 or j = 0;

 x[i] == y[j] then  x[i] and y[j] must be a element in one longest common subsequence.

*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;


enum LCSChoice
{
	choice_invalid,
	choice_middle,
	choice_left,
	choice_upper
};

int CountLCSIncreaseingWay(const string& x, const string& y)
{
	int R = x.size();
	int C = y.size();
	int nway = 0;
	int lcs[101][101] = { 0 };
	int m[101][101] = { 0 };

	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			if (x[i - 1] == y[j - 1])
			{
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
				m[i][j] = choice_middle;
				if (i + 1 <= R && j + 1 <= C)
				{
					if (x[i] != y[j])
					{
						++nway;
					}
				}
				else if (i == R && j<C)
				{
					++nway;
				}
			}
			else
			{
				lcs[i][j] = lcs[i - 1][j];
				m[i][j] = choice_upper;
				if (lcs[i][j - 1]>lcs[i][j])
				{
					lcs[i][j] = lcs[i][j - 1];
					m[i][j] = choice_left;
				}
			}
		}
	}

	cout << nway << endl;

	return 0;
}



int main()
{
	int t = 0;
	string x, y;
	int M, N;
	cin >> t;

	while (t--)
	{
		cin >> M >> N;
		cin >> x;
		cin >> y;
		CountLCSIncreaseingWay(x, y);
		x.clear();
		y.clear();
	}

	return 0;
}