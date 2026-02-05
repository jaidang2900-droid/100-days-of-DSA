#include <stdio.h>

int main() {

    // Two sorted logs (arrays)
    int log1[] = {1, 4, 7, 10};
    int log2[] = {2, 3, 6, 8};

    int n1 = 4;   // size of first log
    int n2 = 4;   // size of second log

    int merged[8];   // array to store merged result

    int i = 0, j = 0, k = 0;

    // Compare elements from both logs
    while (i < n1 && j < n2) {
        if (log1[i] < log2[j]) {
            merged[k] = log1[i];
            i++;
        } else {
            merged[k] = log2[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of log1
    while (i < n1) {
        merged[k] = log1[i];
        i++;
        k++;
    }

    // Copy remaining elements of log2
    while (j < n2) {
        merged[k] = log2[j];
        j++;
        k++;
    }

    // Print merged log
    printf("Merged Chronological Log:\n");
    for (i = 0; i < n1 + n2; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}
