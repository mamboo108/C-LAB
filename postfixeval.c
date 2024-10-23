#include<stdio.h>
#include<ctype.h>
#include<math.h>
#define max 100

int stack[max];
int top = -1;

void push(int x) {
    if(top == max - 1) {
        printf("Overflow\n");
    } else {
        top++;
        stack[top] = x;
    }
}

int pop() {
    if(top == -1) {
        printf("Underflow\n");
        return -1;
    } else {
        int value = stack[top];
        top--;
        return value;
    }
}

int eval(char *exp) {
    for(int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];
        if(isdigit(ch)) {
            push(ch - '0');  // Proper character to integer conversion
        } else {
            int val2 = pop();
            int val1 = pop();
            switch(ch) {
                case '+':
                    push(val1 + val2);
                    break;
                case '-':
                    push(val1 - val2);
                    break;
                case '*':
                    push(val1 * val2);
                    break;
                case '/':
                    push(val1 / val2);
                    break;
                default:
                    printf("Invalid operator encountered\n");
                    return -1;
            }
        }
    }
    return pop();
}

int main() {
    char exp[max];
    printf("Enter the postfix expression: ");
    scanf("%s", exp);
    int result = eval(exp);
    if(result != -1) {
        printf("Result is %d\n", result);
    }
    return 0;
}
