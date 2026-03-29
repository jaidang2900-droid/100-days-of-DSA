#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to convert tree into its mirror
struct TreeNode* mirrorTree(struct TreeNode* root) {
    // Base case
    if (root == NULL)
        return NULL;

    // Swap left and right subtrees
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively apply to subtrees
    mirrorTree(root->left);
    mirrorTree(root->right);

    return root;
}