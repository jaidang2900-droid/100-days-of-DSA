#include <stdio.h>
#include <stdlib.h>

// Function to compare elements for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Check if we can place k cows with at least 'dist' spacing
int canPlaceCows(int stalls[], int n, int k, int dist) {
    int count = 1;  // place first cow at first stall
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];
        }
        if (count >= k)
            return 1;
    }
    return 0;
}

// Main function to find maximum minimum distance
int aggressiveCows(int stalls[], int n, int k) {
    // Sort stalls
    qsort(stalls, n, sizeof(int), compare);

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, n, k, mid)) {
            result = mid;   // possible answer
            low = mid + 1;  // try for larger distance
        } else {
            high = mid - 1; // reduce distance
        }
    }

    return result;
}

// Driver code
int main() {
    int n = 5;
    int stalls[] = {1, 2, 8, 4, 9};
    int k = 3;

    int ans = aggressiveCows(stalls, n, k);
    printf("Maximum minimum distance = %d\n", ans);

    return 0;
}