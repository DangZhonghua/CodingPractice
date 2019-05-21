/*

https://leetcode-cn.com/problems/path-sum-ii/
https://leetcode-cn.com/problems/path-sum/
https://leetcode-cn.com/problems/longest-univalue-path/


Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
Note: A leaf is a node with no children.
Example:
Given the below binary tree and sum = 22,
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:
[
   [5,4,11,2],
   [5,8,4,5]
]


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


#include<iostream>
#include<vector>
using namespace std;

 struct TreeNode 
 {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };



class Solution 
{
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        vector< vector<int> > vpaths;
        vector<int> vpath;
        if(root)
        {
            preOrderFindPath(vpaths,vpath,root,sum,0);
        }
        return vpaths;
    }
private:
    void preOrderFindPath(vector<vector<int>>& vpaths, vector<int>& vpath, TreeNode* node, int sum, int presum)
    {
        presum += node->val;
        vpath.push_back(node->val);
        if(nullptr == node->left && nullptr == node->right) // This is leaf node
        {
            if(presum == sum)
            {
                vpaths.push_back(vpath);
            }     
        }
        else
        {
            if(node->left)
            {
                preOrderFindPath(vpaths,vpath,node->left,sum,presum);
            }
            if(node->right)
            {
                preOrderFindPath(vpaths,vpath,node->right,sum,presum);
            }
        }
        vpath.pop_back();
        presum -= node->val;   
        return;
    }
};