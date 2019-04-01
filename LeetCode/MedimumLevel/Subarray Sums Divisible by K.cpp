/*
https://leetcode-cn.com/problems/subarray-sums-divisible-by-k/

974. Subarray Sums Divisible by K

Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.

Example 1:
Input: A = [4,5,0,-2,-3,1], K = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by K = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

Note:
1 <= A.length <= 30000
-10000 <= A[i] <= 10000
2 <= K <= 10000

*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution
{
public:
	int subarraysDivByK(vector<int>& A, int K)
	{
		int sum = 0;
		int count = 0;
		int N = A.size();
		unordered_map<int, int> mapSum2Count;

		for (int i = 0; i < N; ++i)
		{
			sum += A[i];
			int r = sum % K;
			//cout << sum << " : " << r << " " << endl;
			if (0 == r)
			{
				++count;
			}

			if (mapSum2Count.count(r))
			{
				count += mapSum2Count[r];
				
				if (r>0 && mapSum2Count.count(r - K) )  // example: r =2, check if there are -5  if K= 7
				{
					count += mapSum2Count[r - K];
				}
				if (r < 0 && mapSum2Count.count(K + r)) // example: r = -5, check if there are 2 if k = 7
				{
					count += mapSum2Count[K + r];
				}
				mapSum2Count[r] += 1; // forget this at first time. 

			}
			else
			{
				if (r > 0 && mapSum2Count.count(r - K))
				{
					count += mapSum2Count[r - K];
				}
				if (r < 0 && mapSum2Count.count(K + r))
				{
					count += mapSum2Count[K + r];
				}
	
				mapSum2Count[r] += 1;
			}
		}
		//cout << endl;
		return count;
	}
};


int main()
{
	Solution sol;
	vector<int> A1{ 4, 5, 0, -2, -3, 1 };
	int K = 5;

	//cout << sol.subarraysDivByK(A1, K) << endl;

	vector<int> A2{ -1, 2, 9 };
	K = 2;
	//cout << sol.subarraysDivByK(A2, K) << endl;

	vector<int> A3{ 2, -2, 2, -4 };
	K = 6;

	//cout << sol.subarraysDivByK(A3, K) << endl;

	vector<int> A4{ 7, -5, 5, -8, -6, 6, -4, 7, -8, -7 };
	K = 7;

	cout << sol.subarraysDivByK(A4, K) << endl;

	return 0;
}