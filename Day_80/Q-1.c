#include <stdio.h>

#define INF 1000000000  // A large value representing infinity

void floydWarshall(int n, int graph[n][n]) {
    int dist[n][n];

    // Step 1: Initialize distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Step 2: Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++) {          // Intermediate vertex
        for (int i = 0; i < n; i++) {      // Source vertex
            for (int j = 0; j < n; j++) {  // Destination vertex
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    // Step 3: Print result
    printf("Shortest distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 4;

    int graph[4][4] = {
        {0,   5,  INF, 10},
        {INF, 0,   3, INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    floydWarshall(n, graph);

    return 0;
}