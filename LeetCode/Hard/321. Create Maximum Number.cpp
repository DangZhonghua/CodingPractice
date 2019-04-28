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
        

        for(int s = 0; s<=N1 && s<=k;  ++s )
        {
            vselect1.clear();
            vselect2.clear();
            
            if( (k-s) <= N2)
            {
                SelectMaximumNumber(nums1,vselect1,s);
                SelectMaximumNumber(nums2,vselect2,k-s);
                
            }
        }

    }

private:

    void SelectMaximumNumber(vector<int>& nums, vector<int>& vselect, int k)
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

		return;
	}

    void CombineMaximumNumber(vector<int>& vselect1, vector<int>& vselect2, vector<int>& vc)
    {
        int i = 0;
        int j = 0;
        while( i<vselect1.size() && j<vselect2.size() )
        {
            if(vselect1)
        }
    }
};


