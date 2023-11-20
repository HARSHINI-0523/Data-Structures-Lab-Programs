/*A Program that Demonstrates Circular Queue*/
#include <stdio.h>
# define max 6

int queue[max];
int front=-1;
int rear=-1;

void enqueue(int element)
{
    if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        queue[rear]=element;
    }
    else if((rear+1)%max==front)
    {
        printf("Queue is overflow..");
    }
    else
    {
        rear=(rear+1)%max;
        queue[rear]=element;
    }
}

int dequeue() {
    int item;
    if((front == -1) && (rear == -1)) {
        printf("\nQueue is underflow..");
        return -1;
    }
    else if(front == rear) {
        item = queue[front];
        printf("\nThe dequeued element is %d", item);
        front = -1;
        rear = -1;
    }
    else {
        item = queue[front];
        printf("\nThe dequeued element is %d", item);
        front = (front + 1) % max;
    }
    return item;
}

void display()
{
    int i=front;
    if(front==-1 && rear==-1)
        printf("\n Queue is empty..");
    else
    {
        printf("\nElements in a Queue are :");
        while(i<=rear)
        {
            printf("%d,", queue[i]);
            i=(i+1)%max;
        }
    }
}

int size() {
    if(rear >= front)
        return (rear - front + 1);
    else
        return (max - front + rear + 1);
}

int Front() {
    if(front == -1) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    return queue[front];
}

int Rear() {
    if(rear == -1) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    return queue[rear];
}
int isEmpty() {
    return front == -1;
}
int isFull() {
    return (rear + 1) % max == front;
}
void main () {
    int choice, x;
    while(1) {
        printf("\n*************************Main Menu*****************************\n");
        printf("\n=================================================================\n");
        printf("\n1.Insert an element\n2.Delete an element\n3.Display the queue\n4.Get the front element\n5.Get the rear element\n6.Check if the queue is empty\n7.Get the size of the queue\n8.Check if the queue is full\n9.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the element which is to be inserted: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                if(isEmpty())
                    printf("\nThe queue is empty\n");
                else
                    printf("\nThe front element is %d\n", Front());
                break;
            case 5:
                if(isEmpty())
                    printf("\nThe queue is empty\n");
                else
                    printf("\nThe rear element is %d\n", Rear());
                break;
            case 6:
                if(isEmpty())
                    printf("\nThe queue is empty\n");
                else
                    printf("\nThe queue is not empty\n");
                break;
            case 7:
                printf("\nThe size of the queue is %d\n", size());
                break;
            case 8:
                if(isFull())
                    printf("\nThe queue is full\n");
                else
                    printf("\nThe queue is not full\n");
                break;
            case 9:
                exit(0);
            default:
                printf("\nEnter valid choice??\n");
        }
    }
}
 
