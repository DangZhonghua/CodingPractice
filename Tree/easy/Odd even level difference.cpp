/*
https://practice.geeksforgeeks.org/problems/odd-even-level-difference/1/?ref=self
Odd even level difference

Given a a Binary Tree, your task is to complete the function getLevelDiff which  
returns the difference between the sum of nodes at odd level and the sum of nodes at even level . 
The function getLevelDiff  takes only one argument  ie the root of the binary tree . 

       2
     /    \
    3     5
For the above tree the odd level sum is 2 and even level sum is 8 thus the difference is 2-8=-6

Input:
The task is to complete the method which takes one argument, root of Binary Tree. 
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return an integer denoting the difference between 
the sum of nodes at odd level and the sum of nodes at even level

Constraints:
1 <=T<= 30
1 <= Number of nodes<= 20

Example:
Input
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output
-4
60


There are two test cases.  First case represents a tree with 3 nodes and 2 edges where root is 1, 
left child of 1 is 3 and right child of 1 is 2.   Second test case represents a tree with 4 edges and 5 nodes.

*/

//The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; 

/*You are required to complete this function*/

#include<queue>
using namespace std;

int getLevelDiff(Node *root)
{
    queue<Node*>    levelQ;
    int nLevel      = 1;
    int nCurCount   = 0;
    int nNextCount  = 0;
    int nOddSum     = 0;
    int nEvenSum    = 0;

    if(nullptr == root)
    {
        return 0;
    }

    levelQ.push(root);
    nCurCount += 1;

    while(nCurCount)
    {
        while(nCurCount)
        {
            Node* head = levelQ.front();
            levelQ.pop();
            --nCurCount;
            if( (nLevel & 1 ) )
            {
                nOddSum += head->data;
            }
            else
            {
                nEvenSum += head->data;
            }
            if(nullptr != head->left)
            {
                levelQ.push(head->left);
                ++nNextCount;
            }
            if(nullptr != head->right)
            {
                levelQ.push(head->right);
                ++nNextCount;
            }
        }
        nCurCount = nNextCount;
        nNextCount = 0;
        ++nLevel;
    }

    return (nOddSum-nEvenSum);
}
