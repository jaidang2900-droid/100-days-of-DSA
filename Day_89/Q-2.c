#include <stdio.h>

// Function to check if given capacity can ship within days
int canShip(int* weights, int n, int days, int capacity) {
    int currentWeight = 0;
    int requiredDays = 1;

    for (int i = 0; i < n; i++) {
        if (currentWeight + weights[i] > capacity) {
            requiredDays++;
            currentWeight = 0;
        }
        currentWeight += weights[i];
    }

    return requiredDays <= days;
}

int shipWithinDays(int* weights, int weightsSize, int days) {
    int low = weights[0], high = 0;

    // Find max element and total sum
    for (int i = 0; i < weightsSize; i++) {
        if (weights[i] > low)
            low = weights[i];
        high += weights[i];
    }

    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canShip(weights, weightsSize, days, mid)) {
            result = mid;
            high = mid - 1;  // try smaller capacity
        } else {
            low = mid + 1;   // increase capacity
        }
    }

    return result;
}