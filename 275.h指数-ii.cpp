/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H指数 II
 *
 * https://leetcode-cn.com/problems/h-index-ii/description/
 *
 * algorithms
 * Medium (36.50%)
 * Total Accepted:    1.3K
 * Total Submissions: 3.4K
 * Testcase Example:  '[0,1,3,5,6]'
 *
 * 给定一位研究者论文被引用次数的数组（被引用次数是非负整数），数组已经按照升序排列。编写一个方法，计算出研究者的 h 指数。
 * 
 * h 指数的定义: “h 代表“高引用次数”（high citations），一名科研人员的 h 指数是指他（她）的 （N 篇论文中）至多有 h
 * 篇论文分别被引用了至少 h 次。（其余的 N - h 篇论文每篇被引用次数不多于 h 次。）"
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: citations = [0,1,3,5,6]
 * 输出: 3 
 * 解释: 给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 0, 1, 3, 5, 6 次。
 * 由于研究者有 3 篇论文每篇至少被引用了 3 次，其余两篇论文每篇被引用不多于 3 次，所以她的 h 指数是 3。
 * 
 * 
 * 
 * 说明:
 * 
 * 如果 h 有多有种可能的值 ，h 指数是其中最大的那个。
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 这是 H指数 的延伸题目，本题中的 citations 数组是保证有序的。
 * 你可以优化你的算法到对数时间复杂度吗？
 * 
 * 
 */

#include<vector>
using namespace std;
class Solution
{
public:
	int hIndex(vector<int>& citations)
	{
		int h = 0;
		int N = citations.size();
		for (int i = 0; i < citations.size(); ++i)
		{
			int vl = SearchleftBoundary(citations, citations[i], 0, i);
			int vr = SearchRightBoundary(citations, citations[i], i, N - 1);
			
			int noless = N - vl;
			int large = N - vr;

			if (noless <= citations[i])
			{
				if (h < noless)
				{
					h = noless;
				}
			}
			else
			{
				if (citations[i] >= large && h <= citations[i])
				{
					h = citations[i];
				}
			}
		}

		return h;
	}
private:
	int SearchleftBoundary(vector<int>& nums, int x, int s, int e)
	{
		while (s <= e)
		{
			int m = (s + e) / 2;
			if (x == nums[m])
			{
				e = m - 1;
			}
			else if (x < nums[m])
			{
				e = m - 1;
			}
			else
			{
				s = m + 1;
			}
		}

		return e + 1;
	}

	int SearchRightBoundary(vector<int>& nums, int x, int s, int e)
	{
		while (s <= e)
		{
			int m = (s + e) / 2;
			if (x == nums[m])
			{
				s = m + 1;
			}
			else if (x < nums[m])
			{
				e = m - 1;
			}
			else
			{
				s = m + 1;
			}
		}
		return s - 1;
	}
};

