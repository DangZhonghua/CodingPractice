/*
Two Repeated Elements
https://practice.geeksforgeeks.org/problems/two-repeated-elements/0/?ref=self

You are given an array of N+2 integer elements. All elements of the array are in range 1 to N. And all elements occur once except two numbers which occur twice. Find the two repeating numbers.

Input:
The first line of the input contains an integer T, denoting the total number of test cases. Then T test cases follow Each test case consists of two lines. First line of each test case contains an integer N denoting the range of numbers to be inserted in array of size N+2. Second line of each test case contains the N+2 space separated integers denoting the array elements.

Output: 
Print the two elements occuring twice in the array. Order of the two elements must be preserved as in the original list, i.e., print the element which arrives first(2nd time).

Constraints: 
1 ≤ T ≤ 30
1 ≤ N ≤ 100

Example:

INPUT
1
4
1 2 1 3 4 3
OUTPUT
1 3

*/

#include<vector>
#include<iostream>
using namespace std;

int FindRepeatedElements(int*a, vector<int>& vr, int N)
{
	int xorv = 0;
	int c[101] = { 0 };

	for (int i = 0; i<N; ++i)
	{
		c[a[i]]++;
		if (2 == c[a[i]])
		{
			vr.push_back(a[i]);
		}
	}


	for (int i = 0; i< vr.size(); ++i)
	{
		cout << vr[i] << " ";
	}
	cout << endl;
	return 0;
}



int main()
{
	int t = 0;
	int a[101] = { 0 };
	int N = 0;

	cin >> t;

	while (t>0)
	{
		--t;
		cin >> N;
		int i = 0;
		while (i<N + 2)
		{
			cin >> a[i++];
		}
		vector<int> vr;
		FindRepeatedElements(a, vr, N + 2);
	}

	return 0;
}