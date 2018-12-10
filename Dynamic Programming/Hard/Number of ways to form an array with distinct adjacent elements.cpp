/*
Number of ways to form an array with distinct adjacent elements
https://www.geeksforgeeks.org/number-of-ways-to-form-an-array-with-distinct-adjacent-elements/
Given three integers N, M and X, the task is to find the number of ways to form an array,
such that all consecutive numbers of the array are distinct, and the value at any index of the array
from 2 to N – 1(Considering 1 based indexing) lies between 1 and M,
while the value at index 1 is X and the value at index N is 1.
Note: Value of X lies between 1 and M.

Examples:

Input: N = 4, M = 3, X = 2
Output: 3
The following arrays are possible:
1) 2, 1, 2, 1
2) 2, 1, 3, 1
3) 2, 3, 2, 1

Input: N = 2, M = 3, X = 2
Output: 1
The only possible array is: 2, 1

*/

/*

DP: optimal substructure and overlapped subproblem.
or backtracing?

*/

/*

DP[L][v] += DP[L-1][w]  if v != w
DP[1][x] = 1;
*/

#include<iostream>
#include<vector>
using namespace std;

int CountOfFormArray(int N, int M, int X)
{
	int ret = 0;
	vector< vector<int> > DP(N + 1, vector<int>(M + 1, 0));

	DP[1][X] = 1;

	for (int l = 2; l <= N; ++l)
	{
		if (l == N)
		{
			for (int w = 1; w <= M; ++w)
			{
				if (1 != w)
				{
					DP[l][1] += DP[l - 1][w];
				}
			}
			break;
		}

		for (int v = 1; v <= M; ++v)
		{
			for (int w = 1; w <= M; ++w)
			{
				if (v != w)
				{
					DP[l][v] += DP[l - 1][w];
				}
			}	
		}
	}

	cout << DP[N][1] << endl;

	return ret;
}


int main(int argc, char const *argv[])
{
	vector<int> a{ 4, 3, 2 };
	vector<int> b{2,3,2};

	CountOfFormArray(a[0], a[1], a[2]);
	CountOfFormArray(b[0], b[1], b[2]);

	return 0;
}
