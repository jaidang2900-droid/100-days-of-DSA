#include <stdlib.h>
int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // Allocate space for result (max nodes ~1000 safe assumption)
    int* result = (int*)malloc(sizeof(int) * 1000);
    *returnSize = 0;

    // Queue for BFS
    struct TreeNode* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];

            // If it's the last node of this level
            if (i == levelSize - 1) {
                result[*returnSize] = node->val;
                (*returnSize)++;
            }

            if (node->left)
                queue[rear++] = node->left;
            if (node->right)
                queue[rear++] = node->right;
        }
    }

    return result;
}