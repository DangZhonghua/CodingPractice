/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 *
 * https://leetcode-cn.com/problems/burst-balloons/description/
 *
 * algorithms
 * Hard (49.90%)
 * Total Accepted:    1K
 * Total Submissions: 2.1K
 * Testcase Example:  '[3,1,5,8]'
 *
 * 有 n 个气球，编号为0 到 n-1，每个气球上都标有一个数字，这些数字存在数组 nums 中。
 * 
 * 现在要求你戳破所有的气球。每当你戳破一个气球 i 时，你可以获得 nums[left] * nums[i] * nums[right] 个硬币。 这里的
 * left 和 right 代表和 i 相邻的两个气球的序号。注意当你戳破了气球 i 后，气球 left 和气球 right 就变成了相邻的气球。
 * 
 * 求所能获得硬币的最大数量。
 * 
 * 说明:
 * 
 * 
 * 你可以假设 nums[-1] = nums[n] = 1，但注意它们不是真实存在的所以并不能被戳破。
 * 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
 * 
 * 
 * 示例:
 * 
 * 输入: [3,1,5,8]
 * 输出: 167 
 * 解释: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
 * coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
 * 
 * 
 */



class Solution {
public:
	int maxCoins(vector<int>& nums)
	{
		unsigned long long nMax = 0;
		int N = nums.size();
		vector< vector<unsigned long long> > maxCoins(N + 2, vector<unsigned long long>(N + 2, 0));
		vector<int> vp(N + 2, 1);
		for (int i = 0; i < nums.size(); ++i)
		{
			vp[i + 1] = nums[i];
		}

		for (int i = 1; i <= N; ++i)
		{
			//this is the right way to initialize the 1-size array.
			maxCoins[i][i] = vp[i-1]*vp[i]*vp[i+1];
		}

		for (int L = 2; L <= N; ++L)
		{
			for (int i = 1; i <= N - L + 1; ++i)
			{
				int j = i + L - 1;

				for (int k = i; k <= j; ++k)
				{
					if (maxCoins[i][j] < vp[i - 1] * vp[k] * vp[j+1] + maxCoins[i][k - 1] + maxCoins[k + 1][j])
					{
						maxCoins[i][j] = vp[i - 1] * vp[k] * vp[j+1] + maxCoins[i][k - 1] + maxCoins[k + 1][j];
					}
				}
			}
		}

		// for (auto v : maxCoins)
		// {
		// 	for (auto e : v)
		// 	{
		// 		cout << e << " ";
		// 	}
		// 	cout << endl;
		// }

		return maxCoins[1][N];
	}
};
