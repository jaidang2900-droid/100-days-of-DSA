#include <stdio.h>

int main() {
    int n, i;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Taking array input
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Assume first element is both min and max
    int max = arr[0];
    int min = arr[0];

    // Compare remaining elements
    for(i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    printf("Maximum value = %d\n", max);
    printf("Minimum value = %d\n", min);

    return 0;
}
