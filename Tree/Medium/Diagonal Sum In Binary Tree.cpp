/*
Diagonal Sum In Binary Tree
https://practice.geeksforgeeks.org/problems/diagonal-sum-in-binary-tree/1

Consider lines of slope -1 passing between nodes (dotted lines in below diagram). 
The diagonal sum in a binary tree is the sum of all node’s data lying between these lines. 
Given a Binary Tree, print all diagonal sums.

Consider lines of slope -1 passing between nodes (dotted lines in below diagram). 
The diagonal sum in a binary tree is the sum of all node’s data lying between these lines. 
Given a Binary Tree, print all diagonal sums.

*/

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the function below
Node is as follows:
*/
struct Node{
	int data;
	Node *left,*right;
};

#include<iostream>
#include<queue>
using namespace std;

void diagonalSum(Node* root)
{
 // Add your code here
 queue<Node*> curQue;
 queue<Node*> nextQue;
 queue<Node*>* pCurQue  = &curQue;
 queue<Node*>* pNextQue = &nextQue;
 if(root)
 {
    curQue.push(root);
 }
 
 int sum = 0;
 
 while(!pCurQue->empty())
 {
     Node* head = pCurQue->front();
     while(head)
     {
         sum += head->data;
         if(head->left)
         {
             pNextQue->push(head->left);
         }
         head = head->right;
     }
     pCurQue->pop();
     if(pCurQue->empty())
     {
         queue<Node*>* pTemp = pCurQue;
         pCurQue = pNextQue;
         pNextQue = pTemp;
         cout<<sum<<" ";
         sum = 0;
     }
 }
 
 
}
