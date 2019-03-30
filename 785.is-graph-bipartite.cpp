/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 *
 * https://leetcode-cn.com/problems/is-graph-bipartite/description/
 *
 * algorithms
 * Medium (34.75%)
 * Total Accepted:    829
 * Total Submissions: 2.4K
 * Testcase Example:  '[[1,3],[0,2],[1,3],[0,2]]'
 *
 * 给定一个无向图graph，当这个图为二分图时返回true。
 * 
 * 如果我们能将一个图的节点集合分割成两个独立的子集A和B，并使图中的每一条边的两个节点一个来自A集合，一个来自B集合，我们就将这个图称为二分图。
 * 
 * 
 * graph将会以邻接表方式给出，graph[i]表示图中与节点i相连的所有节点。每个节点都是一个在0到graph.length-1之间的整数。这图中没有自环和平行边：
 * graph[i] 中不存在i，并且graph[i]中没有重复的值。
 * 
 * 
 * 
 * 示例 1:
 * 输入: [[1,3], [0,2], [1,3], [0,2]]
 * 输出: true
 * 解释: 
 * 无向图如下:
 * 0----1
 * |    |
 * |    |
 * 3----2
 * 我们可以将节点分成两组: {0, 2} 和 {1, 3}。
 * 
 * 
 * 
 * 
 * 示例 2:
 * 输入: [[1,2,3], [0,2], [0,1,3], [0,2]]
 * 输出: false
 * 解释: 
 * 无向图如下:
 * 0----1
 * | \  |
 * |  \ |
 * 3----2
 * 我们不能将节点分割成两个独立的子集。
 * 
 * 
 * 注意:
 * 
 * 
 * graph 的长度范围为 [1, 100]。
 * graph[i] 中的元素的范围为 [0, graph.length - 1]。
 * graph[i] 不会包含 i 或者有重复的值。
 * 图是无向的: 如果j 在 graph[i]里边, 那么 i 也会在 graph[j]里边。
 * 
 * 
 */

/*

use BFS to two colored vertices of graph:

One approach is to check whether the graph is 2-colorable or not using backtracking algorithm m coloring problem.
Following is a simple algorithm to find out whether a given graph is Birpartite or not using Breadth First Search (BFS).
1. Assign RED color to the source vertex (putting into set U).
2. Color all the neighbors with BLUE color (putting into set V).
3. Color all neighbor’s neighbor with RED color (putting into set U).
4. This way, assign color to all vertices such that it satisfies all the constraints of m way coloring problem where m = 2.
5. While assigning colors, if we find a neighbor which is colored with same color as current vertex, then the graph cannot be colored with 2 vertices (or graph is not Bipartite) 

*/

#include<vector>
#include<queue>
#include<iostream>
using namespace std;

class Solution 
{
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        bool bBipartite = true;
        int ncurLevel   = 0;
        int nNextLevel  = 0;
        int nCurColor   = m_RedColor;
        int nNextColor  = m_GreenColor;

        queue<int>      levelQ;
        vector<int>     vcolor(graph.size(),0);

        for( int  j = 0; j< graph.size()&& bBipartite; ++j)
        {
            if(vcolor[j])
            {
                continue;
            }
            
            levelQ.push(j);
            vcolor[j] = nCurColor;
            ncurLevel = 1;
            while( ncurLevel && bBipartite)
            {
                while(ncurLevel && bBipartite)
                {
                    int v = levelQ.front();
                    levelQ.pop();
                    --ncurLevel;
                    for(int i = 0; i<graph[v].size(); ++i)
                    {
                        if(!vcolor[graph[v][i]])
                        {
                            levelQ.push( graph[v][i] );
                            ++nNextLevel;
                            vcolor[graph[v][i]] = nNextColor;
                        }
                        else if( vcolor[graph[v][i]] == vcolor[v] )
                        {
                            bBipartite = false;
                            break;
                        }        
                    }
                }
                ncurLevel = nNextLevel;
                nNextLevel = 0;
                int c = nCurColor;
                nCurColor = nNextColor;
                nNextColor = c;
            }
        }

        return bBipartite;
    }
private:
    int m_RedColor{1};
    int m_GreenColor{2};
};

