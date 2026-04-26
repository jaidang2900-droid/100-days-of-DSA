int findMin(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // If mid element is greater than right element
        // minimum is in right half
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } 
        // Else minimum is in left half (including mid)
        else {
            right = mid;
        }
    }

    return nums[left];
}