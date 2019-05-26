/*
https://leetcode-cn.com/problems/3sum/
3Sum

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.
Note:
The solution set must not contain duplicate triplets.
Example:
Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]


*/

#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<utility>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		vector< vector<int> > vr;
		std::sort(nums.begin(), nums.end());
		unordered_map<int, unordered_set<int> > dict;
		for (int i = 0; i < nums.size(); ++i)
		{
			vector<std::pair<int,int>> vpairs;
			if (twoSum(nums, -nums[i], i, vpairs))
			{
				for (int j = 0; j < vpairs.size(); ++j)
				{
					vector<int> vs(3, 0);
					vs[0] = nums[i];
					vs[1] = vpairs[j].first;
					vs[2] = vpairs[j].second;
					std::sort(vs.begin(), vs.end());
					if (dict.end() != dict.find(vs[0]))
					{
						if (dict[vs[0]].end() == dict[vs[0]].find(vs[1]))
						{
							vr.push_back(vs);
							dict[vs[0]].insert(vs[1]);
						}
					}
					else
					{
						dict[vs[0]].insert(vs[1]);
						vr.push_back(vs);
					}
				}
			}
		}


		return vr;
	}
private:
	bool twoSum(vector<int>& nums, int sum, int nSkip, vector<pair<int, int> >& vpair)
	{
		bool bSum = false;

		int i = 0;
		int j = nums.size() - 1;
		while (i < j)
		{
			if (i == nSkip)
			{
				++i;
				continue;
			}
			if (j == nSkip)
			{
				--j;
				continue;
			}
			int s = (nums[i] + nums[j]);
			if (s == sum)
			{
				vpair.push_back(std::make_pair(nums[i], nums[j]));
				bSum = true;
				++i;
				--j;
			}
			else if (s < sum)
			{
				++i;
			}
			else
			{
				--j;
			}
		}
		return bSum;
	}

};




class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector< vector<int> > res;
        int N = nums.size();
        std::sort(nums.begin(), nums.end());
        
        for(int i = 0; i< N-2; ++i )
        {
            //For handle duplicate combination case
            if( i>0 && nums[i-1] == nums[i] ) continue;
            
            int left = i+1;
            int right = N-1;
            
            while( left<right )
            {
                if( (nums[left] + nums[right]) == -nums[i])
                {
                    vector<int> c{nums[i], nums[left], nums[right]};
                    res.push_back(c);
                    
                    while( left <right && nums[left] == nums[left+1] ) ++left;
                    while( left < right && nums[right-1] == nums[right]) --right;
                    ++left;
                    --right;
                }
                else if ( (nums[left]+nums[right]) < -nums[i])
                {
                    ++left;
                }
                else
                {
                    --right;
                }
            }   
        }
        return res;
    }

};



int main()
{
	vector<int> nums{ -1, 0, 1, 2, -1, -4 };
	vector<int> v1{-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
	vector<int> v2{  -2, 0, 2 };

	Solution sol;

	
	vector< vector<int> > a = sol.threeSum(v1);

	for (auto v : a)
	{
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	return 0;
}