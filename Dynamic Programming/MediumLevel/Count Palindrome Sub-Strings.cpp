/*
Count Palindrome Sub-Strings of a String 
https://practice.geeksforgeeks.org/problems/count-palindrome-sub-strings-of-a-string/0
Given a string, the task is to count all palindromic sub-strings present in it.

Input:

The first line of input will contain no of test cases T . Then T test cases follow . Each test case contains 2 lines. The first line of each test case contains an integer N denoting the length of the string, next line of test case contains the string


Output:

For each test case output a single line depecting the number of palindromic substrings present.


Constraints:

1<=T<=100
2<=N<=500


Example:

Input

2
5
abaab
7
abbaeae

Output

3
4

Explanation:

Test Case 1
Input : str = "abaab"
Output: 3
All palindrome substring are : "aba" , "aa" , "baab"

Test Case 2
Input : str = "abbaeae"
Output: 4
All palindrome substring are : "bb" , "abba" ,"aea","eae"


*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int countPS(string str)
{
	int N = str.length();
	vector< vector<bool> > ps(N, vector<bool>(N, false));

	for (int i = 0; i<N; ++i)
	{
		ps[i][i] = true;
	}

	for (int l = 2; l <= N; ++l)
	{
		for (int i = 0; i <= N - l; ++i)
		{
			int j = i + l - 1;
			if (str[i] == str[j])
			{
				if (2 == l)
				{
					ps[i][j] = true;
				}
				else
				{
					ps[i][j] = ps[i + 1][j - 1];
				}
			}
		}
	}

	int count = 0;

	for (int i = 0; i<N; ++i)
	{
		for (int j = i + 1; j<N; ++j)
		{
			if (ps[i][j])
			{
				++count;
			}
		}
	}
	cout << count << endl;


	return count;
}


int main()
{
	int t;
	int N = 0;
	string strtxt;

	cin >> t;
	while (t--)
	{
		cin >> N;
		cin >> strtxt;
		countPS(strtxt);
	}

	return 0;
}

