/*
https://www.geeksforgeeks.org/maximum-subarray-sum-array-created-repeated-concatenation/
Maximum subarray sum in an array created after repeated concatenation

Given an array and a number k, find the largest sum of contiguous array
in the modified array which is formed by repeating the given array k times.

Examples :

Input  : arr[] = {-1, 10, 20}, k = 2
Output : 59
After concatenating array twice, we
get {-1, 10, 20, -1, 10, 20} which has
maximum subarray sum as 59.

Input  : arr[] = {-1, -2, -3}, k = 3
Output : -1

*/

#include<iostream>
#include<vector>
using namespace std;

int MaximumSumbyRepeating(vector<int>& a, int K)
{
	int u = a.size();
	int l = K*a.size();
	int max_end_current = a[0];
	int max_so_far = a[0];

	for (int i = 1; i<l; ++i)
	{
		if (max_end_current>0)
		{
			max_end_current += a[i%u];
		}
		else
		{
			max_end_current = a[i%u];
		}

		if (max_end_current>max_so_far)
		{
			max_so_far = max_end_current;
		}
	}
	cout << max_so_far << endl;

	return 0;
}

int main(int argc, char const *argv[])
{
	vector<int> a{ -1, 10, 20 };
	int K = 3;
	MaximumSumbyRepeating(a, K);

	vector<int> b{ -1, -2, -3 };
	MaximumSumbyRepeating(b, K);
	return 0;
}
