#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to check if two trees are mirror images
bool isMirror(struct TreeNode* t1, struct TreeNode* t2) {
    // If both are NULL, symmetric
    if (t1 == NULL && t2 == NULL)
        return true;

    // If one is NULL, not symmetric
    if (t1 == NULL || t2 == NULL)
        return false;

    // Check values and recursive mirror condition
    return (t1->val == t2->val) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

// Main function to check symmetry
bool isSymmetric(struct TreeNode* root) {
    return isMirror(root, root);
}