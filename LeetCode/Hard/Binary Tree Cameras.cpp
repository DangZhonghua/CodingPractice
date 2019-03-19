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

DP[root] = 

DP[NULL] = 0;

*/

/*
方法一：动态规划

思路
让我们在给定的树中尝试自顶向下地监控每一个节点。每一个节点必须被它自身或者它邻居节点上的某个摄像头监控。
由于摄像头的安放只关心当前节点的状态，我们希望能够利用这一个事实来构建一个高效的解法。
具体来说就是，当决定是否要在某个节点上放置摄像头的时候，我们只需要关心当前节点所在的子树内它本身、它的左孩子和右孩子被监控的状态就可以了。
算法
我们定义 solve(node) 表示 node 处于不同状态时，监控以它为根的子树内其他所有节点需要使用的摄像头的数量。一共有三种本质不同的状态：
【状态 0】准监控子树：子树内除了根节点，其他节点都被摄像头监控了。
【状态 1】完全监控子树：子树内的所有节点都被摄像头监控了，但是根节点上并未放置摄像头。
【状态 2】 已放置摄像头的子树：子树内的所有节点都被摄像头监控了，并且根节点上放置了一个摄像头（可以用于监控此节点在原树中的父亲节点）。
一旦我们以这种方式构建问题，那么答案就呼之欲出了：
为了能够监控一颗 准监控子树，根节点的每一个子节点必须处于状态 1。
为了能够监控一颗 完全监控子树 ，我们不在根节点放置摄像头，但要保证根节点的子节点必须处于状态 1 或状态 2，同时至少有一个子节点处于状态 2。
为了能够监控一颗 已放置摄像头的子树，我们在根节点放置一个摄像头，而根节点的子节点可以处于三种状态的任何一种。


class Solution {
    public int minCameraCover(TreeNode root) {
        int[] ans = solve(root);
        return Math.min(ans[1], ans[2]);
    }

    // 0: Strict ST; All nodes below this are covered, but not this one
    // 1: Normal ST; All nodes below and incl this are covered - no camera
    // 2: Placed camera; All nodes below this are covered, plus camera here
    public int[] solve(TreeNode node) {
        if (node == null)
            return new int[]{0, 0, 99999};

        int[] L = solve(node.left);
        int[] R = solve(node.right);
        int mL12 = Math.min(L[1], L[2]);
        int mR12 = Math.min(R[1], R[2]);

        int d0 = L[1] + R[1];
        int d1 = Math.min(L[2] + mR12, R[2] + mL12);
        int d2 = 1 + Math.min(L[0], mL12) + Math.min(R[0], mR12);
        return new int[]{d0, d1, d2};
    }
}


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
    struct stNodeStatus
    {
        int m_nNonCamera{0};
        int m_nCamera{0};
    };

using MAPSTATUS = unordered_map<TreeNode*,stNodeStatus>;

public:
    int minCameraCover(TreeNode* root) 
    {
       MAPSTATUS stat;
       stat[NULL] = stNodeStatus();
    
      postOrderTraverse(stat, root);
      



    }
private:
    void postOrderTraverse(MAPSTATUS& stat, TreeNode* node)
    {
        if(NULL == node->left && NULL == node->right)
        {
            stNodeStatus nodeStatus;
            nodeStatus.m_nCamera = 1;
            nodeStatus.m_nNonCamera = 0;
            stat[node] = nodeStatus;
            return;
        }

        if(node->left)
        {
            postOrderTraverse(stat,node->left);
        }

        if(node->right)
        {
            postOrderTraverse(stat,node->right);
        }
        
        // if current node is settled
        stNodeStatus lstat = stat[node->left];
        stNodeStatus rstat = stat[node->right];
        
        stNodeStatus cstat;
        //Select both children.
        cstat.m_nCamera = 1+lstat.m_nCamera + rstat.m_nCamera;
        



        // if current is not settled.












        

    }
    


};