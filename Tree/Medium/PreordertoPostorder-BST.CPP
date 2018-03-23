//https://practice.geeksforgeeks.org/problems/preorder-to-postorder/0

// Given an array representing preorder traversal of BST, print its postorder traversal. 

// Input:
// The first line of input contains an integer T denoting the number of test cases.
// The first line of each test case is N,N is the size of array.
// The second line of each test case contains N input A[i].

// Output:
// Postorder traversal of the given preorder traversal is printed. Otherwise 'NO' is printed.

// Constraints:
// 1 <=T<= 100
// 1 <= N <= 1000
// 1 <= arr[i] <= 1000

// Example:

// Input:
// 3
// 5
// 40 30 35 80 100
// 8
// 40 30 32 35 80 90 100 120
// 8
// 7  9 6 1 4 2 3 40

// Output:
// 35 30 100 80 40
// 35 32 30 120 100 90 80 40
// NO


//This is nlog(n) solution. two cursor: one for parent elmemt, one for child element.
//for parent->parent->...->root to verify BST property.

//lets try to construct BST, of course, the BST may can't be constructed. if parent index
// equal with child index.


#include<vector>
#include<map>
#include<queue>
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


//The first element will be acted as root, then search two adjacency elements a, b with a< root< b. If there is no
// such pairs, this is invaild pre-order for BST.
Node* constructBstFromPreOrder(int arr[], int n)
{
	vector<Node*> nodes;
	vector<pair>  ranges;
	vector<char>  branch;
	
	Node* root = CreateNode(arr[0]);
	ranges.push_back(pair(0,n-1));
	nodes.push_back(root);
	branch.push_back(0);

	int i  = 0;
	int nodesCount = 1;
	while(i<nodesCount)
	{
		nodes[i]->data = arr[ranges[i].first];
		
	}
	


	
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

void postOrderFromPreOrder(Node* root)
{
    if(NULL != root)
    {
        return 0;
    }
    postOrderFromPreOrder(root->left);
    postOrderFromPreOrder(root->right);
    cout<<root->data<<" ";
    
}


int main()
{
	int arr[] = { 40, 30, 35, 80, 100 };

	Node* root = constructBstFromPreOrder(arr, _countof(arr));

	postOrderFromPreOrder(root);

	cout<<endl;

	return 0;
}