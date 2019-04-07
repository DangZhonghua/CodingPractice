/*
https://leetcode-cn.com/problems/longest-consecutive-sequence/
Longest Consecutive Sequence

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
Your algorithm should run in O(n) complexity.
Example:
Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

*/


/*

O(N) WTF
16号楼二单元2004室
*/

#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<iostream>
#include<tuple>
using namespace std;
class Solution
{
public:
	int longestConsecutive(vector<int>& nums)
	{
		int maxc = 0;
		unordered_map<int, int>  bigMap;
		unordered_map<int, int>  smallMap;
		unordered_set<int>  numSet;

		for (auto v : nums)
		{
			numSet.insert(v);
		}

		for (auto v : nums)
		{
			if (0 == bigMap.count(v))
			{

				int t = v - 1;
				while (numSet.count(t))
				{
					--t;
				}
				int l = v + 1;
				while (numSet.count(l))
				{
					++l;
				}

				for (int i = t + 1; i < l; ++i)
				{
					bigMap[i] = l - i;
					smallMap[i] = i - t;
					if (maxc < (bigMap[i] + smallMap[i] - 1))
					{
						maxc = (bigMap[i] + smallMap[i] - 1);
					}
				}
			}
		}
		return maxc;
	}
};


/*

int LongestConsecutiveSubsequence(int*a, int N)
{
    unordered_map<int,int> hash;
    int maxindex = 0;
    int maxlen  = 0;

    std::sort(a,a+N);
    
    for(int i = 0; i<N; ++i)
    {
        hash[a[i]] = hash[a[i]-1]+1;
        if(hash[a[i]]> maxlen)
        {
            maxindex = a[i];
            maxlen = hash[a[i]];
        }
    }
    
    cout<<maxlen<<endl;
    

    return 0;
}

*/