/*Operations on Circular Linked List*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* head;
int count = 0;

void insert_begin();
void insert_end();
void delete_begin();
void delete_end();
void sort();
void remove_duplicates();
void display();

int main()
{
    char choice;
    while(1){
        printf("A. Insert at Beginning\n");
        printf("B. Insert at End\n");
        printf("C. Delete at Beginning\n");
        printf("D. Delete at End\n");
        printf("E. Sort the list\n");
        printf("F. Delete duplicates\n");
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
            case 'C': delete_begin();
                break;
            case 'D': delete_end();
                break;
            case 'E': sort();
                break;
            case 'F': remove_duplicates();
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

void insert_begin() {
    int value;
    printf("Enter value to be inserted: ");
    scanf("%d", &value);
    node* temp;
    temp = (node*)malloc(sizeof(node));
    if(temp == NULL) {
        printf("Memory insufficient\n");
    } else {
        temp->data = value;
        if(head == NULL) {
            head = temp;
            temp->next = head;
        } else {
            node* last = head;
            while(last->next != head) {
                last = last->next;
            }
            temp->next = head;
            last->next = temp;
            head = temp;
        }
        count++;
    }
}

void insert_end() {
    int value;
    printf("Enter value to be inserted: ");
    scanf("%d", &value);
    node* temp;
    temp = (node*)malloc(sizeof(node));
    if(temp == NULL) {
        printf("Memory insufficient\n");
    } else {
        temp->data = value;
        if(head == NULL) {
            head = temp;
            temp->next = head;
        } else {
            node* last = head;
            while(last->next != head) {
                last = last->next;
            }
            last->next = temp;
            temp->next = head;
        }
        count++;
    }
}

void delete_begin() {
    if(head == NULL) {
        printf("List is empty\n");
    } else {
        node* temp = head;
        if(head->next == head) {
            head = NULL;
        } else {
            node* last = head;
            while(last->next != head) {
                last = last->next;
            }
            head = head->next;
            last->next = head;
        }
        free(temp);
        count--;
        printf("First node is deleted successfully\n");
    }
}

void delete_end() {
    if(head == NULL) {
        printf("List is empty\n");
    } else {
        node* temp = head;
        if(head->next == head) {
            head = NULL;
        } else {
            node* prev = NULL;
            while(temp->next != head) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = head;
            free(temp);
        }
        count--;
        printf("Ending node is deleted\n");
    }
}

void sort() {
    if(head == NULL) {
        printf("List is empty\n");
    } else {
        node *current = head, *index = NULL;
        int temp;

        if(head->next != head) {
            do {
                index = current->next;
                while(index != head) {
                    if(current->data > index->data) {
                        temp = current->data;
                        current->data = index->data;
                        index->data = temp;
                    }
                    index = index->next;
                }
                current = current->next;
            } while(current->next != head);
        }
    }
}

void remove_duplicates() {
    if(head == NULL) {
        printf("List is empty\n");
    } else {
        node *current = head, *next_next;
        if(head->next != head) {
            do {
                if(current->data == current->next->data) {
                    next_next = current->next->next;
                    free(current->next);
                    current->next = next_next;
                    count--;  // decrement count when a duplicate node is removed
                } else {
                    current = current->next;
                }
            } while(current->next != head);
        }
    }
}

void display()
{
    if(head == NULL)
        printf("List is empty\n");
    else
    {
        node* p;
        p = head;
        while(p->next!=head)
        {
            printf("%d ",p->data);
            p = p->next;
        }
        printf("%d\n",p->data);
    }
}
