#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int precedence(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return 0;
}

int main() {
    char infix[MAX], x;
    scanf("%s", infix);

    for (int i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            printf("%c", infix[i]);
        } 
        else if (infix[i] == '(') {
            push('(');
        } 
        else if (infix[i] == ')') {
            while ((x = pop()) != '(')
                printf("%c", x);
        } 
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                printf("%c", pop());
            }
            push(infix[i]);
        }
    }

    while (top != -1) {
        printf("%c", pop());
    }

    printf("\n");
    return 0;
}
