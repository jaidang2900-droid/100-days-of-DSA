#include <stdio.h>
#include <limits.h>

#define V 100  // Maximum number of vertices

// Function to find vertex with minimum key value
int minKey(int key[], int mstSet[], int n) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < n; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to calculate MST weight using Prim's Algorithm
int primMST(int graph[V][V], int n) {
    int parent[V];   // To store constructed MST
    int key[V];      // Key values used to pick minimum weight edge
    int mstSet[V];   // To represent set of vertices included in MST

    // Initialize all keys as INFINITE and mstSet as false
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Start from vertex 0
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;

        for (int v = 0; v < n; v++) {
            // Update key if graph[u][v] is smaller than current key
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Calculate total weight of MST
    int totalWeight = 0;
    for (int i = 1; i < n; i++) {
        totalWeight += graph[i][parent[i]];
    }

    return totalWeight;
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[V][V];

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int mstWeight = primMST(graph, n);
    printf("Total weight of MST = %d\n", mstWeight);

    return 0;
}