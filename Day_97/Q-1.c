#include <stdio.h>
#include <stdlib.h>

// Structure for interval
typedef struct {
    int start;
    int end;
} Interval;

// Compare function for sorting by start time
int cmp(const void* a, const void* b) {
    Interval* x = (Interval*)a;
    Interval* y = (Interval*)b;
    return x->start - y->start;
}

// Min Heap functions
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int heap[], int size, int i) {
    while (1) {
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == i) break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}

// Insert into heap
void insert(int heap[], int* size, int val) {
    heap[*size] = val;
    heapifyUp(heap, *size);
    (*size)++;
}

// Extract min
int extractMin(int heap[], int* size) {
    int root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
    return root;
}

// Main function
int minMeetingRooms(Interval* intervals, int n) {
    if (n == 0) return 0;

    // Step 1: Sort intervals
    qsort(intervals, n, sizeof(Interval), cmp);

    // Min heap for end times
    int* heap = (int*)malloc(sizeof(int) * n);
    int size = 0;

    // Add first meeting
    insert(heap, &size, intervals[0].end);

    for (int i = 1; i < n; i++) {
        // If room is free
        if (heap[0] <= intervals[i].start) {
            extractMin(heap, &size);
        }
        // Allocate room
        insert(heap, &size, intervals[i].end);
    }

    int result = size;
    free(heap);
    return result;
}