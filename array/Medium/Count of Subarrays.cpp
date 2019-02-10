/*
https://practice.geeksforgeeks.org/problems/count-of-subarrays/0
https://www.geeksforgeeks.org/count-subarrays-whose-maximum-element-greater-k/
Count of Subarrays

Given an array of N positive integers  a1, a2 ............ an.
The value of each contiguous subarray in given array is the maximum element present in that subarray.
Return the number of subarrays having value strictly greater than K.

Input:

The first line of the input contains 'T' denoting the total number of testcases.Then follows the description of testcases.
The first line of each testcase contains two space separated positive integers N and K denoting the size of array and the value of K.
The second line contains N space separated positive integers denoting the elements of array.

Output:

Output the number of subarrays having value strictly greater than K.

Constraints:

1<=T<=50
1<=N<=100
1<=a[i]<=10^5

Example:

Input:
2
3 2
3 2 1
4 1
1 2 3 4

Output:
3
9

The idea is to approach problem by counting subarrays whose maximum element is less than or equal to k as counting such subarrays is easier. To find the number of subarray whose maximum element is less than or equal to k, remove all the element which is greater than K and find the number of subarray with the left elements.
Once we find above count, we can subtract it from n*(n+1)/2 to get our required result. Observe, there can be n*(n+1)/2 possible number of subarray of any array of size n. So, finding the number of subarray whose maximum element is less than or equal to K and substracting it from n*(n+1)/2 gets us the answer.

*/

#include<vector>
#include<iostream>
using namespace std;

class Solution
{
public:
	int CountOfSubAarrayOfLargerThanK(vector<int>& nums, int K)
	{
		int N = nums.size();
		int nTotal = ((N + 1)*N) / 2;

		int i = 0;
		int j = 0;
		int nLess = 0;
		while (j < N)
		{
			if (nums[j] > K)
			{
				nTotal -= (nLess*(nLess + 1)) / 2;
				nLess = 0;
			}
			else
			{
				++nLess;
			}
			++j;
		}
		if (nLess) // I missed this clause at first time
		{
			nTotal -= (nLess*(nLess + 1)) / 2;
		}
		cout << nTotal << endl;
		return nTotal;
	}
};



int main()
{
	vector<int> nums{ 1, 2, 3, 4 };
	vector<int> nums1{ 3, 2, 1 };

	Solution sol;
	//sol.CountOfSubAarrayOfLargerThanK(nums, 1);
	sol.CountOfSubAarrayOfLargerThanK(nums1, 2);

	return 0;
}



int main1()
{
	int t = 0;
	cin >> t;

	while (t--)
	{
		int N, K;
		cin >> N >> K;
		int i = 0;
		vector<int> nums(N, 0);
		while (i < N)
		{
			cin >> nums[i];
			++i;
		}
		Solution sol;
		sol.CountOfSubAarrayOfLargerThanK(nums, K);
	}

	return 0;
}