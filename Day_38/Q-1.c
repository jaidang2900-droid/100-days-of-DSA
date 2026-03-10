#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;

void insertFront(int value)
{
    if((front == 0 && rear == MAX-1) || (front == rear + 1))
    {
        printf("Deque Overflow\n");
        return;
    }

    if(front == -1)
    {
        front = rear = 0;
    }
    else if(front == 0)
    {
        front = MAX - 1;
    }
    else
    {
        front = front - 1;
    }

    deque[front] = value;
}

void insertRear(int value)
{
    if((front == 0 && rear == MAX-1) || (front == rear + 1))
    {
        printf("Deque Overflow\n");
        return;
    }

    if(front == -1)
    {
        front = rear = 0;
    }
    else if(rear == MAX - 1)
    {
        rear = 0;
    }
    else
    {
        rear = rear + 1;
    }

    deque[rear] = value;
}

void deleteFront()
{
    if(front == -1)
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", deque[front]);

    if(front == rear)
    {
        front = rear = -1;
    }
    else if(front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front = front + 1;
    }
}

void deleteRear()
{
    if(front == -1)
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", deque[rear]);

    if(front == rear)
    {
        front = rear = -1;
    }
    else if(rear == 0)
    {
        rear = MAX - 1;
    }
    else
    {
        rear = rear - 1;
    }
}

void display()
{
    if(front == -1)
    {
        printf("Deque is empty\n");
        return;
    }

    int i = front;

    printf("Deque elements: ");

    while(i != rear)
    {
        printf("%d ", deque[i]);
        i = (i + 1) % MAX;
    }

    printf("%d\n", deque[rear]);
}

int main()
{
    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertFront(2);

    display();

    deleteFront();
    deleteRear();

    display();

    return 0;
}