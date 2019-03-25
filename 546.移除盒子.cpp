/*
 * @lc app=leetcode.cn id=546 lang=cpp
 *
 * [546] 移除盒子
 *
 * https://leetcode-cn.com/problems/remove-boxes/description/
 * https://leetcode.com/problems/remove-boxes/discuss/101310/java-top-down-and-bottom-up-dp-solutions
 *
 * algorithms
 * Hard (43.32%)
 * Total Accepted:    248
 * Total Submissions: 577
 * Testcase Example:  '[1,3,2,2,2,3,4,3,1]'
 *
 * 给出一些不同颜色的盒子，盒子的颜色由数字表示，即不同的数字表示不同的颜色。
 * 你将经过若干轮操作去去掉盒子，直到所有的盒子都去掉为止。每一轮你可以移除具有相同颜色的连续 k 个盒子（k >= 1），这样一轮之后你将得到 k*k
 * 个积分。
 * 当你将所有盒子都去掉之后，求你能获得的最大积分和。
 * 
 * 示例 1：
 * 输入:
 * 
 * 
 * [1, 3, 2, 2, 2, 3, 4, 3, 1]
 * 
 * 
 * 输出:
 * 
 * 
 * 23
 * 
 * 
 * 解释:
 * 
 * 
 * [1, 3, 2, 2, 2, 3, 4, 3, 1] 
 * ----> [1, 3, 3, 4, 3, 1] (3*3=9 分) 
 * ----> [1, 3, 3, 3, 1] (1*1=1 分) 
 * ----> [1, 1] (3*3=9 分) 
 * ----> [] (2*2=4 分)
 * 
 * 
 * 
 * 
 * 提示：盒子的总数 n 不会超过 100。
 * 
 */

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;


class Solution 
{
public:
    int removeBoxes(vector<int>& boxes) 
    {
        int N = boxes.size();
        vector< vector< vector<int> > > dp(N,vector< vector<int> >(N, vector<int>(N,0)));
        
        for(int i = 0; i<N; ++i )
        {
            for(int k = 0; k<=i; ++k)
            {
                dp[i][i][k] = (k+1)*(k+1);
            }
        }
        //range[i,j]
        for(int L = 2; L<=N; ++L)
        {
            for(int i = 0; i+L<=N; ++i )
            {
                int j = i+L-1;
                //Now we have range[i,j] with length = L
                //Find the suitable k, since we DO NOT know which one, we try every possible
                for(int k = 0; k<=i; ++k)
                {
                    int maxp = (k+1)*(k+1)+ dp[i+1][j][0];
                    
                    for(int m = i+1; m<=j; ++m)
                    {
                        if(boxes[m] == boxes[i])
                        {
                            maxp = max(maxp, dp[i+1][m-1][0] + dp[m][j][k+1]);
                        }               
                    }
                    dp[i][j][k] = maxp;
                }
            }
        }
    return dp[0][N-1][0];

    }
};

