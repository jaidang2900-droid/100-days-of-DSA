#include <stdio.h>
#define MAX 100

int heap[MAX];
int size = 0;

/* Swap function */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Heapify function (downward) */
void heapify(int i)
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && heap[left] < heap[smallest])
        smallest = left;

    if(right < size && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != i)
    {
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

/* Insert element into heap */
void insert(int value)
{
    int i = size;
    heap[size] = value;
    size++;

    while(i != 0 && heap[(i-1)/2] > heap[i])
    {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

/* Extract minimum element */
int extractMin()
{
    if(size <= 0)
    {
        printf("Heap is empty\n");
        return -1;
    }

    int root = heap[0];
    heap[0] = heap[size-1];
    size--;

    heapify(0);

    return root;
}

/* Display heap */
void display()
{
    int i;
    printf("Heap elements: ");
    for(i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

/* Main function */
int main()
{
    insert(20);
    insert(10);
    insert(30);
    insert(5);
    insert(15);

    display();

    printf("Extracted Min: %d\n", extractMin());

    display();

    return 0;
}