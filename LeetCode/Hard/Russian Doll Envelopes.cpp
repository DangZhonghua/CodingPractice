/*
https://leetcode-cn.com/problems/russian-doll-envelopes/
Russian Doll Envelopes
You have a number of envelopes with widths and heights given as a pair of integers (w, h). 
One envelope can fit into another if and only if both the width and height of one envelope is 
greater than the width and height of the other envelope.
What is the maximum number of envelopes can you Russian doll? (put one inside other)
Note:
Rotation is not allowed.
Example:
Input: [[5,4],[6,4],[6,7],[2,3]]
Output: 3 
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

*/

// this is one application of LIS.

#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
  struct CPairCompator
  {
      bool operator() (const pair<int,int>& lhs, const pair<int,int>& rhs) const
      {
          return (lhs.first*lhs.second)<(rhs.first*rhs.second);
      }
  };
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) 
    {
        int maxe = !envelopes.empty();
        std::sort(envelopes.begin(),envelopes.end(), CPairCompator());
        vector<int> lis(envelopes.size()+1,1);
        for(int i = 1; i<envelopes.size(); ++i)
        {
            for(int j = 0; j<i; ++j)
            {
                if(envelopes[i].first>envelopes[j].first && envelopes[i].second>envelopes[j].second)
                {
                    if(lis[i]<lis[j]+1)
                    {
                        lis[i] = lis[j]+1;
                    }
                }
            }
            if( maxe<lis[i])
            {
                maxe = lis[i];
            }
        }
        return maxe;
    }
};