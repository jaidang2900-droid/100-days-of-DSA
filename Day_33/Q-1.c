#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push operation
void push(char x) {
    stack[++top] = x;
}

// Pop operation
char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

// Check precedence
int precedence(char x) {
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return 0;
}

// Convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, k = 0;
    char ch;

    while (infix[i] != '\0') {
        ch = infix[i];

        // If operand, add to postfix
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }

        // If '(', push to stack
        else if (ch == '(') {
            push(ch);
        }

        // If ')', pop until '('
        else if (ch == ')') {
            while (stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }

        // Operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }

        i++;
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}