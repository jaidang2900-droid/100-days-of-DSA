#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Stack structure
struct Stack {
    struct TreeNode* data[100];
    int top;
};

// Stack functions
void push(struct Stack* s, struct TreeNode* node) {
    s->data[++(s->top)] = node;
}

struct TreeNode* pop(struct Stack* s) {
    return s->data[(s->top)--];
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Function for zigzag traversal
void zigzagTraversal(struct TreeNode* root) {
    if (root == NULL) return;

    struct Stack currentLevel, nextLevel;
    currentLevel.top = -1;
    nextLevel.top = -1;

    int leftToRight = 1;

    push(&currentLevel, root);

    while (!isEmpty(&currentLevel)) {
        struct TreeNode* temp = pop(&currentLevel);
        printf("%d ", temp->val);

        // Left to Right
        if (leftToRight) {
            if (temp->left)
                push(&nextLevel, temp->left);
            if (temp->right)
                push(&nextLevel, temp->right);
        }
        // Right to Left
        else {
            if (temp->right)
                push(&nextLevel, temp->right);
            if (temp->left)
                push(&nextLevel, temp->left);
        }

        // If current level is finished
        if (isEmpty(&currentLevel)) {
            leftToRight = !leftToRight;

            // Swap stacks
            struct Stack tempStack = currentLevel;
            currentLevel = nextLevel;
            nextLevel = tempStack;

            printf("\n"); // Move to next level
        }
    }
}

// Helper function to create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Main function
int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Zigzag Traversal:\n");
    zigzagTraversal(root);

    return 0;
}