/*
https://leetcode-cn.com/problems/triangle/
Triangle

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
For example, given the following triangle
[
	 [2],
	[3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;


class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle)
	{
		long long minv = LLONG_MAX;
		vector<  vector<long long > >  dp(2, vector<long long>(triangle.size() + 1, LLONG_MAX));
		dp[0][0] = triangle[0][0];
		minv = triangle[0][0];

		for (int i = 1; i < triangle.size(); ++i)
		{
			minv = LLONG_MAX;
			for (int j = 0; j < triangle[i].size(); ++j)
			{
				dp[i & 1][j] = LLONG_MAX;  // pay attention this: re-initialize
				if (j - 1 >= 0)
				{
					if (dp[i & 1][j] > dp[(i - 1) & 1][j - 1] + triangle[i][j])
					{
						dp[i & 1][j] = dp[(i - 1) & 1][j - 1] + triangle[i][j];
					}
				}

				if (j <= i - 1)
				{
					if (dp[i & 1][j] > dp[(i - 1) & 1][j] + triangle[i][j])
					{
						dp[i & 1][j] = dp[(i - 1) & 1][j] + triangle[i][j];
					}
				}

				if (dp[i & 1][j] < minv)
				{
					minv = dp[i & 1][j];
				}
			}
		}

		return minv;
	}
};

int main()
{
	Solution sol;
	vector< vector<int> > t1{ {2},{3, 4},{6, 5, 7},{4, 1, 8, 3} };

	cout<<sol.minimumTotal(t1) << endl;

	return 0;
}