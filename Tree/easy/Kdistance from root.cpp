//https://practice.geeksforgeeks.org/problems/k-distance-from-root/1/?ref=self

// Given a Binary Tree and a number k. Print all nodes that are at distance k from root (root is considered at distance 0 from itself).  Nodes should be printed from left to right.
// If k is more that height of tree, nothing should be printed.



/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
// Recursive function to print right view of a binary tree.



//use BFS to calc level of node.


#include <queue>
using namespace std;



void printKdistance(Node *root, int k)
{
  // Your code here
  
  queue<Node*> levelQ;
  
  int nCurLevel     = 0;
  int nNextLevel    = 0;
  int high          = -1;
  
  if(root)
  {
      levelQ.push(root);
      ++high;
      ++nCurLevel;
  }
  
  while(!levelQ.empty())
  {
      while(nCurLevel>0)
      {
          Node* head = levelQ.front();
          levelQ.pop();
          --nCurLevel;
          if(high == k)
          {
              cout<<head->data<<" ";
          }
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
      if(high == k)
      {
          //cout<<endl;
          break;
      }
      ++high;
      nCurLevel = nNextLevel;
      nNextLevel = 0;
  }
  
}