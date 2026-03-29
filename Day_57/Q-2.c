#include <stdlib.h>
void flattenHelper(struct TreeNode* root, struct TreeNode** prev) {
    if (root == NULL)
        return;

    flattenHelper(root->right, prev);
    flattenHelper(root->left, prev);

    root->right = *prev;
    root->left = NULL;

    *prev = root;
}

void flatten(struct TreeNode* root) {
    struct TreeNode* prev = NULL;
    flattenHelper(root, &prev);
}