#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValid(char* s) {
    int n = strlen(s);
    
    char *stack = (char*)malloc(n * sizeof(char));
    int top = -1;
    
    for (int i = 0; i < n; i++) {
        char ch = s[i];
        
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        } 
        else {
            if (top == -1) {
                free(stack);
                return false;
            }
            
            char topChar = stack[top--];
            
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                free(stack);
                return false;
            }
        }
    }
    
    bool result = (top == -1);
    free(stack);
    return result;
}