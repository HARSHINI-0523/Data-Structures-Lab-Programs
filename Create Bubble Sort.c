/*A program to sort the elements using bubble sort*/
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int* arr = (int*)calloc(n,sizeof(int));
    printf("Enter the elements of array: ");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    for(int i=1;i<=n;i++)
        for(int j=0,temp;j<n-i;j++)
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
    printf("\nAfter sorting:\n");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    free(arr);
    return 0;
}
