//https://practice.geeksforgeeks.org/problems/complete-binary-tree/1/?ref=self
// Given a Binary Tree, write a function to check whether the given Binary Tree is Complete Binary Tree or not. A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.
// Input:
// The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the number of edges. The next line contains the edges of the binary tree.
 
// Output:
// Print "Complete Binary Tree" if the tree is a complete binary tree.
// Print "Not Complete Binary Tree" if the tree is not a complete binary tree.
// Constraints:
// 1<=T<=100
// 1<=n<=100

// Example:
// Input:
// 3
// 2
// 1 2 L 1 3 R
// 3
// 1 2 L 2 4 L 1 3 R
// 1
// 1 3 R

// Output:
// Complete Binary Tree
// Complete Binary Tree
// Not Complete Binary Tree: this example output should be Complete Binary Tree

////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Given a binary tree, return true if the tree is complete
   else false */
 
 // use BFS or level-order traversal to complete this task;
 // count number of node of every level.

#include <queue>
using namespace std;

bool isCompleteBT(struct node* root)
{
// Your code goes here
    queue<node*> levelQ;
    int nCurLevel   = 0;
    int nNextLevel  = 0;
    int high        = 0;
    bool bCompleteBinaryTree = true;
    
    if(root)
    {
        levelQ.push(root);
        nCurLevel = 1;
    }
    
    while(!levelQ.empty() && bCompleteBinaryTree)
    {
       if( nCurLevel != (1<<high) )
       {
           bCompleteBinaryTree = false;
           break;
       }
       
       while(nCurLevel>0)
       {
           node* head = levelQ.front();
           levelQ.pop();
           --nCurLevel;
           if(head->left)
           {
               levelQ.push(head->left);
               ++nNextLevel;
           }
           if(head->right)
           {
               levelQ.push(head->right);
               ++nNextLevel;
           }
       }
       ++high;
       nCurLevel    = nNextLevel;
       nNextLevel   = 0;
    }
    
    //This is judge the voliate level whether is the last one.
    if(!bCompleteBinaryTree)
    {
        while(!levelQ.empty())
        {
            node* head = levelQ.front();
            if(head->left||head->right)
            {
                break;
            }
            levelQ.pop();
        }
        
        if(levelQ.empty())
        {
            bCompleteBinaryTree = true;
        }
    }

    return bCompleteBinaryTree;

}