#include <stdio.h>
#include <stdlib.h>   // for abs()

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Assume first two elements as closest
    int minSum = arr[0] + arr[1];
    int first = arr[0];
    int second = arr[1];

    // Check all pairs
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];

            if(abs(sum) < abs(minSum)) {
                minSum = sum;
                first = arr[i];
                second = arr[j];
            }
        }
    }

    printf("\nTwo elements whose sum is closest to zero are: %d and %d\n", first, second);
    printf("Their sum is: %d\n", minSum);

    return 0;
}
