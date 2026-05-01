#include <stdio.h>

// Check if we can split into <= k subarrays with max sum = maxSum
int canSplit(int* nums, int n, int k, int maxSum) {
    int subarrays = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (currentSum + nums[i] <= maxSum) {
            currentSum += nums[i];
        } else {
            subarrays++;
            currentSum = nums[i];

            if (subarrays > k)
                return 0; // not possible
        }
    }
    return 1; // possible
}

int splitArray(int* nums, int numsSize, int k) {
    int low = nums[0], high = 0;

    // Find max element and total sum
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > low)
            low = nums[i];
        high += nums[i];
    }

    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canSplit(nums, numsSize, k, mid)) {
            result = mid;
            high = mid - 1;  // try smaller max sum
        } else {
            low = mid + 1;   // increase allowed sum
        }
    }

    return result;
}