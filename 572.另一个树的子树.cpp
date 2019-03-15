/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一个树的子树
 *
 * https://leetcode-cn.com/problems/subtree-of-another-tree/description/
 *
 * algorithms
 * Easy (39.95%)
 * Total Accepted:    3.1K
 * Total Submissions: 7.7K
 * Testcase Example:  '[3,4,5,1,2]\n[4,1,2]'
 *
 * 给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s
 * 也可以看做它自身的一棵子树。
 * 
 * 示例 1:
 * 给定的树 s:
 * 
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 * 
 * 
 * 给定的树 t：
 * 
 * 
 * ⁠  4 
 * ⁠ / \
 * ⁠1   2
 * 
 * 
 * 返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。
 * 
 * 示例 2:
 * 给定的树 s：
 * 
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 * ⁠   /
 * ⁠  0
 * 
 * 
 * 给定的树 t：
 * 
 * 
 * ⁠  4
 * ⁠ / \
 * ⁠1   2
 * 
 * 
 * 返回 false。
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
use pre-order traversal

*/

#include<vector>
#include<stack>
using namespace std;


//  struct TreeNode 
//  {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  };

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) 
    {
        vector<TreeNode*>  vroot;
        if(nullptr == s || nullptr == t)
        {
            return false;
        }
        bool bSubTree = false;
        FindTargetRoot(s,t,vroot);
        for(auto n:vroot)
        {
            if( IsSubTree(n,t) )
            {
                bSubTree = true;
                break;
            }
        }
        return bSubTree;
    }

private:
    void FindTargetRoot(TreeNode* s, TreeNode* t, vector<TreeNode*>&  vroot )
    {
        if(s->val == t->val)
        {
            vroot.push_back(s);
        }
        if(s->left)
        {
            FindTargetRoot(s->left,t,vroot);
        }
        if(s->right)
        {
            FindTargetRoot(s->right,t,vroot);
        }
    }
private:
    bool IsSubTree(TreeNode* s, TreeNode* t)
    {
        if(s->val != t->val)
        {
            return false;
        }

        bool bleft  = true;
        bool bright = true;

        //Handle left tree
        if(s->left && t->left)
        {
            bleft = IsSubTree(s->left,t->left);
        }
        else
        {
            if(NULL == s->left && NULL == t->left)
            {
                bleft = true;
            }
            else
            {
                bleft = false;
            }
        }
        
        if( !bleft)
        {
            return false;
        }

        //Handle right tree
        if(s->right && t->right)
        {
            bright = IsSubTree(s->right,t->right);
        }
        else
        {
            if(NULL == s->right && NULL == t->right)
            {
                bright = true;
            }
            else
            {
                bright = false;
            }      
        }

        return (bleft&bright);
    }


};

