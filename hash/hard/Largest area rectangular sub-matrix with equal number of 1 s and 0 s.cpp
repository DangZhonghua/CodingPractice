/*
https://www.geeksforgeeks.org/largest-area-rectangular-sub-matrix-equal-number-1s-0s/
Largest area rectangular sub-matrix with equal number of 1’s and 0’s

Given a binary matrix. The problem is to find the largest area
rectangular sub-matrix with equal number of 1’s and 0’s.

Examples:

Input : mat[][] = { {0, 0, 1, 1},
{0, 1, 1, 0},
{1, 1, 1, 0},
{1, 0, 0, 1} }
Output : 8 sq. units
(Top, left): (0, 0)
(Bottom, right): (3, 1)

Input : mat[][] = { {0, 0, 1, 1},
{0, 1, 1, 1} }
Output : 6 sq. units


*/

/*

Consider 0 as -1, then this problem is the same as find largest rectangular which sum = 0

*/




#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


int longestSubarrayWithZeroSum(vector<int>&a, int& maxlen, int& start, int& end)
{
	unordered_map<int, int> sumdict;
	int sum = 0;
	start = 0;
	maxlen = 0;
	for (auto i = 0; i<a.size(); ++i)
	{
		sum += a[i];
		if (0 == sum && maxlen < (i + 1))
		{
			maxlen = (i + 1);
			start = 0;
			end = i;
		}
		else
		{
			auto it = sumdict.find(sum);
			if (sumdict.end() != it)
			{
				if (maxlen<(i - it->second))
				{
					if (maxlen< (i - it->second))
					{
						maxlen = i - it->second;
						start = it->second + 1;
						end = i;
					}
				}
			}
			else
			{
				sumdict.insert(std::make_pair(i, sum));
			}
		}
	}
	return 0;
}


int LargestRectangle(vector< vector<int> >& m)
{
	int C = m[0].size();
	int R = m.size();

	int max = 0;
	int top = 0;
	int left = 0;
	int bottom = 0;
	int right = 0;


	for (auto leftc = 0; leftc<C; ++leftc)
	{
		vector<int> rowsum(R, 0);
		for (auto rightc = leftc; rightc<C; ++rightc)
		{
			for (auto r = 0; r<R; ++r)
			{
				if (0 == m[r][rightc])
				{
					rowsum[r] += -1;
				}
				else
				{
					rowsum[r] += m[r][rightc];
				}
			}

			int maxlen = 0;
			int start = 0;
			int end = 0;
			longestSubarrayWithZeroSum(rowsum, maxlen, start, end);
			if (max<(rightc-leftc+1)*(end-start+1))
			{
				top = start;
				bottom = end;
				left = leftc;
				right = rightc;
				max = (rightc - leftc + 1)*(end - start + 1);
			}
		}
	}

	cout << max<< " [ " << top << "," << left << " ] [ " << bottom << "," << right << " ]" << endl;


	return 0;
}


int main(int argc, char const *argv[])
{

	vector< vector<int> > m{
		{ 0, 0, 1, 1 },
		{ 0, 1, 1, 0 },
		{ 1, 1, 1, 0 },
		{ 1, 0, 0, 1 }
	};

	LargestRectangle(m);

	return 0;
}
