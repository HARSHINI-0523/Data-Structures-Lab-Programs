/*A program to solve towers of hanoi*/
#include<stdio.h>

int toh(int,char,char,char);

int main(){
    int n;
    printf("Enter number of disks: ");
    scanf("%d",&n);

    toh(n,'S','I','D');

    return 0;
}
int toh(int n,char S, char I, char D){
    if(n == 1){
        printf("\nMove disk 1 from %c to %c",S,D);
        return 1;
    }
    toh(n-1,S,D,I);
    printf("\nMove disk %d from %c to %c",n,S,D);
    toh(n-1,I,S,D);
}
 
