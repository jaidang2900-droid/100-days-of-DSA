#include <stdbool.h>
#include <stdlib.h>

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int* color = (int*)malloc(graphSize * sizeof(int));
    
    // Initialize all nodes as uncolored (-1)
    for (int i = 0; i < graphSize; i++) {
        color[i] = -1;
    }

    // Queue for BFS
    int* queue = (int*)malloc(graphSize * sizeof(int));

    for (int i = 0; i < graphSize; i++) {
        // If not colored, start BFS
        if (color[i] == -1) {
            int front = 0, rear = 0;
            queue[rear++] = i;
            color[i] = 0;  // Assign first color

            while (front < rear) {
                int node = queue[front++];

                for (int j = 0; j < graphColSize[node]; j++) {
                    int neighbor = graph[node][j];

                    // If neighbor not colored, assign opposite color
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node];
                        queue[rear++] = neighbor;
                    }
                    // If same color, not bipartite
                    else if (color[neighbor] == color[node]) {
                        free(color);
                        free(queue);
                        return false;
                    }
                }
            }
        }
    }

    free(color);
    free(queue);
    return true;
}