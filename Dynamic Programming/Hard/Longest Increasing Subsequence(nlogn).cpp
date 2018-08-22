/*
Longest Increasing Subsequence
https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0
https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/

Given a sequence, find the length of the longest increasing subsequence from a given sequence .
The longest increasing subsequence means to find a subsequence of a given sequence
in which the subsequence's elements are in sorted order, lowest
to highest, and in which the subsequence is as long as possible.
This subsequence is not necessarily contiguous, or unique.

Note: Duplicate numbers are not counted as increasing subsequence.

For example:
length of LIS for
{ 10, 22, 9, 33, 21, 50, 41, 60, 80 } is 6 and LIS is {10, 22, 33, 50, 60, 80}.



Input:

The first line contains an integer T, depicting total number of test cases.
Then following T lines contains an integer N depicting the size of array and next line followed by the value of array.


Output:

Print the Max length of the subsequence in a separate line.


Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 1000
0 ≤ A[i] ≤ 300

Example:
Input
1
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
Output
6
0 2 6 9 11 15

*/

/*
Store the smallest element at every length.

*/

#include<iostream>
#include<vector>
using namespace std;

int findpos(vector<int>& vls, int target, int N)
{
	int index = -1;
	int s = 0;
	int e = N - 1;

	while (s<=e)
	{
		int m = (s + e) / 2;
		if (vls[m] == target)
		{
			index = m;
			break;
		}
		else if (vls[m] > target)
		{
			e = m - 1;
		}
		else
		{
			s = m + 1;
		}
	}
	if (-1 == index)
	{
		index = s;
	}
	return index;
}

int fastLIS(const vector<int>& a)
{
	int max = 1;
	vector<int> vls(a.size(), 0);

	int nc = 1;
	vls[0] = a[0];


	for (int i = 1; i<a.size(); ++i)
	{
		int index = findpos(vls, a[i], nc);
		if (index == nc)
		{
			vls[nc] = a[i];
			++nc;
			if (nc>max)
			{
				max = nc;
			}
		}
		else if (vls[index] > a[i])
		{
			vls[index] = a[i];
		}
	}

	cout << max << endl;
	return 0;
}

int main(int argc, char const *argv[])
{
	int t = 0;
	int N = 0;
	cin >> t;

	while (t--)
	{
		cin >> N;
		
		if(1 == N)
		{
		    cout<<1<<endl;
		    continue;
		}
		if(0 == N)
		{
		    cout<< 0<<endl;
		    continue;
		}
		vector<int> a(N, 0);
		int i = 0;
		while (i<N)
		{
			int d = 0;
			cin >> d;
			a[i++] = d;
		}
		fastLIS(a);
	}

	//vector<int> a{ 0, 8 ,4 ,12, 2 ,10 ,6 ,14 ,1 ,9 ,5 ,13 ,3 ,11 ,7 ,15 };
	//fastLIS(a);

	return 0;
}
