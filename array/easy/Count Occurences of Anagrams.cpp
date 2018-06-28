/*
Count Occurences of Anagrams 
https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams/0/?ref=self
Given a word and a text, return the count of the occurences of anagrams of the word in the text
(For eg: anagrams of word for are for, ofr, rof etc.))

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a text  consisting of only lowercase Latin Letters.
The second line contains a word consisting of only lowercase Latin Letters.

Output:
Print the count of the occurences of anagrams of the word in the text.

Constraints:
1 <= T <= 50
1 <= |word|<= |text| <= 50
here |word| denotes the size of word and |text| denotes the size of text 

Example:
Input:
2
forxxorfxdofr
for
aabaabaa
aaba

Output:
3
4

*/


/*

use slide window to do this. the slide window size is the target word.

*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int CountOccurencesofAnagrams(const string& strtext, const string& strword)
{
	vector<int> vWordFreq(26, 0);
	vector<int> vWinowFreq(26, 0);
	vector<int>  vindex;
	int n = 0;
	int W = strword.size();

	for (int i = 0; i < W; ++i)
	{
		++vWordFreq[strword[i] - 'a'];
		if (1 == vWordFreq[strword[i] - 'a'])
		{
			vindex.push_back(strword[i] - 'a');
		}
	}

	int i = 0;
	int j = 0;

	while (j < strtext.size())
	{
		++vWinowFreq[strtext[j] - 'a'];
		if ((j - i + 1) == W)
		{
			bool bfind = true;
			for (int k = 0; k<vindex.size(); ++k)
			{
				if (vWordFreq[vindex[k]] != vWinowFreq[vindex[k]])
				{
					bfind = false;
					break;
				}
			}
			if (bfind)
			{
				++n;
			}
			++i;
			vWinowFreq[strtext[i] - 'a'] -= 1;
		}
		++j;
	}

	cout << n << endl;



	return 0;
}

int main()
{
	int t = 0;
	string strtext;
	string strword;

	cin >> t;

	while (t--)
	{
		cin >> strtext;
		cin >> strword;
		CountOccurencesofAnagrams(strtext, strword);
	}

	return 0;
}