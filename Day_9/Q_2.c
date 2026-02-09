void reverseString(char *s, int n) {
    char *start = s;
    char *end = s + n - 1;
    char temp;

    while (start < end) {
        // swap using pointers
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}