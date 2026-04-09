#include <stdio.h>
#include <stdlib.h>

// Function for Topological Sort using Kahn's Algorithm
void topologicalSort(int V, int adj[V][V]) {
    int inDegree[V];

    // Step 1: Initialize in-degree of all vertices as 0
    for (int i = 0; i < V; i++) {
        inDegree[i] = 0;
    }

    // Step 2: Calculate in-degree of each vertex
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1) {
                inDegree[j]++;
            }
        }
    }

    // Step 3: Create a queue
    int queue[V];
    int front = 0, rear = 0;

    // Step 4: Enqueue all vertices with in-degree 0
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Step 5: Process the queue
    int count = 0;

    printf("Topological Order: ");

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        // Reduce in-degree of adjacent vertices
        for (int i = 0; i < V; i++) {
            if (adj[current][i] == 1) {
                inDegree[i]--;

                // If in-degree becomes 0, add to queue
                if (inDegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }

        count++;
    }

    // Step 6: Check for cycle
    if (count != V) {
        printf("\nGraph has a cycle! Topological sort not possible.\n");
    }
}

// Driver Code
int main() {
    int V = 6;

    // Adjacency Matrix representation
    int adj[6][6] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };

    topologicalSort(V, adj);

    return 0;
}