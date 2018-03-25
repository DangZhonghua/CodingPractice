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
#include <utility>
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
	vector<pair<int,int>>  ranges;
	vector<char>  branch;
	vector<int>   parent;

	Node* root = CreateNode(arr[0]);
	ranges.push_back(pair<int,int>(0, n - 1));
	nodes.push_back(root);
	branch.push_back(0);
	parent.push_back(-1);


	int i = 0;
	int nodesCount = 1;
	bool bBst = true;
	while (i < nodesCount && bBst)
	{
		nodes[i]->data = arr[ranges[i].first];
		//Now let's check whether current node voliate BST property.
		{
			int n = parent[i];
			int b = i;
			while (n >= 0)
			{
				if ('L' == branch[b])
				{
					if (nodes[n]->data < nodes[i]->data)
					{
						bBst = false;
						break;
					}
				}
				else if ('R' == branch[b])
				{
					if (nodes[n]->data > nodes[i]->data)
					{
						bBst = false;
						break;
					}
				}
				b = n;
				n = parent[n];
			}
		}
		if (!bBst)
		{
			break;
		}

		//Now lets find the partition according to the pre-order traversal.
		int p = 0;
		for (p = ranges[i].first + 1; p <= ranges[i].second; ++p)
		{
			if (arr[p] > arr[ranges[i].first])
			{
				break;
			}
		}
		if (p - 1 > ranges[i].first)//this is the left subtree
		{
			Node* node = CreateNode(arr[ranges[i].first + 1]);
			nodes.push_back(node);
			parent.push_back(i);
			branch.push_back('L');
			ranges.push_back(pair<int,int>(ranges[i].first + 1, p - 1));

			nodes[i]->left = node;

			++nodesCount;
		}
		if (p <= ranges[i].second)// this is the right subtree
		{
			Node* node = CreateNode(arr[p]);
			nodes.push_back(node);
			parent.push_back(i);
			branch.push_back('R');
			ranges.push_back(pair<int,int>(p, ranges[i].second));
			nodes[i]->right = node;
			++nodesCount;
		}
		++i;//Current nodes has been finished, so process next.
	}
	if (!bBst)
	{
		root = NULL;
	}

	return root;

}


void verifyBSTByInorder(Node* root)
{
	if (NULL == root)
	{
		return;
	}
	verifyBSTByInorder(root->left);
	cout << root->data << " ";

	verifyBSTByInorder(root->right);
}

void postOrderFromPreOrder(Node* root)
{
	if (NULL == root)
	{
		return;
	}
	postOrderFromPreOrder(root->left);
	postOrderFromPreOrder(root->right);
	cout << root->data << " ";

}


int main()
{
	int arr[] = { 7 , 9 ,6, 1, 4 ,2 ,3, 40 };

	Node* root = constructBstFromPreOrder(arr, _countof(arr));
	if (NULL == root)
	{
		cout << "This is not a BST";
	}
	else
	{
		postOrderFromPreOrder(root);
	}

	cout << endl;

	return 0;
}