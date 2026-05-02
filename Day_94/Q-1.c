#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
    if (n <= 0) return;

    // Step 1: Find max
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    // Step 2: Frequency array
    int *count = (int*)calloc(max + 1, sizeof(int));

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Step 3: Prefix sum
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Step 4: Output array
    int *output = (int*)malloc(n * sizeof(int));

    // Traverse from right → stable sort
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Step 5: Copy back
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // Free memory
    free(count);
    free(output);
}

// Driver code
int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}