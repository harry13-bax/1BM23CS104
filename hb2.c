#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100
typedef struct {
    char items[MAX];
    int top;
} Stack;
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}
int isEmpty(Stack* stack) {
    return stack->top == -1;
}
void push(Stack* stack, char item) {
    if (stack->top < MAX - 1) {
        stack->items[++(stack->top)] = item;
    }
}
char pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->items[(stack->top)--];
    }
    return '\0'; 
}
char peek(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top];
    }
    return '\0'; 
}
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return 0;
}
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
void infixToPostfix(char* infix, char* postfix) {
    Stack* stack = createStack();
    int i,j = 0;

    for ( i = 0; infix[i]; i++) {
        if (isalnum(infix[i])) { 
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(stack);
            }
            pop(stack); 
        } else if (isOperator(infix[i])) {
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(infix[i])) {
                postfix[j++] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }
    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }
    postfix[j] = '\0'; 

    free(stack); 
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter a valid parenthesized infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = 0; 

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
