/*

https://leetcode-cn.com/problems/create-maximum-number/
http://www.cnblogs.com/grandyang/p/5136749.html

321. Create Maximum Number

Given two arrays of length m and n with digits 0-9 representing two numbers.
Create the maximum number of length k <= m + n from digits of the two.
The relative order of the digits from the same array must be preserved.
Return an array of the k digits.
Note: You should try to optimize your time and space complexity.
Example 1:
Input:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
Output:
[9, 8, 6, 5, 3]
Example 2:
Input:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
Output:
[6, 7, 6, 0, 4]
Example 3:
Input:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
Output:
[9, 8, 9]

*/


#include<vector>
#include<stack>
#include<iostream>
using namespace std;


class Solution
{
public:
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k)
	{
		vector<int> vselect1;
		vector<int> vselect2;
		vector<int> vr;

		int N1 = nums1.size();
		int N2 = nums2.size();


		for (int s = 0; s <= N1 && s <= k; ++s)
		{
			vselect1.clear();
			vselect2.clear();

			if ((k - s) <= N2)
			{
				SelectMaximumNumber(nums1, vselect1, s);
				SelectMaximumNumber(nums2, vselect2, k - s);
				vector<int> vc;
				CombineMaximumNumber(vselect1, vselect2, vc);
				AcquireMaxinumNumber(vc, vr);
				for (auto e : vr)
				{
					cout << e << " ";
				}
				cout << endl;
			}
		}

		for (auto e : vr)
		{
			cout << e << " ";
		}
		cout << endl;

		return vr;
	}

private:

	void SelectMaximumNumber(vector<int> & nums, vector<int> & vselect, int k)
	{
		int N = nums.size();
		int nDrop = N - k;

		for (int i = 0; i < N; ++i)
		{
			while (!vselect.empty() && nDrop > 0)
			{
				if (vselect.back() < nums[i])
				{
					vselect.pop_back();
					--nDrop;
				}
				else
				{
					break;
				}
			}
			vselect.push_back(nums[i]);
		}

		while (!vselect.empty() && nDrop > 0)
		{
			vselect.pop_back();
			--nDrop;
		}

		return;
	}

	void CombineMaximumNumber(vector<int> & vselect1, vector<int> & vselect2, vector<int> & vc)
	{
		int i = 0;
		int j = 0;
		int si = 0;
		int sj = 0;

		while (i < vselect1.size() && j < vselect2.size())
		{
			if (LargerThan(vselect1, i, vselect2, j))
			{
				vc.push_back(vselect1[i++]);
			}
			else
			{
				vc.push_back(vselect2[j++]);
			}
		}

		while (i < vselect1.size())
		{
			vc.push_back(vselect1[i++]);
		}
		while (j < vselect2.size())
		{
			vc.push_back(vselect2[j++]);
		}
	}

	void AcquireMaxinumNumber(vector<int> & vc, vector<int> & vr)
	{
		if (LargerThan(vc, vr))
		{
			vr = vc;
		}
	}
	bool LargerThan(vector<int>& vc, vector<int>& vr)
	{
		return vc > vr;
	}
	bool LargerThan(vector<int>vs1, int s1, vector<int> vs2, int s2)
	{
		bool bLarge = false;
		
		while (s1 < vs1.size() && s2 < vs2.size())
		{
			if (vs1[s1] > vs2[s2])
			{
				bLarge = true;
				break;
			}
			else if (vs1[s1] < vs2[s2])
			{
				break;
			}
			++s1;
			++s2;
		}
		if (s1 < vs1.size() && s2 == vs2.size())
		{
			bLarge = true;
		}
		return bLarge;
	}
};


int main()
{
	Solution sol;
	vector<int> nums1{ 3, 4, 6, 5 };
	vector<int> nums2{ 9, 1, 2, 5, 8, 3 };
	int k = 5;

	//sol.maxNumber(nums1, nums2, k);

	vector<int> a1{ 3, 4, 8, 9, 3, 0 };
	vector<int> b1{ 6, 1, 9, 1, 1, 2 };
	k = 6;

	//[9,9,3,1,2,0]

	sol.maxNumber(a1, b1, k);
	if (a1 > b1)
	{
		cout << "Wow!" << endl;
	}

	return 0;
}
