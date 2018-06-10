/*
Largest Independent Set Problem
https://practice.geeksforgeeks.org/problems/largest-independent-set-problem/1

Given a Binary Tree of size N, find size of the Largest Independent Set(LIS) in it. A subset of all tree nodes is an independent set if there is no edge between any two nodes of the subset. Your task is to complete the function LISS(), which finds the size of the Largest Independent Set.

For example:
Consider the following binary tree.The LIS is
LIS: [10, 40, 60, 70, 80]
Size: 5.

Input:
The function takes a single argument as input, the root of the binary tree. There will be T test cases and for each test case the function will be called separately.

Output:
For each test case function should return the size of the Largest Independent Set (LIS).

Constraints:
1<=T<=100
1<=N<=500

Example:
Input:
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R
Output:
2
3

*/

/*

              1+LISS[root->left->left]+LISS[root->left->right] + LISS[root->right->left] + LISS[root->right->right]
LISS[root] = Max
             LISS[root->Left] + LISS[root->right]



*/

#include<unordered_map>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};


int postorderLISS(struct Node* root, unordered_map<struct Node*, int>& hashmapNode2Count)
{
    if(NULL == root)
    {
        return 0;
    }
    int ncount_exc = 0;
    int ncount_inc = 1;
    postorderLISS(root->left,hashmapNode2Count);
    postorderLISS(root->right,hashmapNode2Count);


    auto it = hashmapNode2Count.find(root->left);
    ncount_exc += it->second;
    it = hashmapNode2Count.find(root->right);
    ncount_exc += it->second;

    if(root->left)
    {
        it = hashmapNode2Count.find(root->left->left);
        ncount_inc += it->second;
        it = hashmapNode2Count.find(root->left->right);
        ncount_inc += it->second;
    }
    if(root->right)
    {
        it = hashmapNode2Count.find(root->right->left);
        ncount_inc += it->second;

        it = hashmapNode2Count.find(root->right->right);
        ncount_inc += it->second;
    }

    if(ncount_inc>ncount_exc)
    {
        hashmapNode2Count.insert(std::make_pair(root,ncount_inc));
    }
    else
    {
        hashmapNode2Count.insert(std::make_pair(root,ncount_exc));        
    }

    return 0;
}

int LISS(struct Node *root)
{
    unordered_map<struct Node*, int> hashmapNode2Count;
    hashmapNode2Count.insert(pair<struct Node*,int>(NULL,0));

    postorderLISS(root,hashmapNode2Count);
    auto it = hashmapNode2Count.find(root);

    return it->second;
}


int main()
{



    return 0;
}