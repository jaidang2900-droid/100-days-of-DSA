int searchInsert(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    int ans = numsSize;  // default insert position (end)

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;  // found
        }
        else if (nums[mid] > target) {
            ans = mid;   // possible insert position
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return ans;
}