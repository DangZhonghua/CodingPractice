/*
https://leetcode-cn.com/problems/generate-parentheses/
generateParenthesis

给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
例如，给出 n = 3，生成结果为：
[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]


*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n)
	{
		vector<string> vsp;
		string curstr;
		BacktrackGenerateParenthesis(vsp, curstr, 0, 2*n);
		return vsp;
	}
private:
	void BacktrackGenerateParenthesis(vector<string>& vsp, string& curGeneration, int start, int n)
	{
		if (start == n)
		{
			if (isValidParenthesis(curGeneration))
			{
				vsp.push_back(curGeneration);
			}
			return;
		}
		curGeneration += "(";
		BacktrackGenerateParenthesis(vsp, curGeneration, start + 1, n);
		curGeneration.pop_back();
		curGeneration += ')';
		BacktrackGenerateParenthesis(vsp, curGeneration, start + 1, n);
		curGeneration.pop_back();
	}

	bool isValidParenthesis(const string& curGeneration)
	{
		int nMatchingCount = 0;
		for (char c : curGeneration)
		{
			if ('(' == c)
			{
				++nMatchingCount;
			}
			else if (')' == c)
			{
				--nMatchingCount;
			}
			if (nMatchingCount<0)
			{
				return false;
			}
		}
		return (nMatchingCount == 0);
	}
};


int main(int argc, char const *argv[])
{
	int n = 3;

	Solution  parenthesisObj;
	auto result = parenthesisObj.generateParenthesis(n);

	for (const string& a : result)
	{
		cout << a << endl;
	}

	return 0;
}
