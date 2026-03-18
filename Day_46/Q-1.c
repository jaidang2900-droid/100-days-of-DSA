#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Queue structure
typedef struct Queue {
    struct TreeNode* data;
    struct Queue* next;
} Queue;

// Enqueue
void enqueue(Queue** front, Queue** rear, struct TreeNode* node) {
    Queue* temp = (Queue*)malloc(sizeof(Queue));
    temp->data = node;
    temp->next = NULL;

    if (*rear == NULL) {
        *front = *rear = temp;
        return;
    }

    (*rear)->next = temp;
    *rear = temp;
}

// Dequeue
struct TreeNode* dequeue(Queue** front, Queue** rear) {
    if (*front == NULL)
        return NULL;

    Queue* temp = *front;
    struct TreeNode* node = temp->data;

    *front = (*front)->next;
    if (*front == NULL)
        *rear = NULL;

    free(temp);
    return node;
}

// Check if queue is empty
int isEmpty(Queue* front) {
    return front == NULL;
}

// Level Order Traversal
void levelOrder(struct TreeNode* root) {
    if (root == NULL)
        return;

    Queue *front = NULL, *rear = NULL;

    enqueue(&front, &rear, root);

    while (!isEmpty(front)) {
        struct TreeNode* current = dequeue(&front, &rear);
        printf("%d ", current->val);

        if (current->left != NULL)
            enqueue(&front, &rear, current->left);

        if (current->right != NULL)
            enqueue(&front, &rear, current->right);
    }
}