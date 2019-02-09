/*
https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/
 Binary Tree Zigzag Level Order Traversal

Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
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
#include<deque>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
      deque<TreeNode*> orderLevelQ;
      deque<TreeNode*> reverseLevelQ;
      bool  bOrder = true;
      
      if(root)
      {
          orderLevelQ.push_back(root);
      }


      vector< vector<int> > llv;
      while(!orderLevelQ.empty() || !reverseLevelQ.empty() )
      {
        vector<int> lv;
        if(bOrder)
        {
            while(!orderLevelQ.empty())
            {
                TreeNode* head = orderLevelQ.front();
                orderLevelQ.pop_front();
                lv.push_back(head->val);

                if(head->left)
                {
                    reverseLevelQ.push_back(head->left);
                }
                
                if(head->right)
                {
                    reverseLevelQ.push_back(head->right);
                }
            }
            bOrder = false;
        }
        else
        {
            while(!reverseLevelQ.empty())
            {
                TreeNode* tail = reverseLevelQ.back();
                reverseLevelQ.pop_back();
                lv.push_back(tail->val);
                if(tail->right)
                {
                    orderLevelQ.push_front(tail->right);
                }
                if(tail->left)
                {
                    orderLevelQ.push_front(tail->left);
                }
            }
            bOrder = true;
        }

        llv.push_back(lv);
      }

      return llv;
    }
};