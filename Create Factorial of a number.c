/*A program which calculates the factorial of number*/
#include<stdio.h>

int fact(int);

int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);

    int Factorial = fact(n);

    printf("The Factorial of %d is %d",n,Factorial);

    return 0;
}

int fact(int n){
    if(n==1||n==0)
        return 1;
    else
        return n*fact(n-1);
}
