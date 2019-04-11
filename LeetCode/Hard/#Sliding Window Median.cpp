/*
https://leetcode-cn.com/problems/sliding-window-median/description/
480. Sliding Window Median
Median is the middle value in an ordered integer list. If the size of the list is even,
there is no middle value. So the median is the mean of the two middle value.

Examples:
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Given an array nums, there is a sliding window of size k which is moving from
the very left of the array to the very right. You can only see the k numbers in the window.
Each time the sliding window moves right by one position.
Your job is to output the median array for each window in the original array.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Median
---------------               -----
[1  3  -1] -3  5  3  6  7       1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7       3
 1  3  -1  -3 [5  3  6] 7       5
 1  3  -1  -3  5 [3  6  7]      6
Therefore, return the median sliding window as [1,-1,-1,3,5,6].

Note:
You may assume k is always valid, ie: k is always smaller than input array's size for non-empty array.

*/

/*




*/


#include<vector>
#include<iostream>
#include<map>
#include<set>
using namespace std;

class Solution
{
public:
	vector<double> medianSlidingWindow(vector<int>& nums, int k)
	{
		multiset<double>  wsort(nums.begin(), nums.begin() + k);
		vector<double>    vm;
		multiset<double>::iterator mid = std::next(wsort.begin(), k / 2);
		bool bOdd = k & 1;
		for (int i = k; i <= nums.size(); ++i)
		{
			double m = *mid;
			if (!bOdd)
			{
				m += *(std::prev(mid, 1));
				m /= 2;
			}
			vm.push_back(m);
			if (i == nums.size())
			{
				break;
			}
			wsort.insert(nums[i]);
			if (nums[i] < *mid) --mid;
			if (nums[i - k] <= *mid) ++mid;
			wsort.erase(wsort.lower_bound(nums[i - k]));
		}
		for (auto v : vm)
		{
			cout << v << " ";
		}
		cout << endl;
		return vm;
	}
};

int main()
{
	Solution sol;
	vector<int> a{ 1, 2, 3, 4, 2, 3, 1, 4, 2 };
	int K = 3;

	//sol.medianSlidingWindow(a, K);
	
	vector<int> a1{ 1, 4, 2, 3 };
	K = 4;
	sol.medianSlidingWindow(a1, K);

	return 0;
}