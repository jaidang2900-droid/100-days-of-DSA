#include <stdio.h>
#include <string.h>

char firstRepeatedCharacter(char *s) {
    int visited[26] = {0};  // for 'a' to 'z'

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        if (visited[index] == 1) {
            return s[i];  // first repeated character
        }

        visited[index] = 1;
    }

    return '\0';  // no repeated character found
}

int main() {
    char s[1000];
    printf("Enter string: ");
    scanf("%s", s);

    char result = firstRepeatedCharacter(s);

    if (result != '\0')
        printf("First repeated character: %c\n", result);
    else
        printf("No repeated character found\n");

    return 0;
}