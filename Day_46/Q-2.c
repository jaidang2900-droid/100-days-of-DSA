#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;

    if (root == NULL) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    // Queue capacity
    int capacity = 2000;
    struct TreeNode** queue = (struct TreeNode**)malloc(capacity * sizeof(struct TreeNode*));
    int front = 0, rear = 0;

    queue[rear++] = root;

    // Result arrays
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    while (front < rear) {
        int levelSize = rear - front;

        // Allocate memory for this level
        int* level = (int*)malloc(levelSize * sizeof(int));

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];
            level[i] = node->val;

            if (node->left) {
                queue[rear++] = node->left;
            }

            if (node->right) {
                queue[rear++] = node->right;
            }
        }

        result[*returnSize] = level;
        (*returnColumnSizes)[*returnSize] = levelSize;
        (*returnSize)++;
    }

    free(queue);
    return result;
}