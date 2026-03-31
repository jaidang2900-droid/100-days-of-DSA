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
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Function to find index of value in inorder array
int search(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

// Recursive function to build tree
struct TreeNode* buildTreeHelper(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd)
        return NULL;

    // Get current root from postorder
    int currVal = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = createNode(currVal);

    // If this node has no children
    if (inStart == inEnd)
        return root;

    // Find index in inorder
    int inIndex = search(inorder, inStart, inEnd, currVal);

    // Build right subtree first (important!)
    root->right = buildTreeHelper(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left = buildTreeHelper(inorder, postorder, inStart, inIndex - 1, postIndex);

    return root;
}

// Main function to build tree
struct TreeNode* buildTree(int inorder[], int postorder[], int n) {
    int postIndex = n - 1;
    return buildTreeHelper(inorder, postorder, 0, n - 1, &postIndex);
}

// Function to print preorder (to verify tree)
void printPreorder(struct TreeNode* root) {
    if (root == NULL)
        return;
    printf("%d ", root->val);
    printPreorder(root->left);
    printPreorder(root->right);
}

// Driver code
int main() {
    int inorder[] = {4, 2, 5, 1, 6, 3};
    int postorder[] = {4, 5, 2, 6, 3, 1};
    int n = 6;

    struct TreeNode* root = buildTree(inorder, postorder, n);

    printf("Preorder traversal of constructed tree:\n");
    printPreorder(root);

    return 0;
}