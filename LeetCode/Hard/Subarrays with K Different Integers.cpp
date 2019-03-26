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
Slide window[i,j]:

There are K different in [i,j]: ++j;
if more than K, then ++i util less than k.

*/


#include<unordered_map>
#include<vector>
#include<iostream>
using namespace std;

class Solution
{
public:
	int subarraysWithKDistinct(vector<int>& A, int K)
	{
		int countk = 0;
		int N = A.size();
		unordered_map<int, int> mapValue2Count;

		int i = 0;
		int j = 0;

		while (j < N)
		{
			if (mapValue2Count.size() == K)
			{
				++countk; // count the latest
				if (mapValue2Count.find(A[j]) == mapValue2Count.end())
				{
					mapValue2Count[A[i]] -= 1;
					if (mapValue2Count[A[i]] == 0)
					{
						mapValue2Count.erase(A[i]);
					}
					while (mapValue2Count.size() == K)
					{
						++countk;
						++i;
						mapValue2Count[A[i]] -= 1;
						if (mapValue2Count[A[i]] == 0)
						{
							mapValue2Count.erase(A[i]);
						}
					}
				}
				mapValue2Count[A[j]] += 1; //including A[j]       
			}
			else
			{
				mapValue2Count[A[j]] += 1;
			}
			++j;
		}

		return countk;
	}
};

int main()
{
	vector<int> a{ 1, 2, 1, 2, 3 };
	int K = 2;
	Solution sol;

	sol.subarraysWithKDistinct(a, K);


	return 0;
}