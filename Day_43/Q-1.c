#include <stdio.h>
#include <stdlib.h>

/* Tree Node */
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

/* Queue Node */
struct Queue {
    struct Node* treeNode;
    struct Queue* next;
};

struct Queue *front = NULL, *rear = NULL;

/* Create new tree node */
struct Node* createNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

/* Enqueue */
void enqueue(struct Node* node) {
    struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue));
    temp->treeNode = node;
    temp->next = NULL;

    if(rear == NULL) {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

/* Dequeue */
struct Node* dequeue() {
    if(front == NULL)
        return NULL;

    struct Queue* temp = front;
    struct Node* node = temp->treeNode;

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
    return node;
}

/* Construct Binary Tree from Level Order */
struct Node* buildTree(int arr[], int n) {

    if(n == 0)
        return NULL;

    struct Node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while(i < n) {

        struct Node* current = dequeue();

        /* Left Child */
        if(i < n) {
            current->left = createNode(arr[i++]);
            enqueue(current->left);
        }

        /* Right Child */
        if(i < n) {
            current->right = createNode(arr[i++]);
            enqueue(current->right);
        }
    }

    return root;
}

/* Inorder Traversal (for checking) */
void inorder(struct Node* root) {
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/* Main Function */
int main() {

    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    struct Node* root = buildTree(arr, n);

    printf("Inorder Traversal:\n");
    inorder(root);

    return 0;
}