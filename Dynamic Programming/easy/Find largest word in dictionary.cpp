/*
Find largest word in dictionary 
https://practice.geeksforgeeks.org/problems/find-largest-word-in-dictionary/0/?ref=self


Giving a dictionary and a string ‘str’, your task is to find the longest string in dictionary of size x which can be formed by deleting some characters of the given ‘str’.

Examples:

Input : dict = {"ale", "apple", "monkey", "plea"}   
        str = "abpcplea"  
Output : apple

Input  : dict = {"pintu", "geeksfor", "geeksgeeks", 
                                        " forgeek"} 
         str = "geeksforgeeks"
Output : geeksgeeks


Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. 
Each test case contains an integer x denoting the no of words in the dictionary. 
Then in the next line are x space separated strings denoting the contents of the dictionary.  
Then in the next line is a string 'str'.

Output:
For each test case in a new line print the required output.

Constraints:
1<=T<=100
1<=x, length of str<=1000

Example:
Input:
2
4
ale apple monkey plea
abpcplea
4
pintu geeksfor geeksgeeks forgeek
geeksforgeeks
Output:
apple
geeksgeeks


*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int CalcLenOfLcs(const string& strx, const string& stry)
{
	int R = strx.length();
	int C = stry.length();

	vector< vector<int> > lcs(R + 1, vector<int>(C + 1, 0));

	for (int r = 1; r <= R; ++r)
	{
		for (int c = 1; c <= C; ++c)
		{
			if (strx[r - 1] == stry[c - 1])
			{
				lcs[r][c] = lcs[r - 1][c - 1]+1;
			}
			else
			{
				lcs[r][c] = lcs[r - 1][c];
				if (lcs[r][c]< lcs[r][c - 1])
				{
					lcs[r][c] = lcs[r][c - 1];
				}
			}
		}
	}


	return lcs[R][C];
}

int FindLargestWord(vector<string>& dict, const string& strword)
{
	int maxlen = 0;
	int t = 0;
	for (int i = 0; i<dict.size(); ++i)
	{
		int nlcs = CalcLenOfLcs(strword, dict[i]);
		if (nlcs == dict[i].size() && nlcs>maxlen)
		{
			maxlen = nlcs;
			t = i;
		}
	}

	cout << dict[t].c_str() << endl;

	return 0;
}

int main()
{
	int t = 0;
	vector<string> dict;

	cin >> t;

	while (t--)
	{
		int N = 0;
		cin >> N;
		int i = 0;
		string strdict;
		while (i<N)
		{
			cin >> strdict;
			dict.push_back(strdict);
			strdict.clear();
			++i;
		}
		string strword;
		cin >> strword;
		FindLargestWord(dict, strword);
		dict.clear();
	}

	return 0;
}