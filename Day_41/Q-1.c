#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* next;
};

// Front and Rear pointers
struct node *front = NULL;
struct node *rear = NULL;

// Enqueue operation
void enqueue(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    
    newnode->data = value;
    newnode->next = NULL;

    if(front == NULL && rear == NULL) {
        front = rear = newnode;
    } 
    else {
        rear->next = newnode;
        rear = newnode;
    }

    printf("%d inserted into queue\n", value);
}

// Dequeue operation
void dequeue() {
    if(front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    struct node* temp = front;
    printf("%d deleted from queue\n", front->data);

    front = front->next;
    free(temp);

    if(front == NULL)
        rear = NULL;
}

// Display queue
void display() {
    struct node* temp = front;

    if(front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    enqueue(40);
    display();

    return 0;
}