#include <stdio.h>

// Heapify (max heap)
void heapify(int nums[], int n, int i) {
    while (1) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < n && nums[left] > nums[largest])
            largest = left;

        if (right < n && nums[right] > nums[largest])
            largest = right;

        if (largest == i)
            break;

        int temp = nums[i];
        nums[i] = nums[largest];
        nums[largest] = temp;

        i = largest; // move down
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    // Step 1: Build max heap
    for (int i = numsSize/2 - 1; i >= 0; i--) {
        heapify(nums, numsSize, i);
    }

    // Step 2: Extract max k-1 times
    for (int i = numsSize - 1; i >= numsSize - k + 1; i--) {
        // swap root with last
        int temp = nums[0];
        nums[0] = nums[i];
        nums[i] = temp;

        // heapify reduced heap
        heapify(nums, i, 0);
    }

    // kth largest
    return nums[0];
}