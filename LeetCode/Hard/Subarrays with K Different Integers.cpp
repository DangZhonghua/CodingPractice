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
        int i = -1;
        int j = 0;
        
        for(int L = K; L<=N; ++L)
        {
            mapValue2Count.clear();
            for(int i = 0; i<L;++i)
            {
                mapValue2Count[A[i]] += 1;
            }
            if(K == mapValue2Count.size())
            {
                ++countk;
            }
            for(int i = 1; i+L<=N; ++i)
            {

            }
        }
    }
};