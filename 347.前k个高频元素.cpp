/*
* @lc app=leetcode.cn id=347 lang=cpp
*
* [347] 前K个高频元素
*
* https://leetcode-cn.com/problems/top-k-frequent-elements/description/
*
* algorithms
* Medium (53.53%)
* Total Accepted:    7.3K
* Total Submissions: 13.6K
* Testcase Example:  '[1,1,1,2,2,3]\n2'
*
* 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
*
* 示例 1:
*
* 输入: nums = [1,1,1,2,2,3], k = 2
* 输出: [1,2]
*
*
* 示例 2:
*
* 输入: nums = [1], k = 1
* 输出: [1]
*
* 说明：
*
*
* 你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
* 你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
*
*
*/

#include<unordered_map>
#include<queue>
#include<vector>
#include <iostream>
using namespace std;

class Solution
{
	struct FreqDataType
	{
		int  m_nFreq{ 0 };
		int  m_nValue{ 0 };
	};

	struct FreqDataTypeCompare
	{
		bool operator () (const FreqDataType& lhs, const FreqDataType& rhs) const
		{
			return lhs.m_nFreq > rhs.m_nFreq;
		}
	};


public:
	vector<int> topKFrequent(vector<int>& nums, int k)
	{
		unordered_map<int, int> freqDict;
		priority_queue<FreqDataType, vector<FreqDataType>, FreqDataTypeCompare> minHeap;

		// this is O(n) scan
		for (int v : nums)
		{
			freqDict[v] += 1;
		}

		for (auto it = freqDict.begin(); it != freqDict.end(); ++it)
		{
			if (minHeap.size() < k)
			{
				FreqDataType e;
				e.m_nFreq = it->second;
				e.m_nValue = it->first;
				minHeap.push(e);
			}
			else
			{
				if (minHeap.top().m_nFreq < it->second)
				{
					minHeap.pop();
					FreqDataType e;
					e.m_nFreq = it->second;
					e.m_nValue = it->first;
					minHeap.push(e);
				}
			}
		}

		vector<int> vr(minHeap.size(), 0);
		int P = minHeap.size() - 1;
		while (!minHeap.empty())
		{
			vr[P] = minHeap.top().m_nValue;
			--P;
			minHeap.pop();
		}


		//for (int e : vr)
		//{
		//	cout << e << " ";
		//}
		//cout << endl;

		return vr;
	}
};

// int main()
// {
// 	Solution sol;
// 	vector<int> nums1{ 1, 1, 1, 2, 2, 3 };
// 	int K = 2;

// 	sol.topKFrequent(nums1, K);


// 	return 0;
// }

