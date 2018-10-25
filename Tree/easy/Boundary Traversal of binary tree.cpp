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

void printLeftEdge(Node* root)
{
    if(root)
    {
       
        if(root->left)
        {
             cout<<root->data<<" ";
            printLeftEdge(root->left);
        }
        else if(root->right)
        {
             cout<<root->data<<" ";
            printLeftEdge(root->right);
        }
    }
}

void printLeaves(Node* root)
{
    if(root)
    {
        if(NULL ==  root->left && NULL == root->right)
        {
            cout<<root->data<<" ";
        }
        else
        {
            printLeaves(root->left);
            printLeaves(root->right);
        }
    }
}

void printRightEdge(Node* root)
{
    if(root)
    {
        if(root->right)
        {
            printRightEdge(root->right);
            cout<<root->data<<" ";
        }
        else if(root->left)
        {
            printRightEdge(root->left);
            cout<<root->data<<" ";
        }
        
    }
}


void printBoundary(Node *root)
{
     //Your code here
     if(root)
     {
         cout<<root->data<<" ";
         printLeftEdge(root->left);
         printLeaves(root->left);
         printLeaves(root->right);
         printRightEdge(root->right);
     }
}