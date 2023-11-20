/*A program which binary searches using recursion*/
#include<stdio.h>
#include<stdlib.h>

int bs(int*,int,int,int);

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    int* arr = (int*)calloc(n,sizeof(int));

    printf("\nEnter the elements in the list: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    int x;
    printf("Enter element to be searched: ");
    scanf("%d",&x);

    int l=0,h=n-1;

    int result = bs(arr,l,h,x);

    if(result == -1)
        printf("\nElement not found in the list");
    else
        printf("Element found at index: %d",result);

    free(arr);
    return 0;
}
int bs(int* arr,int l,int h,int x){
    int mid = (l+h)/2;
    while(l<=h){
        if(arr[mid]== x)
            return mid;
        else if(arr[mid]>x)
            return bs(arr,l,mid-1,x);
        else
            return bs(arr,mid+1,h,x);
    }
    return -1;
}
