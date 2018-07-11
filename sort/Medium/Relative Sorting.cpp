/*
Relative Sorting
https://practice.geeksforgeeks.org/problems/relative-sorting/0/?ref=self
Given two array A1[] and A2[], sort A1 in such a way that the relative order among the elements will be same as those  in A2.
For the elements not present in A2. Append them at last in sorted order. It is also given that the number of elements in A2[]
are smaller than or equal to number of elements in A1[] and A2[] has all distinct elements.

Input: A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}
A2[] = {2, 1, 8, 3}
Output: A1[] = {2, 2, 1, 1, 8, 8, 3, 5, 6, 7, 9}

Since 2 is present first in A2[], all occurrences of 2s should appear first in A[],
then all occurrences 1s as 1 comes after 2 in A[]. Next all occurrences of 8 and then all occurrences of 3.
Finally we print all those elements of A1[] that are not present in A2[]


Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is M and N.  M is the number of elements in A1 and N is the number of elements in A2.
The second line of each test case contains M elements. The third line of each test case contains N elements.

Output:

Print the sorted array according order defined by another array.

Constraints:

1 ≤ T ≤ 50
1 ≤ M ≤ 50
1 ≤ N ≤ 10 & N ≤ M
1 ≤ A1[i], A2[i] ≤ 1000

Example:

Input:
1
11 4
2 1 2 5 7 1 9 3 6 8 8
2 1 8 3

Output:
2 2 1 1 8 8 3 5 6 7 9


*/

#include<iostream>
#include<algorithm>
using namespace std;

struct RelativeCom
{
	static int* dict;
	bool operator() (int lhs, int rhs) const
	{
		if (-1 != dict[lhs] && -1 != dict[rhs])
		{
			return dict[lhs]<dict[rhs];
		}
		else if (-1 != dict[lhs] && -1 == dict[rhs])
		{
			return true;
		}
		else if (-1 == dict[lhs] && -1 != dict[rhs])
		{
			return false;
		}
		else
		{
			return lhs<rhs;
		}
	}

};
int* RelativeCom::dict = NULL;

int RelativeSort(int*a, int*b, int m, int n)
{
	int dict[1001];
	for (int i = 0; i <= 1000; ++i)
	{
		dict[i] = -1;
	}

	for (int i = 0; i<n; ++i)
	{
		dict[b[i]] = i;
	}

	RelativeCom::dict = dict;
	RelativeCom relcom;

	std::stable_sort(a, a + m, relcom);

	for (int i = 0; i<m; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}



int main()
{
	int a[100];
	int b[100];
	int t = 0;
	int M = 0;
	int N = 0;

	cin >> t;

	while (t--)
	{
		cin >> M >> N;
		int i = 0;
		while (i<M)
		{
			cin >> a[i++];
		}
		i = 0;
		while (i<N)
		{
			cin >> b[i++];
		}
		RelativeSort(a, b, M, N);
	}


	return 0;
}