/*
Longest subarray having average greater than or equal to x
https://www.geeksforgeeks.org/longest-subarray-having-average-greater-than-or-equal-to-x/

Given an array of integers and an integer x. Find length of maximum size subarray having average of
integers greater than or equal to x.

Examples:

Input : arr[] = {-2, 1, 6, -3}, x = 3
Output : 2
Longest subarray is {1, 6} having average
3.5 greater than x = 3.

Input : arr[] = {2, -3, 3, 2, 1}, x = 2
Output : 3
Longest subarray is {3, 2, 1} having
average 2 equal to x = 2.

*/

/*

this can be solved in O(n^3) algorithm definitely.
Or use O(n) space to O(n^2) algorithm.

*/

#include <iostream>
#include <vector>
using namespace std;

int longestSubarrayAvg(vector<int>& a, int X)
{
	int ret = 0;
	vector<int> vsum(a.size(), 0);
	int sum = 0;
	for (int i = 0; i < a.size(); ++i)
	{
		sum += a[i];
		vsum[i] = sum;
	}
	//Now, lets traverse the sum array using range window

	int maxlen = 0;

	for (int i = 0; i < a.size(); ++i)
	{
		for (int j = i; j < a.size(); ++j)
		{
			float fAvg = 0;
			float fsum = 0;
			if (i == 0)
			{
				fsum = (float)vsum[j];
			}
			else
			{
				fsum = float(vsum[j] - vsum[i - 1]);
			}
			fAvg = fsum / (j - i + 1);
			if (fAvg >= X && maxlen < (j - i + 1))
			{
				maxlen = (j - i + 1);
			}
		}
	}

	cout << maxlen << endl;

	return ret;
}


int main(int argc, char const *argv[])
{
	vector<int> a{ -2, 1, 6, -3 };
	int X = 3;
	longestSubarrayAvg(a, X);

	vector<int> b{ 2, -3, 3, 2, 1 };
	X = 2;
	longestSubarrayAvg(b, X);
	return 0;
}
