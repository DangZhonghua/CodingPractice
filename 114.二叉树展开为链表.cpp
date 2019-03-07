/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 *
 * https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (57.89%)
 * Total Accepted:    4.4K
 * Total Submissions: 7.6K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * 给定一个二叉树，原地将它展开为链表。
 * 
 * 例如，给定二叉树
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 将其展开为：
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
 * 
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
use right pointer as the list next pointer

*/

#include<iostream>
#include<stack>
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
    void flatten(TreeNode* root) 
    {
        stack<TreeNode*> dfsStack;
        TreeNode* pre = NULL;

        if(root)
        {
            dfsStack.push(root);    
        }
        while( !dfsStack.empty())
        {
            TreeNode* tp = dfsStack.top();
            dfsStack.pop();
            if(tp->right)
            {
                dfsStack.push(tp->right);
            }
            if(tp->left)
            {
                dfsStack.push(tp->left);
            }
            tp->right = tp->left = NULL;
            if(pre)
            {
                pre->right = tp;
                pre = tp;
            }
            else
            {
                pre = tp;
            }           
        }
    }
};

