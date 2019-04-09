/*
https://leetcode-cn.com/problems/word-search-ii/
Word Search II

Given a 2D board and a list of words from the dictionary, find all words in the board.
Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally
or vertically neighboring. The same letter cell may not be used more than once in a word.
Example:
Input:
words = ["oath","pea","eat","rain"] and board =
[
['o','a','a','n'],
['e','t','a','e'],
['i','h','k','r'],
['i','f','l','v']
]

Output: ["eat","oath"]
Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/

/*

use DFS to solve this problem, seems backtracking technique

*/



#include<vector>
#include<string>
#include<iostream>
using namespace std;


class Trie
{
	struct  Node
	{
		char  szLetter[26];
		Node* szNext[26];
		bool  szEnd[26];

		Node()
		{
			for (int i = 0; i < 26; ++i)
			{
				szLetter[i] = 0;
				szNext[i] = nullptr;
				szEnd[i] = false;
			}
		}
	};

public:
	/** Initialize your data structure here. */
	Trie()
	{
		m_root = new Node();
	}

	/** Inserts a word into the trie. */
	void insert(string word)
	{
		int   N = word.length();
		int   i = 0;
		Node* p = m_root;

		while (i < N)
		{
			int index = word[i] - 'a';
			p->szLetter[index] = 1;
			if (i + 1 == N)
			{
				p->szEnd[index] = true;
				break;
			}
			if (nullptr == p->szNext[index])
			{
				p->szNext[index] = new Node();
			}
			p = p->szNext[index];
			++i;
		}
	}

	/** Returns if the word is in the trie. */
	bool search(string word)
	{
		int N = word.length();
		int i = 0;
		bool bExist = true;
		Node* p = m_root;

		while (i < N)
		{
			int index = word[i] - 'a';
			if (0 == p->szLetter[index])
			{
				bExist = false;
				break;
			}
			if (i + 1 == N)
			{
				if (!p->szEnd[index])
				{
					bExist = false;
				}
				break;
			}
			p = p->szNext[index];
			if (nullptr == p)
			{
				bExist = false;
				break;
			}
			++i;
		}
		return bExist;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string& prefix, bool& bWord)
	{
		int N = prefix.length();
		int i = 0;
		bool bExist = true;
		Node* p = m_root;

		bWord = false;

		while (i < N)
		{
			int index = prefix[i] - 'a';
			if (0 == p->szLetter[index])
			{
				bExist = false;
				break;
			}
			if (i + 1 == N)
			{
				if (p->szEnd[index])
				{
					//cout<<prefix<<endl;
					bWord = true;
				}
				break;
			}
			p = p->szNext[index];
			if (nullptr == p)
			{
				bExist = false;
				break;
			}
			++i;
		}
		return bExist;
	}

private:
	Node* m_root{ nullptr };
};

int rBN[4] = { 0, -1, 0, 1 };
int cBN[4] = { -1, 0, 1, 0 };

class Solution
{
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
	{
		m_R = board.size();
		m_C = board[0].size();
		m_vs.clear();
		vector< vector<bool> > vflags(m_R, vector<bool>(m_C, false));
		string  strWord;
		BuildDictionary(words);

		for (string& str : words)
		{
			cout << str << endl;
		}


		for (int r = 0; r < m_R; ++r)
		{
			for (int c = 0; c < m_C; ++c)
			{
				strWord.push_back(board[r][c]);
				vflags[r][c] = true;
				DFSSearch(strWord, r, c, vflags, board);
				strWord.pop_back();
				vflags[r][c] = false;
			}
		}

		return m_vs;
	}

private:
	void DFSSearch(string& strWord, int r, int c, vector< vector<bool> >& vflag, vector<vector<char>>& board)
	{
		bool bWord = false;
		if (!m_pDict->startsWith(strWord, bWord))
		{
			return;
		}
		if (bWord && !m_pSet->search(strWord))
		{
			m_pSet->insert(strWord);
			m_vs.push_back(strWord);
		}

		for (int i = 0; i < 4; ++i)
		{
			int nr = r + rBN[i];
			int nc = c + cBN[i];

			if (nr >= 0 && nr < m_R && nc >= 0 && nc < m_C&& !vflag[nr][nc])
			{
				vflag[nr][nc] = true;
				strWord.push_back(board[nr][nc]);
				DFSSearch(strWord, nr, nc, vflag, board);
				vflag[nr][nc] = false;
				strWord.pop_back();
			}
		}
	}
private:
	void BuildDictionary(vector<string>& words)
	{
		m_pSet = new Trie;
		m_pDict = new Trie;
		for (int i = 0; i < words.size(); ++i)
		{
			m_pDict->insert(words[i]);
		}
	}

private:
	int m_R{ 0 };
	int m_C{ 0 };
	vector<string> m_vs;
	Trie* m_pDict{ nullptr };
	Trie* m_pSet{ nullptr };
};


int main()
{
	vector< vector<char> > board(1, vector<char>(1, 'a'));
	vector<string> words(1, "b");
	Solution sol;
	sol.findWords(board, words);

	return 0;
}