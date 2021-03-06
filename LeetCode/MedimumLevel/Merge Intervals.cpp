/*
https://leetcode-cn.com/problems/merge-intervals/
Merge Intervals

Given a collection of intervals, merge all overlapping intervals.
Example 1:
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

*/

/*
This can be solved by interval tree.

[[2,3],[4,5],[6,7],[8,9],[1,10]]
[[4,5],[6,7],[8,9]]
[[1,10]]
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */




#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};






class Solution 
{
public:
	struct CompareInterval
	{

		bool operator ()(const Interval& lhs, const Interval& rhs) const
		{
			if (lhs.end < rhs.start)
			{
				return true;
			}
			return false;
		}

	};

public:
	vector<Interval> merge(vector<Interval>& intervals)
	{
		set<Interval, CompareInterval> is;
		int i = 0;
		while( i <intervals.size())
		{
			auto it = is.find(intervals[i]);
			if (is.end() == it)
			{
				is.insert(intervals[i]);
				++i;
			}
			else
			{
				int start = it->start < intervals[i].start ? it->start : intervals[i].start;
				int end   = it->end < intervals[i].end ? intervals[i].end : it->end;
				Interval a(start, end);
				is.erase(it);
				if (is.insert(a).second) //this is important since the new generated interval may be overlapped some within the set.
				{
					++i;
				}
				else
				{
					intervals[i] = a;
				}	
			}
		}

		vector<Interval> vi;
		for (auto it = is.begin(); it != is.end(); ++it)
		{
			vi.push_back(*it);
		}
		return vi;
	}
};


int main()
{
	vector<Interval> intervals{ {2,3 }, { 4,5 }, { 6,7 }, { 8,9 }, { 1,10 }};
	Solution sol;
	sol.merge(intervals);


	return 0;
}