#include <stdio.h>

int integerSqrt(int n) {
    if (n == 0 || n == 1)
        return n;

    int low = 0, high = n, mid;
    int ans = 0;

    while (low <= high) {
        mid = low + (high - low) / 2;

        // To avoid overflow, use mid <= n / mid
        if (mid <= n / mid) {
            ans = mid;        // mid is a possible answer
            low = mid + 1;    // try for a bigger value
        } else {
            high = mid - 1;   // reduce the search space
        }
    }

    return ans;
}

int main() {
    int n;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    int result = integerSqrt(n);

    printf("Integer square root of %d is %d\n", n, result);

    return 0;
}