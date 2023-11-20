/*A program which implements Binary Search on integers*/
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    int A[n];

    printf("\nEnter the elements of the array: ");
    for(int i = 0;i<n;i++)
        scanf("%d",&A[i]);

    int x;
    printf("\nEnter the element to be searched: ");
    scanf("%d",&x);

    int low=1,high=n-1;

    while(low<=high)
    {
        int mid = (low+high)/2;
        if(x==A[mid])
        {
         printf("Element found at index: %d",mid);
         exit(0);
        }
        else if(x<A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    if(low>high)
        printf("Element not found");
}
