#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define max 100

char stack[max];
int top = -1;

void push(char x) {
    if (top == max - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = x;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1; // Return -1 to signal an error
    } else {
        return stack[top--]; // Return the top element and decrement top
    }
}

int prec(char x) {
    if (x == '+' || x == '-') {
        return 1;
    } else if (x == '*' || x == '/') {
        return 2;
    } else if (x == '^') {
        return 3;
    }
    return 0; // No precedence for other characters
}

void calc(char infix[]) {
    char postfix[max];
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        if (isalnum(ch)) { // If the character is an operand
            postfix[j++] = ch; // Add operand to output
        } else if (ch == '(') {
            push(ch); // Push '(' onto stack
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop(); // Pop until '(' is found
            }
            pop(); // Discard '('
        } else { // Operator
            while (top != -1 && prec(stack[top]) >= prec(ch)) {
                postfix[j++] = pop(); // Pop operators of higher or equal precedence
            }
            push(ch); // Push the current operator onto the stack
        }
    }

    // Pop remaining operators in the stack
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null-terminate the postfix string
    printf("Postfix expression: %s\n", postfix); // Correct output format
}

int main() {
    char infix[max];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    calc(infix);
    return 0;
}
