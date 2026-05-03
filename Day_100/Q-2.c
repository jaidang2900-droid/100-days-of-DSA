#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Pair;

static void merge(Pair* a, int l, int m, int r, int* count, Pair* temp) {
    int i = l, j = m + 1, k = l;
    int rightMoved = 0;  // how many from right have been placed before current left

    while (i <= m && j <= r) {
        if (a[j].val < a[i].val) {
            temp[k++] = a[j++];
            rightMoved++;
        } else {
            count[a[i].idx] += rightMoved;
            temp[k++] = a[i++];
        }
    }

    while (i <= m) {
        count[a[i].idx] += rightMoved;
        temp[k++] = a[i++];
    }

    while (j <= r) {
        temp[k++] = a[j++];
    }

    for (int p = l; p <= r; p++) {
        a[p] = temp[p];
    }
}

static void mergeSort(Pair* a, int l, int r, int* count, Pair* temp) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(a, l, m, count, temp);
    mergeSort(a, m + 1, r, count, temp);
    merge(a, l, m, r, count, temp);
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    if (numsSize == 0) return NULL;

    int* count = (int*)calloc(numsSize, sizeof(int));
    Pair* arr = (Pair*)malloc(sizeof(Pair) * numsSize);
    Pair* temp = (Pair*)malloc(sizeof(Pair) * numsSize);

    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
    }

    mergeSort(arr, 0, numsSize - 1, count, temp);

    free(arr);
    free(temp);
    return count;
}