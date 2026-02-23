#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at end
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

// Function to merge two sorted lists
struct Node* mergeLists(struct Node* head1, struct Node* head2) {

    struct Node* mergedHead = NULL;
    struct Node* temp = NULL;

    // If any list is empty
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    // Initialize mergedHead
    if (head1->data <= head2->data) {
        mergedHead = createNode(head1->data);
        head1 = head1->next;
    } else {
        mergedHead = createNode(head2->data);
        head2 = head2->next;
    }

    temp = mergedHead;

    // Merge remaining nodes
    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            temp->next = createNode(head1->data);
            head1 = head1->next;
        } else {
            temp->next = createNode(head2->data);
            head2 = head2->next;
        }
        temp = temp->next;
    }

    // Add remaining elements
    while (head1 != NULL) {
        temp->next = createNode(head1->data);
        head1 = head1->next;
        temp = temp->next;
    }

    while (head2 != NULL) {
        temp->next = createNode(head2->data);
        head2 = head2->next;
        temp = temp->next;
    }

    return mergedHead;
}

// Function to print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {

    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // First sorted list: 1 3 5
    list1 = insertEnd(list1, 1);
    list1 = insertEnd(list1, 3);
    list1 = insertEnd(list1, 5);

    // Second sorted list: 2 4 6
    list2 = insertEnd(list2, 2);
    list2 = insertEnd(list2, 4);
    list2 = insertEnd(list2, 6);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    struct Node* mergedList = mergeLists(list1, list2);

    printf("Merged List: ");
    printList(mergedList);

    return 0;
}