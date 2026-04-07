#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to perform DFS and detect cycle
bool dfs(int node, bool visited[], bool recStack[], int V, int** adj) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {  // if there is an edge
            if (!visited[i]) {
                if (dfs(i, visited, recStack, V, adj))
                    return true;
            }
            else if (recStack[i]) {
                return true;  // cycle found
            }
        }
    }

    recStack[node] = false;  // remove from recursion stack
    return false;
}

// Function to detect cycle in directed graph
bool isCyclic(int V, int** adj) {
    bool* visited = (bool*)calloc(V, sizeof(bool));
    bool* recStack = (bool*)calloc(V, sizeof(bool));

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack, V, adj))
                return true;
        }
    }

    return false;
}

int main() {
    int V = 4;

    // Allocate adjacency matrix
    int** adj = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        adj[i] = (int*)calloc(V, sizeof(int));
    }

    // Example graph:
    // 0 → 1 → 2 → 0 (cycle)
    // 2 → 3
    adj[0][1] = 1;
    adj[1][2] = 1;
    adj[2][0] = 1;
    adj[2][3] = 1;

    if (isCyclic(V, adj))
        printf("Cycle detected\n");
    else
        printf("No cycle found\n");

    return 0;
}