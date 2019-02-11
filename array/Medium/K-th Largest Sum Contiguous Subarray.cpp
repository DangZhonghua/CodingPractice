/*
https://www.geeksforgeeks.org/k-th-largest-sum-contiguous-subarray/
K-th Largest Sum Contiguous Subarray
Given an array of integers. Write a program to find the K-th largest sum of contiguous subarray
within the array of numbers which has negative and positive numbers.

Examples:


Input: a[] = {20, -5, -1}
k = 3
Output: -1
Explanation: All sum of contiguous
subarrays are (20, 15, 14, -5, -6, -1)
so the 4th largest sum is -1.

Input: a[] = {10, -10, 20, -40}
k = 6
Output: -10
Explanation: The 6th largest sum among
sum of all contiguous subarrays is -10.

*/

/*

An efficient approach is store the pre-sum of the array in a sum[] array. We can find sum of contiguous subarray from index i to j as sum[j]-sum[i-1]
Now for storing the Kth largest sum, use a min heap (priority queue) in which we push the contiguous sums till we get K elements,
once we have our K elements, check if the element if greater then the Kth element it is inserted to
the min heap with popping out the top element in the min-heap, else not inserted .
At the end the top element in the min-heap will be your answer.

*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;

class Solution
{
public:
	int KthLargestSumSubarray(vector<int>& a, int K)
	{
		priority_queue<int, vector<int>, greater<int> > minHeap;
		vector<int> prefixSum(a.size() + 1, 0);
		int sum = 0;
		
		K += 1;

		for (int i = 0; i<a.size(); ++i)
		{
			sum += a[i];
			prefixSum[i + 1] = sum;

			if (minHeap.size() == K)
			{
				if (a[i]>minHeap.top())
				{
					minHeap.pop();
					minHeap.push(a[i]);
				}
			}
			else
			{
				minHeap.push(a[i]);
			}
		}

		for (int i = 1; i <= a.size(); ++i)
		{
			for (int j = i + 1; j <= a.size(); ++j)
			{
				int subSum = prefixSum[j] - prefixSum[i - 1];
				if (minHeap.size() == K)
				{
					if (minHeap.top()<subSum)
					{
						minHeap.pop();
						minHeap.push(subSum);
					}
				}
				else
				{
					minHeap.push(subSum);
				}
			}
		}

		return minHeap.top();

	}
};

int main()
{
	int K = 0;
	Solution sol;
	vector<int> a{ 20, -5, -1 };
	vector<int> b{ 10, -10, 20, -40 };

	K = 3;

	cout << sol.KthLargestSumSubarray(a, K) << endl;
	K = 6;
	cout << sol.KthLargestSumSubarray(b, K) << endl;

	return 0;
}