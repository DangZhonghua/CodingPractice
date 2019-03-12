/*
https://leetcode-cn.com/problems/delete-and-earn/

Delete and Earn
Given an array nums of integers, you can perform operations on the array.
In each operation, you pick any nums[i] and delete it to earn nums[i] points. 
After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.
You start with 0 points. Return the maximum number of points you can earn by applying such operations.

Example 1:
Input: nums = [3, 4, 2]
Output: 6
Explanation: 
Delete 4 to earn 4 points, consequently 3 is also deleted.
Then, delete 2 to earn 2 points. 6 total points are earned.


Example 2:
Input: nums = [2, 2, 3, 3, 3, 4]
Output: 9
Explanation: 
Delete 3 to earn 3 points, deleting both 2's and the 4.
Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
9 total points are earned.

Note:
The length of nums is at most 20000.
Each element nums[i] is an integer in the range [1, 10000].

*/



#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;



class Solution 
{
public:
    int deleteAndEarn(vector<int>& nums) 
    {
        unordered_map<int, int> mapNum2Count;
        int maxv = 0;

        for(int n:nums)
        {
            mapNum2Count[n] += 1;
            if(n>maxv)
            {
                maxv = n;
            }
        }

        vector<int> dp(maxv+1,0);   
        for(int i = 1; i<=maxv; ++i)
        {
            if(i>=2)
            {
                 dp[i] = max( dp[i-2] + mapNum2Count[i]*i, dp[i-1]);
            }
            else
            {
                 dp[i] = max(mapNum2Count[i]*i, dp[i-1]);
            }
        }
        return dp[maxv];
    }
};

int main()
{
    vector<int> nums1{2, 2, 3, 3, 3, 4};
    Solution sol;
    cout<<sol.deleteAndEarn(nums1)<<endl;

    return 0;
}