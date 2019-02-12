/*
https://leetcode-cn.com/problems/minimum-window-substring/
Minimum Window Substring
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
Example:
Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:
If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.

*/

/*

"cabwefgewcwaefgcf"
"cae"

"aefgc"

"cwae"


*/

#include<string>
#include<vector>
#include<iostream>
#include<unordered_map>
#include<utility>
using namespace std;


class Solution
{
private:
	struct wdata
	{
		int  tc{ 0 };
		int  sc{ 0 };
	};

public:
	string minWindow(string s, string t)
	{
		int TN = t.length();
		int SN = 0;
		unordered_map<int, wdata > dict;
		for (int k = 0; k < t.length(); ++k)
		{
			dict[t[k]].tc += 1;
		}

		int i = 0;
		int j = 0;
		int w1 = 0;
		int w2 = -1; //iiiiiiiiiiiiiiiiii
		int minlen = s.length();
		while (i <= j && j <= s.size()) //iiiiiiiiiiiiiiiiiiiiiiii
		{
			if (SN < TN)
			{
				UpdateWindow(dict, SN, s[j]);
				++j;
			}
			else if (SN == TN)
			{
				if (minlen >= (j - i))
				{
					minlen = j - i;
					w1 = i;
					w2 = j;  //iiiiiiiiiii
				}
				DeleteFromWindow(dict, SN, s[i]);
				++i;
			}
		}
		string sr = "";
		if (w2 >= w1)
		{
			sr = s.substr(w1, minlen);
		}
		return sr;
	}
private:
	bool UpdateWindow(unordered_map<int, wdata >& dict, int& SN, int c)
	{
		auto it = dict.find(c);
		if (it != dict.end())
		{
			it->second.sc += 1;
			if (it->second.sc <= it->second.tc)
			{
				++SN;
			}
		}
		return true;
	}

	bool DeleteFromWindow(unordered_map<int, wdata >& dict, int& SN, int c)
	{
		auto it = dict.find(c);
		if (it != dict.end())
		{
			it->second.sc -= 1;
			if (it->second.sc < it->second.tc)
			{
				--SN;
			}
		}
		return true;
	}
};


int main(int argc, char const *argv[])
{
	Solution sol;
	string s = "cabwefgewcwaefgcf";
	string t = "cae";
	//s = "ADOBECODEBANC";

	//t = "ABC";
	s = "a";
	t = "aa";

	cout << sol.minWindow(s, t) << endl;

	return 0;
}
