//https://leetcode-cn.com/problems/sum-of-left-leaves/submissions/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution 
{
public:
    int sumOfLeftLeaves(TreeNode* root) 
    {
        int sum = 0;
        if(root)
        {
            preOrderLeftsum(NULL, root, sum);
        }
        return sum;
    }
    void preOrderLeftsum(TreeNode* p,TreeNode* node,int& sum)
    {
        if( nullptr == node->left && nullptr == node->right)
        {
            if(p && p->left == node)
            {
                sum += node->val;
            }
        }
        if(node->left)
        {
            preOrderLeftsum(node,node->left, sum);
        }
        if(node->right)
        {
            preOrderLeftsum(node,node->right, sum);
        }
    }
};