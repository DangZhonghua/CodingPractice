/*
Vertex Cover Problem | Set 2

https://www.geeksforgeeks.org/vertex-cover-problem-set-2-dynamic-programming-solution-tree/
A vertex cover of an undirected graph is a subset of its vertices such that for every edge (u, v) of the graph, 
either ‘u’ or ‘v’ is in vertex cover. Although the name is Vertex Cover, the set covers all edges of the given graph.
The problem to find minimum size vertex cover of a graph is NP complete. But it can be solved in polynomial time for trees. 
In this post a solution for Binary Tree is discussed. The same solution can be extended for n-ary trees.

For example, consider the following binary tree. 
The smallest vertex cover is {20, 50, 30} and size of the vertex cover is 3.

*/

/*

vc(root) = min{
                1+vc[root->left->left]+ vc[root->left->right] + vc[root->right->left] + vc[root->right->right],
                vc[root->left] + vc[root->right]
             }
vc[null] = 0;


*/

#include<iostream>
#include<unordered_map>
using namespace std;

struct treeNode_t
{
    int m_data;
    struct treeNode_t* left, *right;
};



int MinimumVertexCover(treeNode_t* root)
{
    

    return 0;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
