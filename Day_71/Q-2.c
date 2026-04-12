#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int absVal(int x) {
    return x < 0 ? -x : x;
}

// Manhattan Distance
int dist(int* a, int* b) {
    return absVal(a[0] - b[0]) + absVal(a[1] - b[1]);
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    
    int n = pointsSize;
    
    int* minDist = (int*)malloc(n * sizeof(int));
    bool* visited = (bool*)malloc(n * sizeof(bool));
    
    // Initialize
    for (int i = 0; i < n; i++) {
        minDist[i] = INT_MAX;
        visited[i] = false;
    }
    
    minDist[0] = 0; // Start from point 0
    int totalCost = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        // Pick minimum distance node not visited
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }

        visited[u] = true;
        totalCost += minDist[u];

        // Update distances
        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int d = dist(points[u], points[v]);
                if (d < minDist[v]) {
                    minDist[v] = d;
                }
            }
        }
    }

    free(minDist);
    free(visited);

    return totalCost;
}