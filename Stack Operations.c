/*Demonstration of stack operations using arrays*/
#include<stdio.h>
#include<stdlib.h>

int isempty();
int isfull();
void push();
void pop();
void peek();
void display();
int count();

int n, top=-1;
int *a;

void main()
{
    printf("Enter the size of stack: ");
    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*n);
    while(1)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. isempty\n");
        printf("5. isfull\n");
        printf("6. Display\n");
        printf("7. count\n");
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
            case 5: isfull();
                break;
            case 6: display();
                break;
            case 7: count();
                break;
            default: exit(0);
        }
    }
}

int isempty()
{
    if(top == -1)
        printf("\nThe list is empty\n");
    else
        printf("\nThe list is not empty\n");
}

int isfull()
{
    if(top==n-1)
        printf("\nThe list is full\n");
    else
        printf("\nThe list is not full\n");
}

void push()
{
    int data;
    printf("\nEnter the value to be added: ");
    scanf("%d",&data);
    if (top==n-1)
        printf("\nStack is full\n");
    else
    {
        top++;
        a[top]=data;
    }
}

void pop()
{
    if (top==-1)
        printf("\nStack is empty\n");
    else{
        printf("\nThe top most element is removed.\n");
        top--;
    }
}

void peek()
{
    if(top==-1)
        printf("\nStack is empty\n");
    else
        printf("\nThe top most element is %d\n",a[top]);
}

void display()
{
    if (top==-1)
        printf("\nThe stack is empty.\n");
    else{
        printf("\nThe stack have elements: \n");
        for(int i=top;i>=0;i--)
            printf("%d\n",a[i]);
    }
}

int count()
{
    printf("\nThe number of elements: %d\n",top+1);
}
