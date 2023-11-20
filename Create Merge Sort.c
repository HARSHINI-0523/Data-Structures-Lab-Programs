/*A Program which sorts the given elements using merge sort*/
#include<stdio.h>
#include<stdlib.h>

void merge(int a[],int low,int mid,int high)
{
    int h = low,i = low,j = mid+1,b[high+1];
    while(h<= mid && j<=high)
    {
        if(a[h]<=a[j])
            b[i]=a[h],h++;
        else
            b[i]=a[j],j++;
        i++;
    }
    if(h>mid)
        for(int k =j;k<=high;k++)
            b[i]=a[k],i++;
    else
        for(int k=h;k<=mid;k++)
            b[i]=a[k],i++;
    for(int k=low;k<=high;k++)
        a[k]=b[k];
}

void mergeSort(int arr[],int low,int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
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

    mergeSort(arr,0,n-1);

    printf("\nElements after Merge Sort: ");
    for(int i = 0;i<n;i++)
        printf("%d ",arr[i]);

    return 0;
}
