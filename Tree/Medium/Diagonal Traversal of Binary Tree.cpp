/*
Diagonal Traversal of Binary Tree
https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

Given a Binary Tree, print the diagnol traversal of the binary tree.

Consider lines of slope -1 passing between nodes. 
Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.


Input:
The task is to complete the method which takes 1 argument, root of Binary Tree. The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.
git
Output:
The function should print out the diagonal traversal of the binary tree.

Constraints:
1 <=T<= 30
1 <= Number of nodes<= 100
1 <= Data of a node<= 1000

Example:

Input
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output
1 2 3
10 30 20 60 40

There are two test casess.  First case represents a tree with 3 nodes and 2 edges where root is 1, 
left child of 1 is 3 and right child of 1 is 2.   Second test case represents a tree with 4 edges and 5 nodes.

*/


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; 

#include<iostream>
#include<queue>
using namespace std;


/*

Traverse according to the left or right child.  This is slope.
*/

void diagonalPrint(Node *root)
{
   // your code here
   queue<Node*> curDQ;
   queue<Node*> nextDQ;
   queue<Node*>* pCurDQ   = &curDQ;
   queue<Node*>* pNextDQ  = &nextDQ;

   if(root)
   {
     curDQ.push(root);
     //root = root->right;
   }
   // when the Node is poped from queue, it is outputted.
   while(!pCurDQ->empty())
   {
        //This is current level.
       Node* head = pCurDQ->front();
       while(head)  //util there is no element from the current node with the same slope.
       {
           cout<<head->data<<" ";
           //this is the next level.
           if(head->left)
           {
               pNextDQ->push(head->left);
           }
           head = head->right;
       }

       pCurDQ->pop();
       if(pCurDQ->empty())
       {
           queue<Node*>* pTemp = pCurDQ;
           pCurDQ = pNextDQ;
           pNextDQ = pTemp;
       }
   }
}
