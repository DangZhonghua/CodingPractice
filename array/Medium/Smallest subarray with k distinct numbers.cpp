/*
https://www.geeksforgeeks.org/smallest-subarray-k-distinct-numbers/
Smallest subarray with k distinct numbers

We are given an array a consisting of n integers and an integer k. We need to find the minimum range in array [l, r]
(both l and r are inclusive) such that there are exactly k different numbers.
Examples:
Input : arr[] = { 1, 1, 2, 2, 3, 3, 4, 5}
k = 3
Output : 5 7

Input : arr[] = { 1, 2, 2, 3}
k = 2
Output : 0 1

*/

/*

Sliding Windows technique

*/


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	int shortestWindowWithKDistinct(vector<int>& nums, int K)
	{
		unordered_map<int, int> dictNum2Count;
		int i = -1;
		int j = 0;
		int ws = 0;
		int we = nums.size() - 1;

		while (j<nums.size() && i <= j)
		{
			auto it = dictNum2Count.find(nums[j]);
			if (it != dictNum2Count.end())
			{
				it->second += 1;
			}
			else
			{
				dictNum2Count[nums[j]] = 1;
			}
			//check whether 
			while (K == dictNum2Count.size())
			{
				if (j - i<we - ws + 1)
				{
					ws = i + 1;
					we = j;
				}
				//try to narrow the window
				++i;
				auto it = dictNum2Count.find(nums[i]);
				if (it != dictNum2Count.end())
				{
					it->second -= 1;
					if (0 == (it->second))
					{
						dictNum2Count.erase(it);
					}
				}
			}
			++j;
		}
		cout << ws << " " << we << endl;
		return 0;
	}

};

int main()
{
	int K = 0;
	Solution sol;
	vector<int> nums1{ 1, 1, 2, 2, 3, 3, 4, 5 };
	vector<int> nums2{ 1, 2, 2, 3 };

	K = 3;
	sol.shortestWindowWithKDistinct(nums1, K);
	K = 2;
	sol.shortestWindowWithKDistinct(nums2, K);

	return 0;
}
