/*
https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/
Find Mode in Binary Search Tree
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
 

For example:
Given BST [1,null,2,2],

   1
    \
     2
    /
   2
 

return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
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

use in-order traversal

[6,2,8,0,4,7,9,null,null,2,6]

*/


#include<vector>
#include<unordered_map>
using namespace std;



class Solution 
{
public:
    vector<int> findMode(TreeNode* root) 
    {
        int preMode = 0;
        vector<int> vm,vc;
        if(nullptr == root)
        {
            return vm;
        }

        InOrderTraversalFindMode(root,vm,vc,preMode);
        
        if(vc.size()>preMode)
        {
            vm.clear();
            vm.push_back(vc.back());
        }
        else if( vc.size() == preMode)
        {
            vm.push_back(vc.back());
        }
        
        
        return vm;
    }
private:
    void InOrderTraversalFindMode(TreeNode* root, vector<int>& vm, vector<int>& vc, int& m)
    {
       if(nullptr != root->left)
       {
           InOrderTraversalFindMode(root->left, vm,vc,m);
       }
       
       if(!vc.empty())
       {
           if(vc.back() == root->val)
           {
               vc.push_back(root->val);
           }
           else
           {
                if(m < vc.size())
                {
                    vm.clear();
                    vm.push_back(vc.back());
                    m = vc.size();
                    vc.clear();
                    vc.push_back(root->val);
                }
                else if( m == vc.size())
                {
                    vm.push_back(vc.back());
                    vc.clear();
                    vc.push_back(root->val);
                }
           }
       }
       else
       {
          vc.push_back(root->val);
       }
       
       if(nullptr != root->right)
       {
           InOrderTraversalFindMode(root->right, vm,vc,m);
       }
    }

};