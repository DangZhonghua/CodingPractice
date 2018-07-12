/*
Save Ironman
https://practice.geeksforgeeks.org/problems/save-ironman/0

Jarvis is weak in computing palindromes for Alphanumeric characters.
While Ironman is busy fighting Thanos, he needs to activate sonic punch but Jarvis is stuck in computing palindromes.
You are given a string containing the alphanumeric character. Find whether the string is palindrome or not.
If you are unable to solve it then it may result in the death of Iron Man.

Input:
The first line of the input contains t, the number of test cases. Each line of the test case contains string 'S'.

Output:
Each new line of the output contains "YES" if the string is palindrome and "NO" if the string is not a palindrome.

Constraints:
1<=t<=100
1<=|S|<=100000
Note: Consider alphabets and numbers only for palindrome check. Ignore symbols and whitespaces.

Example:
Input:
2
I am :IronnorI Ma, i
Ab?/Ba

Output:
YES
YES

*/


#include<iostream>
#include<string>
using namespace std;

int SaveIronMan(const string& strtext)
{
	int i = 0;
	int j = strtext.length() - 1;
	bool bPlaindromic = true;

	while (i<j)
	{
		if (!(('A' <= strtext[i] && 'Z' >= strtext[i]) || ('0' <= strtext[i] && '9' >= strtext[i]) || ('a' <= strtext[i] && 'z' >= strtext[i])))
		{
			++i;
			continue;
		}
		if (!(('A' <= strtext[j] && 'Z' >= strtext[j]) || ('0' <= strtext[j] && '9' >= strtext[j]) || ('a' <= strtext[j] && 'z' >= strtext[j])))
		{
			--j;
			continue;
		}
		char l = strtext[i];
		if ('a' <= l && 'z' >= l)
		{
			l -= 32;
		}
		char r = strtext[j];

		if ('a' <= r && 'z' >= r)
		{
			r -= 32;
		}

		if (l != r)
		{
			bPlaindromic = false;
			break;
		}
		else
		{
			++i;
			--j;
		}
	}

	if (bPlaindromic)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}

	return 0;
}

int main()
{
	int t = 0;
	string strtext;

	cin >> t;
	cin.get();
	char ch;
	while (t--)
	{

		getline(cin, strtext);
		//while ((ch = cin.get()) != '\n')
		//{
		//	strtext.push_back(ch);
		//}
	
		SaveIronMan(strtext);
		strtext.clear();
	}
	return 0;
}