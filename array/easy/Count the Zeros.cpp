/*
Count the Zeros 
https://practice.geeksforgeeks.org/problems/count-the-zeros/0/?ref=self

Given an array of size N consisting of only 0's and 1's ,which is sorted in such a manner that all the 1's are placed first and then they are followed by all the 0's. You have to find  the count of all the 0's.
 

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
The first line of each test case contains an integer N, where N is the size of the array A[ ].
The second line of each test case contains N space separated integers of all 1's follwed by all the 0's, denoting elements of the array A[ ].


Output:
Print out the number of 0's in the array. 
 

Constraints:
1 <= T <= 100
1 <= N <= 30
0 <= A[i] <= 1
 

Example :

Input:
3
12
1 1 1 1 1 1 1 1 1 0 0 0 
5
0 0 0 0 0
6
1 1 1 1 1 1


Output:
3
5
0
 

Expected Complexity:

O(logN)

*/

/*

This is 

*/

#include<iostream>
#include<vector>
using namespace std;

int CountZero(vector<int>& a)
{
	int s = 0;
	int e = a.size() - 1;
	int m = 0;
	int index = -1;
	int count = 0;

	while (s <= e)
	{
		m = (s + e) / 2;
		if (1 == a[m])
		{
			// the last 1 in second half
			s = m;
			if (m + 1 < a.size() && 1 == a[m + 1])
			{
				s = m+1;
			}
			else
			{
				break;
			}
		}
		else
		{
			//the last 1 in first half.
			e = m - 1;
		}
	}

	if (-1 == e)
	{
		count = a.size();
	}
	else
	{
		count = a.size() - (s + 1);
	}
	

	cout << count << endl;


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
		vector<int> a(N, 0);
		int i = 0;
		while (i < N)
		{
			int d = 0;
			cin >> d;
			a[i++] = d;
		}
		CountZero(a);
	}
	return 0;
}
