#include <stdio.h>

/* Function to heapify a subtree rooted at index i */
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    int temp;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i)
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

/* Heap Sort Function */
void heapSort(int arr[], int n)
{
    int i, temp;

    /* Step 1: Build Max Heap */
    for(i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    /* Step 2: Extract elements from heap */
    for(i = n-1; i > 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

/* Print array */
void printArray(int arr[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Main function */
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}