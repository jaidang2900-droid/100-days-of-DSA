#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void dfs(int node, int n, int graph[MAX][MAX], bool visited[]) {
    visited[node] = true;

    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i, n, graph, visited);
        }
    }
}

bool isConnected(int n, int graph[MAX][MAX]) {
    bool visited[MAX] = {false};

    // Start DFS from node 0
    dfs(0, n, graph, visited);

    // Check if all nodes are visited
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            return false;
    }
    return true;
}

int main() {
    int n = 4;

    int graph[MAX][MAX] = {
        {0,1,1,0},
        {1,0,1,0},
        {1,1,0,1},
        {0,0,1,0}
    };

    if (isConnected(n, graph))
        printf("Graph is Connected\n");
    else
        printf("Graph is Not Connected\n");

    return 0;
}