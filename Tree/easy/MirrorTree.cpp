//https://practice.geeksforgeeks.org/problems/two-mirror-trees/1

//use pre-order traversal to complete this task.

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Node structure
struct Node
{
    int data;
    Node* left, *right;
}; */
/* Given two trees, should return true if they are
   mirror of each other. */
   
 #include <stack>
 using namespace std;

//use pre-order traversal method to solve this problem

int areMirror(Node* a, Node* b)
{

 bool bMirror = true;
 stack<Node*> ts1;
 stack<Node*> ts2;
 
 
 if(a)
 {
    ts1.push(a);
 }
 if(b)
 {
     ts2.push(b);
 }
 
 while(!ts1.empty() && !ts2.empty() && bMirror)
 {
     Node* t1 = ts1.top();
     Node* t2 = ts2.top();
     
     if(t1->data != t2->data)
     {
         bMirror = false;
         break;
     }
    ts1.pop();
    ts2.pop();
    
    if(t1->left && t2->right)
    {
        ts1.push(t1->left);
        ts2.push(t2->right);
    }
    else
    {
        if(!(t1->left == NULL && t2->right == NULL))
        {
             bMirror = false;
            break;
           
        }
    }
    if(t1->right && t2->left)
    {
        ts1.push(t1->right);
        ts2.push(t2->left);
    }
    else
    {
        if(!(t1->right == NULL && t2->left == NULL))
        {
             bMirror = false;
            break;
           
        }
    }
     
 }
 
    
    return bMirror;
   // Your code here
}
