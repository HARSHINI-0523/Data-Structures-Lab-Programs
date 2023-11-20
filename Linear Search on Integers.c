/*A program to implement linear search on integers*/
#include<stdio.h>

int main()
{
    int n,i=0;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    int A[n];

    printf("\nEnter the elements of the array: ");
    for(int i = 0;i<n;i++)
        scanf("%d",&A[i]);

    int x;
    printf("\nEnter the element to be searched: ");
    scanf("%d",&x);

    while(i<n&&x!=A[i])
        i++;		//goes to the searching element or last

    if(A[i]==x)	//if target is matched returns 1
        printf("\nElement found at index: %d",i);
    else
        printf("\nElement not found");
}
