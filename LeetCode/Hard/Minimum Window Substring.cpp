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
using namespace std;

class Solution {
public:
	string minWindow(string s, string t)
	{
		unordered_map<char, int> dict;
		bool bFind = true;
		string strw = "";

		for (char c : s)
		{
			dict[c] += 1;
		}
		for (char c : t)
		{
			if (dict.end() != dict.find(c))
			{
				dict[c] -= 1;
				if (dict[c] < 0)
				{
					bFind = false;
					break;
				}
			}
			else
			{
				bFind = false;
				break;
			}
		}

		if (bFind)
		{
			int i = 0;
			int j = s.length() - 1;
			while (i <= j)
			{
				dict[s[i]] -= 1;
				if (dict[s[i]] < 0)
				{
					break;
				}
				++i;
			}
			while (i <= j)
			{
				dict[s[j]] -= 1;
				if (dict[s[j]] < 0)
				{
					break;
				}
				--j;
			}

			strw = s.substr(i, j - i + 1);
		}

		return strw;
	}
};

int main(int argc, char const *argv[])
{
	string s = "ADO";
	string t = "ABC";
	Solution sol;

	cout << sol.minWindow(s, t) << endl;

	return 0;
}
