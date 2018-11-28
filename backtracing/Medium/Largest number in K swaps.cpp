/*
Largest number in K swaps
https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps/0
https://www.geeksforgeeks.org/find-maximum-number-possible-by-doing-at-most-k-swaps/


Given a number K and string S of digits denoting a positive integer,
build the largest number possible by performing swap operations on the digits of S atmost K times.

Input
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow.
The first line of each test case contains a positive integer K.
The second line of each test case contains a string of digits denoting a positive integer.


Output
Print out the largest number possible.


Constraints
1 <= T <= 100
0 <   S <= 30
0 <   K  <= 10

Examples

Input
3
4
1234567
3
3435335
2
1034

Output
7654321
5543333
4301

*/
#include<string>
#include<iostream>
using namespace std;

void swapChar(char& x, char& y)
{
	char c = x;
	x = y;
	y = c;
}

void btSwap(string& x, int K, int start, string& strMax)
{
	if (0 == K)
	{
		return;
	}

	int len = x.length();
	for (int i = start; i < len; ++i)
	{
		for (int j = i + 1; j < len; ++j)
		{
			if (x[i] < x[j]) // this is the possibility of making "number" larger.
			{
				swapChar(x[i], x[j]);
				if (x.compare(strMax) > 0)
				{
					strMax = x;
				}
				btSwap(x, K - 1, start + 1, strMax);
				swapChar(x[i], x[j]); // this is backtrace
			}
		}
	}

}

int MaximumValueBySwap(string& x, int K)
{
	int ret = 0;
	string strMax;
	strMax = x; //for no swap occuring.
	btSwap(x, K, 0, strMax);
	cout << strMax << endl;

	return ret;
}

int main(int argc, char const *argv[])
{
	int t = 0;
	cin >> t;

	while (t--)
	{
		int K = 0;
		cin >> K;
		string x;
		cin >> x;
		MaximumValueBySwap(x, K);
	}
	return 0;
}
