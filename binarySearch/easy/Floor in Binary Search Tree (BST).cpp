/*
Floor in Binary Search Tree (BST)
https://www.geeksforgeeks.org/floor-in-binary-search-tree-bst/

*/

#include<iostream>
using namespace std;


struct Node
{
	int data;
	Node* left, *right;
};

int FloorInBst(Node* root, int x)
{
	Node* node = root;
	int fl = -1;

	while (node)
	{
		if (node->data>x)
		{
			node = node->left;
		}
		else
		{
			if (node->data == x)
			{
				fl = x;
				break;
			}
			else
			{
				if (fl< node->data)
				{
					fl = node->data;
				}
				node = node->right;

			}
		}
	}

	//cout << fl << endl;

	return fl;
}


/*This function is used to create and
initialises new Nodes*/
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->left = temp->right = NULL;
	temp->data = key;
	return temp;
}

/* This function is used to insert
new values in BST*/
Node* insert(Node* root, int key)
{
	if (!root)
		return newNode(key);
	if (key < root->data)
		root->left = insert(root->left, key);
	else
		root->right = insert(root->right, key);
	return root;
}

int main()
{
	/* Let us create following BST
	7
	/    \
	5      10
	/  \    /  \
	3    6   8   12 */
	Node* root = NULL;
	root = insert(root, 7);
	insert(root, 10);
	insert(root, 5);
	insert(root, 3);
	insert(root, 6);
	insert(root, 8);
	insert(root, 12);
	cout << FloorInBst(root, 9) << endl;
	cout << FloorInBst(root, 12) << endl;
	cout << FloorInBst(root, 6) << endl;


	return 0;
}