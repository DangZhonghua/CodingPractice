/*

Smallest Positive missing number 
https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number/0/?ref=self
https://www.geeksforgeeks.org/find-the-smallest-positive-number-missing-from-an-unsorted-array/
You are given an unsorted array with both positive and negative elements. 
You have to find the smallest positive number missing from the array in O(n) time using constant extra space.

Input:
First line consists of T test cases. First line of every test case consists of N, 
denoting the number of elements in array. Second line of every test case consists of elements in array.

Output:
Single line output, print the smallest positive number missing.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
5
1 2 3 4 5
5
0 -10 1 3 -20
Output:
6
2

*/

/*

Slide window:[0, INT_MAX], Then scan the array, do intersection with the window

*/

#include<math.h>
#include<iostream>
#include<climits>
using namespace std;

int SegmentNP(int*a, int N)
{
	int i = 0;
	int j = N - 1;

	while (i<j)
	{
		if (a[j] >0 && a[i] <= 0)
		{
			--j;
			++i;
		}
		else if (a[j] <= 0 && a[i]>0)
		{
			int t = a[j];
			a[j] = a[i];
			a[i] = t;
			--j;
			++i;
		}
		else if (a[j] <= 0 && a[i] <= 0)
		{
			++i;
		}
		else if (a[j]>0 && a[i]>0)
		{
			--j;
		}
	}
	
	if (a[j] <= 0)
	{
		++j;
	}

	return j;
}

//Use element as index 
int findMissing(int* a, int N)
{
	for (int i = 0; i < N; ++i)
	{
		if (abs(a[i]) - 1 < N && a[abs(a[i]) - 1] > 0)
		{
			a[abs(a[i]) - 1] = -a[abs(a[i]) - 1];
		}
	}
	int i = 0;
	for (i = 0; i < N; ++i)
	{
		if (a[i]>0)
		{
			break;
		}
	}

	return i+1;
}

int FindMissingPositiveNumber(int*a, int N)
{
	int seg = SegmentNP(a, N);
	int missing = findMissing(a + seg, N - seg);
	cout << missing << endl;

	return 0;
}

int main()
{
	int t = 0;
	int N = 0;
	int a[200];

	cin >> t;

	while (t--)
	{
		cin >> N;
		int i = 0;
		while (i<N)
		{
			cin >> a[i++];
		}
		FindMissingPositiveNumber(a, N);
	}

	return 0;
}