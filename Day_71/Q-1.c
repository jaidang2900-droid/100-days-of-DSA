#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int hashTable[SIZE];

// Initialize hash table
void init() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1; // -1 means empty
    }
}

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Insert using Quadratic Probing
void insert(int key) {
    int index = hash(key);

    if (hashTable[index] == -1) {
        hashTable[index] = key;
        return;
    }

    // Collision occurred → Quadratic probing
    for (int i = 1; i < SIZE; i++) {
        int newIndex = (index + i * i) % SIZE;

        if (hashTable[newIndex] == -1) {
            hashTable[newIndex] = key;
            return;
        }
    }

    printf("Hash table is full, cannot insert %d\n", key);
}

// Search element
int search(int key) {
    int index = hash(key);

    if (hashTable[index] == key)
        return index;

    for (int i = 1; i < SIZE; i++) {
        int newIndex = (index + i * i) % SIZE;

        if (hashTable[newIndex] == key)
            return newIndex;

        if (hashTable[newIndex] == -1)
            return -1; // Stop early if empty slot found
    }

    return -1;
}

// Display hash table
void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Index %d: %d\n", i, hashTable[i]);
        else
            printf("Index %d: EMPTY\n", i);
    }
}

// Main function
int main() {
    init();

    insert(23);
    insert(43);
    insert(13);
    insert(27);
    insert(33);

    display();

    int key = 43;
    int pos = search(key);

    if (pos != -1)
        printf("Element %d found at index %d\n", key, pos);
    else
        printf("Element %d not found\n", key);

    return 0;
}