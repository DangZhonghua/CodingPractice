/*
https://leetcode-cn.com/problems/edit-distance/
Edit Distance
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
You have the following 3 operations permitted on a word:
Insert a character
Delete a character
Replace a character
Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

*/

#include<string>
#include<vector>
using namespace std;

/*

            ed[i-1][j-1]
ed[i][j] =  
            min{ ed[i][j-1]+1(insert), ed[i-1][j] + 1 (delete), ed[i-1][j-1] + 1 (replace) }


*/


class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int R = word1.size();
        int C = word2.size();
        vector< vector<int> > ed(R+1, vector<int>(C+1,0));
        
        for(int c = 1 ;c<=C; ++c)
        {
            ed[0][c] = c; //insert
        }
        for(int r = 1; r<=R; ++r)
        {
            ed[r][0] = r; //delete
        }

        for(int r = 1; r <= R; ++r)
        {
            for(int c = 1; c<=C; ++c)
            {
                if( word1[r-1] == word2[c-1])
                {
                    ed[r][c] = ed[r-1][c-1];
                }
                else
                {
                    ed[r][c] = ed[r][c-1]+1; //insert
                    if( ed[r][c] > ed[r-1][c]+1) //delete
                    {
                        ed[r][c] = ed[r-1][c]+1;
                    }
                    if( ed[r][c]> ed[r-1][c-1]+1) //replace
                    {
                        ed[r][c] = ed[r-1][c-1]+1;
                    }
                }
            }
        }
        return ed[R][C];
    }
};