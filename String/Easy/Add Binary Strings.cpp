/*
https://practice.geeksforgeeks.org/problems/add-binary-strings/0/?ref=self
Add Binary Strings
Print the resultant string after adding given two binary strings

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case contains two binary strings s1 and s2 separated by space.

Output:
For each test case print the resultant binary string.

Constraints:

1<=T<=70

1<=|s1|,|s2|<=200, where |s| represents the length of string s

Example:

Input:

2
1101 111
10 01

Output:

10100
11

*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

int addBinaryString(const string& x, const string& y)
{
	stack<char> sr;
	int  char2Int[2] = { 0, 1 };
	char Int2char[2] = { '0', '1' };

	int c = 0;

	int i = x.length() - 1;
	int j = y.length() - 1;

	while (i >= 0 && j >= 0)
	{
		int s = c + char2Int[x[i] - '0'] + char2Int[y[j] - '0'];
		c = 0;
		if (s > 1)
		{
			c = s / 2;
		}
		sr.push(Int2char[s % 2]);
		--i;
		--j;
	}

	while (i >= 0)
	{
		int s = c + char2Int[x[i] - '0'];
		c = 0;
		if (s > 1)
		{
			c = s / 2;
		}
		sr.push(Int2char[s % 2]);
		--i;
	}
	while (j >= 0)
	{
		int s = c + char2Int[y[j] - '0'];
		c= 0;
		if (s > 1)
		{
			c = s / 2;
		}
		sr.push(Int2char[s % 2]);
		--j;
	}
	if (c)
	{
		sr.push(Int2char[c]);
	}
	
	string strsum;

	while (!sr.empty())
	{
		strsum += sr.top();
		sr.pop();
	}

	cout << strsum << endl;

	return 0;
}


int main()
{
	int t = 0;
	string x, y;

	cin >> t;
	while (t--)
	{
		cin >> x >> y;
		addBinaryString(x, y);
	}
	return 0;
}