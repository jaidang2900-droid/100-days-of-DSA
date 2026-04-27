int mySqrt(int x) {
    if (x == 0 || x == 1)
        return x;

    int low = 0, high = x, mid;
    int ans = 0;

    while (low <= high) {
        mid = low + (high - low) / 2;

        // Avoid overflow: use mid <= x / mid instead of mid * mid <= x
        if (mid <= x / mid) {
            ans = mid;        // valid candidate
            low = mid + 1;    // try to find a bigger one
        } else {
            high = mid - 1;   // reduce range
        }
    }

    return ans;
}