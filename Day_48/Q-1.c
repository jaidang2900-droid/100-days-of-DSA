#include <stdio.h>
#include <stdlib.h>

// Definition of Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to count leaf nodes
int countLeafNodes(struct TreeNode* root) {
    // Base case
    if (root == NULL)
        return 0;

    // If node is a leaf
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Recursively count in left and right subtree
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Main function to test
int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    int leafCount = countLeafNodes(root);
    printf("Number of leaf nodes: %d\n", leafCount);

    return 0;
}