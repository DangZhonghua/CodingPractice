//https://practice.geeksforgeeks.org/problems/leaves-to-dll/1/?ref=self

// Given a Binary Tree, extract all leaves of it in a Doubly Linked List (DLL). Note that the DLL need to be created in-place. Assume that the node structure of DLL and Binary Tree is same, only the meaning of left and right pointers are different. In DLL, left means previous pointer and right means next pointer. Head of DLL should point to the left most leaf and than in inorder traversal and so on.

// Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.

// Input:
// The task is to complete the method which takes two arguments, root of Binary Tree and reference to head of DLL.
// The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
// There are multiple test cases. For each test case, this method will be called individually.

// Output:
// In the function make changes in Head.

// Constraints:
// 1<=T<=100
// 1<=N<=10000

// Example:
// Input:
// 2
// 2
// 1 2 L 1 3 R
// 3
// 1 2 L 1 3 R 2 4 L
// Output:
// 2 3
// 3 2 
// 4 3
// 3 4 

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Complete the function below
Node is as follows:
struct Node{
	int data;
	Node *left,*right;
};
*/

#include <stack>
using namespace std;

Node *convertToDLL(Node *root,Node **head_ref)
{
    //add code here.
    stack<Node*> inorderS;
    
    if(NULL == root)
    {
        *head_ref = NULL;
         return NULL;
    }
    
    Node* pleft = NULL;
    if(root)
    {
        inorderS.push(root);
        pleft = root->left;
    }
    
    Node* head = NULL;
    Node* last = NULL;
    
    while(!inorderS.empty() || pleft)
    {
        while(pleft)
        {
            inorderS.push(pleft);
            pleft = pleft->left;
        }
        
        //access the in-order root now.
        //But it is leaf node? so judge it
        
        Node* t = inorderS.top();
        inorderS.pop();
        
        if(NULL == t->left && NULL == t->right)
        {
            if(NULL == head)
            {
                //Create DLL head
                head = t;
                last = t;
                head->left = NULL;
                head->right = NULL;
            }
            else
            {
                //Insert into DLL list.
                last->right = t;
                t->left     = last;
                last        = t;
                last->right = NULL;
            }
        }
        else
        {
            if(NULL != t->right)
            {
                pleft = t->right;
            }
        }
        
    }
    
    *head_ref = head;
    
    return head;

}