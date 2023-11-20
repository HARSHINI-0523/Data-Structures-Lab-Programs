#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

long long arr[MAX], nxt[MAX], dp[MAX];
int stack[MAX], top = -1;

void push(int x) {
    stack[++top] = x;
}

void pop() {
    if(top != -1)
        top--;
}

int peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int main() {
    int n;
    scanf("%d", &n); 

    for(int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    push(0);

    for(int i = 1; i < n; i++) {
        while(!isEmpty() && arr[i] > arr[peek()]) {
            nxt[peek()] = i;
            pop();
        }
        push(i);
    }

    while(!isEmpty()) {
        nxt[peek()] = -1;
        pop();
    }

    long long ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(nxt[i] == -1) {
            dp[i] = arr[i];
            ans = (ans > dp[i]) ? ans : dp[i];
        } else {
            dp[i] = arr[i] ^ dp[nxt[i]];
            ans = (ans > dp[i]) ? ans : dp[i];
        }
    }
    printf("%lld\n", ans);
    
    return 0;
