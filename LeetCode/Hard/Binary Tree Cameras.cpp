/*
https://leetcode-cn.com/problems/binary-tree-cameras/
Binary Tree Cameras

Given a binary tree, we install cameras on the nodes of the tree. 

Each camera at a node can monitor its parent, itself, and its immediate children.

Calculate the minimum number of cameras needed to monitor all nodes of the tree.

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

DP[a] = DP[ a->parent->parent] + DP[ a->left->left ] + DP[a->left->right] + DP[a->right->left] + DP[a->right->right]
        DP[a->parent], DP[a->left], DP[a->right]

DP[NULL] = 0;

*/


#include<iostream>
#include<vector>
#include<unordered_map>
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
    int minCameraCover(TreeNode* root) 
    {
        unordered_map<TreeNode*, TreeNode*> mapChild2Parent;
    }
};