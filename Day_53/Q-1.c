#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Structure for queue (for level order traversal)
struct QueueNode {
    struct Node* treeNode;
    int hd;
    struct QueueNode* next;
};

// Create new tree node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Enqueue
void enqueue(struct QueueNode** front, struct QueueNode** rear, struct Node* root, int hd) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->treeNode = root;
    temp->hd = hd;
    temp->next = NULL;

    if (*rear == NULL) {
        *front = *rear = temp;
        return;
    }

    (*rear)->next = temp;
    *rear = temp;
}

// Dequeue
struct QueueNode* dequeue(struct QueueNode** front, struct QueueNode** rear) {
    if (*front == NULL)
        return NULL;

    struct QueueNode* temp = *front;
    *front = (*front)->next;

    if (*front == NULL)
        *rear = NULL;

    return temp;
}

// Structure to store vertical order
struct ListNode {
    int data;
    struct ListNode* next;
};

// Add node to vertical list
void addToList(struct ListNode** head, int data) {
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->data = data;
    temp->next = NULL;

    if (*head == NULL) {
        *head = temp;
    } else {
        struct ListNode* t = *head;
        while (t->next)
            t = t->next;
        t->next = temp;
    }
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (root == NULL)
        return;

    // Range of HD (for simplicity)
    int min = 0, max = 0;

    // Array for storing lists (assuming range -100 to +100)
    struct ListNode* arr[200] = {NULL};

    struct QueueNode *front = NULL, *rear = NULL;

    enqueue(&front, &rear, root, 0);

    while (front != NULL) {
        struct QueueNode* temp = dequeue(&front, &rear);

        struct Node* node = temp->treeNode;
        int hd = temp->hd;

        if (hd < min) min = hd;
        if (hd > max) max = hd;

        addToList(&arr[hd + 100], node->data);

        if (node->left)
            enqueue(&front, &rear, node->left, hd - 1);

        if (node->right)
            enqueue(&front, &rear, node->right, hd + 1);

        free(temp);
    }

    // Print vertical order
    for (int i = min; i <= max; i++) {
        struct ListNode* temp = arr[i + 100];
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Driver Code
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Vertical Order Traversal:\n");
    verticalOrder(root);

    return 0;
}