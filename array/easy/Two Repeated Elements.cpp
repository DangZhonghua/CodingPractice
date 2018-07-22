/*
Two Repeated Elements
https://practice.geeksforgeeks.org/problems/two-repeated-elements/0/?ref=self
https://www.geeksforgeeks.org/?p=7953/comment-page-1#comment-1300

You are given an array of N+2 integer elements. All elements of the array are in range 1 to N.
And all elements occur once except two numbers which occur twice. Find the two repeating numbers.

Input:
The first line of the input contains an integer T, denoting the total number of test cases.
Then T test cases follow Each test case consists of two lines. First line of each test case
contains an integer N denoting the range of numbers to be inserted in array of size N+2.
Second line of each test case contains the N+2 space separated integers denoting the array elements.

Output:
Print the two elements occuring twice in the array. Order of the two elements must be preserved as
in the original list, i.e., print the element which arrives first(2nd time).

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

int CountSort_FindRepeatedElements(int*a, vector<int>& vr, int N)
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

int XOR_FindTwoRepeatedElements(int*a, int size)
{
	//Suppose the two repeated elements are x and y as follow
	int x = 0;
	int y = 0;
	int xora = 0;
	//to use xor, we need to get x xor y first.

	for (int i = 0; i<size; ++i)
	{
		xora ^= a[i];
	}
	//Up to now, x and y are xor out the xora
	//According to the problem description

	for (int i = 1; i <= size - 2; ++i)
	{
		xora ^= i;
	}

	//Now we get the xor since the x and y is odd times by above 1... size-2
	int last_diff = xora &(~(xora - 1));

	for (int i = 0; i<size; ++i)
	{
		if (last_diff & a[i])
		{
			x ^= a[i];
		}
		else
		{
			y ^= a[i];
		}
	}
	// Now x is out from the x^a[i]

	for (int i = 1; i <= size - 2; ++i)
	{
		if (last_diff & i)
		{
			x ^= i;
		}
		else
		{
			y ^= i;
		}
	}

	int xcount = 0;
	int ycount = 0;
	
	for(int i = 0; i<size; ++i)
	{
		if(x == a[i])
		{
			++xcount;
			if(2 == xcount)
			{
				break;
			}
		}
		else if(y == a[i])
		{
			++ycount;
			if(2 == ycount)
			{
				break;
			}
		}

	}
	if (2 == xcount)
	{
		cout << x << " " << y << endl;
	}
	else
	{
		cout << y << " " << x << endl;
	}
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
		XOR_FindTwoRepeatedElements(a, N + 2);
	}

	return 0;
}