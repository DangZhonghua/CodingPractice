/*
Non-negative Integers without Consecutive Ones
https://leetcode-cn.com/problems/non-negative-integers-without-consecutive-ones/
http://www.cnblogs.com/grandyang/p/6959585.html

Given a positive integer n, find the number of non-negative integers less than or equal to n, 
whose binary representations do NOT contain consecutive ones.
Example 1:
Input: 5
Output: 5
Explanation: 
Here are the non-negative integers <= 5 with their corresponding binary representations:
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
    110
5 : 101
    111

    1000
    1100
    1010
    1110
    
Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 

Note: 1 <= n <= 10^9
*/

/*
Dynamic programming:
subproblem: prefix [:i]

what is the relationship between subproblem

dp[i][0] = dp[i-1][0] + dp[i-1][1]
dp[i][1] = dp[i-1][0]

total = dp[n][0] + dp[n][1]

*/



#include<vector>
#include<string>
#include<iostream>
using namespace std;


class Solution 
{
public:
    int findIntegers(int num) 
    {
        if( 0 == num)
        {
            return 0;
        }

        //Calc the bit count of num
        int nCount  = 1; //1 for single 0 bits
        int n       = num;
        int nBits   = 0;
        string strnum;
        while(n)
        {
            strnum += ((n&1)?"1":"0");
            ++nBits;
            n >>=1;
        }
        vector<int> vones(nBits,0);
        vector<int> vzeros(nBits,0);
        
        for(int i = 1; i<nBits; ++i)
        {
            vzeros[i] = vzeros[i-1] + vones[i-1];
            vones[i]  = vzeros[i-1];
        }

        int ans = (vzeros[nBits-1] + vones[nBits-1]);
        
        //find the most significant continuous "one" bits
        for(int i = nBits-2; i>=0; --i)
        {
            if('1' == strnum[i] && '1' == strnum[i+1])
            {
                break;
            }
            if( '0' == strnum[i] && '0' == strnum[i+1])
            {
                ans -= vones[i];
            }
        }
        return ans;
    }
};


/*

其实长度为k的二进制数字符串没有连续的1的个数是一个斐波那契数列f(k)。比如当k=5时，二进制数的范围是00000-11111，
我们可以将其分为两个部分，00000-01111和10000-10111，因为任何大于11000的数字都是不成立的，
因为有开头已经有了两个连续1。而我们发现其实00000-01111就是f(4)，而10000-10111就是f(3)，
所以f(5) = f(4) + f(3)，这就是一个斐波那契数列啦。那么我们要做的首先就是建立一个这个数组，方便之后直接查值。
我们从给定数字的最高位开始遍历，如果某一位是1，后面有k位，就加上f(k)，
因为如果我们把当前位变成0，那么后面k位就可以直接从斐波那契数列中取值了。
然后标记pre为1，再往下遍历，如果遇到0位，则pre标记为0。
如果当前位是1，pre也是1，那么直接返回结果。最后循环退出后我们要加上数字本身这种情况，参见代码如下： 

*/


/*

class Solution {
public:
    int findIntegers(int num) 
    {
        int res = 0, k = 31, pre = 0;
        vector<int> f(32, 0);
        f[0] = 1; f[1] = 2;
        for (int i = 2; i < 31; ++i) 
        {
            f[i] = f[i - 2] + f[i - 1];
        }
        while (k >= 0) 
        {
            if (num & (1 << k)) 
            {
                res += f[k];
                if (pre) 
                {
                     return res;
                }
                pre = 1;
            }
            else 
            {
                pre = 0;
            }
            --k;
        }
        return res + 1;
    }
};

*/