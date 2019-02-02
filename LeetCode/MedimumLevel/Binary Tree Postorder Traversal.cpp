/*
https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
Binary Tree Postorder Traversal

Given a binary tree, return the postorder traversal of its nodes' values.
Example:
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
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

#include<iostream>
#include<vector>
#include<stack>
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
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> vpr;
        stack<TreeNode*>  pos;
        TreeNode* pre = NULL; // the mark which is the flag means all sub-trees have finished traversal.
        if(root)
        {
            pos.push(root);
        }
        while(!pos.empty())
        {
            TreeNode* h = pos.top();
            
            if(   NULL == pre  || ( pre != h->left && pre != h->right) ) // the subtrees root at the h is not finished traversal
            {
                if(h->right)
                {
                    pos.push(h->right);
                }
                if(h->left)
                {
                    pos.push(h->left);
                }
            }
            if( (NULL == h->left &&  NULL == h->right) ) //there are no sub-trees
            {
                vpr.push_back(h->val);
                pos.pop();
            }
            else
            {
                if( h->right && pre == h->right)
                {
                    vpr.push_back(h->val);
                    pos.pop();
                }
                else if( h->left && pre == h->left)
                {
                    vpr.push_back(h->val);
                    pos.pop();
                }
            }
            pre = h;
        }
        
        return vpr;
    }
};