/*
https://leetcode-cn.com/problems/binary-tree-paths/


给定一个二叉树，返回所有从根节点到叶子节点的路径。
说明: 叶子节点是指没有子节点的节点。
示例:
输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3


*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


#include<string>
#include<vector>
using namespace std;


class Solution 
{
public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> vpath;

        vector< vector<int> > vnpaths;
        vector<int> vnpath;
        
        if( root)
        {
            preOrderPath(root,vnpaths,vnpath);
        }
        
        for(int i = 0; i<vnpaths.size(); ++i)
        {
            string path;
            for(int j = 0; j<vnpaths[i].size(); ++j)
            {
                path += std::to_string(vnpaths[i][j]);
                if(j < vnpaths[i].size() - 1 )
                {
                    path += "->";
                }
            }
            vpath.push_back(path);
        }

        return vpath;
    }
private:
    void preOrderPath(TreeNode* node, vector< vector<int> >& vnpaths,  vector<int>& vnpath)
    {

        vnpath.push_back(node->val);
        if(nullptr == node->left && nullptr == node->right) //reach the leaf
        {
            vnpaths.push_back(vnpath);
        }

        if(nullptr != node->left)
        {
            preOrderPath(node->left,vnpaths, vnpath);
        }
        if(nullptr != node->right)
        {
            preOrderPath(node->right,vnpaths,vnpath);
        }
        vnpath.pop_back();
    }
};