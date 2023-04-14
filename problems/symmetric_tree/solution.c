/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void preOrder (struct TreeNode *p, char * s );
void preOrderMirror ( struct TreeNode *p, char * s );

bool isSymmetric(struct TreeNode* root){
    char s1[2000] = "";
    char s2[2000] = "";
    if(root->left == NULL && root->right == NULL) {
        return true;
    } 
    if(root->left && root->right == NULL) {
        return false;
    }
    if(root->left == NULL && root->right) {
        return false;
    }

    preOrder(root->left, s1);
    preOrderMirror(root->right, s2);

    printf(s1);
    printf("\n");
    printf(s2);
    printf("\n");
    
    if(strcmp(s1, s2) == 0) {
        return true;
    }
        
    return false;

}

void preOrder ( struct TreeNode *p, char * s ) {
        
    if( p == NULL) {
        char temp[2] = "n";
        strcat(s, temp);
    } else {
        char temp[7];
        sprintf(temp, "[%d]", p->val);
        strcat(s, temp);

        preOrder( p->left, s);
        preOrder( p->right, s); 
    }
}

void preOrderMirror ( struct TreeNode *p, char * s ) {
        
    if( p == NULL) {
        char temp[2] = "n";
        strcat(s, temp);
    } else {
        char temp[7];
        sprintf(temp, "[%d]", p->val);
        strcat(s, temp);

        preOrderMirror( p->right, s); 
        preOrderMirror( p->left, s);
    }
}