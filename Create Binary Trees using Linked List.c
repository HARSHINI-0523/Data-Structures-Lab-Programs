/***********************
*implement binary tree using linked list
*insertion using level order
***********************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int max = INT_MIN,min = INT_MAX,found=0;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node* createNode(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct queue{
    int front, rear, size;
    struct node* *arr;
};

struct queue* createQueue(){
    struct queue* newQueue = (struct queue*) malloc(sizeof( struct queue ));

    newQueue->front = -1;
    newQueue->rear = 0;
    newQueue->size = 0;

    newQueue->arr = (struct node**) malloc(100 * sizeof( struct node* ));

    return newQueue;
}

void enqueue(struct queue* queue, struct node *temp){
    queue->arr[queue->rear++] = temp;
    queue->size++;
}

struct node *dequeue(struct queue* queue){
    queue->size--;
    return queue->arr[++queue->front];
}

void insertNode(int data) {
    struct node *newNode = createNode(data);
    if(root == NULL){
        root = newNode;
        return;
    }
    else {
        struct queue* queue = createQueue();
        enqueue(queue, root);

        while(true) {
            struct node *node = dequeue(queue);
            if(node->left != NULL && node->right != NULL) {
                enqueue(queue, node->left);
                enqueue(queue, node->right);
            }
            else {
                if(node->left == NULL) {
                    node->left = newNode;
                    enqueue(queue, node->left);
                }
                else {
                    node->right = newNode;
                    enqueue(queue, node->right);
                }
                break;
            }
        }
    }
}

int HeightOfTheBinaryTree(struct node* root){
    int leftHeight,rightHeight;
    if(root==NULL)
        return 0;
    else{
        leftHeight = HeightOfTheBinaryTree(root->left);
        rightHeight = HeightOfTheBinaryTree(root->right);

        if(leftHeight>rightHeight)
            return leftHeight+1;
        else
            return rightHeight+1;
    }
}

int DeepestNode(struct node* root){
    struct node* temp;
    struct queue *q;
    if(!root) return 0;
    q = createQueue();
    enqueue(q,root);
    while(q->size != 0)
    {
        temp = dequeue(q);
        if(temp->left)
            enqueue(q,temp->left);
        if(temp->right)
            enqueue(q,temp->right);
    }
    return temp->data;
}

void deleteDeepestNode() {
    struct node *temp, *parent;
    struct queue* queue = createQueue();
    enqueue(queue, root);
    while(queue->size != 0) {
        temp = dequeue(queue);
        if(temp->data == DeepestNode(root)) {
            if(parent->right)
                parent->right = NULL;
            else
                parent->left = NULL;
            free(temp);
            return;
        }
        if(temp->left) {
            parent = temp;
            enqueue(queue, temp->left);
        }
        if(temp->right) {
            parent = temp;
            enqueue(queue, temp->right);
        }
    }
}

void delete(int data) {
    struct node *temp, *parent;
    struct queue* queue = createQueue();
    enqueue(queue, root);
    while(queue->size != 0) {
        temp = dequeue(queue);
        if(temp->data == data) {
            temp->data = DeepestNode(root);
            deleteDeepestNode();
            return;
        }
        if(temp->left)
            enqueue(queue, temp->left);
        if(temp->right)
            enqueue(queue, temp->right);
    }
    printf("Element not found in the tree.\n");
}

int NumberOfFullNodes(struct node* root){
    struct node* temp;
    struct queue* q;
    int count = 0;
    if(!root)
        return 0;
    q = createQueue();
    enqueue(q,root);
    while(q->size!=0)
    {
        temp = dequeue(q);
        if(temp->left && temp->right)
            count++;
        if(temp->left)
            enqueue(q,temp->left);
        if(temp->right)
            enqueue(q,temp->right);
    }
    return count;
}

int leafNodes(struct node* root){
    struct node* temp;
    struct queue* q;
    struct queue* res;
    if(!root) return 0;
    q = createQueue();
    enqueue(q,root);
    while(q->size != 0){
        temp = dequeue(q);
        if(!(temp->left)&&!(temp->right))
            printf("%d ",temp->data);
        if(temp->left)
            enqueue(q,temp->left);
        if(temp->right)
            enqueue(q,temp->right);
    }
}

void printPathsRecur(struct node* node, int path[], int pathLen);
void printArray(int ints[], int len);

void printPaths(struct node* node){
  int path[1000];
  printPathsRecur(node, path, 0);
}

void printPathsRecur(struct node* node, int path[], int pathLen){
  if (node==NULL)
    return;

  path[pathLen] = node->data;
  pathLen++;

  if (node->left==NULL && node->right==NULL)
  {
    printArray(path, pathLen);
  }
  else
  {
    printPathsRecur(node->left, path, pathLen);
    printPathsRecur(node->right, path, pathLen);
  }
}

void printArray(int ints[], int len){
  int i;
  for (i=0; i<len; i++)
  {
    printf("%d->", ints[i]);
  }
  printf("NULL\n");
}

int add(struct node* root){
    if(root == NULL)
        return 0;
    else return (root->data + add(root->left) + add(root->right));
}

void inorderTraversal(struct node *node) {
    if(root == NULL){
        printf("Tree is empty\n");
        return;
    }
    else {

        if(node->left != NULL)
            inorderTraversal(node->left);
        printf("%d ", node->data);
        if(node->right != NULL)
            inorderTraversal(node->right);

        }
    }

void preorderTraversal(struct node *node) {
    if(root == NULL){
        printf("Tree is empty\n");
        return;
    }
    else {
        printf("%d ", node->data);
        if(node->left != NULL)
            preorderTraversal(node->left);
        if(node->right != NULL)
            preorderTraversal(node->right);

        }
    }

void postorderTraversal(struct node *node) {
    if(root == NULL){
        printf("Tree is empty\n");
        return;
    }
    else {

        if(node->left != NULL)
            postorderTraversal(node->left);
        if(node->right != NULL)
            postorderTraversal(node->right);
        printf("%d ", node->data);

        }
}

void levelOrderTraversal(struct node* root) {
    if(root == NULL) return;
    struct queue* queue = createQueue();
    enqueue(queue, root);
    while(queue->size!=0) {
        struct node* temp = dequeue(queue);
        printf("%d ", temp->data);
        if(temp->left != NULL)
            enqueue(queue, temp->left);
        if(temp->right != NULL)
            enqueue(queue, temp->right);
    }
}

int maxValue(struct node* node){
    if(root == NULL)
    {
        printf("Tree is empty\n");
        return 0;
    }
    else{
        if(node->data>max)
            max = node->data;
        if(node->left!=NULL)
            maxValue(node->left);
        if(node->right!= NULL)
            maxValue(node->right);
    }
}

int minValue(struct node* node){
    if(root == NULL)
    {
        printf("Tree is empty\n");
        return 0;
    }
    else{
        if(node->data<min)
            min = node->data;
        if(node->left!=NULL)
            minValue(node->left);
        if(node->right!= NULL)
            minValue(node->right);
    }
}

int searchInTree(struct node* node,int value){
    if(root == NULL)
    {
        printf("Tree is empty\n");
        found = 1;
        return 0;
    }
    else{
        if(node->data==value){
            printf("The element found in the tree\n");
            found = 1;
            return 0;
        }
        if(node->left!=NULL)
            searchInTree(node->left,value);
        if(node->right!= NULL)
            searchInTree(node->right,value);
    }
}

void printNodeHeights(struct node* node) {
    if (node == NULL)
        return;
    int nodeHeight = HeightOfTheBinaryTree(node);
    printf("Node value: %d, Height: %d\n", node->data, nodeHeight);
    printNodeHeights(node->left);
    printNodeHeights(node->right);
}

void printNodeDepths(struct node* node, int depth) {
    if (node == NULL)
        return;
    printf("Node value: %d, Depth: %d\n", node->data, depth);
    printNodeDepths(node->left, depth + 1);
    printNodeDepths(node->right, depth + 1);
}

int main() {
    int choice, value, key;
    printf("\n----- Binary Tree -----\n");
    while(1) {
        printf("\n***** MENU *****\n");
        printf("1. Insert\n2. Delete\n3. Pre Order Traversal\n4. In Order Traversal\n5. Post Order Traversal\n6. Level Order Traversal\n7. Height of the binary tree\n8. Deepest node in the binary tree\n9. Number of Full Nodes\n10. Maximum value\n11. Minimum value\n12. Searching\n13. Height of each node\n14. Depth of each node\n15. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter the value to be insert: ");
                scanf("%d", &value);
                insertNode(value);
                break;
            case 2:
                printf("\nEnter the value to be delete: ");
                scanf("%d", &value);
                delete(value);
                break;
            case 3:
                printf("\nPre Order Traversal:\n");
                preorderTraversal(root);
                break;
            case 4:
                printf("\nIn Order Traversal:\n");
                inorderTraversal(root);
                break;
            case 5:
                printf("\nPost Order Traversal:\n");
                postorderTraversal(root);
                break;
            case 6:
                printf("\nLevel Order Traversal:\n");
                levelOrderTraversal(root);
                break;
            case 7:
                printf("\nHeight of the binary tree: %d\n", HeightOfTheBinaryTree(root));
                break;
            case 8:
                printf("\nDeepest node in the binary tree: %d\n", DeepestNode(root));
                break;
            case 9:
                printf("\nNumber of Full Nodes: %d\n", NumberOfFullNodes(root));
                break;
            case 10:
                maxValue(root);
                printf("\nMaximum value in the tree: %d\n", max);
                break;
            case 11:
                minValue(root);
                printf("\nMinimum value in the tree: %d\n", min);
                break;
            case 12:
                printf("\nEnter the value to be searched: ");
                scanf("%d", &key);
                searchInTree(root, key);
                if(found == 0)
                    printf("The element is not found in tree");
                found = 0;
                break;
            case 13:
                printf("\nHeight of each node:\n");
                printNodeHeights(root);
                break;
            case 14:
                printf("\nDepth of each node:\n");
                printNodeDepths(root, 0);
                break;
            case 15:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("\nPlease select correct operations!!!\n");
        }
    }
    return 0;
}
