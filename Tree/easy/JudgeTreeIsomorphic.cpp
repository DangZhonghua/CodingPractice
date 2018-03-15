//https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1/?ref=self

// Write a function to detect if two trees are isomorphic. Two trees are called isomorphic if one of them can be obtained from other by a series of flips, i.e. by swapping left and right children of a number of nodes. Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.

// Input:
// First line consists of T test cases. First line of every test case consists of N, denoting number of Node in tree. Second and third line of every test case consists of N, nodes of binary tree.

// Output:
// Single line output, return the boolean value true if "Yes" else "No".

// Constraints:
// 1<=T<=100
// 1<=N<=100

// Example:
// Input:
// 2
// 3
// 1 2 L 1 3 R 2 4 L
// 1 3 L 1 2 R 3 4 R
// 3
// 1 2 L 1 3 R 2 4 L
// 1 3 L 1 2 R 2 4 R
// Output:
// No
// Yes

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

bool IsNodeIsomorphic(Node*fn, Node* sn)
{
    bool bIsomorphic =  true;
    
    short nfc = 0;
    short nsc = 0;
    
    //Node's child count
    if(fn->left && fn->right)
    {
        nfc = 2;
    }
    else if(fn->left || fn->right)
    {
        nfc = 1;
    }
    
    if(sn->left && sn->right)
    {
        nsc = 2;
    }
    else if(sn->left || sn->right)
    {
        nsc = 1;
    }
    
    do
    {
        
        if(nfc != nsc || fn->data != sn->data)
        {
            bIsomorphic = false;
            break;
        }
        
        if(2 == nfc)
        {
            
            if(fn->left->data == sn->left->data)
            {
                if(fn->right->data != sn->right->data)
                {
                     bIsomorphic = false;
                     break;
                }
            }
            else if(fn->left->data == sn->right->data)
            {
                if(fn->right->data != sn->left->data)
                {
                    bIsomorphic = false;
                    break;
                }
                Node* t = sn->right;
                sn->right = sn->left;
                sn->left = t;
            }
            else
            {
                bIsomorphic = false;
                break;
            }
            
        }
        else if (1 == nfc)
        {
            if(fn->left)
            {
                if(sn->left)
                {
                    if(fn->left->data != sn->left->data)
                    {
                        bIsomorphic = false;
                        break;
                    }
                }
                else if(sn->right)
                {
                    if(fn->left->data != sn->right->data)
                    {
                         bIsomorphic = false;
                         break;
                    }
                    sn->left    = sn->right;
                    sn->right   = NULL;
                }
            }
            else if(fn->right)
            {
                if(sn->right)
                {
                    if(sn->right->data != fn->right->data)
                    {
                        bIsomorphic = false;
                        break;
                    }
                }
                else if(sn->left)
                {
                    if(fn->right->data != sn->left->data)
                    {
                        bIsomorphic = false;
                        break;
                    }
                    sn->right = sn->left;
                    sn->left = NULL;
                }
            }
        }
        
        
    }while(false);

    
    return bIsomorphic;
}

//Pre-order/DFS traversal to slove this from up to bottom and addtionally, correct the second tree to the first one if the two are isomorphic
bool JudgeIsomorphic(Node* root1, Node* root2)
{
    if(!IsNodeIsomorphic(root1, root2))
    {
        return false;
    }
    bool bIsomorphic = true;
    if(root1->left && root2->left)
    {
        bIsomorphic =  JudgeIsomorphic(root1->left,root2->left);
    }
    if(!bIsomorphic)
    {
        return bIsomorphic;
    }
    
    if(root1->right && root2->right)
    {
        bIsomorphic =  JudgeIsomorphic(root1->right,root2->right);
    }
    
    return bIsomorphic;
    
}



bool isIsomorphic(Node *root1,Node *root2)
{
//add code here.
    if(root1 && root2)
    {
        return JudgeIsomorphic(root1, root2);
    }
    else if(NULL == root1 && NULL == root2)
    {
        return true;
    }
    
    return false;
}

