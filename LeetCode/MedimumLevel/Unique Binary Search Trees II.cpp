/*
https://leetcode-cn.com/problems/unique-binary-search-trees-ii/
Unique Binary Search Trees II

Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3



*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include<iostream>
#include<vector>
#include<map>
using namespace std;

 struct TreeNode 
 {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };



/*

BT[i,j] = BT[i,m]  root[m] BT[m+1, j] for m in [i,j] 

*/

class Solution 
{
public:
    vector<TreeNode*> generateTrees(int n) 
    {
      map< int, map<int, vector<TreeNode*> > > mapIndexTree;

      for(int i = 1; i <=n; ++i)
      {
        TreeNode* node = new TreeNode(i);
        map<int,  vector<TreeNode*> > a;
        a[1].push_back(node);
        mapIndexTree[i] = a;
      }

       for(int L = 2;  L<= n; ++L) // Create the binary from small size window
       {
          for(int i = 1; i<=(n-L+1); ++i)
          {
            map<int, vector<TreeNode*> > a;
            a[L] = vector<TreeNode*>();
            mapIndexTree[i] = a;
            int j = i+L-1;
            for( int m = i; m <= j; ++m)  //root at node m.
            {
                int LL = m-i;
                int RL = j-m;
                if( m-1>=i && m+1<=j)
                {
                   auto itleft = mapIndexTree[i].at(LL).begin();
                   
                   for(; itleft != mapIndexTree[i].at(LL).end(); ++itleft)
                   {
                     auto itright = mapIndexTree[m+1].at(RL).begin();
                     for(; itright !=  mapIndexTree[m+1].at(RL).end(); ++itright)
                     {
                       TreeNode* r = new TreeNode(m);
                       r->left = *itleft;
                       r->right = *itright;
                        mapIndexTree[i].at(L).push_back(r);
                     }
                   }
                }
                else if( m-1>=i)
                {
                  auto itleft = mapIndexTree[i].at(LL).begin();
                  for(; itleft != mapIndexTree[i].at(LL).end(); ++itleft)
                  {
                      TreeNode* r = new TreeNode(m);
                      r->left = *itleft;     
                      mapIndexTree[i].at(L).push_back(r);
                  }
                }
                else
                {
                      auto itright = mapIndexTree[m+1].at(RL).begin();
                     for(; itright !=  mapIndexTree[m+1].at(RL).end(); ++itright)
                     {
                       TreeNode* r = new TreeNode(m);
                       r->right = *itright;
                      mapIndexTree[i].at(L).push_back(r);
                     }
                }
                
            }
          }
       }

      return mapIndexTree[1].at(n);
    }
};