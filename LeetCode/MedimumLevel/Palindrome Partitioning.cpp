/*
https://leetcode-cn.com/problems/palindrome-partitioning/
Palindrome Partitioning
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
["aa","b"],
["a","a","b"]
]

*/

/*

ps[i][j] = ps[i+1][j-1] if s[i] = s[j]
0 else
*/


#include<string>
#include<vector>
#include<stack>
#include<iostream>
using namespace std;


class Solution
{
	struct stPS
	{
		int m_s;
		int m_lenIndex;
	};

public:
	vector<vector<string>> partition(string s)
	{
		int N = s.length();
		vector< vector<bool> >  lps(N + 1, vector<bool>(N + 1, false));
		vector< vector<int>  >  psm(N + 1, vector<int>(N + 1, 0));
		vector< vector<string> > vvps;
		vector<string> vps;
		stack<stPS> psStack;
		stPS start;

		for (int i = 0; i <= N; ++i)
		{
			lps[i][i] = true;
			psm[i][1] = 1;
			psm[i][0] = 1;  //the PS count which starting from i.
		}

		for (int L = 2; L<N; ++L)
		{
			for (int i = 0; i <= N - L; ++i)
			{
				int j = i + L - 1;
				if (s[i] == s[j])
				{
					if (2 == L)
					{
						lps[i][j] = true;
					}
					else if (lps[i+1][j-1])
					{
						lps[i][j] = true;
					}
					if (lps[i][j])
					{
						psm[i][0] += 1;
						psm[i][psm[i][0]] = L;
					}
				}
			}
		}

		start.m_s		 = 0;
		start.m_lenIndex = 1;

		// push them at the same time: this is important to keep vps and psStack consistent.
		psStack.push(start);
		vps.push_back(s.substr(0, psm[0][start.m_lenIndex]));

		while (!psStack.empty())
		{
			stPS& tp = psStack.top();

			if (tp.m_lenIndex > psm[tp.m_s][0])
			{
				vps.pop_back();
				psStack.pop();
				continue;
			}
			if ( tp.m_s + psm[tp.m_s][tp.m_lenIndex] == N) //reach the end
			{
				vvps.push_back(vps);
				vps.pop_back();
				psStack.pop();
			}
			else
			{
				start.m_s		 = tp.m_s + psm[tp.m_s][tp.m_lenIndex];
				start.m_lenIndex = 1;
				tp.m_lenIndex += 1;
				vps.push_back(s.substr(start.m_s, psm[start.m_s][start.m_lenIndex]));
				psStack.push(start);
			}
		}

		for (auto vs : vvps)
		{
			for (auto s : vs)
			{
				cout << s << " ";
			}
			cout<<endl;
		}

		return vvps;
	}
};

int main()
{
	string s = "aab";
	Solution sol;

	sol.partition(s);

	return 0;

}