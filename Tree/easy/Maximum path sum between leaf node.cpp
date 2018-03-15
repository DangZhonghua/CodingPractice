//https://practice.geeksforgeeks.org/problems/maximum-path-sum/1/?ref=self

// Given a binary tree in which each node element contains a number. Find the maximum possible sum from one leaf node to another.

// Input:
// First line consists of T test cases. First line of every test case consists of N, denoting number of nodes. Second line of every test case consists of N Spaced 3 elements, Parent node data, child node data and position of child node( 'L'  or  'R' ).

// Output:
// Return the Maximum possible sum.

// Constraints:
// 1<=T<=100
// 1<=N<=30

// Example:
// Input:
// 1
// 12
// -15 5 L -15 6 R 5 -8 L 5 1 R -8 2 L -8 -3 R 6 3 L 6 9 R 9 0 R 0 4 L 0 -1 R -1 10 L
// Output:
// 27

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Complete the function below
Node is as follows
struct Node{
	int data;
	Node *left, *right;
};
*/

 

 
//Use post-order traversal to slove this: when access one node, its children have been accessed
// path sums have been calculated.
#include <vector>
#include <climits>
using namespace std;

int SelecMaxSumPathBetweenLeaf(Node* root, int& nMaxSum)
{
    int nCurMaxSum = 0;
    if(NULL == root->left && NULL == root->right )
    {
        nCurMaxSum = root->data;
    }
    else
    {
        int nLeftSum    = 0;
        int nRightSum   = 0;
        
        if(root->left)
        {
           nLeftSum = SelecMaxSumPathBetweenLeaf(root->left, nMaxSum);
        }
        
        if(root->right)
        {
            nRightSum = SelecMaxSumPathBetweenLeaf(root->right, nMaxSum);
        }
        
        if(root->left && root->right)
        {
            if((nLeftSum + nRightSum + root->data)>nMaxSum)
            {
               nMaxSum = (nLeftSum+nRightSum+root->data);
            }
           
           nCurMaxSum = nLeftSum>nRightSum? nLeftSum:nRightSum;
           nCurMaxSum += root->data;
        }
        else
        {
            if(root->left)
            {
                nCurMaxSum = (nLeftSum + root->data);
            }
            if(root->right)
            {
                nCurMaxSum = (nRightSum + root->data);
            }
        }
    }
    
    return nCurMaxSum;
}



int maxPathSum(struct Node *root)
{
    //add code here.
    int nMaxSum = INT_MIN;
    
    SelecMaxSumPathBetweenLeaf(root, nMaxSum);
    return nMaxSum;
    
}