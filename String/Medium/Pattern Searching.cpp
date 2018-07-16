/*
Pattern Searching
https://practice.geeksforgeeks.org/problems/pattern-searching/0/?ref=self

Given a text and a pattern, Find whether the pattern exist in the text or not.
If it is present print "found" without quotes else print "not found"
without quotes.

Input:

The first line of input contains an integer T denoting the number of test cases.
Each test case consist of a string in 'lowercase' only in a
separate line.

Output:

Print "found" or "not found" in a separate line.


Constraints:

1 ≤ T ≤ 30
1 ≤ |s| ≤ 100


Example:

Input
1
geeksforgeeks
geeks
Output
found

*/

/*

This obvious can be done by KMP. The hardest part of KMP is the prefix array compution.
[prefix] ... [postfix] which prefix the same as postfix.

// How to understand j = lps[j - 1];  x[i] != [j] current matching processing must be stopped.

For restart, which index is the optimal, since x[j-1] = x[i-1], according to the KMP,
we can restart from lps[j-1] since prefix = postfix.

*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;


int CalcPrefixArray(const string& strp, vector<int>&  prefixarray)
{
	int N = strp.length();
	vector<int> lps(N + 1, 0);

	int i = 1;  // this is step pointer
	int j = 0;  // this is last char index of prefix.

	for (i = 1; i < N; ++i)
	{
		while (j>0 && strp[i] != strp[j])
		{
			j = lps[j - 1];
		}
		if (strp[i] == strp[j])
		{
			lps[i] = j + 1;
			++j;		//When i and j is equal, increase the i and j.
		}
	}
	prefixarray = lps;

	return 0;
}



int PatternSearch(const string& strsrc, const string& strp)
{
	vector<int> prefix;
	CalcPrefixArray(strp, prefix);
	// When mismatch at index of strp, from the strp[ prefix[i] ].
	// This is O(n+m) time complexity.
	int SL = strsrc.length();
	int PL = strp.length();

	int j = 0;
	int i = 0;

	while (i < SL && j < PL)
	{
		if (strsrc[i] == strp[j])
		{
			++j;
			++i;
			if (j == PL)
			{
				break;
			}
		}
		else
		{
			if (0 == j)
			{
				++i;
			}
			else
			{
				j = prefix[j - 1];
			}

		}
	}
	if (PL == j)
	{
		cout << "found" << endl;
	}
	else
	{
		cout << "not found" << endl;
	}


	return 0;
}




int main()
{
	int t = 0;
	string strsrc;
	string strpattern;

	cin >> t;

	while (t--)
	{
		cin >> strsrc;
		cin >> strpattern;
		PatternSearch(strsrc, strpattern);
	}
	return 0;
}



