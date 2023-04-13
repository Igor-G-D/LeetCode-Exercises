/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
int height( struct TreeNode *p );

bool isBalanced(struct TreeNode* root){
    if(root == NULL) {
        return true;
    }

    int subtreeLeft = isBalanced(root->left);
    int subtreeRight = isBalanced(root->right);

    if(subtreeLeft && subtreeRight) {
        int balancingFactor = height(root->left) - height(root->right);
        if(balancingFactor <= 1 && balancingFactor >= -1) {
            return true;
        } 
    }
    return false;
}

int height( struct TreeNode *p ) {
    int rightHeight = 0;
    int leftHeight = 0;
    if(p == NULL) {
        return 0;
    } else {
        rightHeight = height(p->right);
        leftHeight = height(p->left);
    }

    if(rightHeight >= leftHeight) { // if the height of the right node is higher, the height of the root node would be height(right) +1. If the heights are the same, doesn't matter if right or left is used
        return (rightHeight+1);
    } else {
        return (leftHeight+1);// if the height of the left node is higher, the height of the root node would be height(left) +1.
    }
}