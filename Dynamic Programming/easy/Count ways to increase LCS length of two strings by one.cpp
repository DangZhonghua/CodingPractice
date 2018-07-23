/*
Count ways to increase LCS length of two strings by one 
https://practice.geeksforgeeks.org/problems/count-ways-to-increase-lcs-length-of-two-strings-by-one/0
https://www.geeksforgeeks.org/count-ways-increase-lcs-length-two-strings-one/

Given two strings of lower alphabet characters, we need to find the number of ways to insert a character 
in the first string such that length of LCS of both strings increases by one.

Input:
The first line of the contains T denoting the number of testcases. Then T testcases follow. 
The first line of each test case contains integers N and M denoting the length of strings str1 and str2.
The second line of each test case contains the strings str1 and str2 consisiting of only lower case alphabets.


Output:

Print the answer for each test case in a new line.

Constraints:
1<= T <=100
1<= N, M <=100

Example:
Input:

1
5 3
abab abc

Output:

3

*/

/*

            LCS[i-1,j-1]+1  if x[i] == y[j]
LCS[i,j] =  max(LCS[i-1,j],LCS[i,j-1]) if x[i] != y[j]
            0 if i == 0 or j = 0;

 x[i] == y[j] then  x[i] and y[j] must be a element in one of longest common subsequence.

The idea is try all 26 possible characters at each position of first string, if length of str1 is m then 
a new character can be inserted in (m + 1) positions, now suppose at any time character c 
is inserted at ith position in str1 then we will match it with all positions 
having character c in str2. Suppose one such position is j, 
then for total LCS length to be one more than previous, below condition should satisfy,

LCS(str1[1, m], str2[1, n]) = LCS(str1[1, i],  str2[1, j-1]) + 
                              LCS(str1[i+1, m], str2[j+1, n])  

Above equation states that sum of LCS of the suffix and prefix substrings at inserted character 
must be same as total LCS of strings, so that when the same character is 
inserted in first string it will increase the length of LCS by one.
In below code two 2D arrays, lcsl and lcsr are used for storing LCS of 
prefix and suffix of strings respectively.
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;


enum LCSChoice
{
	choice_invalid,
	choice_middle,
	choice_left,
	choice_upper
};

int CountLCSIncreaseingWay(const string& x, const string& y)
{
	int R = x.size();
	int C = y.size();
	int nway = 0;
	vector< vector<int> > lcsprefix(R+2, vector<int>(C+2,0));
	vector< vector<int> > lcssuffix(R+2, vector<int>(C+2,0));
	
	//LCS by prefix
	for(int i = 1; i<= R; ++i)
	{
		for(int j = 1; j<=C; ++j)
		{
			if(x[i-1] == y[j-1])
			{
				lcsprefix[i][j] = lcsprefix[i-1][j-1] + 1;
 			}
			else
			{
				lcsprefix[i][j] = lcsprefix[i-1][j];
				if(lcsprefix[i][j]<lcsprefix[i][j-1])
				{
					lcsprefix[i][j] = lcsprefix[i][j-1];
				}
			}
		}
	}
	//lcs by suffix
	for(int i = R; i>0; --i)
	{
		for(int j = C; j>0; --j)
		{
			if(x[i-1] == y[j-1])
			{
				lcssuffix[i][j] = lcssuffix[i+1][j+1] + 1;
			}
			else
			{
				lcssuffix[i][j] = lcssuffix[i+1][j];
				if(lcssuffix[i][j]<lcssuffix[i][j+1])
				{
					lcssuffix[i][j] = lcssuffix[i][j+1];
				}
			}
		}
	}

	for(int i = 0; i<=R; ++i) //for 0...R for R+1 position
	{
		for(int j = 1; j<=C; ++j)
		{
			if( lcsprefix[i][j-1] + lcssuffix[i+1][j+1] == lcsprefix[R][C] )
			{
				++nway;
			}
		}
	}


	
	cout << nway << endl;

	return 0;
}



int main()
{
	int t = 0;
	string x, y;
	int M, N;
	cin >> t;

	while (t--)
	{
		cin >> M >> N;
		cin >> x;
		cin >> y;
		CountLCSIncreaseingWay(x, y);
		x.clear();
		y.clear();
	}

	return 0;
}