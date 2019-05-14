/*
https://leetcode-cn.com/problems/subsets-ii/
http://www.cnblogs.com/TenosDoIt/p/3451902.html
http://www.cnblogs.com/grandyang/p/4310964.html

90. Subsets II

Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
Note: The solution set must not contain duplicate subsets.
Example:
Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
 
*/

/*

这次输入数组允许有重复项，其他条件都不变，只需要在之前那道题解法的基础上稍加改动便可以做出来，
我们先来看非递归解法，拿题目中的例子[1 2 2]来分析，
根据之前 Subsets 子集合 里的分析可知，
当处理到第一个2时，此时的子集合为[], [1], [2], [1, 2]，
而这时再处理第二个2时，如果在[]和[1]后直接加2会产生重复，
所以只能在上一个循环生成的后两个子集合后面加2，发现了这一点，
题目就可以做了，我们用last来记录上一个处理的数字，
然后判定当前的数字和上面的是否相同，若不同，则循环还是从0到当前子集的个数，
若相同，则新子集个数减去之前循环时子集的个数当做起点来循环，这样就不会产生重复了，代码如下：

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &S) {
        if (S.empty()) return {};
        vector<vector<int>> res(1);
        sort(S.begin(), S.end());
        int size = 1, last = S[0];
        for (int i = 0; i < S.size(); ++i) {
            if (last != S[i]) {
                last = S[i];
                size = res.size();
            }
            int newSize = res.size();
            for (int j = newSize - size; j < newSize; ++j) {
                res.push_back(res[j]);
                res.back().push_back(S[i]);
            }
        }
        return res;
    }
};

*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
      vector<vector<int> > vset(1,vector<int>());
      if(nums.empty()) return vset; // empty set is the subset of any set.\
      
      std::sort(nums.begin(),nums.end());
      int last        = nums[0];
      int presetsize  = 1;
      for( int i = 0; i<nums.size(); ++i )
      {
          if(last != nums[i]) //erase the duplicate subset
          {
             presetsize = vset.size(); // this will cause:from empty set to argument as the next loop done.
          }
          int cursetsize = vset.size();
          for(int j = cursetsize-presetsize; j<cursetsize; ++j)
          {
            vset.push_back(vset[j]);
            vset.back().push_back(nums[i]); //argument one digital
          }
          last = nums[i]; //change the last digital
      }
      return vset;
    }
};


//Modify the solution of subsets

class Solution 
{
public:
   // vector<vector<int>> subsets(vector<int>& nums) 
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        int N = nums.size();
        vector< vector<int> > vsets;
        vector<int> partialSet;
        //vsets.push_back(vector<int>()); // need NOT do this, since when nothing is selected, the empty subset is created.
        if(!nums.empty())
        {
           std::sort(nums.begin(), nums.end());
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


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &S) {
        if (S.empty()) return {};
        vector<vector<int>> res;
        vector<int> out;
        sort(S.begin(), S.end());
        getSubsets(S, 0, out, res);
        return res;
    }
    void getSubsets(vector<int> &S, int pos, vector<int> &out, vector<vector<int>> &res) {
        res.push_back(out);
        for (int i = pos; i < S.size(); ++i) {
            out.push_back(S[i]);
            getSubsets(S, i + 1, out, res);
            out.pop_back();
            while (i + 1 < S.size() && S[i] == S[i + 1]) ++i;
        }
    }
};