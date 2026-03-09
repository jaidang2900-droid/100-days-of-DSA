#include <stdio.h>
#define MAX 100

int pq[MAX];
int size = 0;

/* Insert element */
void enqueue(int value)
{
    if(size == MAX)
    {
        printf("Priority Queue Overflow\n");
        return;
    }

    int i = size - 1;

    // Shift elements to maintain priority order
    while(i >= 0 && pq[i] > value)
    {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = value;
    size++;
}

/* Delete highest priority element (smallest value) */
void dequeue()
{
    if(size == 0)
    {
        printf("Priority Queue Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", pq[0]);

    for(int i = 0; i < size - 1; i++)
        pq[i] = pq[i + 1];

    size--;
}

/* Display queue */
void display()
{
    if(size == 0)
    {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Priority Queue: ");
    for(int i = 0; i < size; i++)
        printf("%d ", pq[i]);
    printf("\n");
}

int main()
{
    int choice, value;

    while(1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}