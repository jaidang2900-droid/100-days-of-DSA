#include <stdlib.h>

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
    int max = 1000; // constraint-based (safe upper bound)
    
    int count[1001] = {0};

    // Step 1: Count frequencies
    for (int i = 0; i < arr1Size; i++) {
        count[arr1[i]]++;
    }

    // Step 2: Allocate result array
    int* result = (int*)malloc(sizeof(int) * arr1Size);
    int idx = 0;

    // Step 3: Place elements in order of arr2
    for (int i = 0; i < arr2Size; i++) {
        while (count[arr2[i]] > 0) {
            result[idx++] = arr2[i];
            count[arr2[i]]--;
        }
    }

    // Step 4: Place remaining elements in ascending order
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            result[idx++] = i;
            count[i]--;
        }
    }

    *returnSize = arr1Size;
    return result;
}