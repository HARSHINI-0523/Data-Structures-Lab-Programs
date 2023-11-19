#include <stdio.h>
#define MAX 2000000

typedef short int si;

si stack1[MAX], stack2[MAX];
si top1 = -1, top2 = -1;

void push1(si x) {
    stack1[++top1] = x;
}

void push2(si x) {
    stack2[++top2] = x;
}

void pop1() {
    if(top1 != -1)
        top1--;
}

void pop2() {
    if(top2 != -1)
        top2--;
}

si peek1() {
    return stack1[top1];
}

si peek2() {
    return stack2[top2];
}

int isEmpty1() {
    return top1 == -1;
}

int isEmpty2() {
    return top2 == -1;
}

int main()
{
    si n;
    scanf("%hd", &n);
    
    si a[n];
    for(si i=0;i<n;i++) scanf("%hd", &a[i]);
    
    si next_greater[n], next_smaller[n];
    
 	for (si i=n-1; i>=0; i--)
    {
		while (!isEmpty1() && a[peek1()] <= a[i] )
            pop1();
 
 
        if (!isEmpty1())
            next_greater[i] = peek1();
        else
            next_greater[i] = -1;
 
        push1(i);
    }
    
 	for (si i=n-1; i>=0; i--)
    {
        while (!isEmpty2() && a[peek2()] >= a[i])
            pop2();
 
		if (!isEmpty2())
            next_smaller[i] = peek2();
		else
            next_smaller[i] = -1;
 
        push2(i);
    }
    
    
    for (si i=0; i< n; i++)
    {
	    if (next_greater[i] != -1 && next_smaller[next_greater[i]] != -1)
            printf("%hd ", a[next_smaller[next_greater[i]]]);
		else
            printf("-1 ");
    }
    
    return 0;
}
