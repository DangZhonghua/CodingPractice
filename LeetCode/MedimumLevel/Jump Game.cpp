/*
https://leetcode-cn.com/problems/jump-game/
Jump Game
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
Example 1:
Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:
Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.


给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个位置。
示例 1:
输入: [2,3,1,1,4]
输出: true
解释: 从位置 0 到 1 跳 1 步, 然后跳 3 步到达最后一个位置。
示例 2:
输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。

*/

#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	bool canJump(vector<int>& nums)
	{
		vector<bool> vj(nums.size(), false);
        
        
		if (nums[0] || nums.size() == 1)
		{
			vj[0] = true;
		}
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] && vj[i])
			{
				for (int j = 1; j <= nums[i]; ++j)
				{
					if ((i + j) < nums.size())
					{
						vj[i + j] = true;
					}
				}
			}
		}
		return vj[nums.size() - 1];
	}
};

int main()
{
	vector<int> a{ 2,3,1,1,4 };
	Solution sol;
	cout << sol.canJump(a) << endl;

	vector<int> b{ 3,2,1,0,4 };
	
	cout << sol.canJump(b) << endl;
	return 0;
}