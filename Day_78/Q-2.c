#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void dfs(int u, int parent, int* visited, int* disc, int* low,
         int* ap, List** adj, int* time) {

    visited[u] = 1;
    disc[u] = low[u] = ++(*time);
    int children = 0;

    for (int i = 0; i < adj[u]->size; i++) {
        int v = adj[u]->arr[i];

        if (!visited[v]) {
            children++;
            dfs(v, u, visited, disc, low, ap, adj, time);

            if (low[v] < low[u])
                low[u] = low[v];

            if (parent == -1 && children > 1)
                ap[u] = 1;

            if (parent != -1 && low[v] >= disc[u])
                ap[u] = 1;
        }
        else if (v != parent) {
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }
}

int* articulationPoints(int V, List** adj, int* returnSize) {

    int* visited = (int*)calloc(V, sizeof(int));
    int* disc = (int*)malloc(V * sizeof(int));
    int* low = (int*)malloc(V * sizeof(int));
    int* ap = (int*)calloc(V, sizeof(int));

    int time = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, -1, visited, disc, low, ap, adj, &time);
        }
    }

    int count = 0;
    for (int i = 0; i < V; i++) {
        if (ap[i]) count++;
    }

    if (count == 0) {
        int* res = (int*)malloc(sizeof(int));
        res[0] = -1;
        *returnSize = 1;
        return res;
    }

    int* res = (int*)malloc(count * sizeof(int));
    int idx = 0;

    for (int i = 0; i < V; i++) {
        if (ap[i])
            res[idx++] = i;
    }

    *returnSize = count;
    return res;
}