/*
https://leetcode-cn.com/problems/house-robber-iii/
House Robber III

The thief has found himself a new place for his thievery again. There is only one entrance to this area, 
called the "root." Besides the root, each house has one and only one parent house. After a tour, 
the smart thief realized that "all houses in this place forms a binary tree". 
It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.


*/

/*

M[root] =  root->val + M[root->left->left] + M[root->left->right]  + M[root->right->left] + M[root->right->right],
           M[root->left] + M[root->right]

M[NULL] = 0;

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
#include<unordered_map>
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