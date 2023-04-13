/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2){

    if(root1 == NULL && root2 == NULL) {
        return NULL;
    }
    struct TreeNode * node = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    if (root1 && root2 == NULL) {
        node->val = root1->val;
        node->left = mergeTrees(root1->left, NULL);
        node->right = mergeTrees(root1->right, NULL);
    }

    if (root1 == NULL && root2) {
        node->val = root2->val;

        node->left = mergeTrees(NULL, root2->left);
        node->right = mergeTrees(NULL, root2->right);
    }

    if(root1 && root2) {
        node->val = root1->val + root2->val;
            
        node->left = mergeTrees(root1->left, root2->left);
        node->right = mergeTrees(root1->right, root2->right);
    }

    return node;
}