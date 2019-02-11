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
			bool bCheck{false};
			int  tc{0};
			int  sc{0};
	};

public:
	string minWindow(string s, string t)
	{

		unordered_map<int,wdata > dict;
		for(int i = 0; i<t.length(); ++i)
		{
			dict[t[i]].bCheck = true;
			dict[t[i]].tc += 1;
		}
		int i = 0;
		int j = 0;
		while(i<=j && j<s.size())
		{
			
		}
	}
};


int main(int argc, char const *argv[])
{
	Solution sol;
	string s = "cabwefgewcwaefgcf";
	string t = "cae";
	s = "ADOBECODEBANC";
	s = "BANC";

	t = "ABC";

	cout << sol.minWindow(s, t) << endl;

	return 0;
}
