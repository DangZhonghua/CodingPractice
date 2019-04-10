/*
https://leetcode-cn.com/problems/max-consecutive-ones-iii/
1004. Max Consecutive Ones III

Given an array A of 0s and 1s, we may change up to K values from 0 to 1.
Return the length of the longest (contiguous) subarray that contains only 1s. 
 
Example 1:
Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
Output: 6
Explanation: 
[1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
Example 2:
Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
Output: 10
Explanation: 
[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
 
Note:
1 <= A.length <= 20000
0 <= K <= A.length
A[i] is 0 or 1 

*/

/*

use backtracking technqiue?     lost my mind again!!!
See http://www.cnblogs.com/grandyang/p/6376115.html 

Why I lost my mind again? Seems I always count the K for every specific number: which zero number be flipped or not.
But we just count the number, NEED NOT care the which number being flipped.

*/

#include<vector>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;

class Solution 
{
public:
    int longestOnes(vector<int>& A, int K) 
    {
        queue<int> zeroQ;
        int maxlen = 0;
        int left = 0;
        int right = 0;
        int N = A.size();

        for(int right = 0; right<N; ++right)
        {
            if( 0 == A[right])
            {
                zeroQ.push(right);
            }
            while(zeroQ.size()>K)
            {
                left = zeroQ.front()+1;
                zeroQ.pop();
            }
            maxlen = max(maxlen,right-left+1);
        }
        return maxlen;
    }
};

class Solution1 
{
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int res = 0, zero = 0, left = 0, k = 1;
        for (int right = 0; right < nums.size(); ++right) 
        {
            if (nums[right] == 0) ++zero;
            while (zero > k) 
            {
                if (nums[left++] == 0) --zero;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};



class Solution2 {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int res = 0, left = 0, k = 1;
        queue<int> q;
        for (int right = 0; right < nums.size(); ++right) 
        {
            if (nums[right] == 0) 
            {
                q.push(right);
            }
            if (q.size() > k) 
            {
                left = q.front() + 1; 
                q.pop();
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};



