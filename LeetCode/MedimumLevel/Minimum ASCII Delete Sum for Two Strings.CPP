/*
https://leetcode-cn.com/problems/minimum-ascii-delete-sum-for-two-strings/
Minimum ASCII Delete Sum for Two Strings
Given two strings s1, s2, find the lowest ASCII sum of deleted characters to make two strings equal.
Example 1:
Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.

Example 2:
Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.

Note: 
0 < s1.length, s2.length <= 1000.
All elements of each string will have an ASCII value in [97, 122].

*/

#include<vector>
#include<string>
using namespace std;


/*
            ed[i-1][j-1]  w[i] = s[j]
ed[i][j] = 
            min{ed[i-1][j]+w[i], ed[i][j-1]+s[j]} w[i] != s[j]


*/

class Solution 
{
public:
    int minimumDeleteSum(string word1, string word2) 
    {
        int R = word1.length()+1;
        int C = word2.length()+1;
        vector< vector<int> > md(R+1, vector<int>(C+1, 0));
        for(int r = 1; r<=R;++r)
        {
            md[r][0] = md[r-1][0] + word1[r-1];
        }
        for(int c = 1; c<=C; ++c)
        {
            md[0][c] = md[0][c-1] + word2[s-1];
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
                    md[r][c] = md[r-1][c]+word1[r-1];
                    if(md[r][c]>md[r][c-1]+word2[c-1])
                    {
                        md[r][c] = md[r][c-1] + word2[c-1];
                    }
                }
                
            }
        }
        return md[R][C];
    }
};