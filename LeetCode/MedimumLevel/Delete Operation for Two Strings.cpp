/*
https://leetcode-cn.com/problems/delete-operation-for-two-strings/
 Delete Operation for Two Strings
 Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, 
 where in each step you can delete one character in either string. 
Example 1:
Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

Note:
The length of given words won't exceed 500.
Characters in given words can only be lower-case letters.


*/




#include<string>
#include<vector>
using namespace std;



/*
            ed[i-1][j-1]  w[i] = s[j]
ed[i][j] = 
            min{ed[i-1][j]+1, ed[i][j-1]+1} w[i] != s[j]


*/
class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int R = word1.length()+1;
        int C = word2.length()+1;
        vector< vector<int> > md(R+1, vector<int>(C+1, 0));
        for(int r = 0; r<=R;++r)
        {
            md[r][0] = r;
        }
        for(int c = 0; c<=C; ++c)
        {
            md[0][c] = c;
        }
        
        for(int r = 1; r<=R; ++r)
        {
            for(int c = 1; c<=C; ++c)
            {
                if(word1[r-1] == word2[c-1])
                {
                    md[r][c] = md[r-1][c-1];
                }
                else
                {
                    md[r][c] = md[r-1][c]+1;
                    if(md[r][c]>md[r][c-1]+1)
                    {
                        md[r][c] = md[r][c-1]+1;
                    }
                }
                
            }
        }
        return md[R][C];
    }
};