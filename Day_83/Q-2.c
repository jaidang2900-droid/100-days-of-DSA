int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Found target
        if (nums[mid] == target)
            return mid;

        // Left half is sorted
        if (nums[left] <= nums[mid]) {
            if (target >= nums[left] && target < nums[mid]) {
                right = mid - 1;  // search left
            } else {
                left = mid + 1;   // search right
            }
        }
        // Right half is sorted
        else {
            if (target > nums[mid] && target <= nums[right]) {
                left = mid + 1;   // search right
            } else {
                right = mid - 1;  // search left
            }
        }
    }

    return -1; // not found
}