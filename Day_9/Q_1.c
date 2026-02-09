//Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.
#include <stdio.h>

int main() {
    char str[100];
    int i, length = 0;

    // Input the code name
    printf("Enter the code name: ");
    scanf("%s", str);

    // Find length of the string
    while (str[length] != '\0') {
        length++;
    }

    // Print characters in reverse order
    printf("Mirror format: ");
    for (i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    return 0;
}
