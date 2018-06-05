/*
Minimal moves to form a string
https://practice.geeksforgeeks.org/problems/minimal-moves-to-form-a-string/0


Given a string S, we need to write a program to check if it is possible to construct the given string S by performing any of the below operations any number of times. In each step, we can:

Add any character at the end of the string.
or, append the string to the string itself.
The above steps can be applied any number of times. We need to print the minimum steps required to form the string.

Input:
The first line contains an integer T, the number of test cases. For each test case, there is a string s which we need to form. 
Output:
For each test case, the output is an integer displaying the minimum number of steps required to form that string.

Constraints:
1<=T<=100
1<=s.length()<=10^5

Example:
Input
3
aaaaaaaa 
aaaaaa 
abcabca
Output
4
4
5

Explanation:
1.  move 1: add 'a' to form "a"
     move 2: add 'a' to form "aa"
     move 3: append "aa" to form "aaaa"
     move 4: append "aaaa" to form "aaaaaaaa"
2.  move 1: add 'a' to form "a"
     move 2: add 'a' to form "aa"
     move 3: add 'a' to form "aaa"
     move 4: append "aaa" to form "aaaaaa"
3.  move 1: add 'a' to form "a"
     move 2: add 'b' to form "ab"
     move 3: add 'c' to form "abc"
     move 4: append "abc" to form "abcabc"
     move 5: add 'a' to form "abcabca"


*/

/*

This is 0-1 knapsack extension.


*/

#include<string>
#include<vector>
#include<iostream>
using namespace std;

int CalcPS(const char* szText, int N, vector<vector<bool> >& vps)
{
	for (int i = 0; i<N; ++i)
	{
		vps[i][i] = true;
	}

	for (int l = 2; l <= N; ++l)
	{
		for (int i = 0; i <= N - l; ++i)
		{
			int j = i + l - 1;
			if (szText[i] == szText[j])
			{
				if (2 == l)
				{
					vps[i][j] = true;
				}
				else
				{
					vps[i][j] = vps[i + 1][j - 1];
				}
			}
		}
	}

	return 0;
}


int MinimalMovesForString(const char* szText, int N)
{
	//vector< vector<bool> > vps(N + 1, vector<bool>(N + 1, false));

	vector<int> mc(N + 1, 0);
	mc[0] = 1;

	//CalcPS(szText, N, vps);

	for (int i = 1; i<N; ++i)
	{
		mc[i] = mc[i - 1] + 1;

		if ((i % 2))
		{
			bool bsym = true;
			for (int k = 0; k <= i / 2; ++k)
			{
				if (szText[k] != szText[i / 2 + k+1])
				{
					bsym = false;
					break;
				}
			}
			if (bsym)
			{
				if (mc[i] > (mc[i / 2] + 1))
				{
					mc[i] = mc[i / 2] + 1;
				}
			}
		}
	}
	cout << mc[N - 1] << endl;

	return 0;
}


int main(int argc, char const *argv[])
{
	/* code */

	int t = 0;
	string strtxt;

	cin >> t;

	while (t--)
	{
		cin >> strtxt;
		MinimalMovesForString(strtxt.c_str(), strtxt.size());
	}

	return 0;
}
