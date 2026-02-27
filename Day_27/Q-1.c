#include <stdio.h>
#include <stdlib.h>

// Definition of Linked List Node
struct ListNode {
    int data;
    struct ListNode* next;
};

// Function to create new node
struct ListNode* createNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to find intersection point
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    
    if (headA == NULL || headB == NULL)
        return NULL;

    struct ListNode* ptr1 = headA;
    struct ListNode* ptr2 = headB;

    while (ptr1 != ptr2) {
        ptr1 = (ptr1 == NULL) ? headB : ptr1->next;
        ptr2 = (ptr2 == NULL) ? headA : ptr2->next;
    }

    return ptr1;   // Intersection node or NULL
}

// Main function
int main() {

    // Creating common part
    struct ListNode* common = createNode(30);
    common->next = createNode(40);
    common->next->next = createNode(50);

    // First linked list: 10 -> 20 -> 30 -> 40 -> 50
    struct ListNode* headA = createNode(10);
    headA->next = createNode(20);
    headA->next->next = common;

    // Second linked list: 15 -> 30 -> 40 -> 50
    struct ListNode* headB = createNode(15);
    headB->next = common;

    // Finding intersection
    struct ListNode* intersection = getIntersectionNode(headA, headB);

    if (intersection != NULL)
        printf("Intersection at node with value: %d\n", intersection->data);
    else
        printf("No intersection found\n");

    return 0;
}