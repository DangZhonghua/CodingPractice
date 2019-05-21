/*
https://leetcode-cn.com/problems/path-sum/
Path Sum

Given a binary tree and a sum, determine 
if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.
Example:
Given the below binary tree and sum = 22,
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

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
    bool hasPathSum(TreeNode* root, int sum) 
    {
        bool bPath = false;
        if(root)
        {
           bPath = preOrderHelper(root, sum, 0);
        }
        return bPath;
    }
private:
    bool preOrderHelper(TreeNode* root, int sum, int pathsum)
    {
        pathsum += root->val;
        if(nullptr == root->left && nullptr == root->right)
        {
            if(sum == pathsum)
            {
                return true;
            }
        }
        if( root->left && preOrderHelper(root->left,sum,pathsum))
        {
            return true;
        }
        
        if( root->right && preOrderHelper(root->right,sum,pathsum))
        {
            return true;
        }
        return false;
        
    }
};