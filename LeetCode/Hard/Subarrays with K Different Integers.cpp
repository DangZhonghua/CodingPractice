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
	int subarraysWithKDistinct(vector<int>& A, int K)
	{
		int WK 		= 0;
		int countk 	= 0;
		int N = A.size();
		int i = 0;
		int j = 0;
		int ws = 0;

		vector<int> dict(N+1,0); // record the largest index for specific value

		while (j < N)
		{
			if( dict[ A[j] ]  ) // value of A[j] has been counted
			{
				dict[A[j]] = (j+1); // +1 for 1-based index. this is also used for  boolean
				while(A[ws] == A[j])
				{
				  ++ws;
				}
				if(WK == K)
				{
					countk += (ws-i);
				}	
			}
			else
			{
				// in the else clause, the count of unqiue number will be increase
				if(WK == K) // narrow the window in this case.
				{
					while((i+1) != dict[A[i]])
					{
						++i;
					}
					dict[A[i]] = 0;
					ws = i+1;
				}
				dict[ A[j] ] = (j+1);
				++WK;
				if(K == WK)
				{
					++countk;
				}
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