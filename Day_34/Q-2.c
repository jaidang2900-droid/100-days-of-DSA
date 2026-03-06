#include <stdio.h>
#include <ctype.h>
#include <string.h>

int calculate(char* s) {
    long result = 0;
    long last = 0;
    long num = 0;
    char sign = '+';

    int n = strlen(s);

    for (int i = 0; i < n; i++) {

        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }

        if ((!isdigit(s[i]) && s[i] != ' ') || i == n - 1) {

            if (sign == '+') {
                result += last;
                last = num;
            }
            else if (sign == '-') {
                result += last;
                last = -num;
            }
            else if (sign == '*') {
                last = last * num;
            }
            else if (sign == '/') {
                last = last / num;
            }

            sign = s[i];
            num = 0;
        }
    }

    return result + last;
}