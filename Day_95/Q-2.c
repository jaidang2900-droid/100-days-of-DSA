#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2) return 0;

    int minVal = INT_MAX, maxVal = INT_MIN;

    // Step 1: Find min and max
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < minVal) minVal = nums[i];
        if (nums[i] > maxVal) maxVal = nums[i];
    }

    if (minVal == maxVal) return 0;

    // Step 2: Calculate bucket size and count
    int gap = (maxVal - minVal) / (numsSize - 1);
    if ((maxVal - minVal) % (numsSize - 1) != 0) gap++;

    int bucketSize = numsSize - 1;

    int* bucketMin = (int*)malloc(sizeof(int) * bucketSize);
    int* bucketMax = (int*)malloc(sizeof(int) * bucketSize);

    for (int i = 0; i < bucketSize; i++) {
        bucketMin[i] = INT_MAX;
        bucketMax[i] = INT_MIN;
    }

    // Step 3: Fill buckets
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == minVal || nums[i] == maxVal)
            continue;

        int idx = (nums[i] - minVal) / gap;

        if (nums[i] < bucketMin[idx]) bucketMin[idx] = nums[i];
        if (nums[i] > bucketMax[idx]) bucketMax[idx] = nums[i];
    }

    // Step 4: Compute max gap
    int maxGap = 0;
    int prev = minVal;

    for (int i = 0; i < bucketSize; i++) {
        if (bucketMin[i] == INT_MAX) continue;

        int currGap = bucketMin[i] - prev;
        if (currGap > maxGap) maxGap = currGap;

        prev = bucketMax[i];
    }

    // Final gap with maxVal
    if (maxVal - prev > maxGap)
        maxGap = maxVal - prev;

    free(bucketMin);
    free(bucketMax);

    return maxGap;
}