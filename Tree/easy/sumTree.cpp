//https://practice.geeksforgeeks.org/problems/sum-tree/1/?ref=self

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
// Should return true if tree is Sum Tree, else false

bool JudgeSumTree(Node* root, int& sum)
{
    int nleftsum    = 0;
    int nrightsum   = 0;
    bool bleft      = true;
    bool bright     = true;
    
    if(root->left)
    {
        bleft = JudgeSumTree(root->left, nleftsum);
    }
    
    if(!bleft)
    {
        return false;
    }
    
    if(root->right)
    {
        bright = JudgeSumTree(root->right,nrightsum);
    }
    
    if(!bright)
    {
        return false;
    }
    
    sum += (root->data+nleftsum + nrightsum);
    
    if(root->right == NULL && root->left == NULL)
    {
        return true;
    }
    
    if(root->data != (nleftsum + nrightsum))
    {
        return false;
    }
    
    return true;
    
}

bool isSumTree(Node* root)
{
     // Your code here
     
     if(NULL == root)
     {
         return true;
     }
     
     int sum = 0;
     return JudgeSumTree(root,sum);
}