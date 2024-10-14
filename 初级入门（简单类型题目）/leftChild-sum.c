/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//404.左子树之和 ； 广度优先遍历 ； 2024.9.21
//直接遍历二叉树就可以
//使用广度优先遍历，可以先写一个用来判断是否为子树的函数
int isLeftnode(struct TreeNode* node)
{
    return (node->left == NULL) && (node->right == NULL);
}


int sumOfLeftLeaves(struct TreeNode* root) {
    if(root ==NULL)
    {
        return 0;
    }
    //创建广度优先遍历需要使用的队列
    struct TreeNode** q = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 2000);
    //模拟队头和队尾
    int left = 0;
    int right = 0;
    q[right++] = root;
    int ans = 0;
    while(left < right)
    {
        struct TreeNode* node = q[left++];
        if(node->left)
        {
            if(isLeftnode(node->left))
            {
                ans += node->left->val;
            }
            else
            {
                q[right++] = node->left;
            }

        }
        if(node->right)
        {
            if(!isLeftnode(node->right))
            {
                q[right++] = node->right;
            }
        }
    }
    return ans;
}