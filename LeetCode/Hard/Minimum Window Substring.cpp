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

// class Solution {
// public:
// 	string minWindow(string s, string t)
// 	{
// 		struct chPos
// 		{
// 			vector<int> vp;
// 			int count{ 0 };
// 			int index{ 0 };
// 		};

// 		unordered_map<char, chPos > dict;
// 		bool bFind = true;
// 		int  ws = -1;
// 		int  we = -1;
// 		int  wmin = -1;
// 		int  fws = -1;
// 		int  fwe = -1;
// 		string strw = "";

// 		//Build map for char in S about their position.
// 		for (int i = 0; i < s.length(); ++i)
// 		{
// 			if (dict.end() != dict.find(s[i]))
// 			{
// 				dict[s[i]].count += 1;
// 				dict[s[i]].vp.push_back(i);
// 			}
// 			else
// 			{
// 				chPos a;
// 				a.count += 1;
// 				a.vp.push_back(i);
// 				dict[s[i]] = a;
// 			}
// 		}

// 		for (int i = 0; i < t.length(); ++i)
// 		{
// 			if (dict.end() == dict.find(t[i]))
// 			{
// 				bFind = false;
// 				break;
// 			}
// 		}
// 		if (!bFind)
// 		{
// 			return strw;
// 		}

// 		while (1)
// 		{
// 			int Lenp = t.length();
// 			int start = 0;
// 			chPos& fp = dict[t[0]];
// 			if (fp.index >= fp.count)
// 			{
// 				break;
// 			}
// 			ws = fp.vp[fp.index++];
// 			start = ws;
// 			we = -1;
// 			for (int i = 1; i < Lenp; ++i)
// 			{
// 				bool bNext = false;
// 				chPos& fnp = dict[t[i]];
// 				for (int next = fnp.index; next < fnp.count; ++next)
// 				{
// 					if (start < fnp.vp[next])
// 					{
// 						start = fnp.vp[next];
// 						fnp.index = next;
// 						bNext = true;
// 						break;
// 					}
// 				}
// 				if (bNext)
// 				{
// 					we = start;
// 				}
// 				else
// 				{
// 					break;
// 				}
// 			}
// 			if (-1 == we)
// 			{
// 				break;
// 			}
// 			else
// 			{
// 				if (-1 == wmin)
// 				{
// 					wmin = we - ws + 1;
// 					fwe = we;
// 					fws = ws;
// 				}
// 				else
// 				{
// 					if (wmin > (we - ws + 1))
// 					{
// 						wmin = (we - ws + 1);
// 						fwe = we;
// 						fws = ws;
// 					}
// 				}
// 			}
// 		}
		
// 		if (fwe > 0)
// 		{
// 			strw = s.substr(fws, wmin);
// 		}
// 		return strw;
// 	}
// };


class Solution {
public:
	string minWindow(string s, string t)
	{
		struct chPos
		{
			vector<int> vp;
			int count{ 0 };
			int index{ 0 };
		};

		unordered_map<char, chPos > dict;
		bool bFind = true;
		int  ws = -1;
		int  we = -1;
		int  wmin = -1;
		int  fws = -1;
		int  fwe = -1;
		string strw = "";

		//Build map for char in S about their position.
		for (int i = 0; i < s.length(); ++i)
		{
			if (dict.end() != dict.find(s[i]))
			{
				dict[s[i]].count += 1;
				dict[s[i]].vp.push_back(i);
			}
			else
			{
				chPos a;
				a.count += 1;
				a.vp.push_back(i);
				dict[s[i]] = a;
			}
		}

		for (int i = 0; i < t.length(); ++i)
		{
			if (dict.end() == dict.find(t[i]))
			{
				bFind = false;
				break;
			}
		}
		if (!bFind)
		{
			return strw;
		}

		while (1)
		{
			int Lenp = t.length();
			int start = 0;
			chPos& fp = dict[t[0]];
			if (fp.index >= fp.count)
			{
				break;
			}
			ws = fp.vp[fp.index++];
			start = ws;
			we = -1;
			for (int i = 1; i < Lenp; ++i)
			{
				bool bNext = false;
				chPos& fnp = dict[t[i]];
				for (int next = fnp.index; next < fnp.count; ++next)
				{
					if (start < fnp.vp[next])
					{
						start = fnp.vp[next];
						fnp.index = next;
						bNext = true;
						break;
					}
				}
				if (bNext)
				{
					we = start;
				}
				else
				{
					break;
				}
			}
			if (-1 == we)
			{
				break;
			}
			else
			{
				if (-1 == wmin)
				{
					wmin = we - ws + 1;
					fwe = we;
					fws = ws;
				}
				else
				{
					if (wmin > (we - ws + 1))
					{
						wmin = (we - ws + 1);
						fwe = we;
						fws = ws;
					}
				}
			}
		}
		
		if (fwe > 0)
		{
			strw = s.substr(fws, wmin);
		}
		return strw;
	}
};


int main(int argc, char const *argv[])
{
	string s = "cabwefgewcwaefgcf";
	string t = "cae";
	Solution sol;

	s = "ADOBECODEBANC";
	s = "BANC";

	t = "ABC";

	cout << sol.minWindow(s, t) << endl;

	return 0;
}
