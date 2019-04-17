/*
https://leetcode-cn.com/problems/longest-arithmetic-sequence/
Longest Arithmetic Sequence
Given an array A of integers, return the length of the longest arithmetic subsequence in A.
Recall that a subsequence of A is a list A[i_1], A[i_2], ..., A[i_k] with 0 <= i_1 < i_2 < ... < i_k <= A.length - 1, 
and that a sequence B is arithmetic if B[i+1] - B[i] are all the same value (for 0 <= i < B.length - 1).
 
Example 1:
Input: [3,6,9,12]
Output: 4
Explanation: 
The whole array is an arithmetic sequence with steps of length = 3.
Example 2:
Input: [9,4,7,2,10]
Output: 3
Explanation: 
The longest arithmetic subsequence is [4,7,10].
Example 3:
Input: [20,1,15,3,10,5,8]
Output: 4
Explanation: 
The longest arithmetic subsequence is [20,15,10,5].
 
Note:
2 <= A.length <= 2000
0 <= A[i] <= 10000

*/

#include<vector>
#include<unordered_map>
using namespace std;

class Solution 
{
public:
    int longestArithSeqLength(vector<int>& A) 
    {
        int N =  A.size();
        vector< unordered_map<int,int> > vdict(N,unordered_map<int,int>());
        int maxd = 0;
        for(int i = 1; i< N; ++i)
        {
            for( int j = 0; j<i; ++j)
            {
                int d = A[i]-A[j];
                if(vdict[j].count(d))
                {
                    if(vdict[i][d]<vdict[j][d]+1)
                    {
                        vdict[i][d] = vdict[j][d]+1;
                    }
                }
                else
                {
                    if(vdict[i][d]<2)
                    {
                        vdict[i][d] = 2;
                    }
                }
                if( vdict[i][d]>maxd)
                {
                    maxd = vdict[i][d];
                }
            }
        }
        return maxd;
    }
};