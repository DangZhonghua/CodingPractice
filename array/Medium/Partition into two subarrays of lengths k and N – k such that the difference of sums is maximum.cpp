/*
https://www.geeksforgeeks.org/partition-into-two-subarrays-of-lengths-k-and-n-k-such-that-the-difference-of-sums-is-maximum/
Partition into two subarrays of lengths k and (N – k) such that the difference of sums is maximum

Given an array of non-negative integers of length N and an integer k.
 Partition the given array into two subarrays of length K and N – k
 so that the difference between the sum of both subarray is maximum.

Examples :

Input : arr[] = {8, 4, 5, 2, 10}
		k = 2
Output : 17
Explanation :
Here, we can make first subarray of length k = {4, 2}
and second subarray of length N - k = {8, 5, 10}. Then,
the max_difference = (8 + 5 + 10) - (4 + 2) = 17.

Input : arr[] = {1, 1, 1, 1, 1, 1, 1, 1}
		k = 3
Output : 2
Explanation :
Here, subarrays would be {1, 1, 1, 1, 1} and {1, 1, 1}.
So, max_difference would be 2.

*/

/*

Besides, the method mentioned in the webpage, another method can use order-statisticals.

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
	int MaximumDifference(vector<int>& a, int K)
	{
		 K = min(K, (int)(a.size() - K));
		int p = OS_Select(a, 0, a.size() - 1, K);
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i <= p; ++i)
		{
			sum1 += a[i];
		}
		for (int i = p + 1; i < a.size(); ++i)
		{
			sum2 += a[i];
		}

		return (sum2 - sum1);
	};

private:
	int OS_Select(vector<int>& a, int s, int e, int K)
	{
		int p = 0;
		int count = 0;
		while (1)
		{
			p = Do_Select(a, s, e);
			count = (p - s + 1); //count;
			if (count == K)
			{
				break;
			}
			else if (count < K)
			{
				K = (K - count);
				s = p + 1;
			}
			else
			{
				e = p - 1;
			}
		}
		return p;
	};
	int Do_Select(vector<int>& a, int s, int e)
	{
		int pivot = a[e];
		int i = s - 1;
		int j = s;
		for (j = s; j < e; ++j)
		{
			if (a[j] < pivot)
			{
				++i; // the next i is first that larger than pivot
				swap(a[i], a[j]);
			}
		}
		++i;
		swap(a[i], a[e]);

		return i; // i is the pivot point   
	}

	void swap(int& a, int& b)
	{
		int t = a;
		a = b;
		b = t;
	}
};


int main()
{
	vector<int> a{ 8, 4, 5, 2, 10 };
	Solution sol;
	int K = 2;

	cout << sol.MaximumDifference(a, K) << endl;

	vector<int> b{1, 1, 1, 1, 1, 1, 1, 1};
	K = 3;
	cout << sol.MaximumDifference(b, K) << endl;

	return 0;
}