/*
https://www.geeksforgeeks.org/length-longest-balanced-parentheses-prefix/
Length of longest balanced parentheses prefix

Given a string of open bracket ‘(‘ and closed bracket ‘)’. The task is to find the length of longest balanced prefix.

Examples:

Input : S = "((()())())(("
Output : 10
From index 0 to index 9, they are forming
a balanced parentheses prefix.

Input : S = "()(())((()"
Output : 6


*/

/*

find parenthesis range, then concatenation if possbile: if previous range is continuous

*/

#include<iostream>
#include<stack>
#include<string>
#include<utility>
using namespace std;

int longestBalanceParenthesis(const string& x)
{
	stack< int > s;
	int maxlen = 0;

	for (int i = 0; i < x.length(); ++i)
	{
		if (s.empty())
		{
			s.push(i);
		}
		else
		{
			if (x[s.top()] == '(' &&  ')' == x[i])
			{
				s.pop();
			}
			else
			{
				s.push(i);
			}
		}
	}
	if (s.empty())
	{
		maxlen = x.length();
	}
	else
	{
		int preIndex = x.length() - 1;
		while (!s.empty())
		{
			if ((preIndex - s.top()) > maxlen)
			{
				maxlen = (preIndex - s.top());
			}
			preIndex = s.top();
			s.pop();
		}
		if (preIndex > maxlen) // this is important for first part
		{
			maxlen = preIndex;
		}
	}

	return maxlen;
}

int main()
{
	string x = "((()())())((";
	cout << longestBalanceParenthesis(x) << endl;

	x = "()(())((()";
	cout << longestBalanceParenthesis(x) << endl;

	return 0;
}

