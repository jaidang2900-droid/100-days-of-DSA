#include <stdio.h>
#include <stdlib.h>

// Node for linked list
struct Node {
    float val;
    struct Node* next;
};

// Insert node in sorted order (Insertion Sort)
struct Node* sortedInsert(struct Node* head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = value;
    newNode->next = NULL;

    if (head == NULL || head->val >= value) {
        newNode->next = head;
        return newNode;
    }

    struct Node* curr = head;
    while (curr->next != NULL && curr->next->val < value) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

// Bucket Sort
void bucketSort(float arr[], int n) {
    // Step 1: Create buckets
    struct Node** buckets = (struct Node**)malloc(n * sizeof(struct Node*));

    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    // Step 2: Distribute elements
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];  // bucket index
        buckets[index] = sortedInsert(buckets[index], arr[i]);
    }

    // Step 3: Concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        struct Node* curr = buckets[i];
        while (curr != NULL) {
            arr[k++] = curr->val;
            curr = curr->next;
        }
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        struct Node* curr = buckets[i];
        while (curr) {
            struct Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(buckets);
}

// Driver
int main() {
    float arr[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);

    return 0;
}