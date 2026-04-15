#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparator for qsort
int cmp(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

char* winner(char arr[][100], int n) {
    // Create array of pointers for sorting
    char *ptrs[n];
    for (int i = 0; i < n; i++) {
        ptrs[i] = arr[i];
    }

    // Sort the names
    qsort(ptrs, n, sizeof(char *), cmp);

    int maxCount = 1, count = 1;
    char *result = ptrs[0];

    for (int i = 1; i < n; i++) {
        if (strcmp(ptrs[i], ptrs[i - 1]) == 0) {
            count++;
        } else {
            count = 1;
        }

        if (count > maxCount) {
            maxCount = count;
            result = ptrs[i];
        }
    }

    return result;
}

// Example usage
int main() {
    char votes[][100] = {"john", "mary", "john", "alice", "mary", "mary"};
    int n = sizeof(votes) / sizeof(votes[0]);

    char *res = winner(votes, n);
    printf("Winner: %s\n", res);

    return 0;
}