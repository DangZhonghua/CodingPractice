/*
485. Max Consecutive Ones
https://leetcode-cn.com/problems/max-consecutive-ones/
Given a binary array, find the maximum number of consecutive 1s in this array.
Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.

Note: 
The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000

*/

#include <vector>
using namespace std;

class Solution
{
  public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int i = 0;
        int N = nums.size();
        int s = -1;
        int e = 0;
        int maxlen = 0;

        while (i < N)
        {
            if (1 == nums[i])
            {
                if (-1 == s)
                {
                    s = i;
                    e = i;
                }
                else
                {
                    e = i;
                }
            }
            else
            {
                if (-1 != s)
                {
                    if (maxlen < (e - s + 1))
                    {
                        maxlen = (e - s + 1);
                    }
                    s = -1;
                }
            }
            ++i;
        }

        if (-1 != s && maxlen < (e - s + 1))
        {
            maxlen = (e - s + 1);
        }

        return maxlen;
    }
};
