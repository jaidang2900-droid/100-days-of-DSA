int findPeakElement(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // If mid element is less than next, peak lies on right side
        if (nums[mid] < nums[mid + 1]) {
            left = mid + 1;
        } 
        // Otherwise, peak lies on left side (including mid)
        else {
            right = mid;
        }
    }

    return left;  // or right (both are same here)
}