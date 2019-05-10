/*
https://leetcode-cn.com/problems/top-k-frequent-elements/
347. Top K Frequent Elements

Given a non-empty array of integers, return the k most frequent elements.
Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:
Input: nums = [1], k = 1
Output: [1]
Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

*/



#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;


class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int> vr;
        unordered_map<int,int> freq;
        for(int n:nums)
        {
            freq[n] += 1;
        }
        auto f = [&](int i, int j)->bool
        {
            return freq[i]>freq[j];
        };
        priority_queue<int,vector<int>, decltype(f) > minHeap(f);

        for(auto e:freq)
        {
            if(minHeap.size()== k)
            {
                if(freq[e.first] > freq[minHeap.top()])
                {
                    minHeap.pop();
                    minHeap.push(e.first);
                }
            }
            else
            {
                minHeap.push(e.first);
            }
        }
        while(!minHeap.empty())
        {
            vr.push_back(minHeap.top());
            minHeap.pop();
        }
        return vr;
    }
};