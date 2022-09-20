/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int                 depth_track(struct TreeNode *tree);
struct TreeNode*    go_into_tree(struct TreeNode* root, int operation, int depth);

struct TreeNode* reverseOddLevels(struct TreeNode* root){
    int     depth;

    depth = depth_track(root);
    if (depth % 2 == 0 && depth != 0)
        depth = depth - 1;
    while (depth > 0)
    {
        int i = 0;
        int operation = pow(2, depth) - 1;
        
        while (i < (operation - i))
        {
            int tmp;
            struct TreeNode *left_node = go_into_tree(root, i, depth);
            struct TreeNode *right_node = go_into_tree(root, operation - i, depth);
            
            tmp = left_node -> val;
            left_node -> val = right_node -> val;
            right_node -> val = tmp;
            i++;
        }
        depth = depth - 2;
    }
    return (root);
}

int     depth_track(struct TreeNode *tree){
    int             i;
    struct TreeNode *tmp;
    
    i = 0;
    tmp = tree;
    while (tmp -> left != 0)
    {
        tmp = tmp -> left;
        i++;
    }
    return (i);
}

struct TreeNode*    go_into_tree(struct TreeNode* root, int operation, int depth)
{
    int             i;
    int             is_right;

    if (depth == 1)
    {
        root = operation == 0 ? root -> left : root -> right; 
        return (root);
    }
    i = 1;
    while (i <= depth)
    {
        is_right = (operation >> (depth - i)) == 0 ? 0 : 1;
        root = is_right == 0 ? root -> left : root -> right;
        operation = is_right == 0 ? operation : operation - pow(2, depth - i);
        i++;
    }
    return (root);
}


