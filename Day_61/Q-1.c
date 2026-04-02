#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i;
    
    // Input number of vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Declare adjacency matrix
    int adj[n][n];

    // Initialize matrix with 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    int choice;
    printf("Enter 1 for Directed Graph, 2 for Undirected Graph: ");
    scanf("%d", &choice);

    int u, v;

    // Input edges
    printf("Enter edges (u v) where 0 <= u, v < %d:\n", n);
    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        if (u >= n || v >= n || u < 0 || v < 0) {
            printf("Invalid edge! Try again.\n");
            i--;
            continue;
        }

        adj[u][v] = 1;

        // If undirected, mark both sides
        if (choice == 2) {
            adj[v][u] = 1;
        }
    }

    // Display adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}