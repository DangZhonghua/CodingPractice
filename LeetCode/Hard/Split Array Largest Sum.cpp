/*

https://leetcode-cn.com/problems/split-array-largest-sum/
Split Array Largest Sum
Given an array which consists of non-negative integers and an integer m, 
you can split the array into m non-empty continuous subarrays. 
Write an algorithm to minimize the largest sum among these m subarrays. 
Note:
If n is the length of array, assume the following constraints are satisfied: 
1 ≤ n ≤ 1000
1 ≤ m ≤ min(50, n)

Examples: 
Input:
nums = [7,2,5,10,8]
m = 2

Output:
18

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.

*/

/*

use knapsnack technique to solve this.
https://segmentfault.com/a/1190000008377782
https://blog.csdn.net/u014688145/article/details/69525838


说它革新了我的世界观在于它的解决问题思路刷新了我对算法的认识，我的解法典型的给你nums,m想办法去求解minMaxsum，
而大神的思路是假设我们已经在解空间里有了一系列minMaxsums，去搜索一个minMaxsum使得符合m，这让我非常震撼。
很简单，可能的minMaxsum有哪些，中间的哪些minMaxsum我们是不知道的，这是问题的关键！所以这个问题就假设最极端的两头情况：

当 m = 1 时，这种情况，minMaxsum = 整个数组之和。
当 m = 数组长度时，这种情况，minMaxsum = 数组中最大的那个元素。

如：[7,2,5,10,8]  m = 1， 输出 minMaxsum = 32 
而：[7,2,5,10,8]  m = 5， 输出 minMaxsum = 10

所以我们有了两头的解！可以看成如下形式：

  m  5   4  3  2  1
sum 10   ?  ?  ?  32
--------------------- 
作者：Demon的黑与白 
来源：CSDN 
原文：https://blog.csdn.net/u014688145/article/details/69525838 
版权声明：本文为博主原创文章，转载请附上博文链接！

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) 
    {
        int minv = 0;
        long long sum = 0;
        for(int n:nums)
        {
            minv = minv<n? n:minv;
            sum += n;
        }
        return BinarySearchTarget(nums,m,sum,minv);
    }
private:
    int BinarySearchTarget(vector<int>& nums, int m, long long high, long long low )
    {
        long long mid = 0;
        while(low<high) //NOT use low<=high, otherwise dead-loop
        {
            mid = (low+high)/2;
            if(IsVaildMinMaxValue(nums,m,mid))
            {
                high = mid;
            }
            else
            {
                low = mid+1;
            }
        }
        return high;
    }

    bool IsVaildMinMaxValue(vector<int>& nums, int m, long long target)
    {
        int nGroup = 1; // should be initialize as 1, since one point will partition into two segments
        long long sum = 0;
        for(int n:nums)
        {
            sum += n;
            if(sum>target)
            {
                sum = n;
                ++nGroup;
                if(nGroup>m)
                {
                    return false;
                }
            }
        }
        return true;
    }
};