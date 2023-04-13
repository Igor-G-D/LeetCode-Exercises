/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumRootToLeaf(struct TreeNode* root){
    char s[1000] = "";
    return pathValue(root, s);
}

int pathValue (struct TreeNode* p, char * s) { // string to store the number of the path                
    char temp[2];
    char number[1000];
    strcpy(number, s);
    sprintf(temp, "%d", p->val); // converts the value of p to string
    strcat(number, temp); // concatens the next digit

    int leftSum = 0;
    int rightSum = 0;

    if(p->left) {
        leftSum = pathValue(p->left, number);
    }
    if(p->right) {
        rightSum = pathValue(p->right, number);
    }

    if(p->left == NULL && p->right == NULL) {
        char *temp;
        printf(number);
        int t = strtol(number,&temp,2);
        printf("  number: %d\n", t);
        return t;
    }

    return leftSum + rightSum;

}