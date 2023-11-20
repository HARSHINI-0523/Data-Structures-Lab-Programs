#include<stdio.h>
#include<limits.h>
#define MAX 15

int tree[MAX]={1,2,3,4,5,6};
int complete_node = 6;

int max=INT_MIN,min=INT_MAX,sum = 0;

void insert(int data) {
    if(complete_node >= MAX) {
        printf("Tree is full. Cannot insert new element.\n");
        return;
    }
    tree[complete_node] = data;
    complete_node++;
}


void delete(int data) {
    if(complete_node == 0) {
        printf("Tree is empty. Cannot delete.\n");
        return;
    }
    int i;
    for(i = 0; i < complete_node; i++) {
        if(tree[i] == data)
            break;
    }
    if(i == complete_node) {
        printf("Data not found in tree.\n");
        return;
    }
    tree[i] = tree[complete_node - 1];
    complete_node--;
}


int search(int data) {
    for(int i = 0; i < complete_node; i++) {
        if(tree[i] == data)
            return i;
    }
    return -1;
}


void displayTree() {
    printf("\n");
    for (int i = 0; i < complete_node; i++) {
        if (tree[i] != '\0')
            printf(" %d ",tree[i]);
        else
            printf(" - ");
    }
}

int getLeftChild(int index) {
    if(tree[index]!='\0' && (2*index)+1<complete_node)
        return (2*index)+1;
    return -1;
}

int getRightChild(int index) {
    if(tree[index]!='\0' && ((2*index)+2)<complete_node)
        return (2*index)+2;
    return -1;
}

void preorder(int index) {
    if(index>=0 && tree[index]!='\0') {
        printf(" %d ",tree[index]);
        if(tree[index]>=max)
            max = tree[index];
        if(tree[index]<=min)
            min = tree[index];
        sum += tree[index];
        preorder(getLeftChild(index));
        preorder(getRightChild(index));
    }
}

void inorder(int index) {
    if(index>=0 && tree[index]!='\0') {
        inorder(getLeftChild(index));
        printf(" %d ",tree[index]);
        inorder(getRightChild(index));
    }
}

void postorder(int index) {
    if(index>=0 && tree[index]!='\0') {
        postorder(getLeftChild(index));
        postorder(getRightChild(index));
        printf(" %d ",tree[index]);
    }
}

void levelorder() {
    int j;
    for(j=0;j<complete_node;j++) {
        if(tree[j]!='\0')
            printf(" %d ",tree[j]);
    }
}

int isLeaf(int index) {
    if(!getLeftChild(index) && !getRightChild(index)){
        return 1;
    }
    if(tree[getLeftChild(index)]=='\0' && tree[getRightChild(index)]=='\0'){
        return 1;
    }
    return 0;
}

int getMax(int a, int b) {
    return (a>b) ? a : b;
}

int getHeight(int index) {
    if(tree[index]=='\0' || index<0 || isLeaf(index))
        return 0;
    return(getMax(getHeight(getLeftChild(index)), getHeight(getRightChild(index)))+1);
}

int main() {
    int choice, data;
    do {
        printf("\n*********Main Menu*********\n");
        printf("Choose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("1. Insertion\n2. Deletion\n3. Pre Order Traversal\n4. In Order Traversal\n5. Post Order Traversal\n6. Level Order Traversal\n7. Print Leaf Nodes\n8. Print Height of the tree\n9. Maximum Value in the tree\n10. Minimum Value in the tree\n11. Searching in the tree\n12. Exit\n");
        printf("\nEnter your choice?\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("Enter the value to be deleted: ");
                scanf("%d", &data);
                delete(data);
                break;
            case 3:
                printf("\nPreorder:\n");
                preorder(0);
                break;
            case 4:
                printf("\nInorder:\n");
                inorder(0);
                break;
            case 5:
                printf("\nPostorder:\n");
                postorder(0);
                break;
            case 6:
                printf("\nLevelorder:\n");
                levelorder();
                break;
            case 7:
                printf("\nLeaf nodes:\n");
                for(int i=0;i<complete_node;i++) {
                    if(tree[i]!='\0'){
                        if(isLeaf(i))
                            printf("\n%d is a leaf node",tree[i]);
                    }
                }
                break;
            case 8:
                printf("\nHeight of the tree is: %d\n", getHeight(0));
                break;
            case 9:
                printf("\nThe maximum element in tree is %d\n", max);
                break;
            case 10:
                printf("\nThe minimum element in tree is %d\n", min);
                break;
            case 11:
                printf("Enter the value to be searched: ");
                scanf("%d", &data);
                if(search(data) != -1)
                    printf("\n%d is found in the tree", data);
                else
                    printf("\n%d is not found in the tree", data);
                break;
            case 12:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 12);
    return 0;
}
