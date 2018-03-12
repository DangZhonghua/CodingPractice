//https://practice.geeksforgeeks.org/problems/ancestors-in-binary-tree/1/?ref=self

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/
// Function should print all the ancestor of the target node

/////////////////////////////////////////////////////////
//Use post-order to slove this problem.
///////////////////////////////////////////////////////////




#include<vector>
using namespace std;


bool getAncestors(Node* root, int target, vector<int>& spath)
{
    
    if(NULL == root)
    {
        return false;
    }
    
    bool bleft = getAncestors(root->left,target,spath);

    if(!bleft)
    {
       bleft =  getAncestors(root->right,target,spath);
    }
    
    if(bleft)
    {
        spath.push_back(root->data);
    }
    
    if(!bleft && root->data == target)
    {
        bleft = true;
    }
    
    return bleft;
}

bool printAncestors(struct Node *root, int target)
{
     // Code here
     
     vector<int> spath;
     
    bool bfind = getAncestors(root, target, spath);
     
    vector<int>::iterator it = spath.begin();
    
    for(; it != spath.end(); ++it)
    {
        cout<<(*it)<<" ";
    }
 
     cout<<endl;
     
     return bfind;
     
}
