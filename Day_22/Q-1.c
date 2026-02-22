#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct Node {
    int data;
    struct Node* next;
};

// Function to count nodes
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

int main() {
    struct Node *head = NULL, *second = NULL, *third = NULL;

    // Create 3 nodes
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // Assign data and link nodes
    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    // Call function
    int total = countNodes(head);

    printf("Number of nodes in linked list: %d\n", total);

    return 0;
}