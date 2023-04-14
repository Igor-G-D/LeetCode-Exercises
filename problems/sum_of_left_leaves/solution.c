/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int recursiveLeftLeavesSum(struct TreeNode* p, struct TreeNode* parent);

int sumOfLeftLeaves(struct TreeNode* root){
    if(root == NULL) {
        return 0;
    }
    return recursiveLeftLeavesSum(root, NULL);

}

int recursiveLeftLeavesSum(struct TreeNode* p, struct TreeNode* parent) {
    if(p == NULL) {
        return 0;
    }
    if(p->left == NULL && p->right == NULL && parent != NULL) {
        if(parent->left == p) {
            return p->val;
        }
    }
    int sum = recursiveLeftLeavesSum(p->left, p) + recursiveLeftLeavesSum(p->right, p);

    return sum;   
     
}