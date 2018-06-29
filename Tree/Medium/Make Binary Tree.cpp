/*
Make Binary Tree
https://practice.geeksforgeeks.org/problems/make-binary-tree/1/?ref=self


Given Linked List Representation of Complete Binary Tree, construct the Binary tree.
Your task is to complete the function convert which takes two arguments the first being the head denoting 
the head of the linked list and the second argument is root denoting the root of the tree to be constructed.

Note : The complete binary tree is represented as an linked list in a way where If root node is stored at position i, 
its left, and right children are stored at position 2*i+1, 2*i+2 respectively.
 










 

 

 

Input:
The first line of input is the no of test cases T. Then T test cases follow . Each test case contains 2 lines. 
The first line contains an integer N denoting the no of nodes of the linked list . 
Then in the next line are N space separated Ki values of the linked list .

Output:
Output of each test case will be the level order traversal of the the constructed binary tree. You do not have to  print it .

Constraints:
1<=T<=100
1<=N<=100
1<=Ki <=1000

Example(To be used only for expected output ) :
Input
1
5
1 2 3 4 5

Output 
1 2 3 4 5


*/


//The structure of Link list node is as follows 
struct node
{
    int data;
    struct node* next;
};
//The structure of TreeNode is as follows
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

/*You are required to complete this method*/

#include<unordered_map>
using namespace std;

void convert(node *head,TreeNode * &root)
{
    //Your code here
    node* t = head;
    root = NULL;

    if(NULL == t)
    {
        return;
    }
    unordered_map<int, TreeNode*> mapID2Node;
    int i = 0;
    root = new TreeNode;
    root->data = t->data;
    root->left = NULL;
    root->right = NULL;
    mapID2Node[i] = root;
    i = 1;
    t = t->next;

    while(t != NULL)
    {
        TreeNode* pChild = new TreeNode;
        pChild->left = NULL;
        pChild->right = NULL;
        pChild->data = t->data;
        mapID2Node[i] = pChild;
        if(i%2) //left child node
        {
            auto it = mapID2Node.find(i/2);
            if(mapID2Node.end() != it)
            {
                it->second->left = pChild;
            }
        }
        else
        {
            auto it = mapID2Node.find(i/2-1);
            if(mapID2Node.end() != it)
            {
                it->second->right = pChild;
            }
        }
        t = t->next;
        ++i;    
    }

    return;
}
