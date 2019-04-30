/*
https://leetcode-cn.com/problems/remove-duplicate-letters/
Remove Duplicate Letters
Given a string which contains only lowercase letters, remove duplicate letters so that
every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
Example 1:
Input: "bcabc"
Output: "abc"
Example 2:
Input: "cbacdcbc"
Output: "acdb"

*/

#include<string>
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include<stack>
#include<iostream>
using namespace std;

class Solution
{
public:
	string removeDuplicateLetters(string s)
	{
		unordered_map<char, int> mapChar2Count;
		unordered_set<char> setChar;
		deque<char> cs;

		for (int i = 0; i < s.length(); ++i)
		{
			mapChar2Count[s[i]] += 1;
		}
		int CN = mapChar2Count.size();

		int i = 0;
		while (i < s.size())
		{
			//select the minimum char
			while (!cs.empty() && cs.back() >= s[i] && mapChar2Count[cs.back()] > 1 && 0 == setChar.count(s[i]))
			{
                //remove the larger if it will come next. and the current char is not in the stack.
				mapChar2Count[cs.back()] -= 1;
				setChar.erase(cs.back());
				cs.pop_back();
			}
			if (0 == setChar.count(s[i]))
			{
                //if current is not in the current stack.
				setChar.insert(s[i]);
				cs.push_back(s[i]);
			}
			else
			{
                //since the current char in the stack, we don't put it into so just skip it.
				mapChar2Count[s[i]] -= 1;
			}
			++i;
		}

		string str;
		while (!cs.empty())
		{
			str += cs.front();
			cs.pop_front();
		}
		return str;
	}
};

int main()
{
	Solution sol;
	string s1 = "cbacdcbc";
	cout << sol.removeDuplicateLetters(s1) << endl;

	s1 = "bcabc";
	cout << sol.removeDuplicateLetters(s1) << endl;
	return 0;
}