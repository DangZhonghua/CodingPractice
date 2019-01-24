/*
https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating characters.
Example 1:
Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
			 Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/


/*

slide window, and check the repeating char

*/

#include<string>
#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;


class Solution {
public:
	int lengthOfLongestSubstring(string s)
	{
        if(s.empty())
        {
            return 0;
        }
		struct stCountAndPos
		{
			int count{ 0 };
			int pos{ -1 };
		};
		unordered_map<char, stCountAndPos> cmap;
		int ws = 0;
		int we = 1;
		int lw = 1;

		cmap[s[0]] = stCountAndPos{ 1,0 };
		while (ws < we && we < s.length())
		{
			if (cmap[s[we]].count)
			{
				int pos = cmap[s[we]].pos;
				while (ws <= pos)
				{
					cmap[s[ws]].count -= 1;
					++ws;
				}
			}
			cmap[s[we]] = stCountAndPos{ 1,we };
			if ((we - ws+1) > lw)
			{
				lw = (we - ws+1);
			}
			++we;
		}
		if ((we - ws) > lw)
		{
			lw = (we - ws);
		}
		return lw;
	}
};

int main()
{
	string s = "abcabcbb";
	Solution sol;
	cout << sol.lengthOfLongestSubstring(s) << endl;

	s = "bbbbb";
	cout << sol.lengthOfLongestSubstring(s) << endl;


	s = "pwwkew";
	cout << sol.lengthOfLongestSubstring(s) << endl;

	return 0;
}


