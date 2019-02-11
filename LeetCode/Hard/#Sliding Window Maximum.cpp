/*
https://leetcode-cn.com/problems/sliding-window-maximum/
Sliding Window Maximum

Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.
Example:
Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Note: 
You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.
Follow up:
Could you solve it in linear time?

*/

/*

这个问题可以用单调队列解决。


*/


#include<iostream>
#include<vector>
#include<deque>
using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int K) 
    {
        deque<int>  DecrQ;
        vector<int> vmax;
        int i = 0;
        
        for( ; i<K && i< nums.size(); ++i)
        {
            while(!DecrQ.empty() && nums[ DecrQ.back()]<=nums[i])
            {
                DecrQ.pop_back();
            }
            DecrQ.push_back(i);
        }

        for( ; i<nums.size(); ++i)
        {
            vmax.push_back(nums[DecrQ.front()]);

            while(!DecrQ.empty() && DecrQ.front()<= (i-K))
            {
                DecrQ.pop_front();
            }
            while(!DecrQ.empty() && nums[DecrQ.back()]<=nums[i])
            {
                DecrQ.pop_back();
            }
            DecrQ.push_back(i);
        }
        if( !DecrQ.empty())
        {
            vmax.push_back(nums[DecrQ.front()]);
        }
        return vmax;
    }
};