/*Operations on double linked lists*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;

node* head;
int count = 0;

void insert_begin();
void insert_end();
void insert_rapo();
void delete_begin();
void delete_end();
void delete_rapo();
void deleteNthFromEnd();
void search();
void display();
void displayRev();

int main()
{
    char choice;
    while(1){
        printf("A. Insert at Beginning\n");
        printf("B. Insert at End\n");
        printf("C. Insert at random position\n");
        printf("D. Delete at Beginning\n");
        printf("E. Delete at End\n");
        printf("F. Delete at random position\n");
        printf("G. Delete nth node from End\n");
        printf("H. Search for an element\n");
        printf("X. Display list in reverse\n");
        printf("Y. Display\n");
        printf("Z. Print number of nodes\n");
        printf("Others to exit\n");
        printf("Enter the choice: ");
        scanf(" %c",&choice);
        switch(choice)
        {
            case 'A': insert_begin();
                break;
            case 'B': insert_end();
                break;
            case 'C': insert_rapo();
                break;
            case 'D': delete_begin();
                break;
            case 'E': delete_end();
                break;
            case 'F': delete_rapo();
                break;
            case 'G': deleteNthFromEnd();
                break;
            case 'H': search();
                break;
            case 'X': displayRev();
                break;
            case 'Y': display();
                break;
            case 'Z': printf("Number of nodes are %d\n",count);
                break;
            default: exit(0);
        }
    }
    return 0;
}

void insert_begin()
{
    int value;
    printf("Enter value to be inserted: ");
    scanf("%d",&value);
    node* temp;
    temp = (node*)malloc(sizeof(node*));
    if(temp == NULL)
        printf("memory insufficient\n");
    else
    {
        temp->data= value;
        temp->prev = NULL;
        if(head==NULL)
            temp->next=NULL;
        else
        {
            temp->next=head;
            head->prev = temp;
        }
        head = temp;
        count++;
    }
}

void insert_end()
{
    int value;
    printf("Enter value to be inserted: ");
    scanf("%d",&value);
    node* temp;
    temp = (node*)malloc(sizeof(node));
    if(temp == NULL)
        printf("memory insufficient\n");
    else
    {
        temp->data= value;
        temp->next=NULL;
        temp->prev=NULL;
        if(head==NULL)
            head=temp;
        else
        {
            node* p;
            p = head;
            while(p->next!=NULL)
                p = p->next;
            p->next = temp;
            temp->prev = p;
        }
        count++;
    }
}

void insert_rapo()
{
    int value,pos;
    printf("Enter value to be inserted: ");
    scanf("%d",&value);
    printf("Enter the position: ");
    scanf("%d",&pos);
    node* temp;
    temp = (node*)malloc(sizeof(node));
    if(temp == NULL)
        printf("memory insufficient\n");
    else
    {
        temp->data= value;
        temp->next=NULL;
        temp->prev=NULL;
        if(head==NULL)
            head=temp;
        else
        {
            node* p;
            p = head;
            for(int i=0;i<(pos-2);i++)
                p = p->next;
            temp->next = p->next;
            p->next = temp;
            temp->prev = p;
            if(temp->next != NULL)
                temp->next->prev = temp;
        }
        count++;
    }
}

void delete_begin()
{
    if(head == NULL)
        printf("List is empty\n");
    else
    {
        node* p;
        p = head;
        head = head ->next;
        free(p);
        count--;
        printf("First node is deleted successfuly\n");
    }
}

void delete_end()
{
    if(head == NULL)
        printf("List is empty\n");
    else
    {
        node* p;
        p = head;
        while(p->next->next!=NULL)
            p = p->next;
        free(p->next);
        p->next = NULL;
        printf("Ending node is deleted\n");
        count--;
    }
}

void delete_rapo()
{
    int pos;
    printf("Enter the position: ");
    scanf("%d",&pos);
    node* temp;
    temp = (node*)malloc(sizeof(node));
    if(head == NULL)
        printf("List is empty\n");
    else
    {
        node *t, *q;
        t = head;
        for(int i=0; i<(pos-2); i++)
            t = t->next;
        q = t->next;
        t->next = t->next->next;
        if(t->next != NULL)
            t->next->prev = t;
        free(q);
        count--;
    }
}

void deleteNthFromEnd() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    int n;
    printf("Enter the position: ");
    scanf("%d",&n);
    node *first = head;
    node *second = head;
    for(int i = 0; i < n; i++) {
        if(second->next == NULL) {
            if(i == n - 1)
                head = head->next;
            return;
        }
        second = second->next;
    }

    while(second->next != NULL) {
        first = first->next;
        second = second->next;
    }

    node *temp = first->next;
    first->next = first->next->next;
    if(first->next != NULL)
        first->next->prev = first;
    free(temp);
    count--;
}


void search()
{
    node *t;
    int c = 0, p = -1, value;
    printf("Enter the value: ");
    scanf("%d", &value);
    for (t = head; 1; t = t->next)
    {
        c++;
        if (t->data == value)
        {
            printf("%d is in the list at %d position\n", t->data, c);
            p = 1;
            break;
        }
        if (t->next == NULL)
            break;
    }
    if (p == -1)
        printf("Element is not in the list\n");
}

void displayRev()
{
    if(head == NULL)
        printf("List is empty\n");
    else {
        node* p;
        p = head;
        while(p->next != NULL)
            p = p->next;
        while(p->prev != NULL){
            printf("%d ", p->data);
            p = p->prev;
        }
        printf("%d\n", p->data);
    }
}

void display()
{
    if(head == NULL)
        printf("List is empty\n");
    else {
        node* p;
        p = head;
        while(p->next != NULL) {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("%d\n", p->data);
    }
}
