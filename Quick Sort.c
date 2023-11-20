/*A program which sorts the elements using quick sort*/
#include<stdio.h>
#include<stdlib.h>

int partition(int a[],int low,int high)
{
    int pivot = a[low];
    int i = low+1;
    int j= high;
    while(i<=j)
    {
        while(a[i]<=pivot && i<=high)
            i++;
        while(a[j]>pivot && j>=low)
            j--;
        if(i<j)
        {
            int temp = a[i];
            a [i] = a[j];
            a[j] = temp;
        }
    }
    a[low] = a[j];
    a[j] = pivot;
    return j;
}

void quickSort(int a[],int p,int q)
{
    if(p<q)
    {
        int j = partition(a,p,q);
        quickSort(a,p,j-1);
        quickSort(a,j+1,q);
    }
}
int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    int* arr = (int*)calloc(n,sizeof(int));

    printf("\nEnter array elements: ");
    for(int i = 0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("\nElements before sort: ");
    for(int i = 0;i<n;i++)
        printf("%d ",arr[i]);

    quickSort(arr,0,n-1);

    printf("\nElements after quick sort: ");
    for(int i = 0;i<n;i++)
        printf("%d ",arr[i]);

    free(arr);
    return 0;
}
