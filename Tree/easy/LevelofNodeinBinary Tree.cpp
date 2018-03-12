//https://practice.geeksforgeeks.org/problems/level-of-a-node-in-binary-tree/1/?ref=self

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
Structure of the node of the binary tree is
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/
// function should return level of the target node


//use BFS to slove this problem.


#include <queue>
using namespace std;

int getLevel(struct Node *node, int target)
{
	//code here
    queue<Node*> levelQ;
    int curLevel    = 0;
    int nextLevel   = 0;
    int high        = 0;
    bool bFind      = false;
    
    if(node)
    {
        levelQ.push(node);
        curLevel    = 1;
        high        = 1;
    }
    
    while(!levelQ.empty() && !bFind)
    {
        while(curLevel>0)
        {
            Node* h = levelQ.front();
            levelQ.pop();
            --curLevel;
            if(target == h->data)
            {
                bFind = true;
                break;
            }
            if(h->left)
            {
                levelQ.push(h->left);
                ++nextLevel;
            }
            if(h->right)
            {
                levelQ.push(h->right);
                ++nextLevel;
            }
        }
        if(bFind)
        {
            break;
        }
        
        curLevel    = nextLevel;
        nextLevel   = 0;
        ++high;
    }
    
    
    if(!bFind)
    {
        high = 0;
    }
    return high;
    
}
