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
			dp[i][0] = 1;
		}

		for (int i = 1; i <= Len; ++i)
		{
			if ('D' == s[i - 1])
			{
				for (int m = 0; m <= Len; ++m)
				{
					for (int n = m + 1; n <= Len; ++n)
					{
						dp[m][i] += dp[n][i - 1];
					}
					dp[m][i] %= mode;
				}
			}
			else if ('I' == s[i - 1])
			{
				for (int p = 1; p <= Len; ++p)
				{
					for (int n = 0; n < p; ++n)
					{
						dp[p][i] += dp[n][i - 1];
					}
					dp[p][i] %= mode;
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
			numPerm += dp[i][Len];
			numPerm %= mode;
		}
		return numPerm;
	}

private:
	static const unsigned long long mode = 1000000007;
};

int main()
{
	string s = "DID";
	Solution sol;

	cout << sol.numPermsDISequence(s) << endl;

	return 0;
}