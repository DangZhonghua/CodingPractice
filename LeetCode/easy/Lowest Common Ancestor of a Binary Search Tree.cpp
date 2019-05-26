/*
https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
Lowest Common Ancestor of a Binary Search Tree

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

//Find the fork point using the BST characters.


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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        TreeNode* pCA = nullptr;
        
        if(root)
        {
            InorderTraverse(root,p,q,&pCA);
        }
        return pCA;
    }
private:
    void InorderTraverse(TreeNode* node, TreeNode*p, TreeNode* q, TreeNode** pCA)
    {
         if( (node->val > p->val && node->val < q->val) || (node->val< p->val && node->val > q->val) || node->val == p->val || node->val == q->val)
        {
            *pCA = node;
            return;
        } 

        if(node->val > p->val && node->val > q->val )
        {
            //go to the left branch.
            if ( node->left ) 
            {
                InorderTraverse(node->left, p,q,pCA);
            }
            return;
        }
        if( node->val < p->val && node->val < q->val  )
        {
            // go to the right branch
            if(node->right)
            {
                InorderTraverse(node->right,p,q,pCA);
            }
            return;
        }
        
        return;
    }
};