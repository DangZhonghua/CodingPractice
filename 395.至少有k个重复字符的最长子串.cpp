/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有K个重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/description/
 *
 * algorithms
 * Medium (34.45%)
 * Total Accepted:    702
 * Total Submissions: 2K
 * Testcase Example:  '"aaabb"\n3'
 *
 * 找到给定字符串（由小写字符组成）中的最长子串 T ， 要求 T 中的每一字符出现次数都不少于 k 。输出 T 的长度。
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * s = "aaabb", k = 3
 * 
 * 输出:
 * 3
 * 
 * 最长子串为 "aaa" ，其中 'a' 重复了 3 次。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入:
 * s = "ababbc", k = 2
 * 
 * 输出:
 * 5
 * 
 * 最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。
 * 
 * 
 */

#include<string>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include <iostream>
using namespace std;

class Solution
{

public:
	int longestSubstring(string s, int k)
	{
		unordered_map<char, int> mapChar2Count;
		unordered_map<char, int>  mapChar2Pos;
		vector<bool> setCharLessK(256, false);
		for (auto c : s)
		{
			mapChar2Count[c] += 1;
		}
		for (auto it = mapChar2Count.begin(); it != mapChar2Count.end(); ++it)
		{
			if (it->second < k)
			{
				setCharLessK[it->first] = true;
			}
		}
		mapChar2Count.clear();
		int i = 0;
		int b = -1;
		int maxl = 0;

		while (i < s.length())
		{
			if (setCharLessK[s[i]] )
			{
				int largestPos = b;
				for (auto it = mapChar2Count.begin(); it != mapChar2Count.end(); ++it)
				{
					if (it->second < k && largestPos<mapChar2Pos[it->first])
					{
						largestPos = mapChar2Pos[it->first];
					}
				}
				if (maxl < (i - largestPos-1) && k<= (i - largestPos - 1))
				{
					maxl = (i - largestPos-1);
				}
				mapChar2Count.clear();
				mapChar2Pos.clear();
				b = i + 1; //update the window start point
			}
			else
			{
				mapChar2Count[s[i]] += 1;
				mapChar2Pos[s[i]] = i;
			}
			++i;
		}

		if (!mapChar2Count.empty())
		{
			int largestPos = b;
			for (auto it = mapChar2Count.begin(); it != mapChar2Count.end(); ++it)
			{
				if (it->second < k && largestPos < mapChar2Pos[it->first])
				{
					largestPos = mapChar2Pos[it->first];
				}
			}
			if (maxl < (i - largestPos - 1) && k<=(i - largestPos - 1))
			{
				maxl = (i - largestPos - 1);
			}
		}



		return maxl;
	}
};


