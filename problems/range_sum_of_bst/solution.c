/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int rangeSumBST(struct TreeNode* root, int low, int high){
    int leftTree = 0;
    int rightTree = 0;
    if(root->left != NULL) { // get value of sum in left subtree
        leftTree = rangeSumBST(root->left, low, high); // recursion
    }
    if(root->right != NULL) {// get value of sum in right subtree
        rightTree = rangeSumBST(root->right, low, high); // recursion
    }
    if(low <= root->val && root->val <= high) { // if in range, add the value to the sum in each subtree
        return (root->val + rightTree + leftTree);
    } else {
        return rightTree+leftTree; // if not, return sum of subtrees
    }
}