#include <stdlib.h>

// Comparator for qsort
int cmp(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[0] - y[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
            int* returnSize, int** returnColumnSizes) {

    if (intervalsSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    // Step 1: Sort intervals by start time
    qsort(intervals, intervalsSize, sizeof(int*), cmp);

    // Allocate result arrays
    int** result = (int**)malloc(sizeof(int*) * intervalsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * intervalsSize);

    int idx = 0;

    // Initialize first interval
    result[idx] = (int*)malloc(sizeof(int) * 2);
    result[idx][0] = intervals[0][0];
    result[idx][1] = intervals[0][1];
    (*returnColumnSizes)[idx] = 2;
    idx++;

    // Step 2: Merge intervals
    for (int i = 1; i < intervalsSize; i++) {
        int* last = result[idx - 1];

        if (intervals[i][0] <= last[1]) {
            // Overlapping → merge
            if (intervals[i][1] > last[1]) {
                last[1] = intervals[i][1];
            }
        } else {
            // No overlap → add new interval
            result[idx] = (int*)malloc(sizeof(int) * 2);
            result[idx][0] = intervals[i][0];
            result[idx][1] = intervals[i][1];
            (*returnColumnSizes)[idx] = 2;
            idx++;
        }
    }

    *returnSize = idx;
    return result;
}