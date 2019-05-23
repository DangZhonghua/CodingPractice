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
        string path;
        if( root)
        {
            preOrderPath(root,vpath,path);
        }
        return vpath;
    }
private:
    void preOrderPath(TreeNode* node, vector<string>& vpath, string& path)
    {
        if(!path.empty())
        {
            path += "->";
        }
        path.push_back(node->val+'0');
        if(nullptr == node->left && nullptr == node->right) //reach the leaf
        {
            vpath.push_back(path);
        }

        if(nullptr != node->left)
        {
            preOrderPath(node->left,vpath, path);
        }
        if(nullptr != node->right)
        {
            preOrderPath(node->right,vpath,path);
        }
        path.pop_back();
        if(!path.empty())
        {
            path.pop_back();
            path.pop_back();
        }
    }
};