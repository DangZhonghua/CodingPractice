/*
https://leetcode-cn.com/problems/guess-number-higher-or-lower-ii/
Guess Number Higher or Lower II

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.

However, when you guess a particular number x, and you guess wrong, you pay $x. 
You win the game when you guess the number I picked.

Example:

n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

You end up paying $5 + $7 + $9 = $21.

Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.

*/

class Solution {
public:
    int getMoneyAmount(int n) 
    {}
}


class Solution {
    public int getMoneyAmount(int n) {
        /**
        dp[i][j]表示从[i,j]中猜出正确数字所需要的最少花费金额.(dp[i][i] = 0)
        假设在范围[i,j]中选择x, 则选择x的最少花费金额为: max(dp[i][x-1], dp[x+1][j]) + x
        用max的原因是我们要计算最坏反馈情况下的最少花费金额(选了x之后, 正确数字落在花费更高的那侧)
        
        初始化为(n+2)*(n+2)数组的原因: 处理边界情况更加容易, 例如对于求解dp[1][n]时x如果等于1, 需要考虑dp[0][1](0不可能出现, dp[0][n]为0)
        而当x等于n时, 需要考虑dp[n+1][n+1](n+1也不可能出现, dp[n+1][n+1]为0)
        
        如何写出相应的代码更新dp矩阵, 递推式dp[i][j] = max(max(dp[i][x-1], dp[x+1][j]) + x), x~[i:j], 可以画出矩阵图协助理解, 可以发现
        dp[i][x-1]始终在dp[i][j]的左部, dp[x+1][j]始终在dp[i][j]的下部, 所以更新dp矩阵时i的次序应当遵循bottom到top的规则, j则相反, 由于
        i肯定小于等于j, 所以我们只需要遍历更新矩阵的一半即可(下半矩阵)
        **/
        int[][] dp = new int[n+2][n+2];
        for(int i = n; i >= 1; --i) {
            for(int j = i; j <= n; ++j) {
                if(i == j)
                    dp[i][j] = 0;
                else {
                    dp[i][j] = Integer.MAX_VALUE;
                    for(int x = i; x <= j; ++x) 
                        dp[i][j] = Math.min(dp[i][j], Math.max(dp[i][x-1], dp[x+1][j]) + x);
                }
            }
        }
        return dp[1][n];
    }
};


class Solution {
    public: int getMoneyAmount(int n) 
    {
       // int[][] dp = new int[n+2][n+2];
        vector< vector<int> > dp(n+2,vector<int>(n+2,0));
        for(int i = n; i >= 1; --i) {
            for(int j = i; j <= n; ++j) {
                if(i == j)
                    dp[i][j] = 0;
                else {
                    dp[i][j] = INT_MAX;
                    for(int x = i; x <= j; ++x) 
                        dp[i][j] = min(dp[i][j], max(dp[i][x-1], dp[x+1][j]) + x);
                }
            }
        }
        return dp[1][n];
    }
};