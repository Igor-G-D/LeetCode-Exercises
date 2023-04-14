/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void minimumValues(struct TreeNode * p, int *lowest, int *secondLowest);

int findSecondMinimumValue(struct TreeNode* root){
    int lowest = -1;
    int secondLowest = -1;

    minimumValues(root, &(lowest), &(secondLowest));

    return secondLowest;
}

void minimumValues(struct TreeNode * p, int *lowest, int *secondLowest) {
    if(p == NULL) {
        return;
    }

    printf("lowest: %d\n secondLowest: %d\n value: %d\n\n", *lowest, *secondLowest, p->val);

    if(*lowest == -1 && *secondLowest == -1) { // if none have been set yet
        *lowest = p->val;
    } else if (*lowest > p->val) { // if it finds a lower value
        *lowest = p->val;
    } else if( *lowest < p->val && (*secondLowest == -1 || *secondLowest > p->val)) {
        *secondLowest = p->val;
    }
    minimumValues(p->left, lowest, secondLowest);
    minimumValues(p->right, lowest, secondLowest);
}