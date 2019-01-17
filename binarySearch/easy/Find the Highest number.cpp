/*
https://practice.geeksforgeeks.org/problems/find-the-highest-number/0/?ref=self
Find the Highest number

Given an array in such a way that the elements stored in array are in increasing order initially and
then after reaching to a peak element , elements stored are in decreasing order. Find the highest element.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case consists of an integer n. The next line consists of n spaced integers.

Output:
Print the highest number in the array.

Constraints:
1<=T<=100
1<=n<=200
1<=a[i]<=10^5

Example:
Input:
2
11
1 2 3 4 5 6 5 4 3 2 1
5
1 2 3 4 5

Output:
6
5

*/

#include<iostream>
#include<vector>
using namespace std;


int FindLargest(vector<int>& a)
{
	int ret = 0;
	int l = 0;
	int m = 0;
	int s = 0;
	int e = a.size() - 1;



	while (s <= e)
	{
		m = (s + e) / 2;
		if (a[m] >= a[e])
		{
			e = m;
			if (l == a[m])
			{
				break;
			}
			else
			{
				l = a[m];
			}
		}
		else if (a[m] < a[e])
		{
			s = m + 1;
		}
	}

	cout << a[e] << endl;
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
		FindLargest(a);
	}

	return 0;
}
