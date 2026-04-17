#include <stdlib.h>

// Helper DFS function
struct Node* dfs(struct Node* node, struct Node** visited) {
    if (node == NULL) return NULL;

    // If already cloned, return it
    if (visited[node->val] != NULL) {
        return visited[node->val];
    }

    // Create new node
    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = (struct Node**)malloc(sizeof(struct Node*) * node->numNeighbors);

    // Mark as visited
    visited[node->val] = clone;

    // Clone neighbors
    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = dfs(node->neighbors[i], visited);
    }

    return clone;
}

struct Node *cloneGraph(struct Node *s) {
    if (s == NULL) return NULL;

    // Adjust size if constraints are larger
    struct Node** visited = (struct Node**)calloc(101, sizeof(struct Node*));

    return dfs(s, visited);
}