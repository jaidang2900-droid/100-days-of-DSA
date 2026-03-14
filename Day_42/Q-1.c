#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* Queue structure */
typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

/* Stack structure */
typedef struct {
    int arr[MAX];
    int top;
} Stack;

/* Queue functions */
void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

int isQueueEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }

    if (q->front == -1)
        q->front = 0;

    q->arr[++q->rear] = value;
}

int dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }

    int value = q->arr[q->front];

    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;

    return value;
}

/* Stack functions */
void initStack(Stack *s) {
    s->top = -1;
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = value;
}

int pop(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

/* Reverse queue using stack */
void reverseQueue(Queue *q) {
    Stack s;
    initStack(&s);

    while (!isQueueEmpty(q)) {
        push(&s, dequeue(q));
    }

    while (!isStackEmpty(&s)) {
        enqueue(q, pop(&s));
    }
}

/* Display queue */
void display(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->arr[i]);

    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    printf("Original Queue: ");
    display(&q);

    reverseQueue(&q);

    printf("Reversed Queue: ");
    display(&q);

    return 0;
}