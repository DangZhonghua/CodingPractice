/*
Children Sum Parent 
https://practice.geeksforgeeks.org/problems/children-sum-parent/1/?ref=self

Given a binary tree, write a function that returns true if the tree satisfies the following property.

For every node, data value must be equal to the sum of data values in left and right children. Consider data value as 0 for NULL children.

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.

Input:
The first line consists of T test cases. The first line of every test case consists of N, denoting the number of edges in the tree. The second and third line of every test case consists of N, nodes of the binary tree.


Output:
Return 1 if the given tree satisfies the given property else return 0. 

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
3
4 1 L 4 3 R 3 3 L
5
10 8 L 10 2 R 8 3 L 8 5 R 2 2 L​

Output:
1
1​

*/

/*Complete the function below
Node is as follows:*/
struct Node{
	int data;
	Node *left,*right;
};


//use post-order traversal
#include<iostream>
using namespace std;


int postOrderSum(Node* node, bool& bVoliation)
{
    bVoliation = false;
    if(NULL == node)
    {
        return 0;
    }

    /*this is for leaf node*/
    if(NULL == node->left && NULL == node->right)
    {
        return node->data;
    }
    bool bleftVoliation = false;
    int leftv = postOrderSum(node->left, bleftVoliation);
    bool brightVoliation = false;
    int rightv = postOrderSum(node->right, brightVoliation);
    if(bleftVoliation || brightVoliation)
    {
        bVoliation = true;
    }
    if(node->data != (leftv+rightv) )
    {
        bVoliation = true;
    }
    return node->data;
    
}


int isSumProperty(Node *node)
{
 // Add your code here
  bool bVoliation = false;
  postOrderSum(node,bVoliation);
  
  return !bVoliation;

}