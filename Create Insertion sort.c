/*A program to sort the elements using insertion sort*/
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int* arr = (int*)calloc(n,sizeof(int));
    printf("Enter the elements of array: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(int i=1,j;i<n;i++){
        int key = arr[i];
        for(j=i-1;j>=0;j--)
            if(key<arr[j])
                arr[j+1]=arr[j];
        arr[j+1]=key;
    }
    printf("\nAfter sorting:\n");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    free(arr);
    return 0;
}
