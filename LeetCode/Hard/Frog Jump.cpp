/*

https://leetcode-cn.com/problems/frog-jump/
Frog Jump

A frog is crossing a river. The river is divided into x units and at each unit there may or may not exist a stone. 
The frog can jump on a stone, but it must not jump into the water.

Given a list of stones' positions (in units) in sorted ascending order, 
determine if the frog is able to cross the river by landing on the last stone. 
Initially, the frog is on the first stone and assume the first jump must be 1 unit.

If the frog's last jump was k units, then its next jump must be either k - 1, k, or k + 1 units. 
Note that the frog can only jump in the forward direction.

Note:

    The number of stones is ≥ 2 and is < 1,100.
    Each stone's position will be a non-negative integer < 231.
    The first stone's position is always 0.

Example 1:

[0,1,3,5,6,8,12,17]

There are a total of 8 stones.
The first stone at the 0th unit, second stone at the 1st unit,
third stone at the 3rd unit, and so on...
The last stone at the 17th unit.

Return true. The frog can jump to the last stone by jumping 
1 unit to the 2nd stone, then 2 units to the 3rd stone, then 
2 units to the 4th stone, then 3 units to the 6th stone, 
4 units to the 7th stone, and 5 units to the 8th stone.

Example 2:

[0,1,2,3,4,8,9,11]

Return false. There is no way to jump to the last stone as 
the gap between the 5th and 6th stone is too large.

https://www.cnblogs.com/ilovezyg/p/6901280.html
*/

/*

i and j is the unit number

               dp[i][k-1]    
dp[j][k] =     dp[i][k]
               dp[i][k+1]

dp[current stone][ step size]
*/


#include <iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;


class Solution
{
public:
	bool canCross(vector<int> &stones)
	{
		unordered_map<long long, unordered_set<long long> > dp;
		
		for (int i = 2; i < stones.size(); ++i)
		{
			dp[stones[i]] = unordered_set<long long>();
		}

		dp[0].insert(0);
		dp[1].insert(1);

		for (int i = 1; i < stones.size(); ++i)
		{
			unordered_set<long long>& dict = dp[stones[i]];
			for (auto it = dict.begin(); it != dict.end(); ++it)
			{
				if (dp.end() != dp.find(stones[i] + (*it)))
				{
					dp[stones[i] + (*it)].insert(*it);
				}
				if (dp.end() != dp.find(stones[i] + (*it) + 1))
				{
					dp[stones[i] + (*it)+1].insert(*it+1);
				}
				if ((*it)>1 && dp.end() != dp.find(stones[i] + (*it) - 1))
				{
					dp[stones[i] + (*it) - 1].insert(*it - 1);
				}
			}
		}

		
		bool bReach = false;
		if (!dp[*stones.rbegin()].empty())
		{
			bReach = true;
		}
		return bReach;
	}
};


int main()
{
	Solution sol;
	vector<int> s1{0, 1, 3, 4, 5, 7, 9, 10, 12};

	cout << sol.canCross(s1) << endl;

	vector<int> s2{ 0, 1, 2, 3, 4, 8, 9, 11 };
	
	cout << sol.canCross(s2) << endl;

	return 0;

}