#include <stdio.h>
#include <stdlib.h>

// Definition of tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to find LCA
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    
    // Base case
    if (root == NULL)
        return NULL;

    // If either p or q matches with root
    if (root == p || root == q)
        return root;

    // Search in left and right subtree
    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // If both sides return non-NULL, root is LCA
    if (left != NULL && right != NULL)
        return root;

    // Otherwise return non-NULL child
    if (left != NULL)
        return left;
    else
        return right;
}