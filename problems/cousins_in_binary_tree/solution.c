/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int returnDepth(struct TreeNode * p, int n);
int returnParent(struct TreeNode * p, int n, int parent);

bool isCousins(struct TreeNode* root, int x, int y){
    int depthx = returnDepth(root, x);
    int depthy = returnDepth(root, y);
    int parentx = returnParent(root, x, -1);
    int parenty = returnParent(root, y, -1);
    
    if ( parentx == -1 || parenty == -1) { // if either are -1, means one was not found, therefor the condition is false
        return false;
    }

    if((depthx == depthy) && (parentx != parenty)) { // only are cousins if they have the same depth and different parents
        return true;
    }

    return false; // otherwise, false

}

int returnDepth(struct TreeNode * p, int n) { // returns depth of node with n value, or -1 if not found
    if(p == NULL) {
        return -1;
    }
    if(p->val == n) {
        return 0;
    }
    
    int left = returnDepth(p->left, n);
    int right = returnDepth(p->right, n);
    
    if(left != -1) {
        return ++left; 
    } else  if (right != -1){
        return ++right;
    }  

    return -1;
}

int returnParent(struct TreeNode * p, int n, int parent) { // returns value of parent of node with n value, -1 if not found
    if (p == NULL) {
        return -1;
    }
    if(p->val == n) {
        return parent;
    }
    
    int left = returnParent(p->left, n, p->val);
    int right = returnParent(p->right,n, p->val);

    if(left != -1) {
        return left; 
    } else  if (right != -1){
        return right;
    }  

    return -1;
}