/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void    invertTree_recur(struct TreeNode *now);

struct TreeNode* invertTree(struct TreeNode* root){
    if (root != 0)
        invertTree_recur(root);
    return (root);
}

void   invertTree_recur(struct TreeNode *now){
    struct TreeNode    *tmp;
    
    if (now -> left != 0)
        invertTree_recur(now -> left);
    if (now -> right != 0)
        invertTree_recur(now -> right);
    tmp = now -> left;
    now -> left = now -> right;
    now -> right = tmp;
}


