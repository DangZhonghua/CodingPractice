/*
https://leetcode-cn.com/problems/ones-and-zeroes/
Ones and Zeroes

In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.
For now, suppose you are a dominator of m 0s and n 1s respectively. 
On the other hand, there is an array with strings consisting of only 0s and 1s.
Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. 
Each 0 and 1 can be used at most once. 
Note:
The given numbers of 0s and 1s will both not exceed 100
The size of given string array won't exceed 600.

Example 1:
Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
Output: 4

Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are “10,”0001”,”1”,”0”

Example 2:
Input: Array = {"10", "0", "1"}, m = 1, n = 1
Output: 2

Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".
*/

/*

This is 2D knapsack problem.
\
*/


#include<vector>
#include<string>
#include<iostream>
using namespace std;


class Solution
{
public:
	int findMaxForm(vector<string>& strs, int m, int n)
	{
		vector<int> vones(strs.size(), 0);
		vector<int> vzeros(strs.size(), 0);

		vector< vector< vector<int> > > dp(strs.size() + 1, vector< vector<int> >(m+1, vector<int>(n+1, -1)));
		dp[0][0][0] = 0;

		for (int i = 0; i <= m; ++i)
		{
			for (int j = 0; j <= n; ++j)
			{
				dp[0][i][j] = 0;
			}
		}
		for (int i = 0; i <= strs.size(); ++i)
		{
			for (int j = 0; j <= n; ++j)
			{
				dp[i][0][j] = 0;
			}
			for (int k = 0; k <= m; ++k)
			{
				dp[i][k][0] = 0;
			}
		}

		for (int i = 0; i < strs.size(); ++i)
		{
			for (int j = 0; j < strs[i].size(); ++j)
			{
				if ('1' == strs[i][j])
				{
					vones[i] += 1;
				}
				else if ('0' == strs[i][j])
				{
					vzeros[i] += 1;
				}
			}
		}

		for (int i = 1; i <= strs.size(); ++i)
		{
			for (int zero = 0; zero <= m; ++zero)
			{
				for (int one = 0; one <= n; ++one)
				{
					dp[i][zero][one] = dp[i - 1][zero][one];
					if (zero >= vzeros[i - 1] && one >= vones[i - 1])
					{					
						if (-1 != dp[i - 1][zero - vzeros[i - 1]][one - vones[i - 1]])
						{
							if (dp[i - 1][zero - vzeros[i - 1]][one - vones[i - 1]] + 1 >= dp[i - 1][zero][one])
							{
								dp[i][zero][one] = dp[i - 1][zero - vzeros[i - 1]][one - vones[i - 1]] + 1;
							}
						}
					}
				}
			}
		}
		return dp[strs.size()][m][n];
	}
};

int main()
{
	vector<string> strs{ "10","0","1" };
	int m = 1;
	int n = 1;
	Solution sol;

	cout << sol.findMaxForm(strs, m, n) << endl;

	return 0;
}