#include <stdio.h>

// Function to calculate total hours needed at speed k
int canFinish(int* piles, int pilesSize, int h, int k) {
    long hours = 0;

    for (int i = 0; i < pilesSize; i++) {
        // Ceiling division: (piles[i] + k - 1) / k
        hours += (piles[i] + k - 1) / k;
    }

    return hours <= h;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int left = 1;
    int right = 0;

    // Find maximum pile (upper bound)
    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > right)
            right = piles[i];
    }

    int ans = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canFinish(piles, pilesSize, h, mid)) {
            ans = mid;        // possible answer
            right = mid - 1;  // try smaller k
        } else {
            left = mid + 1;   // need larger k
        }
    }

    return ans;
}

// Example usage
/*int main() {
    int piles[] = {3, 6, 7, 11};
    int h = 8;
    int size = sizeof(piles) / sizeof(piles[0]);

    int result = minEatingSpeed(piles, size, h);
    printf("Minimum eating speed: %d\n", result);

    return 0;
}*/