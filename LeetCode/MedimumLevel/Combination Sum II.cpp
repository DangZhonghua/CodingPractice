/*
https://leetcode-cn.com/problems/combination-sum-ii/
Combination Sum II

Given a collection of candidate numbers (candidates) and a target number (target),
find all unique combinations in candidates where the candidate numbers sums to target.
Each number in candidates may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:
Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]

*/


/*

This is 0-1 knapsnack problem

*/


#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;


class Solution
{
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
	{
		std::sort(candidates.begin(), candidates.end());
		int R = candidates.size();
		vector< vector<bool> > dp(R + 1, vector<bool>(target + 1, false));
		vector< vector<int> >  vc(target + 1, vector<int>());

		dp[0][0] = true;
		for (int i = 0; i <= R; ++i)
		{
			dp[i][0] = true;
		}
		for (int i = 1; i <= R; ++i)
		{
			for (int t = 1; t <= target; ++t)
			{
				if (t >= candidates[i - 1] && dp[i - 1][t - candidates[i - 1]])
				{
					dp[i][t] = true;
					vc[t].push_back(i);
				}
				if (!dp[i][t])
				{
					dp[i][t] = dp[i - 1][t];
				}
			}
		}

		// for (auto v : dp)
		// {
		// 	for (auto e : v)
		// 	{
		// 		cout << e << " ";
		// 	}
		// 	cout << endl;
		// }

		vector< vector<int> > vr;
		vector<int> svc;
		vector<bool> vb(R + 1, false);
		//if (dp[R][target])
		{
			BuildCombination(candidates, target, vb, vr, vc, svc);
			// for (auto v : vr)
			// {
			// 	for (int a : v)
			// 	{
			// 		cout << a << " ";
			// 	}
			// 	cout << endl;
			// }
		}

		return vr;
	}
private:
	void BuildCombination(vector<int>& candidates, int target, vector<bool>& vb, vector<vector<int> >& vr, vector< vector<int> >& vcr, vector<int>& vc)
	{
		
		if (0 == target)
		{
			vector<int> vi = vc;
			std::sort(vi.begin(), vi.end());
			bool bFind = false;
			for (auto v : vr)
			{
				if (v.size() == vi.size())
				{
					bFind = true;
					for (int i = 0; i < vi.size(); ++i)
					{
						if (vi[i] != v[i])
						{
							bFind = false;
						}
					}
				}
				if (bFind)
				{
					break;
				}
			}
			if (!bFind)
			{
				vr.push_back(vi);
			}
		}

		for (int i : vcr[target])
		{
			if (vb[i])
			{
				continue;
			}
			vb[i] = true;
			vc.push_back(candidates[i - 1]);
			BuildCombination(candidates, target - candidates[i - 1],vb, vr, vcr, vc);
			vc.pop_back();
			vb[i] = false;
		}

	}
};

int main(int argc, char const *argv[])
{
	Solution sol;

	vector<int> a{4,4,2,1,4,2,2,1,3};

	int  target = 6;
	//sol.combinationSum2(a, target);


	vector<int> b{ 2, 4, 1, 5, 5, 4, 1, 2, 4 };
	target = 10;
	sol.combinationSum2(b, target);


	return 0;
}
