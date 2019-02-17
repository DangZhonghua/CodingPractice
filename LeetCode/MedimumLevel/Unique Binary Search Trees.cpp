/*
https://leetcode-cn.com/problems/unique-binary-search-trees/
Unique Binary Search Trees

Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/

#include<vector>
#include<iostream>
using namespace std;

class Solution 
{
public:
    int numTrees(int n) 
    {
       if(n<=1)
       {
          return n;
       }
        vector<int> tc(n+1,0);
        tc[0] = 1;
        tc[1] = 1;
        
        for(int i = 2; i<=n; ++i) // total node number
        {
           for(int j = 1; j<=i; ++j) // root node ID
           {
              //root at j
            tc[i] += (tc[j-1]*tc[i-j]);
           }
        }
      return tc[n];
    }
};