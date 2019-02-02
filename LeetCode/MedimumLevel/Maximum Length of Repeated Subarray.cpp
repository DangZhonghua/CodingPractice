/*
https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/
Maximum Length of Repeated Subarray

Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.
Example 1:
Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].

Note:
1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100

*/

/*
                DP[i-1][j-1] + 1 if A[i] == B[j]
DP[i][j] =      
                0 if(A[i] != B[j])

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) 
    {
        int R = A.size();
        int C = B.size();
        vector<vector<int>> lcs(R+1,vector<int>(C+1,0));
        
        for(int i = 1; i<=R; ++i)
        {
            for(int j = 1;j<=C;++j)
            {
                if(A[i-1] == B[j-1])
                {
                    lcs[i][j] = lcs[i-1][j-1]+1;
                }
            }
        }
        return lcs[R][C];
    }
};