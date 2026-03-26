typedef struct {
    struct TreeNode **data;
    int front, rear, capacity;
} Queue;

// Create queue
Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * capacity);
    q->front = 0;
    q->rear = 0;
    q->capacity = capacity;
    return q;
}

// Resize queue if needed
void resizeQueue(Queue* q) {
    int newCap = q->capacity * 2;
    q->data = (struct TreeNode**)realloc(q->data, sizeof(struct TreeNode*) * newCap);
    q->capacity = newCap;
}

// Enqueue
void enqueue(Queue* q, struct TreeNode* node) {
    if (q->rear == q->capacity)
        resizeQueue(q);
    q->data[q->rear++] = node;
}

// Dequeue
struct TreeNode* dequeue(Queue* q) {
    return q->data[q->front++];
}

// Check empty
int isEmpty(Queue* q) {
    return q->front == q->rear;
}

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int capacity = 100;
    int** result = (int**)malloc(sizeof(int*) * capacity);
    *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);

    Queue* q = createQueue(100);
    enqueue(q, root);

    int level = 0;
    *returnSize = 0;

    while (!isEmpty(q)) {
        int size = q->rear - q->front;

        // Resize result arrays if needed
        if (*returnSize == capacity) {
            capacity *= 2;
            result = (int**)realloc(result, sizeof(int*) * capacity);
            *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * capacity);
        }

        int* row = (int*)malloc(sizeof(int) * size);

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = dequeue(q);

            int index;
            if (level % 2 == 0)
                index = i;                // left → right
            else
                index = size - 1 - i;    // right → left

            row[index] = node->val;

            if (node->left)
                enqueue(q, node->left);
            if (node->right)
                enqueue(q, node->right);
        }

        result[*returnSize] = row;
        (*returnColumnSizes)[*returnSize] = size;
        (*returnSize)++;

        level++;
    }

    return result;
}