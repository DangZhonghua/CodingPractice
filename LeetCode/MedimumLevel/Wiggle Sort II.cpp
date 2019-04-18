/*
https://leetcode-cn.com/problems/wiggle-sort-ii/
Wiggle Sort II

Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
Example 1:
Input: nums = [1, 5, 1, 1, 6, 4]
Output: One possible answer is [1, 4, 1, 5, 1, 6].
Example 2:
Input: nums = [1, 3, 2, 2, 3, 1]
Output: One possible answer is [2, 3, 1, 3, 1, 2].
Note:
You may assume all input has valid answer.
Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?

*/

/*

use order statistic to partition the whole into two segment,
all elements in first segment are less then  any one in the second segment.
After partition, interval these two parts.

*/

#include<iostream>
#include<vector>
using namespace std;



//[5,8,5,7,3,6,2,5,1]
class Solution
{

public:
	void wiggleSort(vector<int>& nums)
	{
		wiggleSortNspace(nums);
	}

private:
	void wiggleSortNspace(vector<int>& nums)
	{
		int N = nums.size();
		int K = N / 2;
		int s = 0;
		int e = N - 1;
		int p = 0;

		while (K)
		{
			p = partitionArray(nums, s, e);
			int C = p - s + 1;
			if (C == K)
			{
				break;
			}
			else if (C > K) // continue to partition in the first half
			{
				e = p - 1;
			}
			else
			{
				s = p + 1;
				K = K - C;
			}
		}


		//for (auto e : nums)
		//{
		//	cout << e << " ";
		//}
		//cout << endl<<p<<endl;

		//Now i is the pivot position
		int i = p;
		int j = N - 1;

		vector<int> vws(N, 0);
		int index = 0;

		while (i >= 0 && j > p)
		{
			vws[index++] = nums[i--];
			vws[index++] = nums[j--];
		}
		if (i >= 0)
		{
			vws[index] = nums[i];
		}
		if (j > p)
		{
			vws[index] = nums[j];
		}

		//adjust the last element.
		if (N > 1 && vws[N - 1] == vws[N - 2])
		{

			int t = 1;
			bool bFindLarge = true;
			if (N & 1)
			{
				t = 0;
				bFindLarge = false;
			}

			for (int i = t; i < N - 2; i += 2)
			{
				if (bFindLarge) //1,3
				{
					if (vws[N - 1] < vws[i])
					{
						if (vws[i - 1]< vws[N - 1] && vws[N - 1]>vws[i + 1])
						{
							int m = vws[N - 1];
							vws[N - 1] = vws[i];
							vws[i] = m;
							break;
						}
					}
				}
				else
				{
					if (vws[N - 1] > vws[i]) //0 ,2
					{
						if (i >= 1)
						{
							if (vws[N - 1] < vws[i - 1] && vws[N - 1] < vws[i + 1])
							{
								int m = vws[N - 1];
								vws[N - 1] = vws[i];
								vws[i] = m;
								break;
							}
						}
						else
						{
							if (vws[N - 1] < vws[i + 1])
							{
								int m = vws[N - 1];
								vws[N - 1] = vws[i];
								vws[i] = m;
								break;
							}
						}

					}
				}
			}
		}


		nums = vws;
		for (auto e : nums)
		{
			cout << e << " ";
		}
		cout << endl;
	}

private:
	int partitionArray(vector<int>& nums, int s, int e)
	{
		int i = s - 1;
		int j = s;
		int pivot = nums[e];

		while (j < e)
		{
			if (nums[j] <= pivot) // for handle duplicated elements, we need use "<="
			{
				++i;
				int t = nums[i];
				nums[i] = nums[j];
				nums[j] = t;
			}
			++j;
		}
		++i;
		nums[e] = nums[i];
		nums[i] = pivot;
		return i;
	}
};

int main()
{
	Solution sol;
	vector<int> nums1{ 1, 5, 1, 1, 6, 4 };
	//sol.wiggleSort(nums1);

	//vector<int> nums2{ 1, 3, 2, 2, 3, 1 };
	//sol.wiggleSort(nums2);

	//vector<int> nums3{ 1, 1, 2, 1, 2, 2, 1 };
	//sol.wiggleSort(nums3);

	//vector<int> nums4{ 4, 5, 5, 6 };

	//sol.wiggleSort(nums4);

	vector<int> nums5{ 5, 3, 1, 2, 6, 7, 8, 5, 5};

	sol.wiggleSort(nums5);

	return 0;
}