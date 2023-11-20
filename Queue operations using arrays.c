/*A program to demonstrate queue operations*/
#include<stdio.h>
#include<stdlib.h>
#define maxsize 5
void insert();
void delete();
void display();
int front = -1, rear = -1;
int queue[maxsize];
int Size();
int Front();
int Rear();
int IsEmpty();
int IsFull();

void main () {
    int choice;
    while(choice != 8) {
        printf("\n*************************Main Menu*****************************\n");
        printf("\n=================================================================\n");
        printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Check size of queue\n5.Check front element of queue\n6.Check rear element of queue\n7.Check if queue is empty\n8.Check if queue is full\n9.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nSize of queue: %d", Size());
                break;
            case 5:
                printf("\nFront element of queue: %d", Front());
                break;
            case 6:
                printf("\nRear element of queue: %d", Rear());
                break;
            case 7:
                if(IsEmpty()) printf("\nQueue is empty");
                else printf("\nQueue is not empty");
                break;
            case 8:
                if(IsFull()) printf("\nQueue is full");
                else printf("\nQueue is not full");
                break;
            case 9:
                exit(0);
            default:
                printf("\nEnter valid choice??\n");
        }
    }
}


void insert()
{
    int item;
    printf("\nEnter the element\n");
    scanf("\n%d",&item);
    if(rear == maxsize-1)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
        rear = rear+1;
    queue[rear] = item;
    printf("\nValue inserted ");

}
void delete()
{
    int item;
    if (front == -1 || front > rear)
    {
        printf("\nUNDERFLOW\n");
        return;

    }
    else
    {
        item = queue[front];
        if(front == rear)
        {
            front = -1;
            rear = -1 ;
        }
        else
            front = front + 1;
        printf("\nvalue deleted ");
    }
}

void display()
{
    int i;
    if(rear == -1)
    {
        printf("\nEmpty queue\n");
    }
    else
    {   printf("\nprinting values .....\n");
        for(i=front;i<=rear;i++)
        {
            printf("\n%d\n",queue[i]);
        }
    }
}

int Size() {
    if (front == -1) return 0;
    else return rear - front + 1;
}

int Front() {
    if (front == -1) {
        printf("\nQueue is empty\n");
        return -1;
    }
    else return queue[front];
}
int Rear() {
    if (rear == -1) {
        printf("\nQueue is empty\n");
        return -1;
    }
    else return queue[rear];
}
int IsEmpty() {
    if (front == -1) return 1;
    else return 0;
}
int IsFull() {
    if (rear == maxsize-1) return 1;
    else return 0;
}
 
