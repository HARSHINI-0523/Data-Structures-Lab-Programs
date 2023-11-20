/*A program to sort the elements using selection sort*/
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int* arr = (int*)calloc(n,sizeof(int));
    printf("Enter the elements of array: ");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    for(int i=0;i<n;i++){
        int target = i,temp;
        for(int j=i+1;j<n;j++)
            if(arr[j]<arr[target])
                target = j;
        temp = arr[target];
        arr[target]=arr[i];
        arr[i]=temp;
    }
    printf("\nAfter sorting:\n");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    free(arr);
    return 0;
}
