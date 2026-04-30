#include <stdio.h>

// Function to check if allocation is possible
int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pagesSum = 0;

    for (int i = 0; i < n; i++) {
        // If a single book has more pages than maxPages
        if (arr[i] > maxPages)
            return 0;

        if (pagesSum + arr[i] <= maxPages) {
            pagesSum += arr[i];
        } else {
            students++;
            pagesSum = arr[i];

            if (students > m)
                return 0;
        }
    }
    return 1;
}

// Main function to allocate books
int allocateBooks(int arr[], int n, int m) {
    if (n < m)
        return -1; // Not enough books

    int sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    int low = max, high = sum, result = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1; // try smaller maximum
        } else {
            low = mid + 1;
        }
    }

    return result;
}

// Driver code
int main() {
    int arr[] = {12, 34, 67, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = 2;

    int result = allocateBooks(arr, n, m);

    if (result == -1)
        printf("Allocation not possible\n");
    else
        printf("Minimum maximum pages = %d\n", result);

    return 0;
}