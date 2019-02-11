/*
Find the k largest numbers after deleting the given elements
https://www.geeksforgeeks.org/find-the-k-largest-numbers-after-deleting-the-given-elements/

Given an array of integers, find the k largest number after deleting the given elements.
In case of repeating elements, delete one instance for every instance of the element present
in the array containing the elements to be deleted.
Assume that atleast k elements will be left after deleting n elements.
Examples:
Input : array[] = { 5, 12, 33, 4, 56, 12, 20 }, del[] = { 12, 56, 5 }, k = 3
Output : 33 20 12
Explanation : After deletions { 33, 4, 12, 20 } will be left. Print top 3 highest elements from it.

*/

/*
use minHeap
*/

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<functional>
using namespace std;

class Solution
{
public:
	int LargestKAfterDeletion(vector<int>& a, vector<int>& d, int K)
	{
		unordered_set<int> dict;
		priority_queue<int, vector<int>, greater<int> > minHeap;
		for (int i = 0; i < d.size(); ++i)
		{
			dict.insert(d[i]);
		}

		for (int i = 0; i < a.size(); ++i)
		{
			auto it = dict.find(a[i]);
			if (it == dict.end())
			{
				if (K == minHeap.size())
				{
					if (a[i] > minHeap.top())
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
			else
			{
				dict.erase(a[i]);
			}
		}
		while (!minHeap.empty())
		{
			cout << minHeap.top() << " ";
			minHeap.pop();
		}
		cout << endl;

		return 0;
	}
};


int main()
{
	vector<int> a{ 5, 12, 33, 4, 56, 12, 20 };
	vector<int> d{ 12, 56, 5 };
	int k = 3;
	Solution sol;
	sol.LargestKAfterDeletion(a, d, k);

	return 0;
}