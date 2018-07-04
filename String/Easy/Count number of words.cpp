/*
Count number of words 
https://practice.geeksforgeeks.org/problems/count-number-of-words/0/?ref=self

Given a string consisting of spaces,\t,\n and lower case  alphabets.Your task is to count the number of words where spaces,\t and \n work as separators.

Input:
The first line of input contains an integer T denoting the number of test cases.Each test case consist of a string.

Output:
Print the number of words present in the string.

Constraints:
1<=T<=100

Example:
Input:
2
abc\t\ndef   ghi
one   two   three  \t  four
Output:
3
4

*/


#include<string>
#include<iostream>
using namespace std;

int CountWordsOfString(const string& strtext)
{
	int s = -1;
	int count = 0;

	for (int i = 0; i < strtext.size(); ++i)
	{
		if (strtext[i] == '\t' || strtext[i] == '\n' || strtext[i] == ' ')
		{
			if (-1 != s)
			{
				++count;
			}
			s = -1;
		}
		else
		{
			if (-1 == s)
			{
				s = i;
			}
		}
	}
	if (-1 != s)
	{
		++count;
	}

	cout<<count<<endl;

	return 0;
}


int main(int argc, char const *argv[])
{
	int t = 0;
	string strtext;

	cin >> t;

	while (t--)
	{
		cin >> strtext;

		CountWordsOfString(strtext);
	}

	return 0;
}