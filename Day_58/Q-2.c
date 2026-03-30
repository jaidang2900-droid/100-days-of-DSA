#include <stdlib.h>

// Helper function to find index in inorder
int findIndex(int* inorder, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Recursive function
struct TreeNode* build(int* preorder, int* inorder, int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd)
        return NULL;

    // Create root node
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[*preIndex];
    root->left = root->right = NULL;

    (*preIndex)++;

    // If leaf node
    if (inStart == inEnd)
        return root;

    // Find root index in inorder
    int inIndex = findIndex(inorder, inStart, inEnd, root->val);

    // Build left and right subtree
    root->left = build(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = build(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return root;
}

// Main function
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int preIndex = 0;
    return build(preorder, inorder, 0, inorderSize - 1, &preIndex);
}