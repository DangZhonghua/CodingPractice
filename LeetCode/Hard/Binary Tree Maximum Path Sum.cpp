/*
https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/
Binary Tree Maximum Path Sum

Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42

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

/*

use post-order to do this

*/

#include<iostream>
#include<climits>
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
    int maxPathSum(TreeNode* root) 
    {
        int maxsum    = INT_MIN;
        if( root)
        {
          postOrderPath(root,maxsum);
        }
        else
        {
          maxsum = 0;
        }
        

        return maxsum;
    }
  int postOrderPath(TreeNode* node, int& targetsum)
  {
     int leftsum = 0;
     int rightsum = 0;
     
     if(node->left)
     {
       leftsum = postOrderPath(node->left,targetsum);
     }
     if(node->right)
     {
       rightsum = postOrderPath(node->right,targetsum);
     }

     //judge the maximum sum path.
     int curmax = node->val;
     if(curmax< node->val + leftsum)
     {
       curmax = node->val + leftsum;
     }
     if(curmax<node->val + rightsum )
     {
       curmax = (node->val + rightsum);
     }
     if(curmax < node->val + leftsum + rightsum)
     {
       curmax = node->val + leftsum + rightsum;
     }
     
     if(targetsum<curmax)
     {
       targetsum = curmax;
     }

     int maxSum = node->val;
     if(maxSum < node->val + leftsum)
     {
       maxSum = node->val + leftsum;
     }
     if(maxSum < node->val + rightsum )
     {
       maxSum = node->val + rightsum;
     }

     return maxSum;
  }
};