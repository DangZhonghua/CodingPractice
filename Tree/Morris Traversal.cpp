



struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


##1 既然当前节点没有左子树，那么当前节点肯定没有前序节点，所以可以直接访问当前节点。
##2：当 当前节点有左子树的的情况下，那么我们肯定要先访问它的前序节点，
    ###2.1 我们首先尝试找到前序节点： 找到 左子树中的”最右“的节点， 如果这个最右节点的右子树指针是空，那么这是第一次找到该前序，所以设置右子树指针为当前节点
    ###2.2 如果这个最右节点的右子树指针指向当前节点，那么所有的前序节点已经访问完了，所以可以访问当前节点。

重复 1 和 2 直到所有节点都访问结束。

void inorderMorrisTraversal(TreeNode *root) 
{
    TreeNode *cur = root, *prev = NULL;
    while (cur != NULL)
    {
        if (cur->left == NULL)          // 1. 没有前驱结点
        {
            printf("%d ", cur->val);
            cur = cur->right;
        }
        else
        {
            // find predecessor
            prev = cur->left;
            while (prev->right != NULL && prev->right != cur)
                prev = prev->right;

            if (prev->right == NULL)   // 2.a)  chain
            {
                prev->right = cur;
                cur = cur->left;
            }
            else      // 2.b) if prev->right == cur, 表明所有的前序节点已经访问结束了"cur->left == NULL"， 所以 visit and restore 
            {
                prev->right = NULL;
                printf("%d ", cur->val);
                cur = cur->right;
            }
        }
    }
}