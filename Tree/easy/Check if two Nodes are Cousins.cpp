/*
Check if two Nodes are Cousins 
https://practice.geeksforgeeks.org/problems/check-if-two-nodes-are-cousins/1/?ref=self
Given the binary Tree and the two nodes say ‘a’ and ‘b’, determine whether the two node 
values are cousins of each other or not.

Two nodes value are cousins of each other if they are at same level and have different parents.

Note:The Input/Ouput format and Example given are used for system's internal purpose, 
and should be used by a user for Expected Output only. 
As it is a function problem, hence a user should not read any input from stdin/console. 
The task is to complete the function specified, and not to write the full code.

Input:
First line consists of T test cases. First line consists of a integer N denoting number of nodes. 
Second line consists of N triplets consisting of 2 integers and a character. 
Third line consists of 2 integers to check whether they are cousins or not.

Output:
Single line output, print "1" if they are cousins else "0". You don't have to print just return true or false.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
2
1 2 L 1 3 R
2 3
4
1 2 L 1 3 R 3 4 R 2 5 L
4 5
Output:
0
1

*/


//Complete the function below
//Node is as follows:
struct Node{
  int data;
  Node *left,*right;
};

/*
record the parent the level during traversal.
*/

#include<queue>
using namespace std;

bool ifCousin(Node *root,Node *a,Node *b)
{
   //add code here.
   int alevel = -1;
   Node* aParent = nullptr;
   int blevel = -1;
   Node* bParent = nullptr;
   queue<Node*> curQue;
   queue<Node*> nextQue;
   
   queue<Node*>* pCurQue = &curQue;
   queue<Node*>* pNextQue = &nextQue;
   
   if(root == a)
   {
       alevel = 0;
   }
   if(root == b)
   {
       blevel = 0;
   }
   int nLevel = 0;
   curQue.push(root);
   bool bCousin = false;
   while( !pCurQue->empty())
   {
       ++nLevel;
       while(!pCurQue->empty())
       {
           Node* head =pCurQue->front();
           pCurQue->pop();
           if(head->left)
           {
               if(a->data == head->left->data)
               {
                   aParent = head;
                   alevel = nLevel;
               }
               else if(b->data == head->left->data)
               {
                   bParent = head;
                   blevel = nLevel;
               }
               pNextQue->push(head->left);
           }
           if(head->right)
           {
               if(a->data == head->right->data)
               {
                   aParent = head;
                   alevel = nLevel;
               }
               else if(b->data == head->right->data)
               {
                   bParent = head;
                   blevel = nLevel;
               }
               pNextQue->push(head->right);
           }
       }
       if(nullptr != aParent && nullptr != bParent)
       {
           if(aParent != bParent)
           {
               bCousin = true;    
           }
           break;
       }
       else if( nullptr != aParent || nullptr != bParent)
       {
           break;
       }
       else
       {
           queue<Node*>* t = pCurQue;
           pCurQue = pNextQue;
           pNextQue = t;
       }
   } 

    return bCousin;

}