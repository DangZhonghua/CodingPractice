/*
Construct Binary Tree from Parent Array 
https://practice.geeksforgeeks.org/problems/construct-binary-tree-from-parent-array/1/?ref=self

Given an array that represents a Tree in such a way that array indexes are values in tree nodes and 
array values give the parent node of that particular index (or node). 
The value of the root node index would always be -1 as there is no parent for root. 
Construct the standard linked representation of given Binary Tree from this given representation.

The Binary tree  node structure has 3 fields, a data part which stores the data, 
a left pointer which points to the left element of the tree and a right pointer which points to the right node of the  tree. 

There are multiple test cases. For each test case, this function will be called individually.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of two lines. First line of each test case contains an integer N denoting the size of the tree array . Second line of each test case consists of 'N' space separated integers denoting the elements of the array . 

Output:
The Output will be the sorted level order traversal of the tree you are only required to return the modified tree root.

Expected Time Complexity: O(N)

Constraints:
1<=T<=100
1<=N<=200

Example:
Input:
1
7
-1 0 0 1 1 3 5     

Output:
0 1 2 3 4 5 6       (Sorted Level Order  Traversal of the constructed tree)

Explanation:
 

For the array parent[] = {-1, 0, 0, 1, 1, 3, 5};
the tree generated will have a sturcture like  
         0
       /   \
      1     2
     / \
    3   4
   /
  5 
 /
6


*/


 //node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; 

/*  Function which returns the  root of 
    the constructed binary tree. */


/*
Test case:
2
34
1 13 31 7 17 33 27 1 5 15 19 3 33 17 19 21 23 25 31 11 29 13 27 7 25 -1 23 15 3 11 21 5 9 9
21
9 13 17 9 5 7 11 1 19 3 5 3 13 0 11 15 19 1 15 17 -1


*/

#
#include<unordered_map>
using namespace std;

Node* CreateNode(int data)
{
	Node* node = new Node;
	if (node)
	{
		node->data = data;
		node->left = NULL;
		node->right = NULL;
	}
	return node;
}

Node *createTree(int parent[], int n)
{
	// Your code here
	if (0 == n)
	{
		return NULL;
	}
	unordered_map<int, Node*> mapID2Node;
	Node* root = NULL;

	for (int index = 0; index<n; ++index)
	{
		Node* node = NULL;

		//Since the current node may be previous node's parent. so the current may be exist as previous create it as parent
		//so we need check it.
		auto itnode = mapID2Node.find(index);
		if (itnode != mapID2Node.end())
		{
			node = itnode->second;
		}
		else
		{
			node = CreateNode(index);
			mapID2Node[index] = node;
		}

		if (-1 == parent[index])
		{
			root = node;
			continue;
		}

		auto it = mapID2Node.find(parent[index]);
		//If parent is not existed, we create it.
		if (mapID2Node.end() == it)
		{
			mapID2Node[parent[index]] = CreateNode(parent[index]);
			it = mapID2Node.find(parent[index]);
		}

		if (NULL == it->second->left)
		{
			it->second->left = node;
		}
		else if (NULL == it->second->right)
		{
			it->second->right = node;
		}
	}

	return root;
}

int main()
{
	int a[] = { 1, 13, 31, 7, 17, 33, 27, 1, 5, 15, 19, 3, 33, 17, 19, 21, 23, 25, 31, 11, 29, 13, 27, 7, 25, -1, 23, 15, 3, 11, 21, 5, 9, 9 };

	Node* root = createTree(a, 34);

	return 0;
}