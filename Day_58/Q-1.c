#include <stdio.h>
#include <stdlib.h>

// Definition of tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Function to find index of value in inorder array
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Recursive function to build tree
struct TreeNode* buildTree(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd)
        return NULL;

    // Pick current node from preorder
    int curr = preorder[*preIndex];
    (*preIndex)++;

    struct TreeNode* root = newNode(curr);

    // If no children
    if (inStart == inEnd)
        return root;

    // Find index in inorder
    int inIndex = search(inorder, inStart, inEnd, curr);

    // Build left and right subtrees
    root->left = buildTree(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return root;
}

// Wrapper function
struct TreeNode* constructTree(int preorder[], int inorder[], int n) {
    int preIndex = 0;
    return buildTree(preorder, inorder, 0, n - 1, &preIndex);
}

// Function to print inorder (for checking)
void printInorder(struct TreeNode* root) {
    if (root == NULL)
        return;
    printInorder(root->left);
    printf("%d ", root->val);
    printInorder(root->right);
}

// Driver code
int main() {
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[]  = {9, 3, 15, 20, 7};
    int n = sizeof(preorder) / sizeof(preorder[0]);

    struct TreeNode* root = constructTree(preorder, inorder, n);

    printf("Inorder of constructed tree: ");
    printInorder(root);

    return 0;
}