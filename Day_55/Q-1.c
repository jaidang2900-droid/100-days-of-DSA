#include <stdio.h>
#include <stdlib.h>

// Definition of a tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue structure
struct Queue {
    struct TreeNode* data[100];
    int front, rear;
};

// Initialize queue
void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Enqueue
void enqueue(struct Queue* q, struct TreeNode* node) {
    if (q->rear == 99) return;
    if (q->front == -1) q->front = 0;
    q->data[++q->rear] = node;
}

// Dequeue
struct TreeNode* dequeue(struct Queue* q) {
    if (isEmpty(q)) return NULL;
    struct TreeNode* temp = q->data[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return temp;
}

// Function to print right view
void rightView(struct TreeNode* root) {
    if (root == NULL) return;

    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        int size = q.rear - q.front + 1;

        for (int i = 0; i < size; i++) {
            struct TreeNode* temp = dequeue(&q);

            // Print last node of current level
            if (i == size - 1)
                printf("%d ", temp->val);

            if (temp->left)
                enqueue(&q, temp->left);
            if (temp->right)
                enqueue(&q, temp->right);
        }
    }
}

// Example usage
int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->right = createNode(5);
    root->right->right = createNode(4);

    printf("Right view of the binary tree:\n");
    rightView(root);

    return 0;
}