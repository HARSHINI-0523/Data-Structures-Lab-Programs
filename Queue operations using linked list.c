/*A program to demonstrate queue operations using Linked List*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front;
struct node *rear;
void insert();
void delete();
void display();
int size();
int Front();
int Rear();
int isEmpty();

void main () {
    int choice;
    while(choice != 8) {
        printf("\n*************************Main Menu*****************************\n");
        printf("\n=================================================================\n");
        printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Get the front element\n5.Get the rear element\n6.Check if the queue is empty\n7.Get the size of the queue\n8.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",& choice);
        switch(choice) {
            case 1:
            insert();
                break;
            case 2:
            delete();
            printf("\nAn element is deleted\n");
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
            exit(0);
                break;
            default:
            printf("\nEnter valid choice??\n");
        }
    }
}


void insert()
{
    struct node *ptr;
    int item;

    ptr = (struct node *) malloc (sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    else
    {
        printf("\nEnter value?\n");
        scanf("%d",&item);
        ptr -> data = item;
        if(front == NULL)
        {
            front = ptr;
            rear = ptr;
            front -> next = NULL;
            rear -> next = NULL;
        }
        else
        {
            rear -> next = ptr;
            rear = ptr;
            rear->next = NULL;
        }
    }
}
void delete ()
{
    struct node *ptr;
    if(front == NULL)
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    else
    {
        ptr = front;
        front = front -> next;
        free(ptr);
    }
}
void display()
{
    struct node *ptr;
    ptr = front;
    if(front == NULL)
    {
        printf("\nEmpty queue\n");
    }
    else
    {   printf("\nprinting values .....\n");
        while(ptr != NULL)
        {
            printf("\n%d\n",ptr -> data);
            ptr = ptr -> next;
        }
    }
}
int size() {
    struct node *ptr;
    int count = 0;
    ptr = front;
    while(ptr != NULL) {
        count++;
        ptr = ptr -> next;
    }
    return count;
}
int Front() {
    if(front != NULL)
        return front->data;
    else
        return -1;
}
int Rear() {
    if(rear != NULL)
        return rear->data;
    else
        return -1;
}
int isEmpty() {
    if(front == NULL)
        return 1;
    else
        return 0;
}
