#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Queue;

void push(Queue* q, int x) {
    q->arr[++q->rear] = x;
}

int pop(Queue* q) {
    return q->arr[q->front++];
}

int peek(Queue* q) {
    return q->arr[q->front];
}

int isEmpty(Queue* q) {
    return q->front > q->rear;
}

int main() {
    int N, Num;
    scanf("%d", &N);
    
    Queue Q;
    Q.front = 0;
    Q.rear = -1;
    
    for(int i = 0; i < N; i++) {
        scanf("%d", &Num);
        push(&Q, Num);
    }
    int a[N];
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    int total_time = 0, executed_job = 0;
    while(!isEmpty(&Q)) {
        int job = peek(&Q);
        if(job == a[executed_job]) {
            pop(&Q);
            total_time++;
            executed_job++;
        }
        else {
            push(&Q, pop(&Q));
            total_time++;
        }
    }
    
    printf("%d\n", total_time);
    return 0;
}
