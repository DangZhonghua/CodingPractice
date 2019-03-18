/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有K个重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/description/
 * http://www.cnblogs.com/grandyang/p/5852352.html
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
		if(s.length()<k)
		{
			return 0;
		}
		int maxl = 0;
		int N = s.length();
		unordered_map<char, int>  mapChar2Count;
		int i = 0;

		while( i+k<= N )
		{
			int count = 0; // iff all char freq is larger than K, count == 0;
			int nextIndex = i;
			int mapChar2Count[256]= {0};
			for(int j = i; j<N; ++j)
			{
				char C = s[j];
				//CalcCharCount(mapChar2Count,count,s[j],k);
				mapChar2Count[C] += 1;
				if(1 == mapChar2Count[C])
				{
					++count;
				}

				if(k == mapChar2Count[C])
				{
					--count;
				}

				if(0 == count)
				{
					maxl = max(maxl, j-i+1);
					nextIndex = j;
				}
			}
			i = (nextIndex+1);
		}
		return maxl;
	}

private:
	void  CalcCharCount(unordered_map<char, int>&  mapChar2Count, int& count, char C, int K)
	{
		mapChar2Count[C] += 1;
		if(1 == mapChar2Count[C])
		{
			++count;
		}

		if(K == mapChar2Count[C])
		{
			--count;
		}
	}

private:

};

/*

我们遍历字符串，对于每一个字符，我们都将其视为起点，然后遍历到末尾，我们增加哈希表中字母的出现次数，
如果其小于k，我们将mask的对应位改为1，如果大于等于k，将mask对应位改为0。然后看mask是否为0，是的话就更新res结果，
然后把当前满足要求的子字符串的起始位置j保存到max_idx中，等内层循环结束后，将外层循环变量i赋值为max_idx+1，继续循环直至结束，参见代码如下：

*/


// class Solution {
// public:
//     int longestSubstring(string s, int k) 
// 	{
//         int res = 0, i = 0, n = s.size();
//         while (i + k <= n) 
// 		{
//             int m[26] = {0}, mask = 0, max_idx = i;
//             for (int j = i; j < n; ++j) 
// 			{
//                 int t = s[j] - 'a';
//                 ++m[t];
//                 if (m[t] < k) 
// 				{
// 					mask |= (1 << t);
// 				}
//                 else 
// 				{
// 					mask &= (~(1 << t));
// 				}

//                 if (mask == 0) 
// 				{
//                     res = max(res, j - i + 1);
//                     max_idx = j;
//                 }
//             }
//             i = max_idx + 1;
//         }
//         return res;
//     }
// };
