/*
Longest K unique characters substring
https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring/0

Given a string you need to print the size of the longest possible substring that has exactly k unique characters.
If there is no possible substring print -1.
Example
For the string aabacbebebe and k = 3 the substring will be cbebebe with length 7.


Input:
The first line of input contains an integer T denoting the no of test cases then T test cases follow. Each test case contains two lines . The first line of each test case contains a string s and the next line conatains an integer k.

Output:
For each test case in a new line print the required output.

Constraints:
1<=T<=100
1<=k<=10

Example:
Input:
2
aabacbebebe
3
aaaa
1
Output:
7
4


*/

#include<iostream>
#include<string>

using namespace std;

int LongestKUniqueSubstring(const string& strtxt, int K)
{
	int N = strtxt.size();
	int c[256] = { 0 };

	int i = 0;
	int j = 0;
	int maxlen = 0;
	int nunique = 0;
	int s = 0;
	int e = 0;

	c[strtxt[0]] = 1;
	nunique = 1;
	maxlen = 0;

	if (K == 1)
	{
		maxlen = 1;
	}

	j = 1;

	while (j<N && i<j)
	{
		if (c[strtxt[j]] == 0)
		{
			++nunique;
			c[strtxt[j]] = 1;
			if (nunique == K)
			{
				if (maxlen<j - i)
				{
					maxlen = j - i+1;
					s = i;
					e = j;
				}
			}

			if (nunique > K)
			{
				while (nunique > K && i<j)
				{
					c[strtxt[i]] -= 1;
					if (c[strtxt[i]] == 0)
					{
						--nunique;
					}
					++i;
				}
			}
		}
		else
		{
			c[strtxt[j]] += 1;
			if (nunique == K)
			{
				if (maxlen<j - i + 1)
				{
					maxlen = j - i + 1;
					s = i;
					e = j;
				}
			}
		}
		++j;
	}

	if (maxlen == 0)
	{
		cout << -1 << endl;
	}
	else
	{
		//string longest = strtxt.substr(s, e);
		//cout << longest << endl;
		cout << maxlen << endl;
	}

	return 0;
}


int main()
{
	int t = 0;
	string strtxt;
	int K = 0;

	cin >> t;

	while (t--)
	{
		cin >> strtxt;
		cin >> K;
		LongestKUniqueSubstring(strtxt, K);
	}
	

	return 0;
}