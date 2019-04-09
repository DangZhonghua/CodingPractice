/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 *
 * https://leetcode-cn.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (48.31%)
 * Total Accepted:    5.1K
 * Total Submissions: 10.4K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * 给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
 * 
 * 你可以对一个单词进行如下三种操作：
 * 
 * 
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 * 
 * 
 * 示例 1:
 * 
 * 输入: word1 = "horse", word2 = "ros"
 * 输出: 3
 * 解释: 
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 * 
 * 
 * 示例 2:
 * 
 * 输入: word1 = "intention", word2 = "execution"
 * 输出: 5
 * 解释: 
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
 * 
 * 
 */


/*
            ed[i-1,j-1]  if x[i] == y[j]
ed[i,j] = 
            min
            {
                ed[i-1,j-1]+1 //replace
                ed[i-1,j]+1 //delete
                ed[i,j-1]   // insert at j position to make new-inserted be j+1
            }
             if x[i] != y[j]
            
*/



#include<string>
#include<vector>
using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int R = word1.size();
        int C = word2.size();
        vector< vector<int> > ed(R+1, vector<int>(C+1,0));
        
        // for word1 is empty case
        for(int c = 1 ;c<=C; ++c)
        {
            ed[0][c] = c; //insert
        }
         // for word2 is empty case
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

