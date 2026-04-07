#include <stdbool.h>
#include <stdlib.h>

bool dfs(int node, bool* visited, bool* recStack, int** adj, int* size) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < size[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, visited, recStack, adj, size))
                return true;
        }
        else if (recStack[neighbor]) {
            return true; 
        }
    }

    recStack[node] = false;
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* size = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(numCourses * sizeof(int)); // max possible
    }

    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];

        adj[b][size[b]++] = a;
    }

    bool* visited = (bool*)calloc(numCourses, sizeof(bool));
    bool* recStack = (bool*)calloc(numCourses, sizeof(bool));

    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack, adj, size))
                return false; // cycle exists → cannot finish
        }
    }

    return true;
}