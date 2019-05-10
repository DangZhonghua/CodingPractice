/*
https://leetcode-cn.com/problems/next-greater-element-i/
Next Greater Element I



*/


#include <vector>
#include <unordered_map>
using namespace std;

class Solution 
{
public:
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) 
	{
		int BN = nums.size();

		vector<int> vNextBig(findNums.size(), -1);
		vector<int> vbig(BN,-1);
		unordered_map<int, int> mapEle2NextLargerIndex;

		if (0 == BN)
		{
			return vNextBig;
		}

		mapEle2NextLargerIndex[nums.back()] = -1;
		for (int i = nums.size() - 2; i >= 0; --i)
		{
			if (nums[i + 1] > nums[i])
			{
				vbig[i] = (i + 1);
			}
			else
			{
				int j = vbig[i + 1];
				while (-1 != j)
				{
					if (nums[j] > nums[i])
					{
						break;
					}
					j = vbig[j];
				}
				vbig[i] = j;
			}
			
			mapEle2NextLargerIndex[nums[i]] = vbig[i];
		}
		
		for (int i = 0; i < findNums.size(); ++i)
		{
			if (-1 != mapEle2NextLargerIndex[findNums[i]])
			{
				vNextBig[i] = nums[mapEle2NextLargerIndex[findNums[i]]];
			}
		}
		
		return vNextBig;
	}
};