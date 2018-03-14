//https://practice.geeksforgeeks.org/problems/vertical-sum/1/?ref=self


// Given a Binary Tree, find vertical sum of the nodes that are in same vertical line. Print all sums through different vertical lines.

// Input:
// First line of every test case consists of T test case. First line of every test case consists of N, denoting number of nodes. Second line of every test case consists of 3*N elements denoting , 2 integers and 1 character ,i.e., parent node , child node and character denotes which child.

// Output:
// Single line output, print the vertical sum from left to right.

// Constraints:
// 1<=T<=100
// 1<=N<=100

// Example:
// Input:
// 2
// 3
// 5 2 L 5 3 R 2 1 L
// 5
// 5 3 R 5 2 L 2 1 L 2 7 R 3 6 L
// Output:
// 1 2 5 3 
// 1 2 18 3 


//Use level-order or BFS to complete this task.

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Complete the function below
Node is as follows:
struct Node{
int data;
Node *left,*right;
};
*/

#include<map>
#include<queue>
using namespace std;


void printVertical(Node *root)
{
//add code here.
    map<int, int> mapLevel2sum;
    queue<Node*> levelQ;
    queue<int>   levelDQ;
    
    if(root)
    {
        levelQ.push(root);
        levelDQ.push(0);
      
    }
    
    while(!levelQ.empty())
    {
        Node* head  = levelQ.front();
        int   headD = levelDQ.front();
        levelQ.pop();
        levelDQ.pop();
        auto it = mapLevel2sum.find(headD);
        if( mapLevel2sum.end() != it)
        {
            it->second += head->data;
        }
        else
        {
            mapLevel2sum.insert(std::make_pair(headD,head->data));
        }
        if(head->left)
        {
            levelQ.push(head->left);
            levelDQ.push(headD-1);
        }
        if(head->right)
        {
            levelQ.push(head->right);
            levelDQ.push(headD+1);
        }
    }
    
    for(auto it = mapLevel2sum.begin(); it != mapLevel2sum.end(); ++it)
    {
        cout<<it->second<<" ";
    }
    //cout<<endl;
    
}