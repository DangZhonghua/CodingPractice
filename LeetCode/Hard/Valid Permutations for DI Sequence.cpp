/*
https://leetcode-cn.com/problems/valid-permutations-for-di-sequence/
Valid Permutations for DI Sequence

We are given S, a length n string of characters from the set {'D', 'I'}. (These letters stand for "decreasing" and "increasing".)
A valid permutation is a permutation P[0], P[1], ..., P[n] of integers {0, 1, ..., n}, such that for all i:
If S[i] == 'D', then P[i] > P[i+1], and;
If S[i] == 'I', then P[i] < P[i+1].
How many valid permutations are there?  Since the answer may be large, return your answer modulo 10^9 + 7.

Example 1:
Input: "DID"
Output: 5
Explanation:
The 5 valid permutations of (0, 1, 2, 3) are:
(1, 0, 3, 2)
(2, 0, 3, 1)
(2, 1, 3, 0)
(3, 0, 2, 1)
(3, 1, 2, 0)

 (3,2,3,)
Note:
1 <= S.length <= 200
S consists only of characters from the set {'D', 'I'}.
*/

/*

			Sum (DP[n][i-1]) for all n>m  if s[i-1] = 'D'
DP[m][i] =
			Sum (DP[p][i-1]) for all p<m  if s[i-1] = 'I'

*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution
{
public:
	int numPermsDISequence(string s)
	{
		if (s.empty())
		{
			return 0;
		}
		int numPerm = 0;
		int Len = s.length();
		vector< vector<unsigned long long > > dp(Len + 1, vector<unsigned long long>(Len + 1, 0));
		for (int i = 0; i <= Len; ++i)
		{
			dp[0][i] = 1;
		}

		for (int i = 1; i <= Len; ++i) // string cursor
		{
			for (int j = 0; j <= i; ++j) // digital cursor: j<i ensure the number only use once.
			{
				if ('D' == s[i - 1])
				{
					for (int k = j; k < i; ++k)
					{
						dp[i][j] += dp[i - 1][k];
						dp[i][j] %= mode;
					}
				}
				else // 'I' case
				{
					for (int k = 0; k < j; ++k)
					{
						dp[i][j] += dp[i - 1][k];
						dp[i][j] %= mode;
					}
				}
			}
		}

		for (auto v : dp)
		{
			for (auto a : v)
			{
				cout << a << " ";
			}
			cout << endl;
		}
		cout << endl;

		for (int i = 0; i <= Len; ++i)
		{
			numPerm += dp[Len][i];
			numPerm %= mode;
		}
		return numPerm;
	}

private:
	static const unsigned long long mode = 1e9 + 7;//1000000007;
};

int main()
{
	string s = "DID";
	Solution sol;

	cout << sol.numPermsDISequence(s) << endl;

	return 0;
}