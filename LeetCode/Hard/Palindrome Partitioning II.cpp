/*
https://leetcode-cn.com/problems/palindrome-partitioning-ii/
Palindrome Partitioning II
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example:

Input: "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

*/

/*

mc[i][j] = min{mc[i,k] + mc[k+1][j] + 1}

*/

#include<string>
#include<vector>
#include<iostream>

using namespace std;

// class Solution {
// public:
// 	int minCut(string s)
// 	{
// 		int N = s.length();
// 		vector<vector<bool> > bps(N, vector<bool>(N, false));
// 		vector<vector<int> >  nps(N, vector<int>(N, N+1));
		

// 		for (int i = 0; i < N; ++i)
// 		{
// 			bps[i][i] = true;
// 			nps[i][i] = 0;
// 		}

// 		for (int L = 2; L <= N; ++L)
// 		{
// 			for (int i = 0; i <= N - L; ++i)
// 			{
// 				int j = i + L - 1;
// 				if (s[i] == s[j])
// 				{
// 					if (2 == L)
// 					{
// 						bps[i][j] = true;
// 					}
// 					else if (bps[i + 1][j - 1])
// 					{
// 						bps[i][j] = true;
// 					}
// 				}
// 			}
// 		}

// 		vector<int> dp(N+1,0);
// 		for (int L = 2; L <= N; ++L)
// 		{
// 			for (int i = 0; i <= N - L; ++i)
// 			{
// 				int j = i + L - 1;
// 				if (bps[i][j])
// 				{
// 					nps[i][j] = 0;
// 				}
// 				else
// 				{
// 					for (int k = i; k < j; ++k)
// 					{
// 						if ( /*bps[i][k] && bps[k+1][j] && */(nps[i][k] + nps[k + 1][j] + 1) < nps[i][j])
// 						{
// 							nps[i][j] = (nps[i][k] + nps[k + 1][j] + 1);
// 						}
// 					}
// 				}
// 			}
// 		}

// 		return nps[0][N - 1];
// 	}
// };


class Solution {
public:
	int minCut(string s)
	{
		int N = s.length();
		vector<vector<bool> > bps(N, vector<bool>(N, false));
		vector<int >  nps(N, 0);
		
		for(int i = 0; i<N; ++i)
		{
			bps[i][i] = true;
			if(i+1<N)  //for length == 2
			{
				bps[i][i+1] = (s[i] == s[i+1]);
			}
		}
		
		for(int L = 2; L<N; ++L)
		{
			for(int i = 0; i+L<N; ++i)
			{
				bps[i][i+L] = (bps[i+1][i+L-1] && s[i] == s[i+L]);
			}
		}

		for(int i = 0; i<N; ++i)
		{
			nps[i] = i+1;
			if(bps[0][i])
			{
				nps[i] = 0;
			}
			else
			{
				for(int j = 1; j<=i; ++j)
				{
					if(bps[j][i])
					{
						nps[i] = min(nps[i], nps[j-1]+1 /* at j position seg */);
					}
				}
			}	
		}

		return nps[N - 1];
	}
};


int main()
{
	string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	Solution sol;

	cout << sol.minCut(s) << endl;

	return 0;
}