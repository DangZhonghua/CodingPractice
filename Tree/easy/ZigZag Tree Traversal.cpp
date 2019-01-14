/*
ZigZag Tree Traversal 
https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1/?ref=self

Given a binary tree of size N, your task is to complete the function zigZagTraversal(), that prints the nodes of binary tree in ZigZag manner.

For Example:
For the below binary tree the zigzag order 
traversal will be 1 3 2 7 6 5 4.

Input:
The function takes a single argument as input, the reference pointer to the root of the binary tree.
There will be T testcases and for each test case the function will be called separately.
Output:
For each test case print on a new line space separated all the nodes of the tree in ZigZag manner.
Constraints:
1<=T<=500
1<=N<=1000
Example:
Input:
1
10
1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 3 7 R 4 8 L 5 9 R 6 10 L 7 11 R
Output:
1 3 2 4 5 6 7 11 10 9 8

*/


//User function Template for C++
//Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node *left, *right;
};

// your task is to complete this function 
// Function takes a single argument as input
// the root of the binary tree
// print a new line after each test case

#include<deque>
#include<iostream>
using namespace std;

void outputNodes( deque<Node*>& q, bool bStartFromHead)
{
    if(bStartFromHead)
    {
        int nq = q.size();
        int i = 0;
        while(i<nq)
        {
            Node* head = q.front();
            cout<< head->data<<" ";
            q.pop_front();
            q.push_back(head);
            ++i;
        }
    }
    else
    {
        int nq = q.size();
        int i = 0;
        while(i<nq)
        {
            Node* head = q.back();
            cout<< head->data<<" ";
            q.pop_back();
            q.push_front(head);
            ++i;
        }
    }
    
}

void zigZagTraversal(Node* root)
{
	// Code here
    if(NULL == root)
    {
        return;
    }
    deque<Node*> s;
    deque<Node*> snext;
    s.push_back(root);
    
    deque<Node*>* cur = &s;
    deque<Node*>* next = &snext;

    bool bStartFromHead = true;

    while(!cur->empty())
    {
        outputNodes(*cur,bStartFromHead);
        while(!cur->empty())
        {
            Node* head = cur->front();
            cur->pop_front();
            if(NULL != head->left)
            {
                next->push_back(head->left);
            }
            if( NULL != head->right)
            {
                next->push_back(head->right);
            }
        }
        bStartFromHead = !bStartFromHead;
        deque<Node*> *t = cur;
        cur = next;
        next = t;
    }
    cout<<endl;

}