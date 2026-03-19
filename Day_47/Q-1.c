#include <stdio.h>
#include <stdlib.h>

// Definition of TreeNode
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to find height (max depth)
int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0; // base case
    }

    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);

    // return max of left & right + 1 (for current node)
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Helper function to create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Example usage
int main() {
    /*
            1
           / \
          2   3
         /
        4
    */

    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);

    printf("Height of Binary Tree: %d\n", maxDepth(root));

    return 0;
}