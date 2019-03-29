/*
https://leetcode-cn.com/problems/continuous-subarray-sum/
523. Continuous Subarray Sum
 Given a list of non-negative numbers and a target integer k, write a function to check 
 if the array has a continuous subarray of size at least 2 that sums up to the multiple of k, 
 that is, sums up to n*k where n is also an integer.

Example 1:

Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.

Example 2:

Input: [23, 2, 6, 4, 7],  k=6
Output: True
Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.

Note:

    The length of the array won't exceed 10,000.
    You may assume the sum of all the numbers is in the range of a signed 32-bit integer.
ss

*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// class Solution 
// {
// public:
//     bool checkSubarraySum(vector<int>& nums, int k) 
//     {
//         if( 0 == k)
//         {
//             return false;
//         }
//         k = k>0? k:-k;
//         bool bSum = false;
//         int N = nums.size();
//        // vector<int> mapReminder2Index(k+1,-1);
//        unordered_map<int,int> mapReminder2Index;
//         vector<int> vsum(N,0);
//         for(int i = 1; i<N; ++i)
//         {
//             vsum[i] = (vsum[i-1]+nums[i]);
//         }

//         for(int i = 0; i<N; ++i)
//         {
//             int m = vsum[i]%k;
//             if( 0 != mapReminder2Index[m])
//             {
//                 if(i-mapReminder2Index[m]+1>1)
//                 {
//                     bSum = true;
//                     break;
//                 }
//             }
//             else
//             {
//                 mapReminder2Index[m] = i+1;
//             }
//         }
//         return bSum;
//     }
// };

class Solution 
{
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size(), sum = 0;
        unordered_map<int, int> m{{0,-1}};
        for (int i = 0; i < n; ++i) 
        {
            sum += nums[i];
            int t = (k == 0) ? sum : (sum % k);
            if (m.count(t)) 
            {
                if (i - m[t] > 1) return true;
            } 
            else 
            {
             m[t] = i;
            }
        }
        return false;
    }
};