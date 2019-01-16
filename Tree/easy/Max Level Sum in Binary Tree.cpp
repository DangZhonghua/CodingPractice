/*
https://practice.geeksforgeeks.org/problems/max-level-sum-in-binary-tree/1/?ref=self
Max Level Sum in Binary Tree 

Given a Binary Tree having positive and negative nodes, the task is to find maximum sum level in it.

Examples:

Input :               4
                    /   \
                   2    -5
                  / \    /\
                -1   3 -2  6
Output: 6
Explanation :
Sum of all nodes of 0'th level is 4
Sum of all nodes of 1'th level is -3
Sum of all nodes of 0'th level is 6
Hence maximum sum is 6

Input :          1
               /   \
             2      3
           /  \      \
          4    5      8
                    /   \
                   6     7  
Output :  17

 
Input:
The task is to complete the method which takes one argument, root of Binary Tree. The Node has a data part which stores the data, 
pointer to left child and pointer to right child. There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return max sum level in the tree.

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
-1000 <=Data of a node<= 1000

Example(To be used only for expected output):
Input:
2
2
1 2 L 1 3 R
6
4 2 L 4 -5 R 2 -1 L 2 3 R -5 -2 L -5 6 R
Output:
5
6

There are two test cases.  First case represents a tree with 3 nodes and 2 edges 
where root is 1, left child of 1 is 2 and right child of 1 is 3.   
Second test case represents a tree with 6 edges and 7 nodes.


*/

 //Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; 
/*You are required to complete below method */

#include <queue>
using namespace std;

int maxLevelSum(Node * root)
{
  int maxsum = 0;
  int cursum = 0;
  queue<Node*>  levelQ;
  
  if(nullptr == root)
  {
      return 0;
  }
  
  int nCurCount     = 0;
  int nNextCount    = 0;

  levelQ.push(root);
  nCurCount = 1;
  
  while(nCurCount)
  {
      while(nCurCount)
      {
          Node* head = levelQ.front();
          cursum += levelQ.front()->data;
          levelQ.pop();
          --nCurCount;
          if(nullptr != head->left )
          {
              levelQ.push(head->left);
              ++nNextCount;
          }
          if(nullptr != head->right)
          {
              levelQ.push(head->right);
              ++nNextCount;
          }
      }
      nCurCount = nNextCount;
      nNextCount = 0;
      if(cursum>maxsum)
      {
          maxsum = cursum;
      }
      cursum = 0;
  }

    return maxsum;
}
