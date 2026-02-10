#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int left, right, flag = 1;

    printf("Enter a string: ");
    scanf("%s", str);   // reads string without spaces

    left = 0;
    right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            flag = 0;
            break;
        }
        left++;
        right--;
    }

    if (flag == 1)
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");

    return 0;
}
