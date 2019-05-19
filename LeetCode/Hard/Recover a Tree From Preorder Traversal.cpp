/*

https://leetcode-cn.com/problems/recover-a-tree-from-preorder-traversal/
Recover a Tree From Preorder Traversal

We run a preorder depth first search on the root of a binary tree.

At each node in this traversal, we output D dashes (where D is the depth of this node), 
then we output the value of this node.  
(If the depth of a node is D, the depth of its immediate child is D+1.  The depth of the root node is 0.)

If a node has only one child, that child is guaranteed to be the left child.

Given the output S of this traversal, recover the tree and return its root.




Input: "1-2--3--4-5--6--7"
Output: [1,2,5,3,4,6,7]


Input: "1-2--3---4-5--6---7"
Output: [1,2,5,3,null,6,null,4,null,7]

Input: "1-401--349---90--88"
Output: [1,401,null,349,88,90]

*/

/*

hits:Do an iterative depth first search, parsing dashes from the string to inform you how to link the nodes together.

*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*

dfs search the string as pre-order but keep the previous nodes to maintain the ancesdents

*/


class Solution 
{
    struct  TreeInfo
    {
        TreeNode* node{nullptr};
        int level{0};
    };
    
public:
    TreeNode* recoverFromPreorder(string s) 
    {
        stack< TreeInfo > dfsStack;
        int     nLevel = 0;
        int     N = s.length();
        int     i      = 0;
        bool    bStart = false;
        int     nStart = -1;
        TreeNode* root = nullptr;

        while(i<N)
        {
            if('-' != s[i] && -1 == nStart)
            {
                nStart = i;      
            }
            if( '-' == s[i] || (i+1) == N /*for handle the last digital*/ )
            {
                if(-1 != nStart ) // the number has been reached the end
                {
                    string strd = s.substr(nStart,i-nStart+1);
                    TreeInfo nodeinfo;
                    nodeinfo.level = nLevel;
                    nodeinfo.node = new TreeNode(atoi(strd.c_str()));
                    if(root == nullptr) root = nodeinfo.node;
                    
                    //Find the parent node.
                    while( !dfsStack.empty() && dfsStack.top().level>=nodeinfo.level )
                    {
                        dfsStack.pop();
                    }

                    if(!dfsStack.empty())
                    {
                        if( nullptr == dfsStack.top().node->left)
                        {
                            dfsStack.top().node->left = nodeinfo.node;
                        }
                        else
                        {
                            dfsStack.top().node->right = nodeinfo.node;
                        }
                    }
                    dfsStack.push(nodeinfo);
                    //For process the next c
                    nLevel = 0;
                    nStart = -1;
                }
                ++nLevel;
            }
            ++i;
        }
        return root;
    }
};