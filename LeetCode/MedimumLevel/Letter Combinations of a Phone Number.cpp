/*
https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive,
return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.
Note that 1 does not map to any letters.

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

*/

/*
2: {abc}
3: {def}
4: {ghi}
5: {jkl}
6: {mno}
7: {pqrs}
8: {tuv}
9: {wxyz}

*/

#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	struct QueueItem
	{
		char cd{ 0 };
		char cL[4];
		int  lCount{ 3 };
		int  nCurIndex = 0;
	};
public:
	//like dfs traversal.
	vector<string> letterCombinations(string digits)
	{
		BuildDigitItemMap(d2Item);
		for (char c : digits)
		{
			levelQ.push_back(d2Item[c]);
		}
		vector<string> vsc;
        if(digits.length())
        {
            string strCombination;
            BuildCombinations(vsc, strCombination, 0);
        }
		return vsc;
	}

private:
	void BuildCombinations(vector<string>& vsc, string& strCombination, int start)
	{
		if (start == levelQ.size())
		{
			vsc.push_back(strCombination);
			return;
		}
		for (int i = 0; i<levelQ[start].lCount; ++i)
		{
			strCombination.push_back(levelQ[start].cL[i]);
			BuildCombinations(vsc, strCombination, start + 1);
			strCombination.pop_back();
		}
	}
	void BuildDigitItemMap(unordered_map<char, QueueItem>& d2Item)
	{
		QueueItem item;
		char  dcn[10]{0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
		char  baseC = 'a';
		char  nTotal = 0;

		for (int i = 2; i < 10; ++i)
		{
			item.lCount = dcn[i];
			item.cd = '0' + i;
			for (int j = 0; j < item.lCount; ++j)
			{
				item.cL[j] = baseC + j + nTotal;
			}
			nTotal += item.lCount;
			d2Item['0' + i] = item;
		}
	}

private:
	vector<QueueItem> levelQ;
	unordered_map<char, QueueItem> d2Item;

};


int main()
{
	int ret = 0;
	Solution combinator;
	string str = "237";
	auto a = combinator.letterCombinations(str);

	for (auto e : a)
	{
		cout << e << endl;
	}

	return 0;
}