//https://practice.geeksforgeeks.org/problems/root-to-leaf-paths-sum/1/?ref=self

// Given a binary tree, where every node value is a number . Find the sum of all the numbers which are formed from root to leaf paths.

// For example consider the following Binary Tree.
 

//            6                               
//          /   \                          
//         3     5                      
//       /   \     \
//      2    5      4             
//         /  \                        
//        7    4                 
            
//   There are 4 leaves, hence 4 root to leaf paths:
//   Path                      Number
//   6->3->2                   632
//   6->3->5->7                6357
//   6->3->5->4                6354
//   6->5>4                    654   
// Answer = 632 + 6357 + 6354 + 654 = 13997 
// Input:
// The task is to complete the method which takes one argument, root of Binary Tree. The Node has a data part which stores the data, pointer to left child and pointer to right child. There are multiple test cases. For each test case, this method will be called individually.

// Output:
// The function should return sum of all the numbers which are formed from root to leaf paths.

// Constraints:
// 1 <=T<= 30
// 1 <=Number of nodes<= 100
// 1 <=Data of a node<= 1000

// Example:
// Input:
// 2
// 2
// 1 2 L 1 3 R
// 4
// 10 20 L 10 30 R 20 40 L 20 60 R

// Output:
// 25
// 2630

// There are two test cases.  First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 2 and right child of 1 is 3. Second test case represents a tree with 4 edges and 5 nodes.

/*

Use pre-order traversal to fetch the path from root to leaf node.
*/


/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
/*You are required to complete below method */

#include<vector>
using namespace std;

long long convertV2D(vector<long long>& vd)
{
    long long num = 0;
    
    int base = 1;
    for(auto it = vd.rbegin(); it != vd.rend(); ++it)
    {
        num +=  (base*(*it));
        base *=10;
    }
    
    return num;
}

void sumpath(vector<long long>& curpath,Node* root, long long& sum)
{
    curpath.push_back(root->data);
    if(NULL == root->left && NULL ==  root->right) //this is leaf node
    {
        sum += convertV2D(curpath);
    }
    else
    {
        if(root->left)
        {
            sumpath(curpath,root->left, sum);
        }
        if(root->right)
        {
            sumpath(curpath,root->right, sum);
        }
    }
    
    curpath.pop_back();
}



long long treePathsSum(Node *root)
{
    //Your code here
    vector<long long> curpath;
    long long sum = 0;
    
    sumpath(curpath,root,sum);
    
    return sum;
}
