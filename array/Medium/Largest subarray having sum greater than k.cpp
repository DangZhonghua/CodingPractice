/*
https://www.geeksforgeeks.org/largest-subarray-having-sum-greater-than-k/
Largest subarray having sum greater than k

Given an array of integers and a value k, find length of largest subarray having sum greater than k.
Examples:
Input : arr[] = {-2, 1, 6, -3}, k = 5
Output : 2
Largest subarray with sum greater than
5 is  {1, 6}.

Input : arr[] = {2, -3, 3, 2, 0, -1}, k = 3
Output : 5
Largest subarray with sum greater than
3 is {2, -3, 3, 2, 0}.

*/

/*

use extra O(n) space to store the sum end at every index, This is necessary because we know whether need include the negative sum.
Use two pointers to traverse the presum vectors to find longest window.
The two pointers: slow, fast
if presum[fast] > K then window is [0,fast]
else
{
if(presum[i]>=presum[i-1])
{
}
else
{
}
}


*/

#include<iostream>
#include<vector>
using namespace std;

//class Solution
//{
//public:
//	int LongestSubarrayWithSumLargerThanK(vector<int>& nums, int K)
//	{
//		int sum = nums[0];
//		int s = 0;
//		int e = -1;
//
//		int ws = 0;
//		int we = -1;
//
//		for (int i = 1; i < nums.size(); ++i)
//		{
//			if (sum > K)
//			{
//				e = i-1;
//				if ((e - s) > (we - ws))
//				{
//					ws = s;
//					we = e;
//				}
//			}
//			else
//			{
//				if (sum < 0)
//				{
//					s = i;
//					e = i-1;
//					sum = 0;
//				}
//			}
//			sum += nums[i];
//		}
//		if (sum > K)
//		{
//			e = nums.size() - 1;
//			if ((e - s) > (we - ws))
//			{
//				ws = s;
//				we = e;
//			}
//		}
//		cout << ws << " " << we << endl;
//
//		return 0;
//	}
//};


class Solution
{
public:
	int LongestSubarrayWithSumLargerThanK(vector<int>& nums, int K)
	{
		int ws = 0;
		int we = -1;
		vector<int> vPresum(nums.size() + 1, 0);
		vPresum[0] = 0;

		for (int i = 0; i < nums.size(); ++i)
		{
			vPresum[i + 1] = (vPresum[i] + nums[i]);
		}
		//

		for (int i = 1; i <= nums.size(); ++i)
		{
			if (vPresum[i]>K)
			{
				ws = 1;
				we = i;
				continue;
			}
			for (int j = 1; j <= i; ++j)
			{
				if ((vPresum[i] - vPresum[j - 1])>K)
				{
					if (i - j>we - ws)
					{
						ws = j;
						we = i;
					}
					break;
				}
			}
		}
		cout << (ws - 1) << " " << (we - 1) << endl;
		cout << nums[ws - 1] << " " << nums[we-1]<<endl;

		return (we-ws+1);
	}
};



int main()
{
	Solution sol;
	int K = 5;
	vector<int> nums{ -2, 1, 6, -3 };
	vector<int> nums1{ 2, -3, 3, 2, 0, -1 };


	cout<<sol.LongestSubarrayWithSumLargerThanK(nums, K)<<endl;

	K = 3;
	cout<<sol.LongestSubarrayWithSumLargerThanK(nums1, K)<<endl;

	return 0;
}

