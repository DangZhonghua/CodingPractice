/*
Boundary Traversal of binary tree
https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1/?ref=self

Write a function to print Boundary Traversal of a binary tree.
For below tree, function should print 20 8 4 10 14 25 22 .

Input:
The task is to complete the method which takes one argument, root of the Tree. 
The struct node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.


Output:
The function should print Boundary  traversal of the tree.

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example:
Input:
2
2
1 2 R 1 3 L
7
20 8 L 20 22 R 8 4 L 8 12 R 12 10 L 12 14 R 22 25 R

Output:
1 3 2
20 8 4 10 14 25 22 .

There are two test casess.  First case represents a tree with 3 nodes and 2 edges where root is 1, 
left child of 1 is 3 and right child of 1 is 2.   
Second test case represents a tree with 7 edges and 8 nodes.


*/



struct Node
{
    int data;
    Node* left, * right;
}; 

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

/*

Use level-order traversal to find the bounary which locate the head and tail of one queue of current level.
for anti_clock_wise print, the left child will into queue, the right child will into stack.

Before one node en-queue, we decide its anti_clock_wise order.


*/

void printBoundary(Node *root)
{
     //Your code here
     queue<Node*> curLevel;
     queue<Node*> nextLevel;
     queue<Node*>* pCurLevel;
     queue<Node*>* pNextLevel;
     queue<Node*>  bQueue;
     stack<Node*>  bStack;
     pCurLevel = &curLevel;
     pNextLevel = &nextLevel;
     
     if(root)
     {
         bQueue.push(root);
         pCurLevel->push(root);
     }
     
     while(!pCurLevel->empty())
     {
         Node* head = pCurLevel->front();
         if(pCurLevel->size() == 1)
         {
             if(head->left)
             {
                 bQueue.push(head->left);
             }
             if(head->right)
             {
                 bStack.push(head->right);
             }
         }
         else
         {
             if(head->left)
             {
                 bQueue.push(head->left);
             }
             else if(head->right)
             {
                 bQueue.push(head->right);
             }
         }
         pCurLevel->pop();
         

         queue<Node*>* pTemp = pCurLevel;
         pCurLevel = pNextLevel;
         pNextLevel = pTemp;
     }

    while(!bQueue.empty())
    {
        cout<<bQueue.front()->data<<" ";
        bQueue.pop();
    }
    while(!bStack.empty())
    {
        cout<<bStack.top()->data<<" ";
        bStack.pop();
    }
    //cout<<endl;
}