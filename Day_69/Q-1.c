#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list node
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

// Structure for graph
typedef struct {
    Node* head[MAX];
} Graph;

// Min Heap Node
typedef struct {
    int vertex;
    int dist;
} HeapNode;

// Min Heap structure
typedef struct {
    int size;
    int capacity;
    int pos[MAX];
    HeapNode* array;
} MinHeap;

// Create new adjacency node
Node* newNode(int v, int w) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = v;
    node->weight = w;
    node->next = NULL;
    return node;
}

// Create graph
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    for (int i = 0; i < V; i++)
        graph->head[i] = NULL;
    return graph;
}

// Add edge (undirected)
void addEdge(Graph* graph, int u, int v, int w) {
    Node* node = newNode(v, w);
    node->next = graph->head[u];
    graph->head[u] = node;

    node = newNode(u, w);
    node->next = graph->head[v];
    graph->head[v] = node;
}

// Create Min Heap
MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->pos = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (HeapNode*)malloc(capacity * sizeof(HeapNode));
    return heap;
}

// Swap heap nodes
void swapHeapNode(HeapNode* a, HeapNode* b) {
    HeapNode t = *a;
    *a = *b;
    *b = t;
}

// Heapify
void minHeapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->array[left].dist < heap->array[smallest].dist)
        smallest = left;

    if (right < heap->size && heap->array[right].dist < heap->array[smallest].dist)
        smallest = right;

    if (smallest != idx) {
        HeapNode smallestNode = heap->array[smallest];
        HeapNode idxNode = heap->array[idx];

        heap->pos[smallestNode.vertex] = idx;
        heap->pos[idxNode.vertex] = smallest;

        swapHeapNode(&heap->array[smallest], &heap->array[idx]);

        minHeapify(heap, smallest);
    }
}

// Check if heap is empty
int isEmpty(MinHeap* heap) {
    return heap->size == 0;
}

// Extract minimum node
HeapNode extractMin(MinHeap* heap) {
    HeapNode root = heap->array[0];
    HeapNode lastNode = heap->array[heap->size - 1];

    heap->array[0] = lastNode;

    heap->pos[root.vertex] = heap->size - 1;
    heap->pos[lastNode.vertex] = 0;

    heap->size--;
    minHeapify(heap, 0);

    return root;
}

// Decrease key
void decreaseKey(MinHeap* heap, int v, int dist) {
    int i = heap->pos[v];
    heap->array[i].dist = dist;

    while (i && heap->array[i].dist < heap->array[(i - 1) / 2].dist) {
        heap->pos[heap->array[i].vertex] = (i - 1) / 2;
        heap->pos[heap->array[(i - 1) / 2].vertex] = i;

        swapHeapNode(&heap->array[i], &heap->array[(i - 1) / 2]);

        i = (i - 1) / 2;
    }
}

// Check if vertex is in heap
int isInMinHeap(MinHeap* heap, int v) {
    return heap->pos[v] < heap->size;
}

// Dijkstra Algorithm
void dijkstra(Graph* graph, int V, int src) {
    int dist[V];

    MinHeap* heap = createMinHeap(V);

    for (int v = 0; v < V; v++) {
        dist[v] = INT_MAX;
        heap->array[v].vertex = v;
        heap->array[v].dist = INT_MAX;
        heap->pos[v] = v;
    }

    dist[src] = 0;
    heap->array[src].dist = 0;
    heap->size = V;

    decreaseKey(heap, src, 0);

    while (!isEmpty(heap)) {
        HeapNode minNode = extractMin(heap);
        int u = minNode.vertex;

        Node* temp = graph->head[u];
        while (temp != NULL) {
            int v = temp->vertex;

            if (isInMinHeap(heap, v) && dist[u] != INT_MAX &&
                dist[u] + temp->weight < dist[v]) {

                dist[v] = dist[u] + temp->weight;
                decreaseKey(heap, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // Print result
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

// Driver code
int main() {
    int V = 5;
    Graph* graph = createGraph(V);

    addEdge(graph, 0, 1, 9);
    addEdge(graph, 0, 2, 6);
    addEdge(graph, 0, 3, 5);
    addEdge(graph, 0, 4, 3);
    addEdge(graph, 2, 1, 2);
    addEdge(graph, 2, 3, 4);

    dijkstra(graph, V, 0);

    return 0;
}