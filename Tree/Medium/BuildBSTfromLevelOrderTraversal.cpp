//https://practice.geeksforgeeks.org/problems/convert-level-order-traversal-to-bst/1


/*

Given a level order traversal of a BST, your task is to complete the function constructBst(),that construct the BST (Binary Search Tree) from its given level order traversal.

Examples:

Input : arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10}
Output : BST: 
        7        
       / \       
      4   12      
     / \  /     
    3  6 8    
   /  /   \
  1   5   10
Input:
The functio constructBst() takes two argument as input, an array (arr) the contains the level order traversal of the BST and an integer N denoting the size of the array.
There will be T test cases and for each test case the function will be called separately.

Output:
For each test return the pointer to the root of the newly constructed BST.

Constraints:
1<=T<=100
1<=N<=103

Example:
Input:
2
9
7 4 12 3 6 8 1 5 10
6
1 3 4 6 7 8
Output:
1 3 4 5 6 7 8 10 12 
1 3 4 6 7 8 

*/

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


//User function Template for C++
/*
Structure of the Node of the node of the bst 
should be as
struct Node
{
	int data;
	Node *left, *right;
};
*/
// You are required to complete this function


//This is nlog(n) solution. two cursor: one for parent elmemt, one for child element.
//for parent->parent->...->root to verify BST property.
//lets try to construct BST, of course, the BST may can't be constructed. if parent index
// equal with child index.

#include<vector>
#include<map>
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};

Node* CreateNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}


Node* constructBst(int arr[], int n)
{
	if (n == 0)return NULL;

	vector<int>   parent; //record current element's parent index.
	vector<char>  branch; //record current element's branch: left or right of parent.
	vector<Node*> nodes;  //Reocrd current element's node.    
	Node* root = CreateNode(arr[0]);
	parent.push_back(-1);
	branch.push_back(0);
	nodes.push_back(root);

	int pre = 0;
	int i = 1;
	while (i<n)
	{
		int index = pre;
		char b = 0;
		bool bChild = true;
		bool bLeftSubTree = false;
		if (arr[index]>arr[i])
		{
			bLeftSubTree = true;
		}

		index = parent[pre];
		b = branch[pre];

		while (index >= 0)
		{
			if ('L' == b) //arr[i] is whether in the left tree?
			{
				if (arr[index]>arr[i])
				{
					//LL not voliate the BST property
					b = branch[index];
					index = parent[index];
				}
				else
				{
					++pre;
					bChild = false;
					break;
				}
			}
			else if ('R' == b)
			{
				if (arr[index]>arr[i])
				{
					++pre;
					bChild = false;
					break;
				}
				else
				{
					b = branch[index];
					index = parent[index];
				}
			}
		}

		if (bChild)
		{
			Node* curnode = CreateNode(arr[i]);
			nodes.push_back(curnode);
			parent.push_back(pre);
			branch.push_back(bLeftSubTree ? 'L' : 'R');
			if (bLeftSubTree)
			{
				((nodes[pre]))->left = curnode;
			}
			else
			{
				((nodes[pre]))->right = curnode;
				++pre;
			}
			++i;
		}
	}

	return root;
}


void verifyBSTByInorder(Node* root)
{
	if (NULL == root)
	{
		return ;
	}
	verifyBSTByInorder(root->left);
	cout << root->data << " ";
	
	verifyBSTByInorder(root->right);
}


int main()
{
	int arr[] = { 7, 4, 12, 3, 6, 8, 1, 5, 10 };

	Node* root = constructBst(arr, _countof(arr));

	verifyBSTByInorder(root);
	cout<<endl;

	return 0;
}