#include <stdio.h>
#include <stdlib.h>

// Definition of Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Count total number of nodes
int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check if tree is Complete Binary Tree
int isComplete(struct Node* root, int index, int totalNodes) {
    if (root == NULL)
        return 1;

    if (index >= totalNodes)
        return 0;

    return isComplete(root->left, 2 * index + 1, totalNodes) &&
           isComplete(root->right, 2 * index + 2, totalNodes);
}

// Check Min-Heap property
int isMinHeap(struct Node* root) {
    // If leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    // If only left child exists
    if (root->right == NULL) {
        return (root->data <= root->left->data) &&
               isMinHeap(root->left);
    }

    // If both children exist
    if (root->data <= root->left->data &&
        root->data <= root->right->data)
        return isMinHeap(root->left) &&
               isMinHeap(root->right);

    return 0;
}

// Main function to check Min-Heap
int checkMinHeap(struct Node* root) {
    int totalNodes = countNodes(root);

    if (isComplete(root, 0, totalNodes) && isMinHeap(root))
        return 1;
    else
        return 0;
}

// Driver Code
int main() {
    struct Node* root = newNode(10);
    root->left = newNode(15);
    root->right = newNode(20);
    root->left->left = newNode(30);
    root->left->right = newNode(40);
    root->right->left = newNode(50);

    if (checkMinHeap(root))
        printf("The tree is a Min-Heap\n");
    else
        printf("The tree is NOT a Min-Heap\n");

    return 0;
}