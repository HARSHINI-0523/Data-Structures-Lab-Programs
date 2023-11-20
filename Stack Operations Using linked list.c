/*Demonstration of stack operations using linkedlists*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

int isempty();
void push();
void pop();
void peek();
void display();
int count();

node* top;
int c=0;

void main(){
    while(1){
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. isempty\n");
        printf("5. Display\n");
        printf("6. count\n");
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: push();
                break;
            case 2: pop();
                break;
            case 3: peek();
                break;
            case 4: isempty();
                break;
            case 5: display();
                break;
            case 6: count();
                break;
            default: exit(0);
        }
    }
}

int isempty()
{
    if(top == NULL)
        printf("\nThe stack is empty\n");
    else
        printf("\nThe stack is not empty\n");
}

void push()
{
    int value;
    printf("\nEnter the value to be added: ");
    scanf("%d",&value);
    node* temp;
    temp = (node*)malloc(sizeof(node*));
    temp->data = value;
    temp->next = NULL;
    if (top==NULL)
        top = temp;
    else{
        temp->next=top;
        top = temp;
    }
    c++;
}

void pop()
{
    if (top==NULL)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        node* p = top;
        printf("\nThe top most element is removed\n");
        top = top->next;
        free(p);
        c--;

        if (top == NULL)
        {
            printf("\nStack is now empty\n");
        }
    }
}

void peek()
{
    if(top==NULL)
        printf("\nStack is empty\n");
    else
        printf("\nThe top most element is %d\n",top->data);
}

void display()
{
    if (top==NULL)
        printf("\nThe stack is empty.\n");
    else{
        printf("\nThe elements in the stack are:\n");
        node* p;
        p = top;
        while(p->next!=NULL){
            printf("%d\n",p->data);
            p = p->next;
        }
        printf("%d\n",p->data);
    }
}

int count(){
    printf("\nThe number of elements: %d\n",c);
}
