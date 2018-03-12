//https://practice.geeksforgeeks.org/problems/maximum-width-of-tree/1/?ref=self

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*  Structure of a Binary Tree 
struct Node
{
    int data;
    Node* left, *right;
}; */
/* Function to get the maximum width of a binary tree*/

#include<queue>
using namespace std;

int getMaxWidth(Node* root)
{
   // Your code here
   queue<Node*> bfsQ;
   
   int nCurWidth    = 0;
   int nNextWidth   = 0;
   int nMaxWidth    = 0;
   
   if(root)
   {
       bfsQ.push(root);
       nCurWidth = 1;
       nMaxWidth = 1;
   }
   
   while(!bfsQ.empty())
   {
      while(nCurWidth>0)
      {
          Node* head = bfsQ.front();
          bfsQ.pop();
          --nCurWidth;
          if(head->left)
          {
            bfsQ.push(head->left);
            ++nNextWidth;
          }
          if(head->right)
          {
              bfsQ.push(head->right);
              ++nNextWidth;
          }
      }
      if(nNextWidth>nMaxWidth)
      {
          nMaxWidth = nNextWidth;
      }
      nCurWidth = nNextWidth;
      nNextWidth = 0;
   }
   
   return nMaxWidth;
   
}
