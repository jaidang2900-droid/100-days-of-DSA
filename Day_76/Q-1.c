#include <stdio.h>
#include <stdlib.h>

void dfs(int** graph, int* graphColSize, int node, int* visited) {
    visited[node] = 1;

    for (int i = 0; i < graphColSize[node]; i++) {
        int neighbor = graph[node][i];
        if (!visited[neighbor]) {
            dfs(graph, graphColSize, neighbor, visited);
        }
    }
}

int countComponents(int** graph, int graphSize, int* graphColSize) {
    int* visited = (int*)calloc(graphSize, sizeof(int));
    int count = 0;

    for (int i = 0; i < graphSize; i++) {
        if (!visited[i]) {
            dfs(graph, graphColSize, i, visited);
            count++;
        }
    }

    free(visited);
    return count;
}