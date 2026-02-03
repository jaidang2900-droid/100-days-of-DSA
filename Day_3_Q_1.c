//Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

#include <stdio.h>

int main() {
    int n, k, i;
    int comparisons = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter key to search: ");
    scanf("%d", &k);

    // Linear Search
    for (i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) {
            printf("Key %d found at position %d\n", k, i + 1);
            printf("Number of comparisons: %d\n", comparisons);
            return 0;
        }
    }

    // If key not found
    printf("Key %d not found\n", k);
    printf("Number of comparisons: %d\n", comparisons);

    return 0;
}
