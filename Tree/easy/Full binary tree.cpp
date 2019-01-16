/*
https://practice.geeksforgeeks.org/problems/full-binary-tree/1/?ref=self
Full binary tree 

Given a Binary tree, your task is to check whether the Binary tree is a full binary tree or not.

Input:
First line consists of T test case. First line of every test case consists of N, 
denoting number of Nodes in a binary tree. Second line of every test case consists 3*N elements 2 integers and a character.

Output:
Single line output, return true if it is a full binary tree else false.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
4
1 2 L 1 3 R 2 4 L 2 5 R
3
1 2 L 1 3 R 2 4 L
Output:
1
0

*/

//Complete the function below
//Node is as follows:
struct Node
{
    int key;
    struct Node *left, *right;
};


#include <queue>
using namespace std;

bool isFullTree(struct Node *root)
{
    //add code here.
    if (nullptr == root)
    {
        return false;
    }
    int nlevel = 0;
    int nCurCount = 0;
    int nNextCount = 0;
    queue<Node *> levelQ;
    bool bFull = true;

    levelQ.push(root);
    nCurCount = 1;

    while(nCurCount && bFull)
    {
        if( (1<<nlevel) != nCurCount)
        {
            bFull = false;
            break;
        }
        while(nCurCount)
        {
            Node* head = levelQ.front();
            levelQ.pop();
            --nCurCount;
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
        ++nlevel;
    }
    return bFull;
}
