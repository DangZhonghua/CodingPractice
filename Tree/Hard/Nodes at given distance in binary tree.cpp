/*
Nodes at given distance in binary tree 
https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1
Given a binary tree, a target node in the binary tree, and an integer value k, 
print all the nodes that are at distance k from the given target node. No parent pointers are available.

Input:
The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. Each test case contains an integer n denoting the number of edges. T
hen the following line contains the edges as given in the example. The next line contains the target node. 
The last line of input contains the the value of distance k.

Output:
Print all the space separated nodes that are at distance k from the given target node.

Constraints:
1<=T<=1000
1<=no of edges<=100
1<=data of node<=100
1<=target<=100

Example:
Input:
2
6
20 8 L 20 22 R 8 4 L 8 12 R 12 10 L 12 14 R
8
2
5
20 7 L 20 24 R 7 4 L 7 3 R 3 1 L
7
2

Output:
10 14 22 
1 24 

*/



/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary Tree node
struct node
{
    int data;
    struct node *left, *right;
}; */
/* Recursive function to print all the nodes at distance k in the
   tree (or subtree) rooted with given root. See  */
void printkdistanceNodeDown(node *root, int k)
{
// Your code here
}
/* Prints all nodes at distance k from a given target node.
 The k distant nodes may be upward or downward.  This function
 Returns distance of root from target node, it returns -1 if target
 node is not present in tree rooted with root. */
int printkdistanceNode(node* root, node* target , int k)
{
// Your code here
}