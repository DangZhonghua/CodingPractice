/*
https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/
Sum Root to Leaf Numbers

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
An example is the root-to-leaf path 1->2->3 which represents the number 123.
Find the total sum of all root-to-leaf numbers.
Note: A leaf is a node with no children.
Example:
Input: [1,2,3]
    1
   / \
  2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
Example 2:
Input: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.

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
    int sumNumbers(TreeNode* root) 
    {
        long long nTotalSum = 0;
        if(root)
        {
            preOrderTraverseSum(root,0, nTotalSum);
        }
        return nTotalSum;
    }

private:
    void preOrderTraverseSum(TreeNode* node, long long pathnum, long long& nTotalsum)
    {
        pathnum *=10;
        pathnum += node->val;

        if(nullptr == node->left && nullptr == node->right) nTotalsum += pathnum; 
        if(node->left) preOrderTraverseSum(node->left,pathnum, nTotalsum);      
        if(node->right) preOrderTraverseSum(node->right,pathnum, nTotalsum);
    }
};