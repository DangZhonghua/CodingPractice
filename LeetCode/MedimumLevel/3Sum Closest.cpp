/*
https://leetcode-cn.com/problems/3sum-closest/
3Sum Closest

Given an array nums of n integers and an integer target,
find three integers in nums such that the sum is closest to target. Return the sum of the three integers.
You may assume that each input would have exactly one solution.
Example:
Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/
#include<vector>
#include<algorithm>
#include<iostream>
#include<climits>
using namespace std;


// class Solution {
// public:
// 	int threeSumClosest(vector<int>& nums, int target)
// 	{
// 		std::sort(nums.begin(), nums.end());
// 		int close = INT_MAX;
// 		int value = INT_MAX;
// 		for (int i = 0; i < nums.size(); ++i)
// 		{
// 			BuildTwoSum(nums, i, target, close,value);
// 		}

// 		return value;
// 	}
// private:
// 	int absValue(int v)
// 	{
// 		return v > 0 ? v : -v;
// 	}
// 	int BuildTwoSum(vector<int>& nums, int nSkip, int target, int& close, int& value)
// 	{
// 		int i = 0;
// 		int j = nums.size() - 1;

// 		while (i < j)
// 		{
// 			if (nSkip == i)
// 			{
// 				++i;
// 				continue;
// 			}
// 			if (nSkip == j)
// 			{
// 				--j;
// 				continue;
// 			}

// 			int sum = nums[nSkip] + nums[i] + nums[j];
// 			if (sum > target)
// 			{
// 				if (absValue(sum - target) < close)
// 				{
// 					close = absValue(sum - target);
// 					value = sum;
// 				}
// 				--j;
// 			}
// 			else if (sum < target)
// 			{
// 				if (absValue(sum - target) < close)
// 				{
// 					close = absValue(target-sum);
// 					value = sum;
// 				}
// 				++i;
// 			}
// 			else
// 			{
// 				value = sum;
// 				break;
// 			}
// 		}
// 		return 0;
// 	}
// };


class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target)
	{
        int N = nums.size();
        int diff = 0;
        
        std::sort(nums.begin(),nums.end());
        int close = (nums[0]+nums[1]+nums[2]);
        
        diff = abs(target-close);
        
        
        for(int i = 0; i<N-2; ++i)
        {
            int left = i+1;
            int right = N-1;
            
            while( left < right)
            {
                int sum = (nums[i]+nums[left]+nums[right] );
                if( diff > abs( target- sum ) )
                {
                    diff  = abs( target-sum );
                    close = sum;
                }
                if(sum<target) ++left;
                else --right;
            }
        }
        
        return close;
    }
};



int main()
{
	vector<int> a = { -1, 2, 1, -4 };
	int target = 1;
	Solution sol;
	
	cout<<sol.threeSumClosest(a, target) << endl;
	
	return 0;
}