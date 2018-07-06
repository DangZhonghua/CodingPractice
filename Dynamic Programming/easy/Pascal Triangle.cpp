/*
Pascal Triangle
https://practice.geeksforgeeks.org/problems/pascal-triangle/0

Given an integer K,return the kth row of pascal triangle.
Pascal's triangle is a triangular array of the binomial coefficients formed by summing up the elements of previous row.

Example of pascal triangle:
1
1 1
1 2 1
1 3 3 1

for K=3, return 3rd row i.e 1 2 1


Input:

The first line contains an integer T,depicting total number of test cases.
Then following T lines contains an integer N depicting the row of triangle to be printed.


Output:

Print the Nth row of triangle in a separate line.


Constraints:

1 ≤ T ≤ 50
1 ≤ N ≤ 25


Example:

Input
1
4
Output
1 3 3 1

*/

/*
this is dynamic programming problem.

pt[i][j] = pt[i-1][j-1] + pt[i-1][j] j-1>=0 && j< level[i-1] element count.

*/

#include<iostream>
#include<vector>
using namespace std;

int pascalTriangle(int N)
{
	vector<int> vcur(N + 1, 0);
	vector<int> vnext(N + 1, 0);

	vector<int>* rcur = &vcur;
	vector<int>* rnext = &vnext;

	vcur[0] = 1;

	for (int i = 1; i<N; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			(*rnext)[j] = 0;
			if (j - 1 >= 0)
			{
				(*rnext)[j] += (*rcur)[j - 1];
			}
			if (j <= i - 1)
			{
				(*rnext)[j] += (*rcur)[j];
			}
		}
		vector<int>* t = rcur;
		rcur = rnext;
		rnext = t;
	}

	for (int i = 0; i<N; ++i)
	{
		cout << (*rcur)[i] << " ";
	}
	cout << endl;



	return 0;
}

int main()
{
	int t = 0;
	int N = 0;

	cin >> t;

	while (t--)
	{
		cin >> N;
		pascalTriangle(N);
	}

	return 0;
}



