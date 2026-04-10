#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 101

// Adjacency list node
typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

// Min heap node
typedef struct {
    int node, dist;
} HeapNode;

// Min heap
typedef struct {
    int size;
    HeapNode arr[MAX * MAX];
} MinHeap;

// Create new adjacency node
Node* newNode(int v, int w) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->v = v;
    node->w = w;
    node->next = NULL;
    return node;
}

// Push into heap
void push(MinHeap* heap, int node, int dist) {
    int i = heap->size++;
    heap->arr[i].node = node;
    heap->arr[i].dist = dist;

    // Heapify up
    while (i > 0 && heap->arr[i].dist < heap->arr[(i - 1) / 2].dist) {
        HeapNode temp = heap->arr[i];
        heap->arr[i] = heap->arr[(i - 1) / 2];
        heap->arr[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Pop min
HeapNode pop(MinHeap* heap) {
    HeapNode root = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->size];

    int i = 0;
    while (1) {
        int left = 2 * i + 1, right = 2 * i + 2, smallest = i;

        if (left < heap->size && heap->arr[left].dist < heap->arr[smallest].dist)
            smallest = left;

        if (right < heap->size && heap->arr[right].dist < heap->arr[smallest].dist)
            smallest = right;

        if (smallest == i) break;

        HeapNode temp = heap->arr[i];
        heap->arr[i] = heap->arr[smallest];
        heap->arr[smallest] = temp;
        i = smallest;
    }

    return root;
}

// Main function
int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    
    // Step 1: Create graph
    Node* graph[MAX] = {NULL};

    for (int i = 0; i < timesSize; i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];

        Node* node = newNode(v, w);
        node->next = graph[u];
        graph[u] = node;
    }

    // Step 2: Distance array
    int dist[MAX];
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    // Step 3: Min Heap
    MinHeap heap;
    heap.size = 0;

    dist[k] = 0;
    push(&heap, k, 0);

    // Step 4: Dijkstra
    while (heap.size > 0) {
        HeapNode top = pop(&heap);
        int u = top.node;

        Node* temp = graph[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Step 5: Find max distance
    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            return -1;
        if (dist[i] > maxTime)
            maxTime = dist[i];
    }

    return maxTime;
}