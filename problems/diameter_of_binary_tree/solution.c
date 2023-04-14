/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode TreeNode;
int diameterOfBinaryTree(TreeNode* root){ 
    if(root == NULL) {
        return 0;
    }
    int heightLeft = height(root->left);
    int heightRight = height(root->right);

    int leftNodeDiameter = diameterOfBinaryTree(root->left);
    int rightNodeDiameter = diameterOfBinaryTree(root->right);

    int highestDiameter;

    if (leftNodeDiameter > rightNodeDiameter) {
        highestDiameter = leftNodeDiameter;
    } else {
        highestDiameter = rightNodeDiameter;
    }

    if(highestDiameter < (heightLeft + heightRight)) {
        highestDiameter = (heightLeft + heightRight);
    } 

    // get the highest value out of the three: diameter of left, diameter of right, diameter of current node

    return highestDiameter;
}

int height(TreeNode * p) { // first, find the height
    if(p == NULL) {
        return 0;
    }
    int left = height(p->left);
    int right = height(p->right);

    if (left > right) { //return highest height
        return ++left; 
    } else {
        return ++right;
    }
}