/*
https://leetcode-cn.com/problems/minimum-cost-for-tickets/
Minimum Cost For Tickets

In a country popular for train travel, you have planned some train travelling one year in advance.
The days of the year that you will travel is given as an array days.  Each day is an integer from 1 to 365.

Train tickets are sold in 3 different ways:

a 1-day pass is sold for costs[0] dollars;
a 7-day pass is sold for costs[1] dollars;
a 30-day pass is sold for costs[2] dollars.

The passes allow that many days of consecutive travel.  For example, if we get a 7-day pass on day 2,
then we can travel for 7 days: day 2, 3, 4, 5, 6, 7, and 8.

Return the minimum number of dollars you need to travel every day in the given list of days.



Example 1:

Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation:
For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total you spent $11 and covered all the days of your travel.

Example 2:

Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation:
For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total you spent $17 and covered all the days of your travel.



Note:0

1 <= days.length <= 365
1 <= days[i] <= 365
days is in strictly increasing order.
costs.length == 3
1 <= costs[i] <= 1000

*/


/*

postfix
dp[i] = min{dp[i+1]+ cost[0], dp[i+7] + cost[1], dp[i+30] + cost[2]}

*/


#include<vector>
#include<iostream>
#include<climits>
using namespace std;

class Solution
{
public:
	int mincostTickets(vector<int>& days, vector<int>& costs)
	{
		vector<int>  mc(366, INT_MAX);

		for (int i = 0; i<days[0]; ++i)
		{
			mc[i] = 0;
		}
		mc[days[0] - 1] = 0;


		for (int i = 0; i<days.size(); ++i)
		{
			if (mc[days[i]] > (mc[days[i]-1] + costs[0]))
			{
				mc[days[i]] = mc[days[i]-1] + costs[0];
			}
			if (i + 1 < days.size())
			{
                // The following is important.
				for (int j = days[i] + 1; j < days[i + 1]; ++j)
				{
					mc[j] = mc[j - 1]; 
				}
			}

			for (int j = 0; j<7; ++j)
			{
				if (days[i] + j<=(*days.rbegin()) && mc[days[i] + j] > mc[days[i]-1] + costs[1])
				{
					mc[days[i] + j] = mc[days[i]-1] + costs[1];
				}
			}

			for (int j = 0; j<30; ++j)
			{
				if (days[i] + j <=(*days.rbegin()) && mc[days[i] + j] > mc[days[i] - 1] + costs[2])
				{
					mc[days[i] + j] = mc[days[i]-1] + costs[2];
				}
			}
		}

		return mc[*days.rbegin()];
	}
};

int main()
{
	Solution sol;
	vector<int>  d1{ 1, 4, 6, 7, 8, 20 };
	vector<int>  c1{ 2, 7, 15 };
	//cout << sol.mincostTickets(d1, c1) << endl;

	vector<int>  d2{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31 };
	vector<int>  c2{ 2, 7, 15 };

	cout << sol.mincostTickets(d2, c2) << endl;

	return 0;

}