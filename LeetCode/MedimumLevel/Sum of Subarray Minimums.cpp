/*
Sum of Subarray Minimums
https://leetcode-cn.com/problems/sum-of-subarray-minimums/
https://leetcode.com/articles/sum-of-subarray-minimums/

Given an array of integers A, find the sum of min(B), where B ranges over every (contiguous) subarray of A.

Since the answer may be large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: [3,1,2,4]
Output: 17
Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.
 

Note:

1 <= A.length <= 30000
1 <= A[i] <= 30000
*/


#include<vector>
#include<deque>
#include<climits>
using namespace std;


// class Solution 
// {
// public:
//     int sumSubarrayMins(vector<int>& A) 
//     {
//         int N = A.size();
//         int sum = 0;
//         vector<int>  mq;

//         for(int i = 0; i<N; ++i)
//         {
//             mq.clear();
//             for(int j = i; j<N; ++j)
//             {
//                 if(!mq.empty())
//                 {
//                     if(mq.back()<A[j])
//                     {
//                         mq.push_back(mq.back());
//                     }
//                     else
//                     {
//                         mq.push_back(A[j]);
//                     }
//                 }
//                 else
//                 {
//                     mq.push_back(A[j]);
//                 }
//                 sum += mq.back();
//                 sum %= 1000000007;
//             }
//         }

//         return sum;
//     }
// };

class Solution 
{
public:
    int sumSubarrayMins(vector<int>& A) 
    {
        int N = A.size();
        int sum = 0;
        vector<int>  mq;

        for(int i = 0; i<N; ++i)
        {
            int minv = INT_MAX;
            for(int j = i; j<N; ++j)
            {
                if(minv>A[j])
                {
                    minv = A[j];
                }
                sum += minv;
                sum %= 1000000007;
            }
        }

        return sum;
    }
};