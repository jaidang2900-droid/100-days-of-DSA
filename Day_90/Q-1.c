#include <stdio.h>

// Function to check if painting is possible within given time
int canPaint(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        if (currentTime + boards[i] <= maxTime) {
            currentTime += boards[i];
        } else {
            painters++;
            currentTime = boards[i];

            if (painters > k) {
                return 0; // Not possible
            }
        }
    }
    return 1; // Possible
}

int minTime(int boards[], int n, int k) {
    int low = boards[0], high = 0;

    // Find max and sum
    for (int i = 0; i < n; i++) {
        if (boards[i] > low)
            low = boards[i];
        high += boards[i];
    }

    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPaint(boards, n, k, mid)) {
            result = mid;
            high = mid - 1;  // try smaller time
        } else {
            low = mid + 1;   // increase time
        }
    }

    return result;
}

// Driver code
int main() {
    int boards[] = {10, 20, 30, 40};
    int n = 4;
    int k = 2;

    printf("Minimum time: %d\n", minTime(boards, n, k));
    return 0;
}