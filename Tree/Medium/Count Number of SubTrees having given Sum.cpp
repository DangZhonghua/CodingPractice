/*

Count Number of SubTrees having given Sum
https://practice.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum/1

Given a binary tree containing N+1 nodes and an integer X. Your task is to complete the function countSubtreesWithSumX(), that returns the count of the number of subtress having total node’s data sum equal to a value X.
Example:

Input : 
Binary Tree:      5
                /   \  
             -10     3
             /  \   /  \
            9    8 -4   7
x = 7

Output : 2
1st one is leaf node:
7.

2nd one is:
      -10
     /   \
    9     8

Input:
The function takes a two argument as input, the reference pointer to the root of the binary tree and an integer denoting the value of X.
There will be T testcases and for each test case the function will be called separately.

Output:
For each test case the function should return the required answer.

Constraints:
1<=T<=10^3
1<=N<=10^3
-10^3 <=Node Value <= 10^3

Example:
Input:
2
6
5 -10 L 5 3 R -10 9 L -10 8 R 3 -4 L 3 7 R
7
2
1 2 L 1 3 R
5
Output:
2
0

*/


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//User function Template for C++

//Structure of the node of the binary tree is as

struct Node {
	int data;
	struct Node *left, *right;
};

// your are required to complete this function
// function should return the count of the number of subtrees with Sum equal to X
// Use the post-order traverse to do this.


int PostOrderCountSubtree(Node* n, int x,int&count)
{
    if(nullptr == n)
    {
        return 0;
    }
    int leftsum     = 0;
    int rightsum    = 0;
    
    leftsum = PostOrderCountSubtree(n->left,x,count);
    rightsum = PostOrderCountSubtree(n->right,x,count);
    int sum = leftsum+rightsum+n->data;
    if(sum == x)
    {
        ++count;
    }
    return sum;
}


int countSubtreesWithSumX(Node* root, int x)
{
	if (!root)return 0;
	// Code here
    int count = 0;
    PostOrderCountSubtree(root, x,count);
    
    return count;
}