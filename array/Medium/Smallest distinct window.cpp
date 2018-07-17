/*
Smallest distinct window
https://practice.geeksforgeeks.org/problems/smallest-distant-window/0
https://www.geeksforgeeks.org/smallest-window-contains-characters-string/
https://www.geeksforgeeks.org/length-smallest-sub-string-consisting-maximum-distinct-characters/

Given a string detect the smallest window length that contains all the distinct characters
of the given string even if it contains repeating elements​.
For eg. A = “aabcbcdbca”, then the result would be 4 as of the smallest window will be “dbca” .

Another example, in “aabcbcdb”, the smallest string that contains all the characters is “abcbcd”.

Input:
The first line of input contains an integer T denoting the no of test cases.
Then T test cases follow. Each test case contains a string S.

Output:
For each test case in a new line print the length of the smallest such string.

Constraints:
1<=T<100
1<=|S|<=1000

Example:
Input:
2
aabcbcdbca
aaab

Output:
4
2

2
lcpsklryvmcpjnbpbwllsrehfmxrkecwitrsglrexvtjmxypunbqfgxmuvgfajclfvenhyuhuorjosamibdn
dbeyhkbsombltouujdrbwcrrcgbflqpottpegrwvgajcrgwdlpgitydvhedtusippyvxsuvbvfenodqasajoy
Output of Online Judge is:
55
71

wwaakwyprxnxpypjgtlhfteetxbafkrejsfvrenlebjtccgjvrsdowiixlidxdiixpervseavnwypdinwdrlacvanhelk
42

*/

/*
1. Statis the unique char count。
2. Slide window [i,j] then step j to j+1. [i, j+1], then forward i+1, i+2... util the freq[a[i+1]] ... = 1

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


int SmallestDistinctWindow(const string& X)
{
	unordered_map<char, int> dict;
	unordered_map<char, int> w;
	int wsize = X.length();

	for (int i = 0; i<X.length(); ++i)
	{
		auto it = dict.find(X[i]);
		if (dict.end() != it)
		{
			it->second += 1;
		}
		else
		{
			dict.insert(std::make_pair(X[i], 1));
		}
	}

	int k = 0;
	int j = 1;
	for (j = 0; j<X.length(); ++j)
	{
		auto itw = w.find(X[j]);
		if (itw != w.end())
		{
			itw->second += 1;
		}
		else
		{
			w.insert(std::make_pair(X[j], 1));
		}
		while (1)
		{
			itw = w.find(X[k]);
			if (w.end() != itw)
			{
				if (itw->second > 1)
				{
					itw->second -= 1;
					++k;
				}
				else
				{
					break;
				}
			}
		}

		if (w.size() == dict.size())
		{
			if (wsize > (j - k + 1))
			{
				wsize = j - k + 1;
			}
		}
		
	}
	cout << wsize << endl;

	return 0;
}

int main()
{
	int t = 0;
	string strx;

	cin >> t;

	while (t--)
	{
		cin >> strx;
		SmallestDistinctWindow(strx);
	}

	return 0;
}