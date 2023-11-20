// C program to evaluate value of a postfix expression
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char item) {
    if(top >= SIZE-1) {
        printf("\nStack Overflow.");
    } else {
        stack[++top] = item;
    }
}

char pop() {
    char item;
    if(top < 0) {
        printf("stack under flow: invalid infix expression");
        getchar();
        exit(1);
    } else {
        item = stack[top--];
        return(item);
    }
}

void push_int(int* stack, int* top, int item) {
    if(*top >= SIZE-1) {
        printf("\nStack Overflow.");
    } else {
        stack[++(*top)] = item;
    }
}

int pop_int(int* stack, int* top) {
    int item;
    if(*top < 0) {
        printf("stack under flow: invalid postfix expression");
        getchar();
        exit(1);
    } else {
        item = stack[*top];
        (*top)--;
        return(item);
    }
}

int is_operator(char symbol) {
    if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-') {
        return 1;
    } else {
        return 0;
    }
}

int precedence(char symbol) {
    if(symbol == '^') {
        return(3);
    } else if(symbol == '*' || symbol == '/') {
        return(2);
    } else if(symbol == '+' || symbol == '-') {
        return(1);
    } else {
        return(0);
    }
}

void InfixToPostfix(char infix_exp[], char postfix_exp[]) {
    int i, j;
    char item;
    char x;

    push('(');
    strcat(infix_exp, ")");

    i = 0;
    j = 0;
    item = infix_exp[i];

    while(item != '\0') {
        if(item == '(') {
            push(item);
        } else if(isdigit(item) || isalpha(item)) {
            postfix_exp[j] = item;
            j++;
        } else if(is_operator(item) == 1) {
            x = pop();
                while(is_operator(x) == 1 && precedence(x) >= precedence(item)) {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
            push(x);
            push(item);
        } else if(item == ')') {
            x = pop();
            while(x != '(') {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
        } else {
            printf("\nInvalid infix Expression.\n");
            getchar();
            exit(1);
        }
        i++;
        item = infix_exp[i];
    }
    if(top > 0) {
        printf("\nInvalid infix Expression.\n");
        getchar();
        exit(1);
    }
    postfix_exp[j] = '\0';
}

int evaluate_postfix(char* postfix_expression) {
    int stack[SIZE];
    int top = -1;
    char ch;
    int i = 0;
    int val;
    int A, B;

    while((ch = postfix_expression[i++]) != '\0') {
        if(isdigit(ch)) {
            push_int(stack, &top, ch - '0');
        } else {
            B = pop_int(stack, &top);
            A = pop_int(stack, &top);
            switch(ch) {
                case '+': push_int(stack, &top, A + B); break;
                case '-': push_int(stack, &top, A - B); break;
                case '*': push_int(stack, &top, A * B); break;
                case '/': push_int(stack, &top, A / B); break;
                case '^': push_int(stack, &top, pow(A, B)); break;
            }
        }
    }

    return stack[0];
}

int main() {
    char infix_expression[SIZE];
    char postfix_expression[SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix_expression);

    InfixToPostfix(infix_expression, postfix_expression);

   xprintf("Postfix expression: %s\n", postfix_expression);

    int result = evaluate_postfix(postfix_expression);

    printf("Result: %d\n", result);

    return 0;
}
