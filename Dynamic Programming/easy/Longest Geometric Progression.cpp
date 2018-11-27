/*
Longest Geometric Progression
https://practice.geeksforgeeks.org/problems/longest-geometric-progression/0

Given a set of numbers, find the Length of the Longest Geometrix Progression (LLGP) in it. The common ratio of GP must be an integer.

Input:



The first line of input contains an integer T denoting the number of test cases. Then T test cases follow.
The first line of each test case contains an integer N denoting the size array A representing the set of numbers
The second line of each test case contains N space separated integers denoting elements of the array A[ ].

Output:

Print the length of the longest geometric progression for each test case in a new line.

Constraints:

1<= T <=100

1<= N <=1000

1<= A[ ] <=10000


Example:

Input:
6
5 7 15 10 20 29
Output:
3

*/

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int LongestGP(vector<int>& a)
{
	int ret = 0;
	int maxval = INT_MIN;
	int minval = INT_MAX;
	int maxlen = 1;
	for (int e : a)
	{
		maxval = maxval > e ? maxval : e;
		minval = minval > e ? e : minval;
	}
	int maxGP = maxval / minval;
	int maxf = 1;
	int maxi = 0;
	std::sort(a.begin(), a.end());

	vector< vector<int> > vgp(a.size(), vector<int>(maxGP + 1, 1));

	for (int i = 1; i < a.size(); ++i)
	{
		for (int j = 0; j<i; ++j)
		{
			if (a[i]>=a[j] && 0 == a[i] % a[j])
			{
				int f = a[i] / a[j];
				int curlen = vgp[j][f] + 1;
				if (vgp[i][f] <= curlen)
				{
					vgp[i][f] = curlen;
				}
				if (vgp[i][f] > maxlen)
				{
					maxlen = vgp[i][f];
					maxf = f;
					maxi = i;
				}
			}
		}
	}

	cout << maxlen << endl;

	return ret;
}


int main(int argc, char const *argv[])
{
	int t = 0;

	cin >> t;

	while (t--)
	{
		int N = 0;
		cin >> N;
		vector<int> a(N, 0);
		int i = 0;
		while (i < N)
		{
			cin >> a[i];
			++i;
		}
		LongestGP(a);
	}


	return 0;
}
