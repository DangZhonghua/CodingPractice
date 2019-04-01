/*
https://leetcode-cn.com/problems/subarrays-with-k-different-integers/

992. Subarrays with K Different Integers

Given an array A of positive integers, call a (contiguous, not necessarily distinct)
subarray of A good if the number of different integers in that subarray is exactly K.
(For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)
Return the number of good subarrays of A.

Example 1:
Input: A = [1,2,1,2,3], K = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
Example 2:
Input: A = [1,2,1,3,4], K = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].

Note:
1 <= A.length <= 20000
1 <= A[i] <= A.length
1 <= K <= A.length

*/

/*

Slide window[s,j]: the minmum window end at j with k different number.

*/


#include<unordered_map>
#include<vector>
#include<iostream>
using namespace std;

class Solution
{
public:
	int subarraysWithKDistinct(vector<int>& a, int K)
	{
		int WK = 0;
		int countk = 0;
		int N = a.size();
		int i = 0;
		int j = 0;
		int ws = 0;

		vector<int> dict(N + 1, 0); // record the largest index for specific value

		while (j < N)
		{
			if (WK == K)
			{
				if (dict[a[j]]) // the value instance of A[j] has been checked
				{
					dict[a[j]] = j + 1; // we only update now, but when we count the subarray.
					++countk; // for new-created because of a[j]
					while (ws != dict[a[ws]] - 1)
					{
						++ws;
					}
					countk += (ws - i);
				}
				else
				{
					//we need decrease the count of unique number

					dict[a[j]] = j + 1; // we only update now, but when we count the subarray.
					++countk;
					bool bextended = false;
					while (ws != dict[a[ws]] - 1)
					{
						bextended = true;
						++ws;
					}
					if (bextended)
					{
						countk += (ws - i);
					}

					dict[a[ws]] = 0;
					++ws;
					i = ws;
				}
			}
			else
			{

				if (dict[a[j]]) // the value instance of A[j] has been checked
				{
					dict[a[j]] = j + 1;
				}
				else
				{
					dict[a[j]] = j + 1;
					++WK;
					if (WK == K) // count if the a[j] incur WK == K 
					{
						++countk;
						while (ws != dict[a[ws]] - 1)
						{
							++ws;
						}
						countk += (ws - i);
					}
				}
			}
			++j;
		}

		return countk;
	}
};

// int main()
// {
// 	vector<int> a{ 1, 2, 1, 2, 3 };
// 	int K = 2;
// 	Solution sol;

// 	//cout << sol.subarraysWithKDistinct(a, K) << endl;

// 	vector<int> b{ 1,2,1,3,4 };
// 	K = 3;
// 	//cout << sol.subarraysWithKDistinct(b, K) << endl;

// 	vector<int> c{ 1,1,1,1,1,1,1,1,1 };
// 	K = 1;
// 	//cout << sol.subarraysWithKDistinct(c, K) << endl;

// 	vector<int> d{ 1,2,1,2,3 };
// 	K = 2;
// 	//cout << sol.subarraysWithKDistinct(d, K) << endl;

// 	//vector<int> e{ 2,2,1,2,2,2,1,1 };
// 	vector<int> e{ 2,2,1,2 };

// 	K = 2;
// 	//cout << sol.subarraysWithKDistinct(e, K) << endl;

// 	vector<int> vf{ 27, 27, 43, 28, 11, 20, 1, 4, 49, 18, 37, 31, 31, 7, 3, 31, 50, 6, 50, 46, 4, 13, 31, 49, 15, 52, 25, 31, 35, 4, 11, 50, 40, 1, 49, 14, 46, 16, 11, 16, 39, 26, 13, 4, 37, 39, 46, 27, 49, 39, 49, 50, 37, 9, 30, 45, 51, 47, 18, 49, 24, 24, 46, 47, 18, 46, 52, 47, 50, 4, 39, 22, 50, 40, 3, 52, 24, 50, 38, 30, 14, 12, 1, 5, 52, 44, 3, 49, 45, 37, 40, 35, 50, 50, 23, 32, 1, 2 };
// 	K = 20;
// 	cout << sol.subarraysWithKDistinct(vf, K) << endl;

// 	return 0;
// }
