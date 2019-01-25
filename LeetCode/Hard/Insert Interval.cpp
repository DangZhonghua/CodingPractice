/*
https://leetcode-cn.com/problems/insert-interval/
Insert Interval

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their start times.
Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) 
    {
        intervals.push_back(newInterval );
        vector<Interval> a;
        merge(intervals,a);
        return a;
    }

private:
    void merge(vector<Interval>& intervals, vector<Interval>& vi)
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
		for (auto it = is.begin(); it != is.end(); ++it)
		{
			vi.push_back(*it);
		}
	}
};