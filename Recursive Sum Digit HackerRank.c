#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long long sum_digits(long long n) {
    if (n == 0) {
        return 0;
    }
    return n % 10 + sum_digits(n / 10);
    //sum of digits recursive condition
}

int main() {
    long long sd = 0;
    int c;
    do {
        c = getchar();
        if (c != ' ')
            sd += c - '0';
    } while (c != ' ');
    
    int k;
    scanf("%d", &k);
    sd *= k;

    while (sd > 10) {
        sd = sum_digits(sd);
    }
    printf("%lld\n", sd);
    return 0;
}
