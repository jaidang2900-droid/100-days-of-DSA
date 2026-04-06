#include <stdbool.h>
#include <stdlib.h>

// Queue structure
typedef struct {
    int node;
    int parent;
} Pair;

bool isCycle(int edges[][2], int E, int V) {

    // Step 1: Count degree
    int* degree = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        // If 1-based indexing, uncomment:
        // u--; v--;

        degree[u]++;
        degree[v]++;
    }

    // Step 2: Allocate adjacency list
    int** adj = (int**)malloc(V * sizeof(int*));
    int* size = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(degree[i] * sizeof(int));
    }

    // Step 3: Fill adjacency list
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        // If 1-based indexing, uncomment:
        // u--; v--;

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    // Step 4: Visited array
    bool* visited = (bool*)calloc(V, sizeof(bool));

    // Step 5: BFS for each component
    for (int i = 0; i < V; i++) {

        if (!visited[i]) {

            // Queue
            Pair* queue = (Pair*)malloc(V * sizeof(Pair));
            int front = 0, rear = 0;

            queue[rear++] = (Pair){i, -1};
            visited[i] = true;

            while (front < rear) {

                Pair current = queue[front++];
                int node = current.node;
                int parent = current.parent;

                for (int j = 0; j < size[node]; j++) {
                    int neighbor = adj[node][j];

                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        queue[rear++] = (Pair){neighbor, node};
                    }
                    else if (neighbor != parent) {
                        return true; // cycle found
                    }
                }
            }

            free(queue);
        }
    }

    return false;
}