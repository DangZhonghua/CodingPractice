/*
Overlapping Intervals
https://practice.geeksforgeeks.org/problems/overlapping-intervals/0

Given a collection of Intervals,merge all the overlapping Intervals.
For example:

Given [1,3], [2,6], [8,10], [15,18],

return [1,6], [8,10], [15,18].

Make sure the returned intervals are sorted.

 

Input:

The first line contains an integer T, depicting total number of test cases. 
Then following T lines contains an integer N depicting the number of Intervals and next line followed 
by the intervals starting and ending positions 'x' and 'y' respectively.


Output:

Print the intervals after overlapping in sorted manner.  
There should be a newline at the end of output of every test case.

Constraints:

1 ≤ T ≤ 50
1 ≤ N ≤ 100
0 ≤ x ≤ y ≤ 100


Example:

Input
2
4
1 3 2 4 6 8 9 10
4
6 8 1 9 2 4 4 7

Output
1 4 6 8 9 10
1 9


*/

/*
Sort the interval according to the start point.
Then merge the sorted intervals
*/

#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;

class comparep
{
public:
	bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) const
	{
		if (lhs.first == rhs.first)
		{
			return lhs.second< rhs.second;
		}
		return lhs.first<rhs.first;
	}
};

int mergeIntervals(vector< pair<int, int> >& vi)
{
	std::sort(vi.begin(), vi.end(), comparep());

	int j = 0;
	for (int i = 1; i< vi.size(); ++i)
	{
		if (vi[j].second>= vi[i].first)
		{
			if (vi[j].second < vi[i].second)
			{
				vi[j].second = vi[i].second;
			}
		}
		else
		{
			++j;
			vi[j] = vi[i];
		}
	}

	for (int i = 0; i <= j; ++i)
	{
		cout << vi[i].first << " " << vi[i].second << " ";
	}
	cout << endl;

	return 0;
}

int main()
{
	int t = 0;
	vector< pair<int, int> > vi;
	int N;

	cin >> t;

	while (t--)
	{
		cin >> N;
		int i = 0;
		while (i<N)
		{
			pair<int, int> a;
			cin >> a.first;
			cin >> a.second;
			++i;
			vi.push_back(a);
		}
		mergeIntervals(vi);
		vi.clear();
	}

}