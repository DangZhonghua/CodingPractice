/*
Check if subtree 
https://practice.geeksforgeeks.org/problems/check-if-subtree/1/?ref=self

Given two binary trees, the task is to complete function isSubtree, which takes two argument. First argument to the function is root of binary tree T1 and Second argument is root of tree T2. Check if the  tree T2 is subtree of the  tree T1.
A subtree of a tree T1 is a tree T2 consisting of a node in T1 and all of its descendants in T1.

Example:

T2:          10
              /   \
            4     6
                 /
             30

T1:                  26
                      /   \
                    10   3
                   /   \     \

               4       6     3
                       /
                    30

In above example T2 is subtree of T1.

Input:

The task is to complete the method . There are multiple test cases. For each test case, this method will be called individually.

Output:

Return 1 if T2 is a subtree of T1, else 0.

Constraints:
1 <=T<= 30
1 <= Number of nodes <= 20

Example:
Input:
2
5
26 10 L 10 20 L 10 30 R 20 40 L 20 60 R
5
26 10 L 10 20 L 10 30 R 20 40 L 20 60 R

3
10 4 L 10 6 R 4 30 R
6
26 10 L 26 3 R 10 4 L 10 6 R 6 25 R 3 3 R

Output:
1
0

Explanation:
First line of input represents number of test cases. Each test case contains four line. 
First line of each test case represents number of nodes in tree T2. 
Second line of each test case represents structure of tree T2. 
Third line of each test case represents number of nodes in tree T1. 
Fourth line of each test case represents structure of tree T1.
Structure of tree:
10 4 L 10 6 R 4 30 R
10 is root node of tree. Left child of 10 is 4 and right child of 10 is 6. Right child of 4 is 30.
 


Note:The Input/Output format and Example given above are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.

*/

/* A binary tree node
struct Node
{
    int key;
    Node* left, * right;
}; */
/*you are required to 
complete this function */

bool JudgeSubTree(Node* T1, Node* T2)
{
  
    if(T1 == NULL && NULL == T2)
    {
      return true;
    }
    else if(NULL == T2 || NULL == T1)
    {
      return false;
    }
    else if( T1->key == T2->key)
    {
      return (JudgeSubTree(T1->left,T2->left) && JudgeSubTree(T1->right, T2->right) );
    }
    else
    {
      return JudgeSubTree(T1->left, T2) || JudgeSubTree(T1->right,T2);
    }

    return false;

}


bool isSubtree(Node*  T1 ,Node * T2)
{
     //Your code here 
     //return 1 if T2 is subtree of T1 else 0

}
