/*
Highway Billboard Problem
https://www.geeksforgeeks.org/highway-billboard-problem/

Consider a highway of M miles. The task is to place billboards on the highway such that revenue is maximized.
The possible sites for billboards are given by number x1 < x2 < ….. < xn-1 < xn,
specifying positions in miles measured from one end of the road. If we place a billboard at position xi,
we receive a revenue of ri > 0.
There is a restriction that no two billboards can be placed within t miles or less than it.

Note : All possible sites from x1 to xn are in range from 0 to M as need to
place billboards on a highway of M miles.

Examples:

Input : M = 20
x[]       = {6, 7, 12, 13, 14}
revenue[] = {5, 6, 5,  3,  1}
t = 5
Output: 10
By placing two billboards at 6 miles and 12
miles will produce the maximum revenue of 10.

Input : M = 15
x[] = {6, 9, 12, 14}
revenue[] = {5, 6, 3, 7}
t = 2
Output : 18

*/

#include <iostream>
#include <vector>
using namespace std;

/*
The following is O(n^2) method

*/

int HighwayBillboard(int *a, int *p, int N, int M, int D)
{
	int max = 0;
	vector<int> vb(N, 0);
	for (int i = 0; i < N; ++i)
	{
		vb[i] = p[i];
		if (max < p[i])
		{
			max = p[i];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (a[i] > a[j] + D && vb[i] < vb[j] + p[i])
			{
				vb[i] = vb[j] + p[i];
			}
		}
		if (max < vb[i])
		{
			max = vb[i];
		}
	}

	cout << max << endl;

	return 0;
}

//This is O(n) method
int HighwayBillboardV2(int *a, int *p, int N, int M, int D)
{
	vector<int> vp(M + 1, 0);
	int pos = 0;
	for (int i = 1; i <= M; ++i)
	{
		if (pos < N)
		{
			if (i != a[pos]) // there is no billboard for current position i
			{
				vp[i] = vp[i - 1];
			}
			else
			{
				if (i <= D)
				{
					vp[i] = p[pos];
				}
				else
				{
					vp[i] = vp[i - 1];
					if (vp[i - D - 1] + p[pos] > vp[i])
					{
						vp[i] = vp[i - D - 1] + p[pos];
					}
				}
				++pos;
			}
		}
		else
		{
			vp[i] = vp[i - 1];
		}
	}
	cout << vp[M]<<endl;

	return 0;
}

int main()
{
	int M = 20;
	int x[] = { 6, 7, 12, 13, 14 };
	int revenue[] = { 5, 6, 5, 3, 1 };
	int t = 5;

	HighwayBillboardV2(x, revenue, sizeof(x) / sizeof(x[0]), M, 5);

	return 0;
}