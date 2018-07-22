/*
Form a palindrome
https://practice.geeksforgeeks.org/problems/form-a-palindrome/0
https://www.geeksforgeeks.org/dynamic-programming-set-28-minimum-insertions-to-form-a-palindrome/

Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
For Example:
ab: Number of insertions required is 1. bab or aba
aa: Number of insertions required is 0. aa
abcd: Number of insertions required is 3. dcbabcd

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is S.

Output:

Print the minimum number of characters.

Constraints:

1 ≤ T ≤ 50
1 ≤ S ≤ 40

Example:

Input:
3
abcd
aba
geeks

Output:
3
0
3

*/

/*

Overlapped-subproblem and optimal substructure.
This is palindrome string, so two endpoint is involved.

C[i+1,j-1] if s[i] == s[j]  since this is minimum insertion, so the equal, it must not need insert
C[i,j] =  min{ C[i+1,j] + 1 ; C[i,j-1] + 1}  if s[i] != s[j], since at most need one insert for s[i] or s[j]

*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int minimumInsertion(const string& strtext)
{
	int N = strtext.size();
	vector< vector<int> > C(N + 1, vector<int>(N + 1, N + 1));

	for (int i = 0; i < N; ++i)
	{
		C[i][i] = 0;
	}

	for (int l = 2; l <= N; ++l)
	{
		for (int i = 0; i <= N - l; ++i)
		{
			int j = i + l - 1;
			if (strtext[i] == strtext[j])
			{
				if (i + 1 <= j - 1)
				{
					C[i][j] = C[i + 1][j - 1];
				}
				else
				{
					C[i][j] = 0;
				}
			}
			else
			{
				C[i][j] = C[i][j - 1] + 1;
				if (C[i][j] > C[i + 1][j] + 1)
				{
					C[i][j] = C[i + 1][j] + 1;
				}
			}
		}
	}

	cout << C[0][N - 1] << endl;

	// for (int i = 0; i < N; ++i)
	// {
	// 	for (int j = 0; j < N; ++j)
	// 	{
	// 		cout << C[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;



	return 0;
}


int main()
{
	int t = 0;
	string strtext;

	cin >> t;

	while (t--)
	{
		cin >> strtext;
		minimumInsertion(strtext);
	}

	return 0;
}