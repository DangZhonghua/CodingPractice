/*
Maximum Length of Pair Chain
https://leetcode-cn.com/problems/maximum-length-of-pair-chain/
You are given n pairs of numbers. In every pair, the first number is always smaller than the second number. 
Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion. 
Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order. 
Example 1:
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]

Note:
The number of given pairs will be in the range [1, 1000].

*/

#include<vector>
using namespace std;

class Solution 
{

    struct PairsCompator
    {
        bool operator ()(const vector<int>& lhs, const vector<int>& rhs) const
        {
            //the following if cases: try to make the pair array increasly sorted.
            if(lhs[1]<rhs[0])
            {
                return true;
            }
            else if(lhs[1] < rhs[1])  
            {
                return true;
            }
            return false;
        }
    };
    
public:
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        vector<int> lpis(pairs.size(),1);
        
        std::sort(pairs.begin(),pairs.end(),PairsCompator());
        int maxlen = 1;
        for(int i = 1; i< pairs.size(); ++i)
        {
            for(int j = 0; j<i; ++j)
            {
                if( pairs[j][1]< pairs[i][0] && lpis[i]<= lpis[j]+1)
                {
                    lpis[i] = lpis[j] + 1;
                }
            }
            if(lpis[i]>maxlen)
            {
                maxlen = lpis[i];
            }
        }
        return maxlen;
    }
};