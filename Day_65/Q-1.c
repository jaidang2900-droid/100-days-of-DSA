#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Adjacency list node
struct Node {
    int data;
    struct Node* next;
};

// Graph structure
struct Graph {
    int V;
    struct Node* adj[MAX];
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    for (int i = 0; i < V; i++) {
        graph->adj[i] = NULL;
    }
    return graph;
}

// Add edge (undirected)
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = graph->adj[v];
    graph->adj[v] = newNode;
}

// DFS function to detect cycle
bool dfsCycle(struct Graph* graph, int v, bool visited[], int parent) {
    visited[v] = true;

    struct Node* temp = graph->adj[v];

    while (temp != NULL) {
        int adjVertex = temp->data;

        if (!visited[adjVertex]) {
            if (dfsCycle(graph, adjVertex, visited, v))
                return true;
        }
        else if (adjVertex != parent) {
            return true; // cycle found
        }

        temp = temp->next;
    }
    return false;
}

// Function to check cycle in graph
bool hasCycle(struct Graph* graph) {
    bool visited[MAX] = {false};

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            if (dfsCycle(graph, i, visited, -1))
                return true;
        }
    }
    return false;
}

// Driver code
int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 1); // This creates a cycle

    if (hasCycle(graph))
        printf("Graph contains cycle\n");
    else
        printf("Graph does not contain cycle\n");

    return 0;
}