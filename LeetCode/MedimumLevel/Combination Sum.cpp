/*
https://leetcode-cn.com/problems/combination-sum/
Combination Sum

Given a set of candidate numbers (candidates) (without duplicates) and a target number (target),
find all unique combinations in candidates where the candidate numbers sums to target.
The same repeated number may be chosen from candidates unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
[7],
[2,2,3]
]
Example 2:
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
[2,2,2,2],
[2,3,3],
[3,5]
]

*/


/*

Use DP or backtracking technique.

*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		std::sort(candidates.begin(), candidates.end());
		int cCount = candidates.size();
		vector< vector<bool> > dp(target + 1, vector<bool>(cCount + 1, false)); // dp: use to calculate sum
		vector< vector<int> > vc(target + 1, vector<int>());  // vc: use to record the element for specific sum.
		for (int i = 0; i <= cCount; ++i)
		{
			dp[0][i] = true;
		}

		for (int s = 1; s <= target; ++s)
		{
			for (int i = 1; i <= cCount; ++i)
			{
				dp[s][i] = dp[s][i-1];
				if (candidates[i - 1] <= s &&  dp[s - candidates[i - 1]][i])
				{
					dp[s][i] = true;
					vc[s].push_back(i);
				}
			}
		}

		vector< vector <int> > vr;
		vector<int> vsc;
		BuildCombination(vr,candidates,vc,vsc,target);

		//for (vector<int>& c : vr)
		//{
		//	for (int e : c)
		//	{
		//		cout << e << " ";
		//	}
		//	cout<<endl;
		//}
		return vr;
	}

private:
	void BuildCombination(vector< vector <int> >& vr, vector<int>& candidates, vector< vector<int> >& vc, vector<int>& vsc, int target)
	{
		if (0 == target)
		{
			//std::sort(vsc.begin(), vsc.end());
			AddCombination(vr,vsc);
			return;
		}
		for (int e : vc[target])
		{
			vsc.push_back(candidates[e-1]);
			BuildCombination(vr,candidates,vc,vsc,target-candidates[e-1]);
			vsc.pop_back();
		}
	}
	void AddCombination(vector< vector <int> >& vr, vector<int> vsc)
	{
		std::sort(vsc.begin(), vsc.end());
		bool bFind = false;
		for (auto v : vr)
		{
			if (v.size() == vsc.size())
			{
				bFind = true;
				for (int i = 0; i < vsc.size(); ++i)
				{
					if (vsc[i] != v[i])
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
			vr.push_back(vsc);
		}
	}
};

int main(int argc, char const *argv[])
{
	vector<int> a{ 2, 3, 6, 7 };
	int target = 7;
	Solution sol;
	//sol.combinationSum(a, target);

	vector<int> b{ 2, 3, 5};
	target = 8;
	//sol.combinationSum(b,target);

	vector<int> c{3,2,6,7};
	target = 11;
	sol.combinationSum(c, target);
	return 0;
}
