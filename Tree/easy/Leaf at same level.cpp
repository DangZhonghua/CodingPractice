/*
https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1/?ref=self
Leaf at same level 

Given a Binary Tree, check if all leaves are at same level or not.

          12
        /    \
      5       7       
    /          \ 
   3            1
  Leaves are at same level

          12
        /    \
      5       7       
    /          
   3          
   Leaves are Not at same level


          12
        /    
      5             
    /   \        
   3     9
  /      /
 1      2
 Leaves are at same level

Input:
The task is to complete the method that takes one argument, 
root of Binary Tree and returns 1 if all leaves are at same level else returns 0

Output:
Output for each test case will be 0 if all leaves are not at same level else it will 1.

Constraints:
1 <=T<= 30
1 <= Number of nodes<= 100
1 <= Data of a node<= 1000

Example(To be used only for expected output):
Input
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output
1
0


*/

The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};

/*You are required to complete this method*/
bool check(Node *root)
{
    //Your code here
}