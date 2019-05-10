/*
https://leetcode-cn.com/problems/split-array-into-consecutive-subsequences/
http://www.cnblogs.com/grandyang/p/7525821.html

Split Array into Consecutive Subsequences

You are given an integer array sorted in ascending order (may contain duplicates),
you need to split them into several subsequences,
where each subsequences consist of at least 3 consecutive integers. Return whether you can make such a split.
Example 1:
Input: [1,2,3,3,4,5]
Output: True
Explanation:
You can split them into two consecutive subsequences :
1, 2, 3
3, 4, 5

Example 2:
Input: [1,2,3,3,4,4,5,5]
Output: True
Explanation:
You can split them into two consecutive subsequences :
1, 2, 3, 4, 5
3, 4, 5

Example 3:
Input: [1,2,3,4,4,5]
Output: False

Note:
The length of the input is in range of [1, 10000]

*/

/*

We iterate through the array once to get the frequency of all the elements in the array

We iterate through the array once more and for each element we either see if it can be appended to
a previously constructed consecutive sequence or if it can be the start of
a new consecutive sequence. If neither are true, then we return false.

*/



/*

111
222
333
444
555 5
66
77

*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*

We iterate through the array once to get the frequency of all the elements in the array

We iterate through the array once more and for each element we either see if it can be appended to
a previously constructed consecutive sequence or if it can be the start of
a new consecutive sequence. If neither are true, then we return false.

*/

class Solution {
public:
	bool isPossible(vector<int>& nums)
	{
		bool  bCon = true;
		unordered_map<int, int> freq;
		unordered_map<int, int> append;

		for (auto n : nums)
		{
			freq[n] += 1;
		}

		for (int i = 0; i < nums.size(); ++i)
		{
			if (0 == freq[nums[i]]) // "start of a new consecutive sequence" can cause this
			{
				continue;
			}
			else if (append[nums[i]]>0) // current can be append the sequence.
			{
				--append[nums[i]];
				++append[nums[i] + 1]; // generate the append request: greedy choice, always generate the append 
			}
			else if (freq[nums[i] + 1] > 0 && freq[nums[i] + 2] > 0)
			{
				--freq[nums[i] + 1];
				--freq[nums[i] + 2];
				++append[nums[i] + 3]; // generate the append request: greedy choice, always generate the append 
			}
			else
			{
				bCon = false;
				break;
			}
			--freq[nums[i]];
		}

		return bCon;
	}
};

int main()
{
	Solution sol;
	vector<int> a1{ 1,2,3,3,4,5 };
	
	cout << sol.isPossible(a1) << endl;


	return 0;
}


// class Solution {
// public:
//     bool isPossible(vector<int>& nums) 
//     {
//         unordered_map<int, int> freq, need;
//         for (int num : nums) ++freq[num];
//         for (int num : nums) 
//         {
//             if (freq[num] == 0) 
//             continue;
//             else if (need[num] > 0) 
//             {
//                 --need[num];
//                 ++need[num + 1];
//             } 
//             else if (freq[num + 1] > 0 && freq[num + 2] > 0) 
//             {
//                 --freq[num + 1];
//                 --freq[num + 2];
//                 ++need[num + 3];
//             } 
//             else 
//             return false;

//             --freq[num];
//         }
//         return true;
//     }
// };


