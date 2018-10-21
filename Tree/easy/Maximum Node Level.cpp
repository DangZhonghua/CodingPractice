/*
Maximum Node Level 
https://practice.geeksforgeeks.org/problems/maximum-node-level/1/?ref=self
Find the level in a binary tree which has the maximum number of nodes. The root is at level 0.

Note: The Input/Output format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.

Input:
The first line consists of T test cases. The first line of every test case consists of N, denoting the number of edges in the tree. The second and third line of every test case consists of N, nodes of the binary tree.

Output:
Print the level number with maximum nodes.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
3
1 2 L 1 3 R 2 4 L
3
1 3 L 1 2 R 2 4 R

Output:
1
1


*/


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

// use level order traversal to count the node number at one level and select the maximum level.
int maxNodeLevel(Node *root)
{
 // Add your code here
 queue<Node*> curLevel;
 queue<Node*> nextLevel;
 
 queue<Node*>* pCurLevel;
 queue<Node*>* pNextLevel;

 pCurLevel  = &curLevel;
 pNextLevel = &nextLevel;
 
 int max = 0;
 int maxLevel = 0;

 int level = 0;
 int count = 0;

 if(root)
 {
     pCurLevel->push(root);
 }

 while(!pCurLevel->empty())
 {
     Node* head = pCurLevel->front();
     pCurLevel->pop();
     ++count;
     if(head->left)
     {
         pNextLevel->push(head->left);
     }
     if(head->right)
     {
         pNextLevel->push(head->right);
     }
     if(pCurLevel->empty())
     {
         if(count>=max)
         {
             max = count;
             maxLevel = level;
         }
         ++level;

        queue<Node*>* pTemp = pCurLevel;
        pCurLevel = pNextLevel;
        pNextLevel = pTemp;    
     }
 }
    return maxLevel;
}