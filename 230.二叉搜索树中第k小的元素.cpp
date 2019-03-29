/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 *
 * https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/description/
 *
 * algorithms
 * Medium (62.73%)
 * Total Accepted:    9.1K
 * Total Submissions: 14.5K
 * Testcase Example:  '[3,1,4,null,2]\n1'
 *
 * 给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。
 * 
 * 说明：
 * 你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。
 * 
 * 示例 1:
 * 
 * 输入: root = [3,1,4,null,2], k = 1
 * ⁠  3
 * ⁠ / \
 * ⁠1   4
 * ⁠ \
 * 2
 * 输出: 1
 * 
 * 示例 2:
 * 
 * 输入: root = [5,3,6,2,4,null,null,1], k = 3
 * ⁠      5
 * ⁠     / \
 * ⁠    3   6
 * ⁠   / \
 * ⁠  2   4
 * ⁠ /
 * ⁠1
 * 输出: 3
 * 
 * 进阶：
 * 如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？
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

use in-order traverse to do this.

*/

#include<iostream>
using namespace std;

// struct TreeNode 
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution 
{
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        int v = 0;
        InOrderTraverse( root,k, 0, v);
        
        return v;
    }

private:
    // return the node number rooted at "root" node
    int InOrderTraverse(TreeNode* root, int k, int nLess, int& v)
    {
        if(nullptr == root)
        {
            return 0;
        }
        int nleft = InOrderTraverse(root->left, k, nLess,v);
        if(nleft<0)
        {
            return -1;
        }

        if(nleft + nLess + 1 == k)
        {
            v = root->val;
            return -1;
        }
        int nright = InOrderTraverse(root->right,k, nleft + nLess + 1,v);
        if(nright<0)
        {
            return -1;
        }
        return (nleft+nright+1);
    }
};

