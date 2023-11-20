/*A program that prints frequency mismatch elements in two arrays*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);

    int *arr = (int*)calloc(n,sizeof(int));
    	//Dynamic memory allocated to arr

    int *count = (int*)calloc(10001,sizeof(int));
		//Dynamic memory allocated to count

    for(int i = 0;i<n;i++){
	//reads the elements and frequency
        scanf("%d",(arr+i));
        count[*(arr+i)]++;
    }

    int m;
    scanf("%d",&m);

    int *brr = (int*)calloc(m,sizeof(int));
	//Dynamic memory allocated to brr

    for(int i = 0;i<m;i++){
	//reads brr elements and decreases the frequency
        scanf("%d",(brr+i));
        count[*(brr+i)]--;
    }

    for(int i =0;i<10001;i++){
/*the elements with negative frequency are non-repeated or their frequency didn’t match.*/
        if(count[i]<0)
            printf("%d ",i);
    }
    free(arr);
    free(count);
    free(brr);
    return 0;
}
