#include <stdio.h>
#include <stdlib.h>

// Comparator for sorting
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Check if we can place m balls with at least 'dist' distance
int canPlace(int* position, int n, int m, int dist) {
    int count = 1;  // first ball placed
    int lastPos = position[0];

    for (int i = 1; i < n; i++) {
        if (position[i] - lastPos >= dist) {
            count++;
            lastPos = position[i];
        }
        if (count >= m)
            return 1;
    }
    return 0;
}

int maxDistance(int* position, int positionSize, int m) {
    // Step 1: sort positions
    qsort(position, positionSize, sizeof(int), compare);

    int low = 1;
    int high = position[positionSize - 1] - position[0];
    int ans = 0;

    // Step 2: binary search
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlace(position, positionSize, m, mid)) {
            ans = mid;        // possible answer
            low = mid + 1;    // try bigger distance
        } else {
            high = mid - 1;   // reduce distance
        }
    }

    return ans;
}