/*
Partition of a set into K subsets with equal sum
https://www.geeksforgeeks.org/partition-set-k-subsets-equal-sum/

Given an integer array of N elements, the task is to divide this array into K non-empty
subsets such that the sum of elements in every subset is same.
All elements of this array should be part of exactly one partition.
Examples:

Input : arr = [2, 1, 4, 5, 6], K = 3
Output : Yes
we can divide above array into 3 parts with equal
sum as [[2, 4], [1, 5], [6]]

Input  : arr = [2, 1, 5, 5, 6], K = 3
Output : No
It is not possible to divide above array into 3
parts with equal sum

*/

/*

this can be sloved by dp as knapsack problem .
Or
Backtracking technique: this is multi-level backtracking problem.

*/

#include<iostream>
#include<vector>
using namespace std;


bool btPartitionKthPackage(vector<int>&a, vector<int>& flag, vector<int>& vsum, int targetsum, int k)
{
	if (vsum[k] == targetsum)
	{
		return true;
	}

	for (int i = 0; i < a.size(); ++i)
	{
		if (flag[i])
		{
			continue;
		}

		vsum[k] += a[i];
		flag[i] = 1;
		if (btPartitionKthPackage(a, flag, vsum, targetsum, k))
		{
			return true;
		}
		//backtrack, skip current item and try the next item.
		vsum[k] -= a[i];
		flag[i] = 0;
	}

	return false;
}

bool btPartitionK(vector<int>&a, vector<int>& flag, vector<int>& vsum, int targetsum, int K)
{
	bool bPartition = true;
	//in this function, we backtrack by K.
	for (int i = 0; i < K; ++i)
	{
		if (!btPartitionKthPackage(a, flag, vsum, targetsum, i))
		{
			bPartition = false;
			break;
		}
	}
	return bPartition;
}

int PartitionIntoK(vector<int>& a, int K)
{
	int sum = 0;
	for (auto v : a)
	{
		sum += v;
	}
	sum /= K;

	vector<int> vflag(a.size(), 0);
	vector<int> vsum(K, 0);

	cout << btPartitionK(a, vflag, vsum, sum, K) << endl;

	return 0;
}

int main(int argc, char const *argv[])
{
	vector<int> a{ 2, 1, 4, 5, 6 };
	int K = 3;

	PartitionIntoK(a, K);

	vector<int> b{ 2, 1, 5, 5, 6 };
	
	PartitionIntoK(b,K);

	return 0;
}
