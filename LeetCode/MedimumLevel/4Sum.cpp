/*
https://leetcode-cn.com/problems/4sum/
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.
Note:
The solution set must not contain duplicate quadruplets.
Example:
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]   

*/

#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int> > res;
        int N = nums.size();
        std::sort(nums.begin(),nums.end());
        
        for(int i =0; i<N-3; ++i)
        {
          if(i>0 && nums[i] == nums[i-1]) continue; //handle duplicate case. 
          for(int j = i+1; j<N-2; ++j)
          {
            if( j>i+1 && nums[j] == nums[j-1]) continue; // handle duplicate case
            int left = j+1;
            int right = N-1;
            // two sum technique
            int sum = target - nums[i]-nums[j];
            while(left<right)
            {
              if( (nums[left] + nums[right]) == sum)
              {
                  vector<int> c{nums[i], nums[j],nums[left],nums[right]};
                  res.push_back(c);
                
                  while(left < right && nums[left] == nums[left+1]) ++left;
                  while(left < right && nums[right-1] == nums[right]) --right;
                  ++left;
                  --right;
              }
              else if((nums[left] + nums[right]) < sum)
              {
                ++left;
              }
              else
              {
                --right;
              }           
            }
          }
        }
     return res;
    }
};