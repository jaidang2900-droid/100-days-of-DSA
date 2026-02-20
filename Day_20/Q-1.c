#include <stdio.h>

int countZeroSumSubarrays(int arr[], int n) {
    int count = 0;

    // Pick starting point
    for (int i = 0; i < n; i++) {
        int sum = 0;

        // Pick ending point
        for (int j = i; j < n; j++) {
            sum += arr[j];

            // Check if sum becomes zero
            if (sum == 0) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int arr[] = {1, -1, 2, -2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = countZeroSumSubarrays(arr, n);

    printf("Number of subarrays with sum 0: %d\n", result);

    return 0;
}