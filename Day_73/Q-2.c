#include <stdlib.h>

// Find with path compression
int find(int parent[], int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

// Union function
int unionSet(int parent[], int rank[], int x, int y) {
    int px = find(parent, x);
    int py = find(parent, y);

    if (px == py)
        return 0; // cycle detected

    // Union by rank
    if (rank[px] < rank[py]) {
        parent[px] = py;
    } else if (rank[px] > rank[py]) {
        parent[py] = px;
    } else {
        parent[py] = px;
        rank[px]++;
    }
    return 1;
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int n = edgesSize;
    
    int *parent = (int*)malloc((n + 1) * sizeof(int));
    int *rank = (int*)calloc((n + 1), sizeof(int));
    
    // Initialize DSU
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int *result = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        // If union fails → cycle edge
        if (!unionSet(parent, rank, u, v)) {
            result[0] = u;
            result[1] = v;
        }
    }

    *returnSize = 2;
    
    free(parent);
    free(rank);
    
    return result;
}