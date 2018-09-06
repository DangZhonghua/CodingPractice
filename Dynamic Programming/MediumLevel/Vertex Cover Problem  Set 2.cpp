/*
Vertex Cover Problem | Set 2

https://www.geeksforgeeks.org/vertex-cover-problem-set-2-dynamic-programming-solution-tree/
A vertex cover of an undirected graph is a subset of its vertices such that for every edge (u, v) of the graph, 
either ‘u’ or ‘v’ is in vertex cover. Although the name is Vertex Cover, the set covers all edges of the given graph.
The problem to find minimum size vertex cover of a graph is NP complete. But it can be solved in polynomial time for trees. 
In this post a solution for Binary Tree is discussed. The same solution can be extended for n-ary trees.

For example, consider the following binary tree. 

                    10
            20              30
        40      50                 60
            70      80        

The smallest vertex cover is {20, 50, 30} and size of the vertex cover is 3.

The idea is to consider following two possibilities for root and recursively for all nodes down the root.
1) Root is part of vertex cover: In this case root covers all children edges. 
We recursively calculate size of vertex covers for left and right subtrees and add 1 to the result (for root).

2) Root is not part of vertex cover: In this case, both children of root must be included in 
vertex cover to cover all root to children edges. 
We recursively calculate size of vertex covers of 
all grandchildren and add number of children to the result (for two children of root).

*/

/*

vc(root) = min{
                1+vc[root->left] + vc[root->right],
                vc[root->left->left] +vc[root->left->right] + 
                vc[root->right->left] + vc[root->right->right] + 2- (root->left==NULL? 1:0) - ((root->right==NULL? 1:0) )
             }
vc[null] = 0;

using post-order traversal

*/

#include<iostream>
#include<unordered_map>
using namespace std;

struct node
{
	int data;
	struct node* left, *right;
};



int MinimumVertexCover(node* root, unordered_map<node*, int>& hvc)
{
	if (root->left)
	{
		MinimumVertexCover(root->left, hvc);
	}

	if (root->right)
	{
		MinimumVertexCover(root->right, hvc);
	}
	int inc = 1;
	int exc = 0;
	inc += (hvc[root->left] + hvc[root->right]);
	
	if (root->left)
	{
		exc += 1;
		exc += (hvc[root->left->left] + hvc[root->left->right]);
	}
	if (root->right)
	{
		exc += 1;
		exc += (hvc[root->right->left] + hvc[root->right->right]);
	}

	hvc[root] = inc>exc ? exc : inc;

	return 0;
}

int VertexCover(node* root)
{
	if (NULL != root)
	{
		unordered_map<node*, int> hvc;
		hvc[NULL] = 0;
		MinimumVertexCover(root, hvc);
		cout << hvc[root] << endl;
	}
	else
	{
		cout << 0 << endl;
	}

	return 0;
}



// A utility function to create a node
struct node* newNode(int data)
{
	struct node* temp = (struct node *) malloc(sizeof(struct node));
	temp->data = data;
	temp->left = temp->right = NULL;
	//temp->vc = 0; // Set the vertex cover as 0
	return temp;
}

// Driver program to test above functions
int main()
{
	// Let us construct the tree given in the above diagram
	struct node *root = newNode(20);
	root->left = newNode(8);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
	root->right = newNode(22);
	root->right->right = newNode(25);

	VertexCover(root);

	return 0;
}