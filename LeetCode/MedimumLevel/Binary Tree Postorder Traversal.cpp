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
    int rob(TreeNode* root) 
    {
        unordered_map<TreeNode*, int> mapNodeC;
        stack<TreeNode*> pos;
        TreeNode* pre = NULL;

        mapNodeC[NULL] = 0;
        if(root)
        {
            pos.push(root);
        }
        
        while(!pos.empty())
        {
            TreeNode* ht = pos.top();

            //push into stack
            if(NULL == pre || (pre != ht->left && pre != ht->right))
            {
                if(ht->right)
                {
                    pos.push(ht->right);
                }
                if(ht->left)
                {
                    pos.push(ht->left);
                }
            } 

            // pop out stack
            if(NULL == ht->left && NULL == ht->right)
            {
                mapNodeC[ht] = ht->val;
                pos.pop();    
            }
            else
            {
                if(ht->right && pre == ht->right)
                {
                    pos.pop();
                    int nodeMaxc = ht->val;
                    if(ht->left)
                    {
                        if(ht->left->left)
                        {
                            nodeMaxc += mapNodeC[ht->left->left];
                        }
                        if(ht->left->right)
                        {
                            nodeMaxc += mapNodeC[ht->left->right];
                        }
                    }
                    if(ht->right)
                    {
                        if(ht->right->left)
                        {
                            nodeMaxc += mapNodeC[ht->right->left];
                        }
                        if(ht->right->right)
                        {
                            nodeMaxc += mapNodeC[ht->right->right];
                        }
                    }

                    if(nodeMaxc<(mapNodeC[ht->right] + mapNodeC[ht->left]) )
                    {
                        nodeMaxc = (mapNodeC[ht->right] + mapNodeC[ht->left]);
                    }
                    mapNodeC[ht] = nodeMaxc;
                }
                else if(ht->left && pre == ht->left)
                {
                    pos.pop();
                    int nodeMaxc = ht->val;
                    if(ht->left->left)
                    {
                        nodeMaxc += mapNodeC[ht->left->left];
                    }
                    if(ht->left->right)
                    {
                        nodeMaxc += mapNodeC[ht->left->right];
                    }
                    if(nodeMaxc < mapNodeC[ht->left] + mapNodeC[ht->right])
                    {
                        nodeMaxc = mapNodeC[ht->left] + mapNodeC[ht->right];
                    }
                    mapNodeC[ht] = nodeMaxc;
                }
            }  
            pre = ht;
        }
        return mapNodeC[root];
    }
};