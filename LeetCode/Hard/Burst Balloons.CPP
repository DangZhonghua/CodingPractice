/*
https://leetcode-cn.com/problems/burst-balloons/
Burst Balloons
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums.
You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins.
Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:

You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:

Input: [3,1,5,8]
Output: 167
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167


*/

/*

which ballon should be bursted lastly ( consider firstly is very complicated)? we don't know, so we try every possible.
coin[i,j] = max{ coin[i,k-1] + nums[im]*nums[k]*nums[jm] + coin[k+1,j] }  the last bursted ballon is supposed to k
This is dynamic programming: this is similar with matrix chain muliply problem.


From the GeeksForGeeks:
A recursive solution is discussed here. We can solve this problem using dynamic programming.
First, consider a sub-array from indices Left to Right(inclusive).
If we assume the balloon at index Last to be the last balloon to be burst in this sub-array,
we would say the coined gained to be-A[left-1]*A[last]*A[right+1].
Also, the total Coin Gained would be this value, plus dp[left][last – 1] + dp[last + 1][right],
where dp[i][j] means maximum coin gained for sub-array with indices i, j.
Therefore, for each value of Left and Right,
we need find and choose a value of Last with maximum coin gained, and update the dp array.
Our Answer is the value at dp[1][N].

*/


//class Solution {
//public:
//	int maxCoins(vector<int>& nums)
//	{
//		unsigned long long nMax = 0;
//		int N = nums.size();
//		vector< vector< vector<unsigned long long> > >
//			maxCoins(N + 2, vector<vector<unsigned long long>>(N + 2, vector<unsigned long long>(N + 2, 1)));
//
//
//		for (int i = 1; i <= N; ++i)
//		{
//			maxCoins[i][i][i] = nums[i - 1];
//		}
//
//		for (int L = 2; L <= N; ++L)
//		{
//			for (int i = 1; i <= N - L + 1; ++i)
//			{
//				int j = i + L - 1;
//				for (int k = i; k <= j; ++k) // k is the last to burst in range [i,j]
//				{
//					for (int ll = i; ll <= k - 1; ++ll)
//					{
//						for (int rl = k + 1; rl <= j; ++rl)
//						{
//							if (maxCoins[i][j][k] < maxCoins[i][k - 1][ll] + nums[ll - 1] * nums[k - 1] * nums[rl - 1] + maxCoins[k + 1][j][rl])
//							{
//								maxCoins[i][j][k] = maxCoins[i][k - 1][ll] + nums[ll - 1] * nums[k - 1] * nums[rl - 1] + maxCoins[k + 1][j][rl];
//							}
//						}
//					}
//					if (nMax < maxCoins[i][j][k])
//					{
//						nMax = maxCoins[i][j][k];
//					}
//				}
//			}
//		}
//		return nMax;
//	}
//};


/*
https://leetcode-cn.com/problems/burst-balloons/
Burst Balloons
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums.
You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins.
Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:

You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:

Input: [3,1,5,8]
Output: 167
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
			 coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167


*/

/*

which balloon should be burst lastly ( consider firstly is very complicated)? we don't know, so we try every possible.
coin[i,j] = max{ coin[i,k-1] + nums[i]*nums[k]*nums[j] + coin[k+1,j] }  the last bursted ballon is supposed to k
This is dynamic programming: this is similar with matrix chain multiply problem.


A recursive solution is discussed here. We can solve this problem using dynamic programming.
First, consider a sub-array from indices Left to Right(inclusive).
If we assume the balloon at index Last to be the last balloon to be burst in this sub-array,
we would say the coined gained to be-A[left-1]*A[last]*A[right+1].Also, the total Coin Gained would be this value, 
plus dp[left][last – 1] + dp[last + 1][right], where dp[i][j] means maximum coin gained for sub-array with indices i, j.
Therefore, for each value of Left and Right, we need find and choose a value of Last with maximum coin gained, and update the dp array.
Our Answer is the value at dp[1][N].

*/

#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;

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

		for (auto v : maxCoins)
		{
			for (auto e : v)
			{
				cout << e << " ";
			}
			cout << endl;
		}

		return maxCoins[1][N];
	}
};



int main()
{
	Solution sol;
	vector<int> nums{ 3, 1, 5, 8 };
	cout << sol.maxCoins(nums) << endl;

	vector<int> nums1{ 1, 2, 3, 4, 5 };
	cout << sol.maxCoins(nums1) << endl;


	return 0;
}

