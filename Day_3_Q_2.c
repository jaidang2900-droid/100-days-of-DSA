int missingNum(int *arr, int size) {
    long long expectedSum = (long long)(size + 1) * (size + 2) / 2;
    long long actualSum = 0;

    for (int i = 0; i < size; i++) {
        actualSum += arr[i];
    }

    return (int)(expectedSum - actualSum);
}