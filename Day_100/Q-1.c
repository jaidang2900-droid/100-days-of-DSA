#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Pair;

// Merge function
void merge(Pair* arr, int left, int mid, int right, int* count) {
    int i = left, j = mid + 1, k = 0;
    int rightCount = 0;

    Pair* temp = (Pair*)malloc(sizeof(Pair) * (right - left + 1));

    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            temp[k++] = arr[j++];
            rightCount++;  // smaller element found
        } else {
            count[arr[i].idx] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        count[arr[i].idx] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy back
    for (int x = 0; x < k; x++) {
        arr[left + x] = temp[x];
    }

    free(temp);
}

void mergeSort(Pair* arr, int left, int right, int* count) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid, count);
    mergeSort(arr, mid + 1, right, count);

    merge(arr, left, mid, right, count);
}

// Main function
int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    int* count = (int*)calloc(numsSize, sizeof(int));

    Pair* arr = (Pair*)malloc(sizeof(Pair) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
    }

    mergeSort(arr, 0, numsSize - 1, count);

    free(arr);
    return count;
}