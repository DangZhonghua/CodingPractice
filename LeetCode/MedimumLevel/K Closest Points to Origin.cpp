/*
https://leetcode-cn.com/problems/k-closest-points-to-origin/
973. K Closest Points to Origin

We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

 

Example 1:

Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)
 

Note:

1 <= K <= points.length <= 10000
-10000 < points[i][0] < 10000
-10000 < points[i][1] < 10000
*/

/*

order statistic

*/

#include<vector>
#include<iostream>
using namespace std;


#include<vector>
#include<iostream>
using namespace std;


class Solution
{
	struct sd
	{
		int d{ 0 };
		int index{ 0 };
	};
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K)
	{

		vector<sd> vd(points.size(), sd());
		for (int i = 0; i < points.size(); ++i)
		{
			vd[i].index = i;
			vd[i].d = points[i][0] * points[i][0] + points[i][1] * points[i][1];
		}

		vector<vector<int>> vr;
		//int p = -1;
		int p = SelectSmallestK(vd, 0, points.size() - 1, K);

		for (int i = 0; i <= p; ++i)
		{
			vr.push_back(points[vd[i].index]);
		}

		return vr;

	}

	int SelectSmallestK(vector<sd>& vd, int s, int e, int K)
	{
		int p = 0;
		while (K)
		{
			p = OS_Select(vd, s, e);
			if ((p - s + 1) < K)
			{
				K -= (p - s + 1);
				s = (p + 1);
			}
			else if (p - s + 1 == K)
			{
				break;
			}
			else
			{
				e = p - 1;
			}
		}
		return p;
	}

	int OS_Select(vector<sd>& vd, int s, int e)
	{
		int i = s - 1;
		sd pivot = vd[e];

		for (int j = s; j < e; ++j)
		{
			if (vd[j].d < pivot.d)
			{
				++i;
				sd t = vd[j];
				vd[j] = vd[i];
				vd[i] = t;
			}
		}
		++i;
		sd t = vd[i];
		vd[i] = pivot;
		vd[e] = t;

		return i;
	}
};

int main()
{
	Solution sol;
	int K = 1;
	vector< vector<int> > a{ {1,3},{-2,2} };
	sol.kClosest(a, K);

	return 0;

}