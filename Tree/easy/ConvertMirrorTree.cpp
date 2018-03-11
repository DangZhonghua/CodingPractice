//https://practice.geeksforgeeks.org/problems/mirror-tree/1

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


//function Template for C++
/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/* Should convert tree to its mirror */


#include<stack>
using namespace std;


void mirror(Node* node) 
{
    // Your Code Here
    stack<Node*> s;
    
    if(node)
    {
        s.push(node);
    }
    while(!s.empty())
    {
        Node* t = s.top();
        Node* left = t->left;
        t->left = t->right;
        t->right = left;
        s.pop();
        
        if(t->left)
        {
            s.push(t->left);
        }
        if(t->right)
        {
            s.push(t->right);
        }
    }
    
}