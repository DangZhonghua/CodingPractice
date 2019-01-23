/*
https://leetcode-cn.com/problems/shortest-palindrome/
Shortest Palindrome

Given a string s, you are allowed to convert it to a palindrome by adding characters in front of it.
Find and return the shortest palindrome you can find by performing this transformation.
Example 1:

Input: "aacecaaa"
Output: "aaacecaaa"

Example 2:
Input: "abcd"
Output: "dcbabcd"

*/

/*

use the DP to find the longest palindrome substring, this LPS must include the prefix of the origin string.
the to be added count Len(origin string) - Len(LPS)

*/

#include<string>
#include<vector>
#include<iostream>
using namespace std;



class Solution {
public:
	string shortestPalindrome(string s)
	{
		if (s.length() == 0)
		{
			return s;
		}
		int Len = s.size();
		vector< vector<int> > dp(Len + 1, vector<int>(Len + 1, 0));
		for (int i = 1; i <= Len; ++i)
		{
			dp[i][i] = 1;
		}
		int lps = 1;
		for (int L = 2; L <= Len; ++L)
		{
			for (int i = 1; i <= Len - L + 1; ++i)
			{
				int j = i + L - 1;
				if (s[i - 1] == s[j - 1])
				{
					if (2 == L)
					{
						dp[i][j] = 2;
					}
					else
					{
						if (dp[i + 1][j - 1])
						{
							dp[i][j] = dp[i + 1][j - 1] + 2;
						}
						else
						{
							dp[i][j] = 0;
						}
					}
				}
				else
				{
					dp[i][j] = 0;
				}
			}
			if (dp[1][L] == L)
			{
				lps = L;
			}
		}

		if (lps == Len)
		{
			return s;
		}

		string strp = s.substr(lps);
		int i = 0;
		int j = strp.length() - 1;
		while (i < j)
		{
			char c = strp[i];
			strp[i] = strp[j];
			strp[j] = c;
			++i;
			--j;
		}
		strp += s;

		return strp;
	}
};


char* shortestPalindrome(char* s)
{
	int Len = strlen(s);
	if (0 == Len)
	{
		return s;
	}
	int** dp = new int*[Len + 1];
	for (int i = 0; i <= Len; ++i)
	{
		dp[i] = new int[Len + 1];
	}

	for (int i = 1; i <= Len; ++i)
	{
		dp[i][i] = 1;
	}
	int lps = 1;
	for (int L = 2; L <= Len; ++L)
	{
		for (int i = 1; i <= Len - L + 1; ++i)
		{
			int j = i + L - 1;
			if (s[i - 1] == s[j - 1])
			{
				if (2 == L)
				{
					dp[i][j] = 2;
				}
				else
				{
					if (dp[i + 1][j - 1])
					{
						dp[i][j] = dp[i + 1][j - 1] + 2;
					}
					else
					{
						dp[i][j] = 0;
					}
				}
			}
			else
			{
				dp[i][j] = 0;
			}
		}
		if (dp[1][L] == L)
		{
			lps = L;
		}
	}

	if (lps == Len)
	{
		return s;
	}

	char* ns = new char[Len - lps + Len];
	strcpy(ns, s + lps);
	int i = 0;
	int j = Len - lps;
	while (i < j)
	{
		char c = ns[i];
		ns[i] = ns[j];
		ns[j] = c;
		++i;
		--j;
	}
	strcat(ns, s);
	return ns;

}

int main()
{
	Solution sol;
	string s = "aacecaaa";
	//cout << sol.shortestPalindrome(s) << endl;

	s = "abcd";

	//cout << sol.shortestPalindrome(s) << endl;

	printf("%s\n",shortestPalindrome((char*)s.c_str()));

	return 0;
}