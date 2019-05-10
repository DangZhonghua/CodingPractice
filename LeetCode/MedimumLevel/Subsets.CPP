/*

https://leetcode-cn.com/problems/subsets/


78. Subsets

Given a set of distinct integers, nums, return all possible subsets (the power set).
Note: The solution set must not contain duplicate subsets.
Example:
Input: nums = [1,2,3]

Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]


*/




#include<iostream>
#include<vector>
using namespace std;


class Solution 
{
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        int N = nums.size();
        vector< vector<int> > vsets;
        vector<int> partialSet;
        //vsets.push_back(vector<int>()); // need NOT do this, since when nothing is selected, the empty subset is created.
        if(!nums.empty())
        {
           CreateSubset(vsets,partialSet,nums,0);
        }
        return vsets;
    }
private:
    void CreateSubset( vector< vector<int> >& vsets, vector<int>& partialSet, vector<int>& nums, int start)
    {
        if( start == nums.size())
        {
            vsets.push_back(partialSet);
            return;
        }

        CreateSubset(vsets,partialSet,nums, start+1);

        partialSet.push_back(nums[start]);
        CreateSubset(vsets,partialSet,nums, start+1);
        partialSet.pop_back();

    }

};