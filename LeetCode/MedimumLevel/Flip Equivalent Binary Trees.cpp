/*
https://leetcode-cn.com/problems/flip-equivalent-binary-trees/
Flip Equivalent Binary Trees

For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.
A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.
Write a function that determines whether two binary trees are flip equivalent.  The trees are given by root nodes root1 and root2.
 
Example 1:
Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
Output: true
Explanation: We flipped at nodes with values 1, 3, and 5.


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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) 
    {
        if( root1 && root2)
        {
            return preorderCheck(root1, root2);
        }
        else if( nullptr == root1 && nullptr == root2)
        {
            return false;
        }
        return false;
    }
public:
    bool preorderCheck(TreeNode* node1, TreeNode* node2)
    {
        if(node1->val != node2->val)
        {
            return false;
        }
        if(node1->left)
        {
            if(nullptr == node2->left && nullptr == node2->right)
            {
                return false;
            }
            if(node2->left && node1->left->val == node2->left->val)
            {
                if(!preorderCheck(node1->left,node2->left))
                {
                    return false;
                }
            }
            else if (node2->right && node1->left->val == node2->right->val)
            {
                if(!preorderCheck(node1->left,node2->right))
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        if(node1->right)
        {
            if(nullptr == node2->left && nullptr == node2->right)
            {
                return false;
            }
            if(node2->left && node1->right->val == node2->left->val)
            {
                if(!preorderCheck(node1->right,node2->left))
                {
                    return false;
                }
            }
            else if (node2->right && node1->right->val == node2->right->val)
            {
                if(!preorderCheck(node1->right,node2->right))
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};