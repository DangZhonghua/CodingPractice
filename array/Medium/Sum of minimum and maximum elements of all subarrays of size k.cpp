/*
https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/
Sum of minimum and maximum elements of all subarrays of size k.

Given an array of both positive and negative integers, the task is to compute sum of minimum and maximum elements
of all sub-array of size k.

Examples:

Input : arr[] = {2, 5, -1, 7, -3, -1, -2}
K = 4
Output : 18
Explanation : Subarrays of size 4 are :
{2, 5, -1, 7},   min + max = -1 + 7 = 6
{5, -1, 7, -3},  min + max = -3 + 7 = 4
{-1, 7, -3, -1}, min + max = -3 + 7 = 4
{7, -3, -1, -2}, min + max = -3 + 7 = 4
Sum of all min & max = 6 + 4 + 4 + 4
= 18

*/

#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution
{
public:
	int SumOfMinMaxWithinWindow(vector<int>& a, int K)
	{
		vector<int> minV(K, 0);
		vector<int> maxV(K, 0);
		MinValueOfEveryWindow(a, K, minV);
		MaxValueOfEveryWindow(a, K, maxV);
		int sum = 0;
		for (int i = 0; i<K; ++i)
		{
			sum += minV[i];
			sum += maxV[i];
		}
		return sum;
	}

private:
	int MinValueOfEveryWindow(vector<int>& a, int K, vector<int>& minV)
	{
		deque<int> IncrQ(K); //The queue front is the minimum value in the current window
		//The queue is used to store the index of element of array.
		int index = 0;
		int i = 0;

		for (i = 0; i<K && i< a.size(); ++i)
		{
			while (!IncrQ.empty() && a[IncrQ.back()] >= a[i])
			{
				IncrQ.pop_back();
			}
			IncrQ.push_back(i);
		}

		for (; i<a.size(); ++i)
		{
			minV[index++] = (a[IncrQ.front()]);

			//Update the minimum value because the window position change.
			while (!IncrQ.empty() && IncrQ.front() <= i - K)
			{
				IncrQ.pop_front();
			}

			//add the current element into Q and keep the increasing property.
			while (!IncrQ.empty() && a[IncrQ.back()] >= a[i])
			{
				IncrQ.pop_back();
			}
			IncrQ.push_back(i);
		}

		minV[index++] = (a[IncrQ.front()]);

		return 0;
	}

	int MaxValueOfEveryWindow(vector<int>& a, int K, vector<int>& maxV)
	{
		deque<int> DecrQ(K); //the queue front is the maximum value in the current window
		int index = 0;
		int i = 0;

		for (i = 0; i<K & i<a.size(); ++i)
		{
			while (!DecrQ.empty() && a[DecrQ.back()] <= a[i])
			{
				DecrQ.pop_back();
			}
			DecrQ.push_back(i);
		}

		for (; i<a.size(); ++i)
		{
			maxV[index++] = a[DecrQ.front()];

			while (!DecrQ.empty() && DecrQ.front()<= i - K)
			{
				DecrQ.pop_front();
			}
			while (!DecrQ.empty() && a[DecrQ.back()] <= a[i])
			{
				DecrQ.pop_back();
			}
			DecrQ.push_back(i);
		}

		maxV[index] = a[DecrQ.front()];
		return 0;
	}

};

int main()
{
	vector<int> a{ 2, 5, -1, 7, -3, -1, -2 };
	int K = 4;
	Solution sol;

	cout << sol.SumOfMinMaxWithinWindow(a, K) << endl;

	return 0;
}