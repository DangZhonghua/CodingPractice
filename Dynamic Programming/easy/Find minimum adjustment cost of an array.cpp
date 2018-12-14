/*

Find minimum adjustment cost of an array
https://practice.geeksforgeeks.org/problems/find-minimum-adjustment-cost-of-an-array/0
https://www.geeksforgeeks.org/find-minimum-adjustment-cost-of-an-array/


Given an array of positive integers, replace each element in the array such that the difference
between adjacent elements in the array is less than or equal to a given target. We need to minimize the adjustment cost,
that is the sum of differences between new and old values.
We basically need to minimize ∑|A[i] – Anew[i]| where 0 <= i <= n-1, n is size of A[] and Anew[]
is the array with adjacent difference less that or equal to target.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow.
The first line of each test case contains two integers N and K where N denotes the size of array A and K is the target.

The second line of each test case contains N space separated integers denoting elements of the array A[ ].

Output:

Print the minimum adjustment cost for each test case in a new line.

Constraints:
1<= T <=100
1<= N, K <=1000
1<= A[ ] <=100


Example:

Input:
4 1
1 3 0 3
Output:
3

*/

/*
optimal substructure and overlapped problem
1. optimal substructure:  subarray solution is contained in the origin solution.
2. overlapped subproblem: the min-cost end at every possible value.
*/

/*

mdc[i][j] = min { mdc[i-1][k] + abs(j-a[i])} for abs(j-k)<X(target)
mdc[0][j] = 0;

*/


#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int absoulate(int x)
{
	return x > 0 ? x : -x;
}

int MinimumAdjustCost(vector<int>& a, int target)
{
	int ret = 0;
	int len = a.size() + 1;
	int max = a[0];
	int mincost = INT_MAX;
	for (auto e : a)
	{
		if (max < e)
		{
			max = e;
		}
	}

	vector< vector<int> > mdc(len, vector<int>(max + 1, INT_MAX));

	for (int i = 0; i < max + 1; ++i)
	{
		mdc[0][i] = 0;
	}

	for (int i = 1; i <= a.size(); ++i) //This is mdc matrix row loop.
	{
		for (int v = 1; v <= max; ++v) // this is Anew[i]
		{
			for (int k = 1; k <= max; ++k)
			{
				
				if (absoulate(v - k) <= target) // difference between adjacent elements
				{
					if (mdc[i][v] > mdc[i - 1][k] + absoulate(a[i - 1] - v))
					{
						mdc[i][v] = mdc[i - 1][k] + absoulate(a[i - 1] - v);
					}
				}		
			}
		}
	}

	for (int k = 1; k <= max; ++k)
	{
		if (mincost > mdc[a.size()][k])
		{
			mincost = mdc[a.size()][k];
		}
	}
	cout << mincost << endl;

	return ret;
}




int main1(int argc, char const *argv[])
{
	vector<int> a{ 1, 3, 0, 3 };
	int x = 1;
	MinimumAdjustCost(a, x);

	vector<int>  b{ 55, 77, 52, 61, 39, 6, 25, 60, 49, 47 };
	x = 10;
	MinimumAdjustCost(b, x);

	return 0;
}

int main()
{
    int t = 0;
    
    cin>>t;
    
    while(t--)
    {
        int N = 0;
        int x = 0;
        cin>>N>>x;
        int i = 0;
        vector<int> a(N,0);
        while(i<N)
        {
            cin>>a[i];
            ++i;
        }
        MinimumAdjustCost(a,x);
        
    }

    return 0;
}
