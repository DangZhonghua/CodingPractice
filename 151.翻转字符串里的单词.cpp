/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 *
 * https://leetcode-cn.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (19.75%)
 * Total Accepted:    7K
 * Total Submissions: 33.5K
 * Testcase Example:  '"the sky is blue"'
 *
 * 给定一个字符串，逐个翻转字符串中的每个单词。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入: "the sky is blue"
 * 输出: "blue is sky the"
 * 
 * 
 * 示例 2：
 * 
 * 输入: "  hello world!  "
 * 输出: "world! hello"
 * 解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 * 
 * 
 * 示例 3：
 * 
 * 输入: "a good   example"
 * 输出: "example good a"
 * 解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 * 
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 无空格字符构成一个单词。
 * 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 * 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。
 * 
 */


#include<string>
using namespace std;
class Solution
{
public:
	string reverseWords(string s)
	{
		if (s.empty()){
			return s;
		}
		int N = s.length();
		reverseString(s, 0, N - 1);

		int i = 0;
		int start = 0;
		while (i<N)
		{
			if (' ' == s[i])
			{
				reverseString(s, start, i - 1);
				start = i + 1;
			}
			++i;
		}
		//for last word.
		reverseString(s, start, i - 1);
		
		i = 0;
		int j = 0;
		int wordStart = -1;
		int strend = -1;
		string sr = "";
		
		while (j < N)
		{
			if (' ' != s[j])
			{
				if (-1 == wordStart)
				{
					wordStart = j;
				}
			}
			else
			{
				if (-1 != wordStart)
				{
					if (!sr.empty())
					{
						sr.push_back(' ');
					}
					while (wordStart < j)
					{
						sr.push_back(s[wordStart++]);
					}
					wordStart = -1;
				}
			}
			++j;
		}

		if (-1 != wordStart)
		{
			if (!sr.empty())
			{
				sr.push_back(' ');
			}
			while (wordStart < j)
			{
				sr.push_back(s[wordStart++]);
			}
			wordStart = -1;
		}

		//cout << sr << endl;
		return sr;

	}

private:
	void reverseString(string& szText, int s, int e)
	{
		char t = 0;
		while (s<e)
		{
			t = szText[s];
			szText[s] = szText[e];
			szText[e] = t;
			++s;
			--e;
		}
	}
};

