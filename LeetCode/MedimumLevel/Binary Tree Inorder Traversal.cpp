/*
https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
Binary Tree Inorder Traversal

Given a binary tree, return the inorder traversal of its nodes' values.
Example:
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?

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

#include<stack>
#include<vector>
#include<iostream>
using namespace std;

struct TreeNode 
{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        // left root right
        stack<TreeNode*> s;
        TreeNode* pPre = NULL; //pPre is mark for finishing left tree
        vector<int> vt;
        
        if(root)
        {
          s.push(root);
          pPre = root->left;
        }
        
        while( !s.empty() || pPre)
        {   
            while(pPre)
            {
                s.push(pPre);
                pPre = pPre->left;
            }
            TreeNode* t = s.top();
            s.pop();
            vt.push_back(t->val);
            if(t->right)
            {
                s.push(t->right);
                pPre = t->right->left;
            }
        }
        return vt;
    }
};