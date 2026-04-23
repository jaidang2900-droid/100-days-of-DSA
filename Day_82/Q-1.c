#include <stdio.h>

// Lower Bound: first index where arr[i] >= x
int lowerBound(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    int ans = n;  // default if not found

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] >= x) {
            ans = mid;
            right = mid - 1; // move left
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

// Upper Bound: first index where arr[i] > x
int upperBound(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    int ans = n;  // default if not found

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > x) {
            ans = mid;
            right = mid - 1; // move left
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    int arr[] = {1, 2, 4, 4, 4, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 4;

    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    printf("Lower Bound of %d = %d\n", x, lb);
    printf("Upper Bound of %d = %d\n", x, ub);

    return 0;
}