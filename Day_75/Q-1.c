#include <stdio.h>
#include <stdlib.h>

// Structure for hash map
typedef struct Node {
    int key;        // prefix sum
    int value;      // index
    struct Node* next;
} Node;

#define SIZE 10007

Node* hashTable[SIZE];

// Hash function
int hash(int key) {
    if (key < 0) key = -key;
    return key % SIZE;
}

// Insert into hash map (only if not present)
void insert(int key, int value) {
    int h = hash(key);
    Node* temp = hashTable[h];
    
    while (temp) {
        if (temp->key == key)
            return; // already exists
        temp = temp->next;
    }
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[h];
    hashTable[h] = newNode;
}

// Search in hash map
int search(int key) {
    int h = hash(key);
    Node* temp = hashTable[h];
    
    while (temp) {
        if (temp->key == key)
            return temp->value;
        temp = temp->next;
    }
    
    return -2; // not found
}

// Function to find longest subarray length with sum = 0
int maxLenZeroSum(int arr[], int n) {
    int sum = 0, maxLen = 0;

    // Initialize hash table
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = NULL;

    // Insert sum = 0 at index -1
    insert(0, -1);

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        int prevIndex = search(sum);

        if (prevIndex != -2) {
            int len = i - prevIndex;
            if (len > maxLen)
                maxLen = len;
        } else {
            insert(sum, i);
        }
    }

    return maxLen;
}

// Driver code
int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = maxLenZeroSum(arr, n);
    printf("Length of longest subarray with sum 0: %d\n", result);

    return 0;
}