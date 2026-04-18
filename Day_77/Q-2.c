#include <stdio.h>
#include <stdlib.h>

int timer;

// DFS function (Tarjan's Algorithm)
void dfs(int u, int parent, int* disc, int* low,
         int** adj, int* adjSize,
         int** result, int* returnSize, int* colSizes) {
    
    disc[u] = low[u] = timer++;

    for (int i = 0; i < adjSize[u]; i++) {
        int v = adj[u][i];

        if (v == parent) continue;

        if (disc[v] == -1) {
            dfs(v, u, disc, low, adj, adjSize, result, returnSize, colSizes);

            low[u] = (low[u] < low[v]) ? low[u] : low[v];

            // Bridge condition
            if (low[v] > disc[u]) {
                result[*returnSize] = (int*)malloc(2 * sizeof(int));
                result[*returnSize][0] = u;
                result[*returnSize][1] = v;
                colSizes[*returnSize] = 2;
                (*returnSize)++;
            }
        } else {
            low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
        }
    }
}


// Main function (LeetCode format)
int** criticalConnections(int n, int** connections, int connectionsSize,
                         int* connectionsColSize,
                         int* returnSize, int** returnColumnSizes) {

    timer = 0;

    // Step 1: Count degree
    int* degree = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0];
        int v = connections[i][1];
        degree[u]++;
        degree[v]++;
    }

    // Step 2: Allocate adjacency list
    int** adj = (int**)malloc(n * sizeof(int*));
    int* adjSize = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(degree[i] * sizeof(int));
    }

    // Step 3: Fill adjacency list
    for (int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0];
        int v = connections[i][1];

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    // Step 4: Allocate arrays
    int* disc = (int*)malloc(n * sizeof(int));
    int* low  = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        disc[i] = -1;
        low[i] = -1;
    }

    // Step 5: Result allocation
    int** result = (int**)malloc(connectionsSize * sizeof(int*));
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(connectionsSize * sizeof(int));

    // Step 6: Run DFS
    for (int i = 0; i < n; i++) {
        if (disc[i] == -1) {
            dfs(i, -1, disc, low, adj, adjSize,
                result, returnSize, *returnColumnSizes);
        }
    }

    return result;
}