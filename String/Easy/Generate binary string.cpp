/*
Generate binary string
https://practice.geeksforgeeks.org/problems/generate-binary-string/0/?ref=self
Given a string containing of ‘0’, ‘1’ and ‘?’ wildcard characters, generate all binary strings that can be formed by replacing each wildcard character by ‘0’ or ‘1’.
 

Input:

The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consist of two lines. The first line of each test case consists of a string S.
 

Output:

Print all binary string that can be formed by replacing each wildcard character.
 

Constraints:

1 ≤ T ≤ 60
1 ≤  length  of string S ≤ 30

Example:

Input
1
1??0?101

Output
10000101 10001101 10100101 10101101 11000101 11001101 11100101 11101101


*/

#include<iostream>
#include<string>
using namespace std;

int genstr(string prefix, const string& x, int p)
{

	int i = 0;
	for ( i = p; i< x.length(); ++i)
	{
		if ('?' != x[i])
		{
			prefix += x[i];
		}
		else
		{
			prefix += '0';
			if (prefix.length() == x.length())
			{
				cout<<prefix<<" ";
			}
			else
			{
				genstr(prefix, x, i + 1);
			}

			prefix[prefix.length() - 1] = '1';
			if (prefix.length() == x.length())
			{
				cout << prefix<<" ";
			}
			else
			{
				genstr(prefix, x, i + 1);
			}

			break;
		}
	}
	if (i == x.length())
	{
		cout<<prefix<<" ";
	}
	return 0;
}


int GenerateString(const string& x)
{
	string strx = "";
	genstr(strx, x, 0);
	cout << endl;
	return 0;
}

int main()
{
	int t = 0;
	string x = "";

	cin >> t;

	while (t--)
	{
		cin >> x;
		GenerateString(x);
	}

	return 0;
}